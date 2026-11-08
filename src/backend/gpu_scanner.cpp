// Implements GPU enumeration and collection of basic device properties via
// OpenCL.
#include "gpu_scanner.h"
std::vector<Gpu> gpuScanner()
{
    // Gather devices across each OpenCL platform before reading their
    // properties.
    std::vector<Gpu> gpuSpecs;
    cl_uint pNumEntries = 0;
    cl_uint numPlatforms;
    clGetPlatformIDs(0, NULL, &numPlatforms);

    pNumEntries = numPlatforms;
    std::vector<cl_platform_id> platforms(numPlatforms);
    clGetPlatformIDs(numPlatforms, platforms.data(), nullptr);
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
        size_t paramSize;
        clGetDeviceInfo(deviceIDs[i], CL_DEVICE_NAME, 0, nullptr, &paramSize);
        std::string name(paramSize, '\0');
        clGetDeviceInfo(deviceIDs[i], CL_DEVICE_NAME, paramSize, name.data(),
                        nullptr);
        name.pop_back();
        clGetDeviceInfo(deviceIDs[i], CL_DEVICE_VENDOR, 0, nullptr,
                        &paramSize);
        std::string vendor(paramSize, '\0');
        clGetDeviceInfo(deviceIDs[i], CL_DEVICE_VENDOR, paramSize,
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
