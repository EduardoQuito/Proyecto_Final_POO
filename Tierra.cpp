#include "Tierra.h"
#include <string>
#include <iomanip>
#include <algorithm>
#include <nl_types.h>

using namespace std;

Tierra::Tierra() {
    plano.resize(ALTURA);
    for (auto& item: plano)
        item.resize(ANCHO);
}

Tierra::Tierra(TipoEntero altura, TipoEntero ancho) {
    plano.resize(altura);
    for (auto& item: plano)
        item.resize(ancho);
}

Tierra::~Tierra() {}
//-----------------------------------------------------------------------
//----------BUSCAR RESTAURANTES, HOTELES Y MUSEOS-------------------------
//-----------------------------------------------------------------------
Objeto Tierra::buscarObjetoRestaurante(string nombre)
{
    Objeto x;
    for (auto &iter : restaurantes)
    {
        if (iter->getNombre()==nombre)
            return *iter;
    }
    return x;
}

Objeto Tierra::buscarObjetoHotel(string nombre)
{
    Objeto x;
    for (auto &iter : hoteles)
    {
        if (iter->getNombre()==nombre)
            return *iter;
    }
    return x;
}


//-----------------------------------------------------------------------
//----------BUSCAR POR CALIFICACION-------------------------
//-----------------------------------------------------------------------

Objeto Tierra::buscarCalificacionRestaurante(TipoEntero calificacion)
{
    Objeto x;
    for (int i=0;i<restaurantes.size();i++)
    {
        if (restaurantes[i]->getCalificacion()==calificacion)
            cout <<"* * * * * * ["<<i<<"] "<<restaurantes[i]->getNombre()<<" :: X = " <<restaurantes[i]->getPosX()<<" :: Y = " << restaurantes[i]->getPosY()<< " :: calificacion = "<< restaurantes[i]->getCalificacion()<<" :: Color = " << restaurantes[i]->getColor()<<endl;
    }
    return x;
}
Objeto Tierra::buscarCalificacionHotel(TipoEntero calificacion)
{
    Objeto x;
    for (int i=0;i<hoteles.size();i++)
    {
        if (hoteles[i]->getCalificacion()==calificacion)
            cout <<"* * * * * * ["<<i<<"] "<<hoteles[i]->getNombre()<<" :: X = " <<hoteles[i]->getPosX()<<" :: Y = " << hoteles[i]->getPosY()<< " :: calificacion = "<< hoteles[i]->getCalificacion()<<" :: Color = " << hoteles[i]->getColor()<<endl;
    }
    return x;
}
//-----------------------------------------------------------------------
//----------MOVER RESTAURANES, HOTELES Y MUSEOS-------------------------
//-----------------------------------------------------------------------
void Tierra::moverRestaurante(string nombre, TipoEntero x, TipoEntero y)
{
    for (auto& iter : restaurantes)
    {
        if (iter->getNombre()==nombre) {
            iter->setPosX(x);
            iter->setPosY(y);
        }
    }
}

void Tierra::moverHotel(string nombre, TipoEntero x, TipoEntero y){
    for (auto& iter : hoteles)
    {
        if (iter->getNombre()==nombre) {
            iter->setPosX(x);
            iter->setPosY(y);
        }
    }
}

//-----------------------------------------------------------------------
//----------VALIDAR RESTAURANES, HOTELES Y MUSEOS------------------------
//-----------------------------------------------------------------------
//                        RESTAURANTE
bool Tierra::validarLugarRestaurante(TipoEntero x, TipoEntero y){
    for (auto& iter : restaurantes)
        if (x >= iter->getPosX() &&
            x <= iter->getPosX() + iter->getAncho() - 1 &&
            y >= iter->getPosY() &&
            y <= iter->getPosY() + iter->getAncho() - 1
                )
            return true;

    return false;
}
// Dos restaurantes no pueden tener el mismo nombre
bool Tierra::validarNombreRestaurante(string nombre){
    for (auto& iter : restaurantes)
        if (iter->getNombre() == nombre)
            return true;
    return false;
}
//No puedo agregar dos restaurantes en un mismo lugar
bool Tierra::validarRestaurante(TipoEntero x, TipoEntero y, TipoEntero ancho){
    for (auto& iter : restaurantes)
        if (x >= iter->getPosX() &&
            x <= iter->getPosX() + ancho - 1 &&
            y >= iter->getPosY() &&
            y <= iter->getPosY() + ancho - 1 )
            return true;
    return false;
}

//                         HOTELES
bool Tierra::validarLugarHotel(TipoEntero x, TipoEntero y){
    for (auto& iter : hoteles)
        if (x >= iter->getPosX() &&
            x <= iter->getPosX() + iter->getAncho() - 1 &&
            y >= iter->getPosY() &&
            y <= iter->getPosY() + iter->getAncho() - 1
                )
            return true;

    return false;
}
// Dos hoteles no pueden tener el mismo nombre
bool Tierra::validarNombreHotel(string nombre){
    for (auto& iter : hoteles)
        if (iter->getNombre() == nombre)
            return true;
    return false;
}
//No puedo agregar dos hoteles en un mismo lugar
bool Tierra::validarHotel(TipoEntero x, TipoEntero y, TipoEntero ancho){
    for (auto& iter : hoteles)
        if (x >= iter->getPosX() &&
            x <= iter->getPosX() + ancho - 1 &&
            y >= iter->getPosY() &&
            y <= iter->getPosY() + ancho - 1 )
            return true;
    return false;
}


