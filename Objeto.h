#ifndef AGREGACION_OBJETO_H
#define AGREGACION_OBJETO_H


#include <iostream>
#include "Tipos.h"
#include <vector>

using namespace std;

class Objeto {
private:
    string nombre;
    double calificacion;
    long telefono;
    TipoCaracter  color = 'R';
    TipoEntero    posX = 30;
    TipoEntero    posY = 25;

public:
    Objeto();
    Objeto(const TipoString& nombre, TipoCaracter color,long telefono,
           TipoEntero posX, TipoEntero posY);
    Objeto(const TipoString& nombre, TipoCaracter color,long telefono,
           TipoEntero posX, TipoEntero posY, double calificacion);
    virtual ~Objeto();
    void setNombre(const TipoString& nombre);
    string     getNombre();
    TipoEntero getPosX();
    TipoEntero getPosY();
    char getColor();
    double getCalificacion();
    long getNumeroTelefono();
    void moverse(TipoEntero x, TipoEntero y);
    string mostrarPosicion();
};

class restaurante: public Objeto{
private:
    string tipoComida;
    string especialidaD;
public:
    restaurante(const TipoString& nombre, TipoCaracter color,long telefono,
                TipoEntero posX, TipoEntero posY, double calificacion, string tipoComida, string especialidaD);
    virtual ~restaurante();
    void settipoComida( string _tipoComida){
        tipoComida= _tipoComida;
    }
    string gettipoComida(){
        return tipoComida;
    }
    void setespecialidaD ( string _especialidaD){
        especialidaD= _especialidaD;
    }
    string getespecialidaD(){
        return especialidaD;
    }


};
class hoteles: public Objeto{
private:
    double estrellas;
    int disponibilidad;
    long numerotelefonico;
public:
    virtual ~hoteles();
    hoteles(const TipoString& nombre, TipoCaracter color,long telefono,
            TipoEntero posX, TipoEntero posY, double calificacion, double estrellas, int disponibilidad);
    void setestrellas(double _estrellas){
        estrellas= _estrellas;
    }
    double getestrellas(){
        return estrellas;
    }
    void setdisponibilidad( int _disponibilidad){
        disponibilidad= _disponibilidad;
    }
    int getdisponibilidad(){
        return disponibilidad;
    }

};
class museo: public Objeto{
private:
    string exposicionA;
public:
    virtual ~museo();
    museo(const TipoString& nombre, TipoCaracter color,long telefono,
          TipoEntero posX, TipoEntero posY, double calificacion, string exposicionA);
    void setexposicionA( string _exposicionA){
        exposicionA= _exposicionA;}
    string getexposicionA(){
        return exposicionA;
    }

};



#endif //AGREGACION_OBJETO_H
