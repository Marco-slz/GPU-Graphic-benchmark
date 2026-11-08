// Declares the OpenCL-based GPU discovery function.
#pragma once

#include "device.h"
#include <iostream>
#include <vector>

// Return the GPUs found across all available OpenCL platforms.
std::vector<Gpu> gpuScanner();
