#include "backend.h"

Backend::Backend(){

    availableGpus = GpuScanner();
    database = DatabaseManager();
    storedGpus = database.getGpus();

}

std::vector<Gpu> Backend::getAvailableGpus(){
    return availableGpus.getGpus();
}

void Backend::scanGpus(){
    availableGpus.scan();
}