#ifndef JSHONMANAGER_H
#define JSHONMANAGER_H

#include <QObject>

#pragma once
#include <QString>
#include <QVector>

struct Person {
    QString name;
    int age;
};

class JsonManager
{
public:
    JsonManager(const QString &filePath);

    bool load();
    bool save();

    QVector<Person> persons;

private:
    QString m_filePath;
};


#endif // JSHONMANAGER_H
