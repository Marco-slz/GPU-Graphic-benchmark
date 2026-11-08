#include "device.h"

// GPU model extending a device identity with graphics hardware specifications.
class Gpu : public Device
// TODO: Add remaining data members
//       Add vector of tests of type Test
//       Implement Test Class
{
  public:
    Gpu(int id, std::string make, std::string model, long long vramCapacity,
        double clockSpeed, double memoryBandwith, double powerLimit);
    Gpu(std::string make, std::string model, long long vramCapacity,
        double clockSpeed);
    // getters.
    long long get_vramCapacity() const;
    double get_clockSpeed() const;
    double get_memoryBandwith() const;
    double get_powerLimit() const;
    // setters.
  private:
    // properties
    long long m_vramCapacity;
    double m_clockSpeed;
    double m_memoryBandwith;
    double m_powerLimit;
    // TODO: add the remaining fields.
};