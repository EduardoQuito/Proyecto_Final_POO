//
// Created by HP on 4/07/2019.
//

#ifndef CADENA_HOTELES_OBJETO_H
#define CADENA_HOTELES_OBJETO_H



#include <iostream>
#include "Tipos.h"

using namespace std;

class Objeto {
private:
    string        nombre;
    TipoCaracter  color;
    TipoEntero    posX;
    TipoEntero    posY;
    TipoEntero    calificacion;
    TipoEntero    ancho;  // cuadrado

public:
    Objeto();
    Objeto(const TipoString& nombre, TipoCaracter color,
           TipoEntero posX, TipoEntero posY, TipoEntero calificacion);
    Objeto(const TipoString& nombre, TipoCaracter color,
           TipoEntero posX, TipoEntero posY,TipoEntero calificacion, TipoEntero ancho);
    virtual ~Objeto();
    void setNombre(const TipoString& nombre);
    string     getNombre();
    TipoEntero getPosX();
    TipoEntero getPosY();
    TipoEntero getCalificacion();

    void setPosX(TipoEntero x) { posX = x; };
    void setPosY(TipoEntero y) { posY = y; }
    void setCalificacion(TipoEntero cali) { calificacion = cali; }

    void setAncho(TipoEntero a) { ancho = a; };
    TipoEntero getAncho() { return ancho; };
    char getColor();
    void moverse(TipoEntero x, TipoEntero y);
    string mostrarPosicion();
};

#endif //CADENA_HOTELES_OBJETO_H
