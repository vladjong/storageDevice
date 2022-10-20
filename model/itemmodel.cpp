#include "itemmodel.h"

ItemModel::ItemModel(QObject *parent)
    : QAbstractItemModel(parent) {}

QVariant ItemModel::headerData(int, Qt::Orientation, int ) const {
    return QVariant();
}

QModelIndex ItemModel::index(int row, int column, const QModelIndex &) const {
    return createIndex(row, column, (void*)&m_item[row]);
}

QModelIndex ItemModel::parent(const QModelIndex &) const {
    return QModelIndex();
}

int ItemModel::rowCount(const QModelIndex &) const {
    return m_item.size();
}

int ItemModel::columnCount(const QModelIndex &) const {
    return 1;
}

QVariant ItemModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        return m_item.at(index.row());
    }
    return QVariant();
}

void ItemModel::addItem(const QString &str) {
    m_item.append(str);
    emit layoutChanged();
}

void ItemModel::clearItem() {
    m_item.clear();
}
