//
// Created by HP on 4/07/2019.
//

#ifndef CADENA_HOTELES_TIERRA_H
#define CADENA_HOTELES_TIERRA_H


#include <iostream>
#include <vector>
#include "Tipos.h"
#include "Objeto.h"

using namespace std;

// Valores constantes
const TipoEntero ALTURA = 21;
const TipoEntero ANCHO  = 21;
const TipoCaracter COLOR ='.';

class Tierra {
private:
    vector<vector<char>> plano;
    vector<Objeto*> restaurantes;
    vector<Objeto*> hoteles;
    vector<Objeto*> Museo;
public:
    Tierra();
    Tierra(TipoEntero altura, TipoEntero ancho);
    virtual ~Tierra();
    //buscar
    Objeto buscarObjetoRestaurante(string nombre);
    Objeto buscarObjetoHotel(string nombre);

    //buscar por calificacion
    Objeto buscarCalificacionRestaurante(TipoEntero calificacion);
    Objeto buscarCalificacionHotel(TipoEntero calificacion);

    //Mover
    void moverRestaurante(string nombre, TipoEntero x, TipoEntero y);
    void moverHotel(string nombre, TipoEntero x, TipoEntero y);

    //Validar lugares
    //----Restaurante
    bool validarLugarRestaurante(TipoEntero x, TipoEntero y);
    bool validarNombreRestaurante(string nombre);
    bool validarRestaurante(TipoEntero x, TipoEntero y, TipoEntero ancho);
    //----Hotel
    bool validarLugarHotel(TipoEntero x, TipoEntero y);
    bool validarNombreHotel(string nombre);
    bool validarHotel(TipoEntero x, TipoEntero y, TipoEntero ancho);

    //Adicionar
    void adicionarObjetoBoss(Objeto* objeto);
    void adicionarRestaurante(Objeto* restaurante);
    void adicionarHotel(Objeto* hotel);

    //remover
    bool removerRestaurante(string& nombre);

    //imprimir
    void imprimirRestaurante();
    void imprimirHotel();
    void imprimirMuseo();
    TipoEntero getAltura();
    TipoEntero getAncho();
    TipoEntero getCantidadObjectos();
    TipoEntero contarPlano();
    TipoEntero contarColumna();
    void dibujarTierra();
    void actualizarTierra();
    void crearPiedras(int cantidad);
};


#endif //CADENA_HOTELES_TIERRA_H
