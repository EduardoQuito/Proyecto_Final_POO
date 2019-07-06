
#include "Menu.h"
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

enum class Opciones { AgregarRestaurante=1,AgregarHotel,RemoverRestaurante, Mostrar, BuscarRestaurante,BuscarHotel,
    MoverRestaurante, MoverHotel, CeldasOcupadas, CeldasOcupadasColumna, CalificacionRestaurante, CalificacionHotel};

void limpiar() {
    cout << "\033[2J\033[0;0H";
}

void esperar() {
    char w;
    do {
        w = input<TipoCaracter>("\nPresione C y Enter para continuar...");
    }while (toupper(w) != 'C');
}

void Menu::imprimirMenu() {
    dibujarMapa();
    cout << "    MENU \n[1] Agregar restaurante (#) \n[2] Agregar hotel ($) \n[3] Remover restaurantes "
            "\n[4] Dibujar mapa \n[5] Buscar restaurante\n[6] Buscar hotel \n[7] Mover restaurante \n[8] Mover hotel"
            " \n[9] Celdas ocupadas\n[10] Celdas ocupadas en Columna \n[11] Buscar Restaurante por calificaion"
            "\n[12] Buscar Hotel por calificaion \n\n[13] Salir del programa ";
}
//-----------------------------------------------------------------------
//----------AGREGRAR RESTAURANTES, HOTELES Y MUSEOS----------------------
//-----------------------------------------------------------------------

void Menu::agregarRestaurante(TipoEntero ancho){
    TipoString nombre;
    TipoCaracter color;
    TipoEntero x;
    TipoEntero y;
    TipoEntero cali;
    bool invalido = true;

    while (invalido) {
        limpiar();
        tierra.dibujarTierra();
        tierra.imprimirRestaurante();
        color = '#';
        nombre = input<TipoString>("Ingrese Nombre : ");
        x = input<TipoEntero>("Ingrese posicion X : ");
        y = input<TipoEntero>("Ingrese posicion Y : ");
        cali = input<TipoEntero>("Ingrese calificacion : ");

        if (x < 0 || x >= tierra.getAncho() - ancho) {
            cout << "Posicion X Incorrecta, los limites son: 0, "
                 << tierra.getAncho() - ancho << "\n";
            esperar();
            continue;
        }

        if (y < 0 || y >= tierra.getAncho() - ancho) {
            cout << "(¡!) Posicion Y Incorrecta, los limites son: 0, "
                 << tierra.getAltura() - ancho << "\n";
            esperar();
            continue;
        }

        // Validar que no choque con un hotel
        if (tierra.validarHotel(x, y,ancho)) {
            cout << "Posicion ocuoada por un hotel." << endl;
            esperar();
            continue;
        }

        // Dos restaurantes no pueden tener el mismo nombre
        if (tierra.validarNombreRestaurante( nombre )) {
            cout << "Nombre ya existente, ingrese otro:" << endl;
            esperar();
            continue;
        }
        //No puedo agregar dos restaurantes en un mismo lugar
        if (tierra.validarLugarRestaurante(x, y)) {
            cout << "Lugar Ocupado:" << endl;
            esperar();
            continue;
        }
        invalido = false;
    }
    tierra.adicionarRestaurante(new Objeto(nombre, color, x, y,cali, ancho));
}
void Menu::agregarHotel(TipoEntero ancho){
    TipoString nombre;
    TipoCaracter color;
    TipoEntero x;
    TipoEntero y;
    TipoEntero cali;
    bool invalido = true;

    while (invalido) {
        limpiar();
        tierra.dibujarTierra();
        tierra.imprimirHotel();
        color = '$';
        nombre = input<TipoString>("Ingrese Nombre : ");
        x = input<TipoEntero>("Ingrese posicion X : ");
        y = input<TipoEntero>("Ingrese posicion Y : ");
        cali = input<TipoEntero>("Ingrese alificacion: ");

        if (x < 0 || x >= tierra.getAncho() - ancho) {
            cout << "Posicion X Incorrecta, los limites son: 0, "
                 << tierra.getAncho() - ancho << "\n";
            esperar();
            continue;
        }

        if (y < 0 || y >= tierra.getAncho() - ancho) {
            cout << "(¡!) Posicion Y Incorrecta, los limites son: 0, "
                 << tierra.getAltura() - ancho << "\n";
            esperar();
            continue;
        }

        // Validar que no choque con un restaurante
        if (tierra.validarHotel(x, y,ancho)) {
            cout << "Posicion ocupado por restaurante" << endl;
            esperar();
            continue;
        }

        // Dos hoteles no pueden tener el mismo nombre
        if (tierra.validarNombreRestaurante( nombre )) {
            cout << "Hotel nombre ya existe, ingrese otro:" << endl;
            esperar();
            continue;
        }
        //No puedo hoteles dos restaurantes en un mismo lugar
        if (tierra.validarLugarRestaurante(x, y)) {
            cout << "Lugar Ocupado:" << endl;
            esperar();
            continue;
        }
        invalido = false;
    }
    tierra.adicionarHotel(new Objeto(nombre, color, x, y,cali, ancho));
}

