#include "database_management.h"
#include <QFile>
#include <QSqlError>

DatabaseManager::DatabaseManager()
{
    const QString dbPath = "assets/database/database.db";
    const bool isFirstRun = !QFile::exists(dbPath);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);
    if (!db.open()) {
        qCritical() << "Could not open database:"
                    << db.lastError().text();
        return;
    }

    if (isFirstRun && !initializeDatabase()) {
        qCritical() << "Could not initialize database.";
    }
}

bool DatabaseManager::initializeDatabase()
{

    QFile schemaFile("assets/database/schema.sql");

    if (!schemaFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qCritical() << "schema.sql could not be read: "
                    << schemaFile.errorString();
        return false;
    }

    const QString schema = QString::fromUtf8(schemaFile.readAll());
    const QStringList statements =
        schema.split(';', Qt::SkipEmptyParts);

    QSqlQuery query(db);

    for (const QString &statement : statements) {
        const QString sql = statement.trimmed();

        if (!sql.isEmpty() && !query.exec(sql)) {
            qCritical() << "Error executing schema:"
                        << query.lastError().text()
                        << "\nStatement:" << sql;
            return false;
        }
    }
    return true;
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

    query.prepare("INSERT INTO gpu_properties(device_id, clock_speed, vram_capacity) "
                  "VALUES(:device_id, :clock_speed, :vram_capacity)");
    const QVariant device_id = query.lastInsertId();
    query.bindValue(":device_id", device_id);
    query.bindValue(":clock_speed", gpu.get_clockSpeed());
    query.bindValue(":vram_capacity", gpu.get_vramCapacity());
    query.exec();
}

std::vector<Gpu> DatabaseManager::getGpus()
{
    std::vector<Gpu> storedGpus;
    // TODO: add bool unified to the database table before uncommenting the code
    // QSqlQuery query(db);
    // query.prepare("SELECT * FROM devices");
    // query.exec();
    // while (query.next())
    // {
    //     storedGpus.push_back(
    //         Gpu(query.value("vendor").toString().toStdString(),
    //             query.value("model").toString().toStdString()));
    // }
    return storedGpus;
}
