#include "personmodel.h"

#include "personmodel.h"

PersonModel::PersonModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int PersonModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return m_data.size();
}

QVariant PersonModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() < 0 || index.row() >= m_data.size())
        return {};

    const auto &person = m_data[index.row()];
    if (role == NameRole)
        return person.name;

    return {};
}

QHash<int, QByteArray> PersonModel::roleNames() const
{
    return {
        { NameRole, "name" }
    };
}

void PersonModel::addPerson(const QString &name)
{
    beginInsertRows(QModelIndex(), m_data.size(), m_data.size());
    m_data.append({ name });
    endInsertRows();
}

void PersonModel::removePerson(int index)
{
    if (index < 0 || index >= m_data.size())
        return;

    beginRemoveRows(QModelIndex(), index, index);
    m_data.removeAt(index);
    endRemoveRows();
}

void PersonModel::updatePerson(int index, const QString &newName)
{
    if (index < 0 || index >= m_data.size())
        return;

    m_data[index].name = newName;
    emit dataChanged(this->index(index), this->index(index));
}
