#include "../headers/mapa.h"
#include "../headers/mainwindow.h"
#include <QApplication>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int m,n,option;
    cout << "--Dimensiones mapa--" << endl;
    cout << "Introduce largo: "; cin >> m; cout << endl;
    cout << "Introduce ancho:"; cin >> n; cout << endl;
    cout << "--Modo de Visualización--" << endl;
    cout << "1. Modo Consola" << endl;
    cout << "2. Modo Gráfico" << endl;
    cin >> option;


    if(option == 1){
        int obs, pea;
        cout << "¿Cuánto porcentaje de obstáculos quiere?" << endl;
        cin >> obs; cout << endl;
        cout << "¿Cuánto porcentaje de peatones quiere?" << endl;
        cin >> pea;
        Mapa mapa(m,n,obs,pea);
        vector<Celda> result = mapa.Astar(0,0, 4,4);
        mapa.visualizar();

        //while(true){sleep(200);}
    }
    else if(option == 2){
        QApplication a(argc, argv);

        MainWindow *w = new MainWindow(new QWidget);

        w -> show();

        return a.exec();
    }
}
