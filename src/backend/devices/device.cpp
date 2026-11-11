// Implements construction and read access for device and GPU model objects.
#include "device.h"
// Construct a device with an explicit identifier and descriptive fields.
Device::Device(int id, std::string vendor, std::string model)
    : m_id{id}, m_vendor{vendor}, m_model{model}
{
}

// Construct a device when an identifier is not supplied.
Device::Device(std::string vendor, std::string model)
    : m_vendor{vendor}, m_model{model}
{
}
// Construct a GPU with identity, memory, clock, bandwidth, and power data.

// Accessors expose stored device and GPU properties without modifying them.
int Device::get_id() const { return m_id; }
std::string Device::get_model() const { return m_model; }
std::string Device::get_vendor() const { return m_vendor; }


