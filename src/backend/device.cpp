#include "device.h"
Device::Device(int id, std::string make, std::string model)
    : m_id{id}, m_make{make}, m_model{model}
{
}
Device::Device(std::string make, std::string model)
    : m_make{make}, m_model{model}
{
}
Gpu::Gpu(int id, std::string make, std::string model, long long vramCapacity,
         double clockSpeed, double memoryBandwith, double powerLimit)
    : Device{id, make, model}, m_vramCapacity{vramCapacity},
      m_clockSpeed{clockSpeed}, m_memoryBandwith{memoryBandwith},
      m_powerLimit{powerLimit}
{
}

Gpu::Gpu(std::string make, std::string model, long long vramCapacity,
         double clockSpeed)
    : Device{make, model}, m_vramCapacity{vramCapacity},
      m_clockSpeed{clockSpeed}
{
}
int Device::get_id() const { return m_id; }
std::string Device::get_make() const { return m_make; }
std::string Device::get_model() const { return m_model; }
long long Gpu::get_vramCapacity() const { return m_vramCapacity; }
double Gpu::get_clockSpeed() const { return m_clockSpeed; }
double Gpu::get_memoryBandwith() const { return m_memoryBandwith; }
double Gpu::get_powerLimit() const { return m_powerLimit; }
