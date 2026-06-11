#include <stdlib.h>
#include <iostream>
#include "articulo.h"
#include <string>
#include "libro.h"
#include "juguete.h"

using namespace std;

int main(){

//un tipo de articulo se puede cambiar por otro 

Articulo* Libro1 = new Libro(808 , 20.0, "el quijote", 500);
Articulo* juguete1 = new Juguete(909, 15.0, "lego", 6);

//ahora que tenemos dos objetos hay que intercambiarlos por referencia

    cout << "Antes del intercambio: " << endl;
    cout << "articulo 1: " << Libro1->getNombre() << " Precio: " << Libro1->getPrecio() << endl;
    cout << "articulo 2: " << juguete1->getNombre() << " Precio: " << juguete1->getPrecio() << endl;

    //intercambio de objetos por referencia
    Articulo* temp = Libro1; //temp apunta a Libro1
    Libro1 = juguete1; //Libro1 ahora apunta a juguete1
    juguete1 = temp; //juguete1 ahora apunta a temp que es el antiguo Libro1

    cout << "Después del intercambio: " << endl;
    cout << "articulo 1: " << Libro1->getNombre() << " Precio: " << Libro1->getPrecio() << endl;
    cout << "articulo 2: " << juguete1->getNombre() << " Precio: " << juguete1->getPrecio() << endl;
    cout << "Aplicando descuento a ambos articulos: " << endl;
    Libro1->aplicarDescuento(); //aplica el descuento del juguete al libro
    juguete1->aplicarDescuento(); //aplica el descuento del libro al juguete

    cout << "articulo 1: " << Libro1->getNombre() << " Precio con descuento: " << Libro1->getPrecio() << endl;
    cout << "articulo 2: " << juguete1->getNombre() << " Precio con descuento: " << juguete1->getPrecio() << endl;

    //liberamos la memoria dinamica
    delete Libro1; //liberamos el nuevo libro que es el antiguo juguete
    delete juguete1; //liberamos el nuevo juguete que es el antiguo libro

    return 0;
}