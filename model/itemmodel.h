#ifndef ITEMMODEL_H
#define ITEMMODEL_H

#include <QAbstractItemModel>

#include <QStringList>

class ItemModel : public QAbstractItemModel {
    Q_OBJECT

public:
    explicit ItemModel(QObject *parent = nullptr);
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void addItem(const QString& str);
    void clearItem();

private:
    QStringList m_item;
};

#endif // ITEMMODEL_H
