#include "jshonmanager.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>

JsonManager::JsonManager(const QString &filePath)
    : m_filePath(filePath)
{
}

bool JsonManager::load()
{
    QFile f(m_filePath);
    if (!f.open(QIODevice::ReadOnly))
        return false;

    QJsonDocument doc = QJsonDocument::fromJson(f.readAll());
    f.close();

    if (!doc.isArray())
        return false;

    persons.clear();

    for (auto v : doc.array()) {
        QJsonObject o = v.toObject();
        Person p;
        p.name = o["name"].toString();
        p.age  = o["age"].toInt();
        persons.append(p);
    }

    return true;
}

bool JsonManager::save()
{
    QJsonArray arr;

    for (const Person &p : persons) {
        QJsonObject o;
        o["name"] = p.name;
        o["age"] = p.age;
        arr.append(o);
    }

    QJsonDocument doc(arr);

    QFile f(m_filePath);
    if (!f.open(QIODevice::WriteOnly))
        return false;

    f.write(doc.toJson());
    f.close();

    return true;
}

