#include <QApplication>
#include "Gra.h"

Gra* gra;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    gra = new Gra();
    gra -> show();
    gra -> poczatkoweMenu();


    return a.exec();
}
