#include "libro.h"
#include <string>

using namespace std;

//constructor
    Libro::Libro(int codigo, double precio, string nombre, int paginas) : Articulo(codigo, precio, nombre) {
        this->paginas = paginas;
    }

//destructor
    Libro::~Libro() {
        //no se necesita liberar memoria dinamica, por lo que el destructor esta vacio
    }

//getters
    int Libro::getPaginas() const {
        return paginas;
    }       
//setters
    void Libro::setPaginas(int paginas) {
        this->paginas = paginas;
    }
//metodo virtual con override
    void Libro::aplicarDescuento() {
        //aplica un descuento del 10% al precio del libro
        double precioActual = getPrecio();
        double descuento = precioActual * 0.10;
        double nuevoPrecio = precioActual - descuento;
        setPrecio(nuevoPrecio);
    }

