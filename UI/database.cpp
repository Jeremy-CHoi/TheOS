#include "database.h"
#include "user.h"
#include <QSql>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include <QSqlDatabase>

Database::Database()
{
    // 1. judge the database exist or not
    if (!QSqlDatabase::contains("test"))
    {
        db_ = QSqlDatabase::addDatabase("QSQLITE", "test");
        qDebug() << db_.connectionName();

        //set database name
        db_.setDatabaseName("users.db");
        qDebug() << db_.databaseName();

    }
    else
    {
        db_ = QSqlDatabase::addDatabase("test");
    }

    // 2. open the database
    if (!db_.open())
    {
        qDebug() << "open:" << db_.lastError().text();
        return;
    }

    // 3. create the database table
    QString sql = "create table if not exists users(name varchar(30), password varchar(30), sex varchar(10), birthday varchar(20));";
    QSqlQuery query(db_);
    if (query.exec(sql))
    {
        qDebug() << "create table successfully!";
    }
    db_.close();
}

Database *Database::getInstance()
{
    static Database db;
    return &db;
}

bool Database::insert(User &user)
{
    QString sql = QString("insert into users values('%1','%2','%3','%4');")
            .arg(user.name())
            .arg(user.password())
            .arg(user.sex())
            .arg(user.birthday());
    // 1. open the database
    if (!db_.open())
    {
        qDebug() << "open:" << db_.lastError().text();
        return false;
    }

    // 2. excute sql
    QSqlQuery query(db_);
    if (!query.exec(sql))
    {
        qDebug() << "insert:" << query.lastError().text();
        return false;
    }

    // 3. close the database
    db_.close();
    return true;
}

bool Database::find(QString name)
{
    QString sql = QString("select name from users where name = :xxx;");

    // 1. open the database
    if (!db_.open())
    {
        qDebug() << "open:" << db_.lastError().text();
        exit(-1);
    }

    // 2. excute sql
    QSqlQuery query(db_);
    query.prepare(sql);
    query.bindValue(":xxx", QVariant(name));
    query.exec();

    // 3. if search successfully:
    if (query.next())
    {
        if (name == query.value(0).toString())
        {
            return true;
        }
    }

    // 4. close the database
    db_.close();
    return false;
}

bool Database::judge(QString name, QString password)
{
    QString sql = QString("select name, password from users where name = :xxx;");

    // 1. open the database
    if (!db_.open())
    {
        qDebug() << "open:" << db_.lastError().text();
        exit(-1);
    }

    // 2. excute sql
    QSqlQuery query(db_);
    query.prepare(sql);
    query.bindValue(":xxx", QVariant(name));
    query.exec();

    // 3. check the password
    if (query.next())
    {
        if(!(password == query.value(1).toString()))
        {
            return false;
        }
    }

    // 4. close the database
    db_.close();
    return true;
}
