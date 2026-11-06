#pragma once
#include <OPENCL/opencl.h>
#include <string>
#include <vector>
//TODO: ADD VENDOR TO DEVICE
class Device
{
  public:
    Device(int id, std::string make, std::string model);
    Device(std::string make, std::string model);
    int get_id() const;
    std::string get_make() const;
    std::string get_model() const;
    //virtual double calculate_performance() = 0;
    //virtual void findDevice() = 0;

  private:
    // properties
    int m_id;
    std::string m_make;
    std::string m_model;
};
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


