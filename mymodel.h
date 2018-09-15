#ifndef MYMODEL_H
#define MYMODEL_H

#include <QObject>
#include <QAbstractItemModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QList>

class ItemData
{
public:
    inline explicit ItemData(ItemData *parent, quint32 id, const QString &name = QString(), const QString &description = QString()) :
        m_parent(parent),
        m_id(id),
        m_name(name),
        m_description(description),
        m_fetched(false)
    {}

    inline ~ItemData() { qDeleteAll(m_childrens); }

    inline ItemData *parent() const { return m_parent; }
    inline const QList<ItemData *> &childrens() const { return m_childrens; }
    inline quint32 id() const { return m_id; }
    inline const QString &name() const { return m_name; }
    inline const QString &description() const { return m_description; }
    inline bool fetched() const { return m_fetched; }

    inline int row() { if(m_parent) return m_parent->childrens().indexOf(this); return 0; }
    inline ItemData *child(int row) const { return m_childrens.at(row); }
    inline int childCount() const { return m_childrens.count(); }

    void fetch(QSqlQuery &query);

private:
    ItemData *m_parent;
    QList<ItemData *> m_childrens;
    quint32 m_id;
    QString m_name;
    QString m_description;
    bool m_fetched;
};

class MyModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit MyModel(QSqlDatabase &db, QObject *parent = 0);

    QModelIndex index(int row, int column, const QModelIndex &parent) const Q_DECL_OVERRIDE;
    QModelIndex parent(const QModelIndex &child) const Q_DECL_OVERRIDE;
    int rowCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent) const Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const Q_DECL_OVERRIDE;
    bool hasChildren(const QModelIndex &parent) const Q_DECL_OVERRIDE;
    void fetchMore(const QModelIndex &parent) Q_DECL_OVERRIDE;
    bool canFetchMore(const QModelIndex &parent) const Q_DECL_OVERRIDE;

private:
    void loadChildrens(ItemData *itemData);

    QSqlDatabase &m_db;
    QSqlQuery m_query;
    ItemData *m_root;
};

#endif // MYMODEL_H
