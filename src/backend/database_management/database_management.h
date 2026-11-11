#include <QSqlDatabase>
#include <QSqlQuery>
#include "gpu.h"

class DatabaseManager{
    public:
        DatabaseManager();
    private:
       QSqlDatabase db;
}