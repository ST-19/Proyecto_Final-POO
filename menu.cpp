#include "Menu.h"
#include <iostream>
#include <string>
#include <cstdio>
#include "Objeto.h"

using namespace std;

enum class Opciones { Agregar=1, Remover, Mostrar, Ubicartipo, UbicarCalificacion};


void limpiar() {
    cout << "\033[2J\033[0;0H";
}

void esperar() {
    char w;
    do {
        w = input<TipoCaracter>("Presione C y Enter para continuar...");
    }while (toupper(w) != 'C');
}

void Menu::imprimirMenu() {
    limpiar();
    cout<<"\n";
    cout << "MENU\n";
    cout << string(4, '-') << "\n\n";
    cout << "1. Agregar un nuevo objeto\n";
    cout << "2. Remover objeto\n";
    cout << "3. Dibujar Mapa\n";
    cout << "4. Ubicar 3 lugares mas cercanos a un punto\n";
    cout << "5. Ubicar 3 mejores lugares por tipo\n";
    cout << "6. Ubicar 3 mejores lugares por calificación\n\n";
    cout << "0. Para Salir\n\n";
}


void Menu::agregarObjeto() {
    cout << "Hotel = 1 "<< endl;
    cout << "Restaurante = 2 "<< endl;
    cout << "Museo = 3 "<< endl;
    auto tipo = input<TipoEntero >("Ingrese Tipo: ");

    if (tipo == 1) {
        auto nombre = input<TipoString>("Ingrese Nombre : ");
        auto color = input<TipoCaracter>("Ingrese color (Un caracter): ");
        auto telefono= input<long>("Ingrese telefono: ");

        auto x = input<TipoEntero>("Ingrese posicion X : ");
        while (x < 0 || x >= tierra.getAncho()) {
            cout << "Posicion X Incorrecta, los limites son: 0, "
                 << tierra.getAncho() - 1 << "\n";
            x = input<TipoEntero>("Ingrese posicion X : ");
        }
        TipoEntero y = input<TipoEntero>("Ingrese posicion Y : ");
        while (y < 0 || y >= tierra.getAncho()) {
            cout << "Posicion Y Incorrecta, los limites son: 0, "
                 << tierra.getAltura() - 1 << "\n";
            y = input<TipoEntero>("Ingrese posicion Y : ");
        }
        auto calificacion = input<double>("Ingrese calificacion de cliente: ");
        auto estrellas = input<double>("Ingrese numero de estrellas sobre 5: ");
        auto dispon = input<TipoEntero>(" Ingrese nmero de habitaciones libres: ");

        tierra.adicionarObjeto(new hoteles(nombre, color,telefono, x, y, calificacion, estrellas, dispon));
    } else if (tipo == 2) {
        auto nombre2 = input<TipoString>("Ingrese Nombre : ");
        auto color2 = input<TipoCaracter>("Ingrese color (Un caracter): ");
        auto telefono= input<long>("Ingrese telefono: ");


        auto x2 = input<TipoEntero>("Ingrese posicion X : ");


        while (x2 < 0 || x2 >= tierra.getAncho()) {
            cout << "Posicion X Incorrecta, los limites son: 0, "
                 << tierra.getAncho() - 1 << "\n";
            x2 = input<TipoEntero>("Ingrese posicion X : ");
        }
        TipoEntero y2 = input<TipoEntero>("Ingrese posicion Y : ");
        while (y2 < 0 || y2 >= tierra.getAncho()) {
            cout << "Posicion Y Incorrecta, los limites son: 0, "
                 << tierra.getAltura() - 1 << "\n";
            y2 = input<TipoEntero>("Ingrese posicion Y : ");
        }
        auto calificacion2 = input<double>("Ingrese calificacion de cliente: ");
        auto tipoComida = input<TipoString>("Ingrese tipo de comida: ");
        auto especialidaD = input<TipoString>("Especialiad del dia: ");
        tierra.adicionarObjeto(new restaurante(nombre2, color2,telefono,
                                               x2, y2, calificacion2, tipoComida, especialidaD));
    }else if (tipo==3) {
        auto nombre = input<TipoString>("Ingrese Nombre : ");
        auto color = input<TipoCaracter>("Ingrese color (Un caracter): ");
        auto telefono= input<long>("Ingrese telefono: ");


        auto x = input<TipoEntero>("Ingrese posicion X : ");


        while (x < 0 || x >= tierra.getAncho()) {
            cout << "Posicion X Incorrecta, los limites son: 0, "
                 << tierra.getAncho() - 1 << "\n";
            x = input<TipoEntero>("Ingrese posicion X : ");
        }
        TipoEntero y = input<TipoEntero>("Ingrese posicion Y : ");
        while (y < 0 || y >= tierra.getAncho()) {
            cout << "Posicion Y Incorrecta, los limites son: 0, "
                 << tierra.getAltura() - 1 << "\n";
            y = input<TipoEntero>("Ingrese posicion Y : ");
        }
        auto calificacion1 = input<double>("Ingrese calificacion de cliente: ");
        auto exposicionA = input<TipoString>(" Ingrese Exposición actual: ");
        tierra.adicionarObjeto(new museo(nombre, color, telefono,x, y, calificacion1, exposicionA));
    }

}

void Menu::removerObjeto() {
    auto nombre = input<TipoString>("Ingrese Nombre: ");

    Objeto* obj = tierra.removerObjeto(nombre);
    if (obj == nullptr) {
        cout << "Objeto No existe\n";
    }
    else {
        delete obj;
        cout << "Objeto: " << nombre << " ha sido removido\n";
    }
    esperar();
}

void Menu::dibujarMapa() {
    limpiar();
    tierra.actualizarTierra();
    tierra.dibujarTierra();
    cout << '\n';
    tierra.imprimirObjetos();
    cout << '\n';
    esperar();
}
void Menu::ubicar_mejores_tipo() {
}

void Menu::ubicar_mejoress_calificacion(){
    int i = 0;
    int x = -1;
    for (auto& item: objetos) {
        int max=-1;
        for (int i=0; i < objetos.size(); i++) {
            int calificacioooon = objetos[i]->getCalificacion();

            if (calificacioooon > max) {
                max = calificacioooon;
                x = i;
            }
        }
        i++;
    }
    cout<<"Los lugares con la mayor calficacion"<<endl<<"Nombre: "<<objetos[x]->getNombre()<<endl<<"calificacion: "<<objetos[x]->getCalificacion()<<endl;
}

void Menu::ubicar_mas_cercanos() {
}

void Menu::ejecutar() {
    do {
        imprimirMenu();
        cin >> opcion;
        seleccionarOpcion();
    } while (opcion != 0);
    cout << "Fin del programa...\n";
}

void Menu::seleccionarOpcion() {
    limpiar();
    switch(Opciones(opcion)) {
        case Opciones::Agregar:  // Agregar Objeto
            agregarObjeto();
            break;
        case Opciones::Remover:  // Remover Objeto
            removerObjeto();
            break;
        case  Opciones::Mostrar: // Dibujando Tierra
            dibujarMapa();
            break;
        case Opciones :: UbicarCalificacion:
            ubicar_mejoress_calificacion();
            break;
    }
}
