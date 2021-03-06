#ifndef MAPA_H
#define MAPA_H

const int CONST_P_PEATONES  = 5;
const int CONST_P_OBSTACULOS = 30;
const int CAP_MAX_COCHE = 6;

#include <vector>
#include <sstream>
#include <fstream>
#include "celda.h"
#include <ctime>
#include <cmath>
#include "f_heuristicas.h"

using namespace std;

/**
 * Mapa: Matriz de celdas, implementada en la línea de comandos. Desde ella se
 *   gestionan las celdas y sus propiedades.
 * Sirve de entorno de simulación del algoritmo A* de busqueda de caminos minimos
 *   que implementamos
 */
class Mapa{

private:
    /**
     * rejilla_: Matriz de celdas.
     * porcentajeObstaculos_: Porcentaje que define la cantidad de celdas que
     *   contendrán obstáculos.
     * nPeatones_: Contiene el número de peatones desplegados por el mapa.
     * x_, y_; Tamaño del mapa (anchura y altura).
     * f_heuristica: Puntero clase padre, realiza el calculo h.
     *      True = manhattan      False = euclidea
     */
    vector<vector<Celda> > rejilla_;
    int porcentajeObstaculos_;
    int nPeatones_;
    int x_, y_;
    f_heuristica* heuristica_;

    /**
     * addObstaculos: Añade obstáculos en las celdas del mapa.
     * mod: Booleano que permite alternar la entrada de obstáculos en el mapa:
     *  mod true: Se añaden los obstáculos desde un archivo que los contiene.
     *  mod false: Los obstáculos se generan aleatoriamente.
     */
    void addObstaculos(bool mod);
    void addPeatones();

    void resetCamino();
    void setVecinosAt(int i, int j);
    void setVecinos();
    bool is_in_set(const Celda&, const std::vector<Celda>&);
    void reconstruir_camino(vector<Celda> &v, Celda actual, Celda I);
    vector<Celda> Astar(unsigned int xInicio, unsigned int yInicio, unsigned int xFinal, unsigned int yFinal);
public:
    static int contador;

    Mapa(int x, int y, bool h, int pObst = CONST_P_OBSTACULOS, int nPeatones_ = CONST_P_PEATONES);
    ~Mapa();

    void caminoMinimo(unsigned int xInicio, unsigned int yInicio, unsigned int xFinal, unsigned int yFinal, int& pasajeros);
    void visualizar();

    void cambiarHeuristica(bool);

};

#endif // MAPA_H
