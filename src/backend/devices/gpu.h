#include "device.h"

// GPU model extending a device identity with graphics hardware specifications.
class Gpu : public Device
// TODO: Add remaining data members
//       Add vector of tests of type Test
//       Implement Test Class
{
  public:
    Gpu(int id, std::string make, std::string model, unsigned long long vramCapacity,
        unsigned long long clockSpeed, double memoryBandwith, double powerLimit);
    Gpu(std::string make, std::string model, unsigned long long vramCapacity,
        unsigned long long clockSpeed);
    // getters.
    unsigned long long get_vramCapacity() const;
    unsigned long long get_clockSpeed() const;
    double get_memoryBandwith() const;
    double get_powerLimit() const;
    // setters.
  private:
    // properties
    unsigned long long m_vramCapacity;
    unsigned long long m_clockSpeed;
    double m_memoryBandwith;
    double m_powerLimit;
    // TODO: add the remaining fields.
};