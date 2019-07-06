//
// Created by HP on 4/07/2019.
//

#ifndef CADENA_HOTELES_MENU_H
#define CADENA_HOTELES_MENU_H



#include "Tierra.h"
#include "Tipos.h"

template <typename T>
T input(string label) {
    T value;
    cout << label;
    cin >> value;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    return value;
}

/*
//--- Esta seria la funcion para leer un string,
//--- esta funcion si se quiere generalizar para colocar un label
//--- y leer cualquier tipo de dato se tendria que convertir al template anterior

string&& input(string label) {
  string value;
  cout << label;
  cin >> value;
  return move(value);
}
 */


class Menu {
    TipoEntero opcion;
    Tierra tierra;
    void imprimirMenu();
    void seleccionarOpcion();

    //Agregar restaurantes, museos y hoteles
    void agregarRestaurante(TipoEntero ancho);
    void agregarHotel(TipoEntero ancho);
    void agregarMuseo(TipoEntero ancho);

    bool validarLugar(TipoEntero x, TipoEntero y);

    //remover
    void removerRestaurante();
    void dibujarMapa();

    //Buscar restaurantes, museos y hoteles
    void buscarRestaurante();
    void buscarHotel();

    //Buscar Clificacion
    void buscarCalificacionRestaurante();
    void buscarCalificacionHotel();

    //Mover restaurantes, museos y hoteles
    void moverRestaurante();
    void moverHotel();

    void numeroDispCeldas();
    void numeroDispCeldasenY();
public:
    Menu(): opcion{} {}
    void ejecutar();
};

#endif //CADENA_HOTELES_MENU_H
