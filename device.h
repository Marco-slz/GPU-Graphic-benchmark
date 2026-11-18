// Defines the common device model and the GPU-specific property model.
#pragma once
#ifdef __APPLE__
#include <OPENCL/opencl.h>
#else
#include <CL/opencl.h>
#endif
#include <string>
#include <vector>

class Device
{
  public:
    Device(int id, std::string vendor, std::string model);
    Device(std::string vendor, std::string model);
    int get_id() const;
    std::string get_model() const;
    std::string get_vendor() const;

  private:
    // properties
    int m_id;
    std::string m_model;
    std::string m_vendor;
};

