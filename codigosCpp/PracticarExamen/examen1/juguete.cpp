#include "juguete.h"

using namespace std;

//constructor
    Juguete::Juguete(int codigo, double precio, string nombre, int edadRecomendada) : Articulo(codigo, precio, nombre) {
        this->edadRecomendada = edadRecomendada;
    }

//destructor
    Juguete::~Juguete() {
        //no se necesita liberar memoria dinamica, por lo que el destructor esta vacio
    }

//getters
    int Juguete::getEdadRecomendada() const {
        return edadRecomendada;
    }
//setters
    void Juguete::setEdadRecomendada(int edadRecomendada) {
        this->edadRecomendada = edadRecomendada;
    }
//metodo virtual con override
    void Juguete::aplicarDescuento() {
        //aplica un descuento del 15% al precio del juguete
        double precioActual = getPrecio();
        double descuento = precioActual * 0.15;
        double nuevoPrecio = precioActual - descuento;
        setPrecio(nuevoPrecio);
    }


