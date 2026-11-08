#include "gpu.h"

Gpu::Gpu(int id, std::string make, std::string model, unsigned long long vramCapacity,
         unsigned long long clockSpeed, double memoryBandwith, double powerLimit)
    : Device{id, make, model}, m_vramCapacity{vramCapacity},
      m_clockSpeed{clockSpeed}, m_memoryBandwith{memoryBandwith},
      m_powerLimit{powerLimit}
{
}

// Construct a GPU from the properties currently supplied by the scanner.
Gpu::Gpu(std::string make, std::string model, unsigned long long vramCapacity,
         unsigned long long clockSpeed)
    : Device{make, model}, m_vramCapacity{vramCapacity},
      m_clockSpeed{clockSpeed}
{
}

unsigned long long Gpu::get_vramCapacity() const { return m_vramCapacity; }
unsigned long long Gpu::get_clockSpeed() const { return m_clockSpeed; }
double Gpu::get_memoryBandwith() const { return m_memoryBandwith; }
double Gpu::get_powerLimit() const { return m_powerLimit; }