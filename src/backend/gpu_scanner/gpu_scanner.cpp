#include "gpu_scanner.h"

GpuScanner::GpuScanner() { scan(); }

void GpuScanner::scan()
{
    gpus.clear();
    // Gather devices across each OpenCL platform before reading their
    // properties.
    cl_int success;

    cl_uint pNumEntries = 0;
    cl_uint numPlatforms;
    success = clGetPlatformIDs(0, NULL, &numPlatforms);
    if (success != CL_SUCCESS)
    {
        throw std::runtime_error("Failed to retrieve OpenCL platforms.");
    }
    pNumEntries = numPlatforms;
    std::vector<cl_platform_id> platforms(numPlatforms);
    success = clGetPlatformIDs(numPlatforms, platforms.data(), nullptr);
    if (success != CL_SUCCESS)
    {
        throw std::runtime_error("Failed to retrieve OpenCL platforms.");
    }
    std::vector<cl_device_id> deviceIDs;
    // Query each platform for GPU devices and append them to the combined list.
    for (cl_uint i = 0; i < pNumEntries; i++)
    {
        cl_uint dNumEntries = 0;
        cl_uint numDevices;
        success = clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_GPU, dNumEntries,
                                 NULL, &numDevices);
        if (success == CL_DEVICE_NOT_FOUND)
        {
            continue;
        }
        if (success != CL_SUCCESS)
        {
            throw std::runtime_error("Failed to retrieve OpenCL platforms.");
        }
        dNumEntries = numDevices;
        std::vector<cl_device_id> platformDeviceIDs(dNumEntries);
        success = clGetDeviceIDs(platforms[i], CL_DEVICE_TYPE_GPU, dNumEntries,
                                 platformDeviceIDs.data(), nullptr);
        if (success != CL_SUCCESS)
        {
            throw std::runtime_error("Failed to retrieve OpenCL platforms.");
        }
        deviceIDs.insert(deviceIDs.end(), platformDeviceIDs.begin(),
                         platformDeviceIDs.end());
    }

    // Read the name, vendor, memory capacity, and maximum clock for each GPU.
    for (size_t i = 0; i < deviceIDs.size(); i++)
    {

        size_t paramSize;
        success = clGetDeviceInfo(deviceIDs[i], CL_DEVICE_NAME, 0, nullptr,
                                  &paramSize);
        if (success != CL_SUCCESS)
        {
            throw std::runtime_error("Failed to retrieve OpenCL platforms.");
        }
        std::string gpuModel(paramSize, '\0');
        success = clGetDeviceInfo(deviceIDs[i], CL_DEVICE_NAME, paramSize,
                                 gpuModel.data(), nullptr);
        if (success != CL_SUCCESS)
        {
            throw std::runtime_error("Failed to retrieve OpenCL platforms.");
        }
     gpuModel.pop_back();
        success = clGetDeviceInfo(deviceIDs[i], CL_DEVICE_VENDOR, 0, nullptr,
                                  &paramSize);
        if (success != CL_SUCCESS)
        {
            throw std::runtime_error("Failed to retrieve OpenCL platforms.");
        }
        std::string gpuVendor(paramSize, '\0');
        success = clGetDeviceInfo(deviceIDs[i], CL_DEVICE_VENDOR, paramSize,
                                  gpuVendor.data(), nullptr);
        if (success != CL_SUCCESS)
        {
            throw std::runtime_error("Failed to retrieve OpenCL platforms.");
        }
        gpuVendor.pop_back();
        cl_ulong vram;
        success = clGetDeviceInfo(deviceIDs[i], CL_DEVICE_GLOBAL_MEM_SIZE,
                                  sizeof(vram), &vram, nullptr);
        if (success != CL_SUCCESS)
        {
            throw std::runtime_error("Failed to retrieve OpenCL platforms.");
        }
        cl_uint clockSpeed;
        success = clGetDeviceInfo(deviceIDs[i], CL_DEVICE_MAX_CLOCK_FREQUENCY,
                                  sizeof(clockSpeed), &clockSpeed, nullptr);
        if (success != CL_SUCCESS)
        {
            throw std::runtime_error("Failed to retrieve OpenCL platforms.");
        }
        gpus.push_back( {gpuModel, gpuVendor, vram, clockSpeed});
    }
}

Gpu GpuScanner::operator[](int index) { return gpus[index]; }

std::vector<Gpu> GpuScanner::getGpus(){
    return gpus;
}