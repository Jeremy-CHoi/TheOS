#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlDatabase>
#include <QVector>
#include "user.h"

class Database
{
public:

    static Database *getInstance();

    bool insert(User &user);

    bool find(QString name);

    bool judge(QString name, QString password);

private:

    Database();

    QSqlDatabase db_;
};

#endif // DATABASE_H
