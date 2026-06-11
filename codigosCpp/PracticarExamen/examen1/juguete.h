#pragma once 
#include "articulo.h"

class Juguete : public Articulo {
    private:
        //atributos
        int edadRecomendada;

    public:

        //constructor
        Juguete(int codigo, double precio, std::string nombre, int edadRecomendada);

        //destructor
        ~Juguete();

        //getters   
        int getEdadRecomendada() const;

        //setters
        void setEdadRecomendada(int edadRecomendada);

        //metodo virtual
        void aplicarDescuento() override; //sobrescribe el metodo virtual puro de la clase base Articulo
};