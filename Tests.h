#pragma once
#include "device.h"
#include <string>

class Test {
  public:
    virtual ~Test() = default;
    virtual std::string name() const = 0;
    virtual double run(cl_device_id device) = 0;  // returns the score
}
;
