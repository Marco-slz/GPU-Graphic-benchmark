// Declares the OpenCL-based GPU discovery function.
#pragma once

#include "gpu.h"
#include <iostream>
#include <vector>
#include <stdexcept>

class GpuScanner{
    public:
        GpuScanner();
        void scan();
        Gpu operator [](int index);
    private:
        std::vector<Gpu> gpus;
};
// Return the GPUs found across all available OpenCL platforms.

