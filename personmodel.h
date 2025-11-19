#ifndef PERSONMODEL_H
#define PERSONMODEL_H

#include <QObject>

#pragma once
#include <QAbstractListModel>

class PersonModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles {
        NameRole = Qt::UserRole + 1
    };

    explicit PersonModel(QObject *parent = nullptr);

    // Basic model functions
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;

    // Role names
    QHash<int, QByteArray> roleNames() const override;

    // Functions callable from QML
    Q_INVOKABLE void addPerson(const QString &name);
    Q_INVOKABLE void removePerson(int index);
    Q_INVOKABLE void updatePerson(int index, const QString &newName);

private:
    struct Person {
        QString name;
    };

    QList<Person> m_data;
};


#endif // PERSONMODEL_H
