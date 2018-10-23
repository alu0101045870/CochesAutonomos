#include "../headers/mapa.h"
#include "../headers/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget *w = new MainWindow(new MapaGrafico());

    w -> show();

    return a.exec();
}