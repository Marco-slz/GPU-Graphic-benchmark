#pragma once    
#include <QSqlDatabase>
#include <QSqlQuery>
#include <vector>
#include "gpu.h"
#include <iostream>
class DatabaseManager{
    public:
        DatabaseManager();
        void storeGpu(Gpu gpu);
       std::vector <Gpu> getGpus();
    private:
       QSqlDatabase db;
};