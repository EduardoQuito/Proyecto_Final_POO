//
// Created by utec on 21/06/19.
//

#ifndef GAME_OBJETO_H
#define GAME_OBJETO_H

#include <iostream>
#include <string>

using namespace std;

class Objeto{;
private:
    string nombre;
    char  color;
    int    posX;
    int    posY;
public:
    Objeto();
    Objeto(const string& nombre, char color,
           int posX, int posY);
    virtual ~Objeto();
    void setNombre(const string& nombre);
    string     getNombre();
    int getPosX();
    int getPosY();
    char getColor();
    void moverse(int x, int y);
    string mostrarPosicion();
};


#endif //GAME_OBJETO_H
