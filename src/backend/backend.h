#pragma once

#include "database_management.h"
#include "gpu.h"
#include "gpu_scanner.h"
#include <vector>

class Backend{
    public:
        Backend();
        std::vector<Gpu> getAvailableGpus();
        void scanGpus();
    private:
        DatabaseManager database;
        GpuScanner availableGpus;
        std::vector <Gpu> storedGpus;
};