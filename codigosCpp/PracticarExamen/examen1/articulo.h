#pragma once
#include <string>



class Articulo {
    private:
        //atributos
        int codigo;
        double precio;
        std::string nombre;

    public:

        //constructor
        Articulo(int codigo, double precio, std::string nombre);

        //destructor
        ~Articulo();

        //getters
        int getCodigo() const;    
        double getPrecio() const;
        std::string getNombre() const;

        //setters
        void setCodigo(int codigo);
        void setPrecio(double precio);
        void setNombre(std::string nombre);

        //metodo virtual
        virtual void aplicarDescuento() = 0; //metodo virtual puro, hace que la clase sea abstracta

        //sobrecarga de operadores
        bool operator==(const Articulo& otro) const {}
};



