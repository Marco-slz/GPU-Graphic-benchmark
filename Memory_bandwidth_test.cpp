#include "Memory_bandwidth_test.h"
#include <chrono>
#include <stdexcept>

std::string MemoryBandwidthTest::name() const { return "Memory Bandwidth"; }

double MemoryBandwidthTest::run(cl_device_id device)
{
    cl_int err;

    cl_context context = clCreateContext(nullptr, 1, &device, nullptr, nullptr, &err);
    if (err != CL_SUCCESS)
        throw std::runtime_error("Failed to create OpenCL context.");


    cl_command_queue queue = clCreateCommandQueue(context, device, 0, &err);
    if (err != CL_SUCCESS)
        throw std::runtime_error("Failed to create command queue.");
    
    cl_ulong maxAlloc;
    err = clgetDeviceInfo(device, CL_DEVICE_MAX_MEM_ALLOC_SIZE,
                          SIZEOF(maxAlloc), &maxAlloxc, nullptr);
    if  (err != CL_SUCCESS)
        throw std::runtime_error("Failed to query max allocation size.");

    size_t bufferSize = 256ull *1024 *1024;
    if (bufferSize > maxAlloc)
    bufferSize = MaxAlloc;

    unsigned char zero = 0;
        err = clEnqueueFillBuffer(queue, src, &zero, sizeof(zero), 0, bufferSize,
                              0, nullptr, nullptr);
    if (err != CL_SUCCESS)
        throw std::runtime_error("Failed to fill source buffer.");

    cl_mem src = clCreateBuffer(context, CL_MEM_READ_WRITE, bufferSize, nullptr, &err);
    if (err != Cl_Success)
        throw std::runtime_error("failed to create source buffer.");

    return 0.0; 
}
