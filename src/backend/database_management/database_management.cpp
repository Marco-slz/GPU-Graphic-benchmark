#include "database_management.h"

DatabaseManager::DatabaseManager()
{

    db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("assets/database/database.db");
    
    db.open();
}

void DatabaseManager::storeGpu(Gpu gpu)
{
    QSqlQuery query(db);
    query.prepare("INSERT INTO devices(device_type, model, vendor) "
                  "VALUES(:device_type, :model, :vendor)");

    query.bindValue(":device_type", "GPU");
    query.bindValue(":model", QString::fromStdString(gpu.get_model()));
    query.bindValue(":vendor", QString::fromStdString(gpu.get_vendor()));

    query.exec();
}

std::vector<Gpu> DatabaseManager::getGpus()
{
    std::vector<Gpu> storedGpus;
    QSqlQuery query(db);
    query.prepare("SELECT * FROM devices");
    query.exec();
    while (query.next())
    {
        storedGpus.push_back(
            Gpu(query.value("vendor").toString().toStdString(),
                query.value("model").toString().toStdString()));
    }
    return storedGpus;
}