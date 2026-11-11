#include "gpu.h"



// Construct a GPU from the properties currently supplied by the scanner.
Gpu::Gpu(std::string vendor, std::string model, unsigned long long vramCapacity,
         unsigned long long clockSpeed)
    : Device{vendor, model}, m_vramCapacity{vramCapacity},
      m_clockSpeed{clockSpeed}
{
}

unsigned long long Gpu::get_vramCapacity() const { return m_vramCapacity; }
unsigned long long Gpu::get_clockSpeed() const { return m_clockSpeed; }