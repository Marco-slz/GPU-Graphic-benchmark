// Implements GPU enumeration and collection of basic device properties via
// OpenCL.
#include "gpuscanner.h"
std::vector<Gpu> gpuScanner()
{
    // Gather devices across each OpenCL platform before reading their
    // properties.
    std::vector<Gpu> gpuSpecs;
    cl_uint pNumEntries = 0;
    cl_uint num_platforms;
    clGetPlatformIDs(0, NULL, &num_platforms);

    pNumEntries = num_platforms;
    std::vector<cl_platform_id> platforms(num_platforms);
    clGetPlatformIDs(num_platforms, platforms.data(), nullptr);
    std::vector<cl_device_id> deviceIDs;
    // Query each platform for GPU devices and append them to the combined list.
    for (cl_uint i = 0; i < pNumEntries; i++)
    {
        cl_uint dNumEntries = 0;
        cl_uint numDevices;
        clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_GPU, dNumEntries, NULL,
                       &numDevices);
        dNumEntries = numDevices;
        std::vector<cl_device_id> platformDeviceIDs(dNumEntries);
        clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_GPU, dNumEntries,
                       platformDeviceIDs.data(), nullptr);
        deviceIDs.insert(deviceIDs.end(), platformDeviceIDs.begin(),
                         platformDeviceIDs.end());
    }

    // Read the name, vendor, memory capacity, and maximum clock for each GPU.
    for (size_t i = 0; i < deviceIDs.size(); i++)
    {
        size_t param_size;
        clGetDeviceInfo(deviceIDs[i], CL_DEVICE_NAME, 0, nullptr, &param_size);
        std::string name(param_size, '\0');
        clGetDeviceInfo(deviceIDs[i], CL_DEVICE_NAME, param_size, name.data(),
                        nullptr);
        name.pop_back();
        clGetDeviceInfo(deviceIDs[i], CL_DEVICE_VENDOR, 0, nullptr,
                        &param_size);
        std::string vendor(param_size, '\0');
        clGetDeviceInfo(deviceIDs[i], CL_DEVICE_VENDOR, param_size,
                        vendor.data(), nullptr);
        vendor.pop_back();
        cl_ulong vram;
        clGetDeviceInfo(deviceIDs[i], CL_DEVICE_GLOBAL_MEM_SIZE, sizeof(vram),
                        &vram, nullptr);

        cl_uint clockSpeed;
        clGetDeviceInfo(deviceIDs[i], CL_DEVICE_MAX_CLOCK_FREQUENCY,
                        sizeof(clockSpeed), &clockSpeed, nullptr);

        long long gpuVram = vram;
        double gpuClockSpeed = clockSpeed;
        // Store the collected values in the application's GPU model.
        gpuSpecs.push_back({name, vendor, gpuVram, gpuClockSpeed});
        // std::cout << "name: " << name << " vendor: " << vendor << " VRam: "
        // << gpuVram / (1024 * 1024 * 1024)<< " gpuClockSpeed: " <<
        // gpuClockSpeed;
    }
    // Return all discovered GPU records to the caller.
    return gpuSpecs;
}
