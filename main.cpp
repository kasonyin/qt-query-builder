#include <QCoreApplication>
#include <QStringList>
#include <QDebug>
#include "model/querybuilder.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QueryBuilder qb;
    qDebug() << qb.select("id, age, name").from("visitors").where("age", ">", 35)
                .groupBy("age").having("count(name) < 2").orderBy("age DESC")
                .limit(10).offset(5).build();

    qDebug() << qb.insert({1,2,3,4,5}).into("visitors").build();
    qDebug() << qb.insert("id", 1)
                ("age", 25)
                ("name", "kason")
                .into("visitors")
                .build();

    qDebug() << qb.update("visitors")
                .set("name", "kasonYin")
                ("age", 24)
                .where("name", "=", "kason")
                .build();

    return 0;
}
