#include <QCoreApplication>
#include <QStringList>
#include <QDebug>
#include "model/querybuilder.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QueryBuilder qb;
    QString sql = qb.select("id, age, name").from("visitors").where("age", ">", 35)
                .groupBy("age").having("count(name) < 2").orderBy("age DESC")
                .limit(10).offset(5).build();
    qDebug() << sql;

    sql = qb.insert({1,2,3,4,5}).into("visitors").build();
    qDebug() << sql;

    sql = qb.insert("id", 1)
                ("age", 25)
                ("name", "kason")
                .into("visitors")
                .build();
    qDebug() << sql;

    sql = qb.update("visitors")
                .set("name", "kasonYin")
                ("age", 24)
                .where("name", "=", "kason")
                .build();
    qDebug() << sql;

    return 0;
}