//-----------------------------------------------------------------------
//----------AGREGRAR RESTAURANTES, HOTELES Y MUSEOS----------------------
//------------------------------------------------------------------------------
void Menu::removerRestaurante(){
    auto nombre = input<TipoString>("Nombre del Robot: ");

    if( !tierra.removerRestaurante(nombre) )
    {
        cout << " NO existe...\n";
    }
    else
    {
        cout << "Restaurante " << nombre << " ha sido removido\n";
    }
    esperar();
}

void Menu::dibujarMapa() {
    tierra.actualizarTierra();
    tierra.dibujarTierra();
    tierra.imprimirRestaurante();
    tierra.imprimirHotel();
}


//-----------------------------------------------------------------------
//----------BUSCAR RESTAURANTES, HOTELES Y MUSEOS----------------------
//-----------------------------------------------------------------------

void Menu::buscarRestaurante(){
    string nombre;
    cout << "Nombre del Restaurante: ";
    cin >> nombre;
    Objeto oBusco = tierra.buscarObjetoRestaurante(nombre);
    if (oBusco.getNombre() == nombre) {
        tierra.dibujarTierra();
        cout << endl << oBusco.mostrarPosicion();
    }
    else {
        cout << endl << "El restaurante no existe";
    }
    esperar();
}
void Menu::buscarHotel(){
    string nombre;
    cout << "Nombre del hotel: ";
    cin >> nombre;
    Objeto oBusco = tierra.buscarObjetoHotel(nombre);
    if (oBusco.getNombre() == nombre) {
        tierra.dibujarTierra();
        cout << endl << oBusco.mostrarPosicion();
    }
    else {
        cout << endl << "El hotel no existe";
    }
    esperar();
}

//----------BUSCAR POR CALIFICACIONES----------------------
void Menu::buscarCalificacionRestaurante(){
    TipoEntero calificacion;
    cout << "Calificacion: ";
    cin >> calificacion;
    Objeto oBusco = tierra.buscarCalificacionRestaurante(calificacion);
    int x=0;
    tierra.dibujarTierra();
    while(x<3)
    {if (oBusco.getCalificacion() == calificacion) {
            cout << endl << oBusco.mostrarPosicion();
        }
        else {
            cout << endl << "El restaurante no existe";
        }x++;
    }
    esperar();
}

void Menu::buscarCalificacionHotel(){
    TipoEntero calificacion;
    cout << "Calificacion: ";
    cin >> calificacion;
    Objeto oBusco = tierra.buscarCalificacionHotel(calificacion);
    if (oBusco.getCalificacion() == calificacion) {
        tierra.dibujarTierra();
        cout << endl << oBusco.mostrarPosicion();
    }
    else {
        cout << endl << "El hotel no existe";
    }
    esperar();
}

