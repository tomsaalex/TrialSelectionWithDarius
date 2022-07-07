#include "CustomListModel.h"

int CustomTabelModel::rowCount(const QModelIndex& parent) const
{
    return storage.size();
}

int CustomTabelModel::columnCount(const QModelIndex& parent) const
{
    return 2;
}


QVariant CustomTabelModel::data(const QModelIndex& index, int role) const
{
    int row = index.row();
    int col = index.column();

    if (role == Qt::DisplayRole)
    {
       if(col == 0)
            return QString::fromStdString(storage[row].getP1());

       if (col == 1)
           return QString::fromStdString(storage[row].getP2());
    }
    else if (role == Qt::UserRole)
    {
            return QString::fromStdString(storage[row].getP1());
    }
    
    return QVariant();
}

void CustomTabelModel::setElements(vector<CoolObject> vect)
{
    storage = vect;

    auto topLeft = createIndex(0, 0);
    auto bottomRight = createIndex(rowCount(), columnCount());

    QModelIndex index;
    string obj;

    emit layoutChanged();
    emit dataChanged(topLeft, bottomRight);
}
