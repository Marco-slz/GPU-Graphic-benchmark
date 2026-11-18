#pragma once
#include "device.h"

// GPU model extending a device identity with graphics hardware specifications.
class Gpu : public Device
// TODO: Add remaining data members
//       Add vector of tests of type Test
//       Implement Test Class
{
  public:
    Gpu(std::string vendor, std::string model, bool unifiedMemory, unsigned long long vramCapacity = 0,
        unsigned long long clockSpeed = 0);
    // getters.
    unsigned long long get_vramCapacity() const;
    unsigned long long get_clockSpeed() const;
    bool get_unifiedMemory () const;
    // setters.
  private:
    // properties
    unsigned long long m_vramCapacity;
    unsigned long long m_clockSpeed;
    bool m_unifiedMemory;
    // TODO: add the remaining fields.
};

