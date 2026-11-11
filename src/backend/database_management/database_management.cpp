#include "database_management.h"

DatabaseManager::DatabaseManager(){
    db =  QSqlDatabase::addDatabase("QSQLITE", "assets/database/db");
    db.open();
}