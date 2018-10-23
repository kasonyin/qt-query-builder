# qt-query-builder

qt-query-builder 是一个基于 qt 的简单的 sql 查询生成器

## Usage:
### Select
``` c++
    QueryBuilder qb;
    QString sql = qb.select("id, age, name")
                            .from("students")
                            .where("age", ">", 18)
                            .groupBy("age")
                            .having("count(name) < 2")
                            .orderBy("age DESC")
                            .limit(10).offset(5)
                            .build();
    qDebug() << sql;
    // SELECT id, age, name FROM students WHERE age>'18' GROUP BY age HAVING count(name)<2 ORDER BY age DESC limit 10 offset 5
```

### Insert
``` c++
    QString sql = qb.insert({1, 25, "Alen"})
                            .into("students")
                            .build();
    qDebug() << sql;
    // INSERT INTO students VALUES(1, 25, 'Alen')

    QString sql = qb.insert("id", 2)
                           ("age", 22)
                           ("name", "Pascal")
                           .into("students")
                           .build();
    qDebug() << sql;
    // INSERT INTO students(id, age, name) VALUES(2, 22, 'Pascal')
```

### Update
``` c++
    QString sql = qb.update("students")
                            .set("name", "kasonYin")
                            ("age", 24)
                            .where("name", "=", "kason")
                            .build();
    qDebug() << sql;
    // UPDATE 
```

## TODO
- [ ] Delete