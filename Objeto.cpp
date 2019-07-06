#include "Objeto.h"

Objeto::Objeto(){}

Objeto::Objeto(const TipoString& nombre, TipoCaracter color,long telefono,
               TipoEntero posX, TipoEntero posY):
        nombre{nombre}, color{color},
        posX{posX}, posY{posY} {}
Objeto::Objeto(const TipoString& nombre, TipoCaracter color,long telefono,
               TipoEntero posX, TipoEntero posY, double calificacion):
        nombre{nombre}, color{color},
        posX{posX}, posY{posY} , calificacion{calificacion}{}

Objeto::~Objeto() {}

void Objeto::setNombre(const TipoString& nombre) { this->nombre = nombre; }
void Objeto::moverse(TipoEntero x, TipoEntero y) {} //--  por implementar

TipoString   Objeto::getNombre() { return nombre; }
TipoEntero   Objeto::getPosX()   { return posX; }
TipoEntero   Objeto::getPosY()   { return posY; }
TipoCaracter Objeto::getColor()  { return color; }
double Objeto::getCalificacion() { return calificacion;}


TipoString Objeto::mostrarPosicion() {
    return "X = " + to_string(posX) + " Y = " + to_string(posY);
}

long Objeto::getNumeroTelefono() {return telefono;}


restaurante::restaurante(const TipoString& nombre, TipoCaracter color,long telefono,
        TipoEntero posX, TipoEntero posY, double calificacion, string _tipoComida, string _especialidaD):Objeto(nombre,color, telefono, posX,posY, calificacion){
    tipoComida= _tipoComida;
    especialidaD = _especialidaD;
}

restaurante::~restaurante() {

}

hoteles::hoteles(const TipoString& nombre, TipoCaracter color,long telefono,
                 TipoEntero posX, TipoEntero posY, double calificacion, double _estrellas, int _disponibilidad):Objeto(nombre,color,telefono,posX,posY,calificacion){
    disponibilidad= _disponibilidad;
    estrellas= _estrellas;
}

hoteles::~hoteles() {

}

museo::museo(const TipoString& nombre, TipoCaracter color,long telefono,
             TipoEntero posX, TipoEntero posY, double calificacion, string _exposicionA):Objeto(nombre,color,posX,posY,calificacion){
    exposicionA= _exposicionA;
}

museo::~museo() {

}
