
#include "Objeto.h"

Objeto::Objeto() : color{}, posX{}, posY{}, calificacion{} { ancho = 1; }

Objeto::Objeto(const TipoString& nombre, TipoCaracter color,
               TipoEntero posX, TipoEntero posY, TipoEntero calificacion):
        nombre{nombre}, color{color},
        posX{ posX }, posY{ posY }, calificacion{} { ancho = 1; }

Objeto::Objeto(const TipoString& nombre, TipoCaracter color, TipoEntero posX, TipoEntero posY, TipoEntero calificacion, TipoEntero ancho)
{
    this->setNombre(nombre);
    this->color = color;
    this->setPosX(posX);
    this->setPosY(posY);
    this->setCalificacion(calificacion);
    this->setAncho(ancho);
}

Objeto::~Objeto() {}

void Objeto::setNombre(const TipoString& nombre) { this->nombre = nombre; }
void Objeto::moverse(TipoEntero x, TipoEntero y) {
    posX = x;
    posY = y;
} //--  por implementar

TipoString   Objeto::getNombre() { return nombre; }
TipoEntero   Objeto::getPosX()   { return posX; }
TipoEntero   Objeto::getPosY()   { return posY; }
TipoEntero   Objeto::getCalificacion(){ return calificacion; }
TipoCaracter Objeto::getColor()  { return color; }

TipoString Objeto::mostrarPosicion() {
    return  getNombre() + " :: X = " + to_string(posX) + " :: Y = " + to_string(posY)+ " :: calificacion = " + to_string(calificacion);
}
