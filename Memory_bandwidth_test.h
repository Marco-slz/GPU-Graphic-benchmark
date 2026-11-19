#pragma once
#include "test.h"

class MemoryBandwidthTest : public Test
{
  public:
    std::string name() const override;
    double run(cl_device_id device) override;   // returns GB/s
};
