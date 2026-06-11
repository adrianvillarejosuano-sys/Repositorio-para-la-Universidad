#pragma once
#include "articulo.h"

class Libro : public Articulo {
    private:
        //atributos
        int paginas;

    public:

        //constructor
        Libro(int codigo, double precio, std::string nombre, int paginas);

        //destructor
        ~Libro();

        //getters   
        int getPaginas() const;

        //setters
        void setPaginas(int paginas);

        //metodo virtual
        void aplicarDescuento() override; //sobrescribe el metodo virtual puro de la clase base Articulo
};