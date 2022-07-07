#pragma once

#include <QtWidgets/QWidget>
#include <qtablewidget.h>
#include <QListWidget>
#include <QVBoxLayout>
#include <vector>
#include <QLineEdit>

#include "ui_OOPunishment.h"
#include "CoolObject.h"
#include "Repository.h"
#include "CustomListModel.h"
using namespace std;

/*
class OOPunishment : public QWidget
{
    Q_OBJECT

        
        
public:
    OOPunishment(QWidget *parent = Q_NULLPTR);

private:
    Ui::OOPunishmentClass ui;
};
*/

class OOPunishment :public QWidget
{
private:
	Repository& repo;

	void InitGUI();
	void ConnectSignalSlots();
	void ReloadList(vector<CoolObject>);

	QVBoxLayout* mainLayout;
	QTableView* tabelVan;
	CustomTabelModel* tabelModel;


	QLineEdit* edit1;
	QLineEdit* edit2;

public:
	OOPunishment(Repository& repo):repo{repo}
	{
		InitGUI();
		ConnectSignalSlots();
		//ReloadList(repo.getAll());
		tabelModel->setElements(repo.getAll());
	}
};

