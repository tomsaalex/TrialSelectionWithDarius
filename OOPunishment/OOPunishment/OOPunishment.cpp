#include "OOPunishment.h"

void OOPunishment::InitGUI()
{
	mainLayout = new QVBoxLayout();
	tabelVan = new QTableView();
	tabelModel = new CustomTabelModel(repo.getAll());
	tabelVan->setModel(tabelModel);

	edit1 = new QLineEdit();
	edit2 = new QLineEdit();

	edit1->setEnabled(false);
	edit2->setEnabled(false);

	mainLayout->addWidget(tabelVan);
	mainLayout->addWidget(edit1);
	mainLayout->addWidget(edit2);

	this->setLayout(mainLayout);
}

void OOPunishment::ConnectSignalSlots()
{
	QObject::connect(tabelVan->selectionModel(), &QItemSelectionModel::selectionChanged, [&]() {
		if (tabelVan->selectionModel()->selectedIndexes().size() == 0)
		{
			return;
		}

		auto item = tabelVan->selectionModel()->selectedIndexes().at(0);
		auto P1 = item.data(Qt::UserRole).toString();
		QString P2;
		auto elements = repo.getAll();
		
		for (auto e : elements)
		{
			if (e.getP1() == P1.toStdString())
			{
				P2 = QString::fromStdString(e.getP2());
			}
		}

		edit1->setText(P1);
		edit2->setText(P2);
	});
}
/*
void OOPunishment::ReloadTable(vector<CoolObject> vect)
{
	lista->setRowCount(vect.size());
	lista->setColumnCount(2);


	for (int i = 0; i < vect.size(); i++)
	{
		QTableWidgetItem* item1 = new QTableWidgetItem(QString::fromStdString(vect[i].getP1()));
		QTableWidgetItem* item2 = new QTableWidgetItem(QString::fromStdString(vect[i].getP2()));

		item1->setData(Qt::UserRole, QString::fromStdString(vect[i].getP1()));
		item2->setData(Qt::UserRole, QString::fromStdString(vect[i].getP1()));

		lista->setItem(i, 0, item1);
		lista->setItem(i, 1, item2);
	}
}
*/
/*void OOPunishment::ReloadList(vector<CoolObject> vect)
{
	for (int i = 0; i < vect.size(); i++)
	{
		QListWidgetItem* item1 = new QListWidgetItem(QString::fromStdString(vect[i].getP2()));

		item1->setData(Qt::UserRole, QString::fromStdString(vect[i].getP1()));

		listVan->insertItem(i, item1);
	}
}*/