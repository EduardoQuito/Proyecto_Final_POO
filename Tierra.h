//
// Created by utec on 21/06/19.
//

#ifndef GAME_TIERRA_H
#define GAME_TIERRA_H

#include <iostream>
#include <vector>
#include "Objeto.h"

using namespace std;

const int ALTURA = 21;
const int ANCHO  = 21;
const char COLOR ='.';

class Tierra {
private:
    vector<vector<char>> plano;
    vector<Objeto*> objetos;
public:
    Tierra();
    Tierra(int altura, int ancho);
    virtual ~Tierra();
    void adicionarObjeto(Objeto* objeto);
    Objeto* removerObjeto(string& nombre);
    void imprimirObjetos();
    int getAltura();
    int getAncho();
    int getCantidadObjectos();
    void dibujarTierra();
    void actualizarTierra();
};


#endif //GAME_TIERRA_H