//----------MOVER RESTAURANTES, HOTELES Y MUSEOS----------------------
void Menu::moverRestaurante(){
    string nombre;
    TipoEntero x, y;
    cout << "Nombre del restaurante: ";
    cin >> nombre;
    Objeto oBusco = tierra.buscarObjetoRestaurante(nombre);
    if (oBusco.getNombre() == nombre) {
        cout << "Ingrese la nueva posicion X: ";
        cin >> x;
        cout << "Ingrese la nueva posicion Y: ";
        cin >> y;
        // Validar que tome lugar en lugar ocupado
        if (tierra.validarRestaurante(x, y, oBusco.getAncho())) {
            cout << "(¡!) Posicion (X,Y) Incorrecta,ocupado" << endl;
            esperar();
            return;
        }
        tierra.moverRestaurante(nombre, x, y);
        tierra.actualizarTierra();
    }
    else {
        cout << endl << "El Restaurante que busca no existe";
    }
}
void Menu::moverHotel(){
    string nombre;
    TipoEntero x, y;
    cout << "Nombre del hotel: ";
    cin >> nombre;
    Objeto oBusco = tierra.buscarObjetoHotel(nombre);
    if (oBusco.getNombre() == nombre) {
        cout << "Ingrese la nueva posicion X: ";
        cin >> x;
        cout << "Ingrese la nueva posicion Y: ";
        cin >> y;
        // Validar que tome kugar en lugar ocupado
        if (tierra.validarHotel(x, y, oBusco.getAncho())) {
            cout << "(¡!) Posicion (X,Y) Incorrecta,ocupado" << endl;
            esperar();
            return;
        }
        tierra.moverHotel(nombre, x, y);
        tierra.actualizarTierra();
    }
    else {
        cout << endl << "El Hotel que busca no existe";
    }
}


void Menu::numeroDispCeldas(){
    cout << "\nEl numero de celdas ocupadas: " << 400-tierra.contarPlano()<<endl;
}
void Menu::numeroDispCeldasenY(){
    cout << tierra.contarColumna()<<endl;
}
void Menu::ejecutar() {
    do {
        limpiar();
        imprimirMenu();
        cout << "\n\n>> Ingrese alternativa: ";
        cin >> opcion;
        seleccionarOpcion();
    } while (opcion != 0);
    cout << "Fin del programa...\n";
}

void Menu::seleccionarOpcion() {
    switch(Opciones(opcion)) {
        case Opciones::AgregarRestaurante:  // Agregar Restaurante
            agregarRestaurante(1);
            break;
        case Opciones::AgregarHotel:  // Agregar Restaurante
            agregarHotel(1);
            break;
        case Opciones::RemoverRestaurante:  // Remover Restaurante
            removerRestaurante();
            break;
        case  Opciones::Mostrar: // Dibujando Tierra
            dibujarMapa();
            break;
        case  Opciones::BuscarRestaurante: // Buscar Restaurante
            buscarRestaurante();
            break;
        case  Opciones::BuscarHotel: // Buscar Hotel
            buscarHotel();
            break;
        case  Opciones::MoverRestaurante: // Mover Restaurante
            moverRestaurante();
            break;
        case  Opciones::MoverHotel: // Mover Restaurante
            moverHotel();
            break;
        case Opciones::CeldasOcupadas: // Contador de celdas ocupadas
            numeroDispCeldas();
            break;
        case Opciones::CeldasOcupadasColumna: // Contador de celdas ocupadas en columnas
            numeroDispCeldasenY();
            break;
        case Opciones::CalificacionRestaurante: // Restaurante por calificacion
            buscarCalificacionRestaurante();
            break;
        case Opciones::CalificacionHotel: // Hotel por calificacion
            buscarCalificacionHotel();
            break;
    }
}
