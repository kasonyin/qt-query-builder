#include <QCoreApplication>
#include <QStringList>
#include <QDebug>
#include "model/querybuilder.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QueryBuilder qb;
    QString sql;

    sql = qb.create("students")
            .increments("id").primary()
            .integer("age").notNull()
            .real("score").defaultIs(0.0)
            .string("name").defaultIs("NULL")
            .build();

    qDebug() << sql;
    // CREATE TABLE students (
    // id INTEGER PRIMARY KEY AUTOINCREMENT,
    // age INTEGER  NOT NULL,
    // score REAL  DEFAULT 0,
    // name TEXT  DEFAULT 'NULL')

    sql = qb.select("*")
            .from("students")
            .build();

    qDebug() << sql;
    // SELECT * FROM students

    sql = qb.select("id, age, name")
            .from("students")
            .where("age", ">", 18)
            .orderBy("name DESC")
            .limit(10).offset(5)
            .build();

    qDebug() << sql;
    // SELECT id, age, name FROM students WHERE age>18 ORDER BY name DESC LIMIT 10 OFFSET 5

    sql = qb.select("id, age, name")
            .from("students")
            .where("name", "NOT NULL")
            .where("AND age>18")
            .groupBy("age")
            .having("count(name) < 2")
            .orderBy("age DESC")
            .limit(10)
            .offset(5)
            .build();

    qDebug() << sql;
    // SELECT id, age, name FROM students WHERE name not null AND age>18 GROUP BY age HAVING count(name) < 2
    // ORDER BY age DESC LIMIT 10 OFFSET 5

    sql = qb.insert({1, 25, 60.5, "Pascal"})
            .into("students")
            .build();

    qDebug() << sql;
    // INSERT INTO students VALUES(1,25,60.5,'Pascal')

    sql = qb.insert("id", 2)
            ("age", 25)
            ("name", "kason")
            .into("students")
            .build();

    qDebug() << sql;
    // INSERT INTO students (id,age,name) VALUES(2,25,'kason')

    sql = qb.update("students")
            .set("name", "kasonYin")
            ("age", 24)
            .where("name", "=", "kason")
            .build();
    qDebug() << sql;
    // UPDATE students SET name='kasonYin', SET age=24 WHERE name='kason'

    sql = qb.delete_()
            .from("students")
            .where("name", "=", "kasonYin")
            .build();
    qDebug() << sql;
    // DELETE FROM students WHERE name='kasonYin'

    return 0;
}
