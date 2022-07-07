#include "OOPunishment.h"
#include "Repository.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repository repo{"InputFile.txt"};
    OOPunishment w{repo};
    w.show();
    return a.exec();
}