//-----------------------------------------------------------------------
//----------ADICIONAR RESTAURANES, HOTELES Y MUSEOS----------------------
//-----------------------------------------------------------------------
void Tierra::adicionarRestaurante(Objeto *restaurante){
    restaurantes.emplace_back(restaurante);
}

void Tierra::adicionarHotel(Objeto *hotel){
    hoteles.emplace_back(hotel);
}


//-----------------------------------------------------------------------
//----------REMOVER RESTAURANES, HOTELES Y MUSEOS----------------------
//-------------------------------------------------------------------------

bool Tierra::removerRestaurante(string &nombre){
    // Buscando objeto
    if (restaurantes.size() == 0) return false;

    auto iter = find_if(begin(restaurantes), end(restaurantes),
                        [&nombre](Objeto* obj){ return obj->getNombre() == nombre; });
    if (iter == end(restaurantes)) return false;
    // Eliminando objeto
    restaurantes.erase(iter);
    //-- si encuentra al objeto lo separa del vector, pero no mata al objeto, esto se hara en el menu.
    return true;
}
//-----------------------------------------------------------------------
//----------IMPRIMIR RESTAURANES, HOTELES Y MUSEOS----------------------
//-----------------------------------------------------------------------
//.......................................................................
void Tierra::imprimirRestaurante(){
    int i = 0;
    for (auto& item: restaurantes) {

        cout << "* * * * * * [" << i << "] ";
        cout << item->mostrarPosicion()
             << " :: Color = " << item->getColor() << '\n';
        i++;
    }
}
//.........................................................................
void Tierra::imprimirHotel(){
    int i = 0;
    for (auto& item: hoteles) {

        cout << "* * * * * * [" << i << "] ";
        cout << item->mostrarPosicion()
             << " :: Color = " << item->getColor() << '\n';
        i++;
    }
}
void Tierra::imprimirMuseo(){
    int i = 0;
    for (auto& item: Museo) {

        cout << "* * * * * * [" << i << "] ";
        cout << item->mostrarPosicion()
             << " :: Color = " << item->getColor() << '\n';
        i++;
    }
}
//...................................................................
//--------------------------------------------------------------------------
void Tierra::actualizarTierra() {
    for (auto &row: plano)
        for (auto &cell: row)
            cell = COLOR;

    // Actualizar informacion en el tablero
    for (auto& item: restaurantes)
        if (item->getAncho() == 1) {
            plano[item->getPosY()][item->getPosX()] = item->getColor();
        }
        else {
            for (int i = 0; i < item->getAncho(); i++)
                for (int j = 0; j < item->getAncho(); j++)
                    plano[item->getPosY() + j][item->getPosX() + i] = item->getColor();
        }

    // Actualizar informacion
    for (auto& item : hoteles)
        if (item->getAncho() == 1) {
            plano[item->getPosY()][item->getPosX()] = item->getColor();
        }
        else {
            for (int i = 0; i < item->getAncho(); i++)
                for (int j = 0; j < item->getAncho(); j++)
                    plano[item->getPosY() + j][item->getPosX() + i] = item->getColor();
        }
}



void Tierra::dibujarTierra() {
    cout << '\n';
    cout << setw(3) << ' ';
    //  titulos
    for (auto j = 0; j < getAncho(); ++j)
        cout << setw(3) << j;
    cout << '\n';

    //  columnas
    for (auto i = 0; i < getAltura(); ++i) {
        cout << setw(3) << i;
        //  objetos
        for (auto j = 0; j < getAncho(); ++j) {
            cout << setw(3) << plano[i][j];
        }
        cout << '\n';
    }
}
TipoEntero Tierra::contarPlano(){
    TipoEntero contador=0;
    for(int i=0; i<plano.size(); i++){
        for(int j=0; j<plano.size(); j++){
            if(plano[i][j]=='.'){
                contador+=1;
            }
        }
    }
    return (contador-41);
}


TipoEntero Tierra::contarColumna(){
    TipoEntero contador=0;
    int b;
    cout<<endl<<"Escoja fila: ";cin>>b;
    for(int j=0; j<plano.size(); j++){

        if(plano[j][b]!='.'){
            contador++;
        }

    }
    cout<<"Celdas Ocupadas en Columna "<<b<<" : ";
    return (contador);
}

TipoEntero Tierra::getAltura() {
    return plano.size();
}

TipoEntero Tierra::getAncho(){
    return plano[0].size();
}

TipoEntero Tierra::getCantidadObjectos()
{
    return TipoEntero();
}
