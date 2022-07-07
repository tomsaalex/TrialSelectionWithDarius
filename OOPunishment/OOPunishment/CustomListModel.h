#pragma once
#include <vector>
#include <qabstractitemmodel.h>
#include "CoolObject.h"

using namespace std;

class CustomTabelModel : public QAbstractListModel {
private:
	vector<CoolObject> storage;
public:
	CustomTabelModel(vector<CoolObject>) : QAbstractListModel(), storage{ storage }{

	};

	int rowCount(const QModelIndex& parent = QModelIndex()) const override;
	int columnCount(const QModelIndex& parent = QModelIndex()) const override;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
	void setElements(vector<CoolObject>);
};


