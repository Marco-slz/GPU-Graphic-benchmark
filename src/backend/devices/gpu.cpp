#include "gpu.h"



// Construct a GPU from the properties currently supplied by the scanner.
Gpu::Gpu(std::string vendor, std::string model, bool unifiedMemory, unsigned long long vramCapacity,
         unsigned long long clockSpeed)
    : Device{vendor, model}, m_vramCapacity{vramCapacity},
      m_clockSpeed{clockSpeed}, m_unifiedMemory{unifiedMemory}
{
}

unsigned long long Gpu::get_vramCapacity() const { return m_vramCapacity; }
unsigned long long Gpu::get_clockSpeed() const { return m_clockSpeed; }
bool Gpu::get_unifiedMemory () const{
  return m_unifiedMemory;
}