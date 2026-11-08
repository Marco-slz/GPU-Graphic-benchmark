// Implements construction and read access for device and GPU model objects.
#include "device.h"
// Construct a device with an explicit identifier and descriptive fields.
Device::Device(int id, std::string make, std::string model)
    : m_id{id}, m_make{make}, m_model{model}
{
}
// Construct a device when an identifier is not supplied.
Device::Device(std::string make, std::string model)
    : m_make{make}, m_model{model}
{
}
// Construct a GPU with identity, memory, clock, bandwidth, and power data.
Gpu::Gpu(int id, std::string make, std::string model, long long vramCapacity,
         double clockSpeed, double memoryBandwith, double powerLimit)
    : Device{id, make, model}, m_vramCapacity{vramCapacity},
      m_clockSpeed{clockSpeed}, m_memoryBandwith{memoryBandwith},
      m_powerLimit{powerLimit}
{
}

// Construct a GPU from the properties currently supplied by the scanner.
Gpu::Gpu(std::string make, std::string model, long long vramCapacity,
         double clockSpeed)
    : Device{make, model}, m_vramCapacity{vramCapacity},
      m_clockSpeed{clockSpeed}
{
}
// Accessors expose stored device and GPU properties without modifying them.
int Device::get_id() const { return m_id; }
std::string Device::get_make() const { return m_make; }
std::string Device::get_model() const { return m_model; }
std::string Device::get_vendor() const { return m_vendor; }

long long Gpu::get_vramCapacity() const { return m_vramCapacity; }
double Gpu::get_clockSpeed() const { return m_clockSpeed; }
double Gpu::get_memoryBandwith() const { return m_memoryBandwith; }
double Gpu::get_powerLimit() const { return m_powerLimit; }
