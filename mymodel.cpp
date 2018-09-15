#include "mymodel.h"

#include <QDebug>
#include <QSqlError>

void ItemData::fetch(QSqlQuery &query)
{
    if(m_fetched)
    {
        qWarning() << m_id << "already fetched";
        return;
    }

    qDebug() << "loadChildrens" << m_id;

    query.bindValue(":ParentID", m_id);
    if(!query.exec())
    {
        qWarning() << query.lastError().text();
        qFatal("could not execute query");
        return;
    }

    while(query.next())
        m_childrens.append(new ItemData(this, query.value("ID").toUInt(), query.value("Name").toString(), query.value("Description").toString()));

    m_fetched = true;
}

MyModel::MyModel(QSqlDatabase &db, QObject *parent) :
    QAbstractItemModel(parent),
    m_db(db),
    m_query(m_db)
{
    if(!m_query.prepare("SELECT `ID`, `Name`, `Description` FROM `Tree` WHERE (:ParentID = 0 AND `ParentID` IS NULL) OR (`ParentID` = :ParentID);"))
    {
        qWarning() << m_query.lastError().text();
        qFatal("could not prepare query");
        return;
    }

    m_root = new ItemData(Q_NULLPTR, 0);
    //m_root->fetch(m_query);
}

QModelIndex MyModel::index(int row, int column, const QModelIndex &parent) const
{
    if(!hasIndex(row, column, parent))
        return QModelIndex();

    auto parentData = parent.isValid() ? static_cast<ItemData*>(parent.internalPointer()) : m_root;

    auto childData = parentData->child(row);
    if (childData)
        return createIndex(row, column, childData);
    else
        return QModelIndex();
}

QModelIndex MyModel::parent(const QModelIndex &child) const
{
    if(!child.isValid())
        return QModelIndex();

    auto childData = static_cast<ItemData*>(child.internalPointer());
    auto parentData = childData->parent();

    if(parentData == m_root)
        return QModelIndex();

    return createIndex(parentData->row(), 0, parentData);
}

int MyModel::rowCount(const QModelIndex &parent) const
{
    if(parent.column() > 0)
        return 0;

    auto parentData = parent.isValid() ? static_cast<ItemData*>(parent.internalPointer()) : m_root;

    return parentData->childCount();
}

int MyModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 2;
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    switch(role)
    {
    case Qt::DisplayRole:
    case Qt::EditRole:
        auto itemData = static_cast<ItemData*>(index.internalPointer());
        switch(index.column())
        {
        case 0: return itemData->name();
        case 1: return itemData->description();
        }
    }

    return QVariant();
}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    switch(orientation)
    {
    case Qt::Horizontal:
        switch(section)
        {
        case 0:
            switch(role)
            {
            case Qt::DisplayRole:
            case Qt::EditRole:
                return tr("Name");
            }
        case 1:
            switch(role)
            {
            case Qt::DisplayRole:
            case Qt::EditRole:
                return tr("Beschreibung");
            }
        }
        break;
    case Qt::Vertical:
        break;
    }

    return QVariant();
}

bool MyModel::hasChildren(const QModelIndex &parent) const
{
    if(parent.column() > 0)
        return false;

    auto parentData = parent.isValid() ? static_cast<ItemData*>(parent.internalPointer()) : m_root;

    if(!parentData->fetched())
        return true;

    return parentData->childCount() > 0;
}

void MyModel::fetchMore(const QModelIndex &parent)
{
    if(parent.column() > 0)
        return;

    auto parentData = parent.isValid() ? static_cast<ItemData*>(parent.internalPointer()) : m_root;

    parentData->fetch(m_query);
}

bool MyModel::canFetchMore(const QModelIndex &parent) const
{
    if(parent.column() > 0)
        return false;

    auto parentData = parent.isValid() ? static_cast<ItemData*>(parent.internalPointer()) : m_root;

    return !parentData->fetched();
}
