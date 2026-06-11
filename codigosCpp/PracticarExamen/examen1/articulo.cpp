#include "articulo.h"
#include <string>

using namespace std;


//constructor
    Articulo::Articulo(int codigo, double precio, string nombre) {
        this->codigo = codigo;
        this->precio = precio;
        this->nombre = nombre;
    }

//getters
    int Articulo::getCodigo() const {
        return codigo;
    }

    double Articulo::getPrecio() const {
        return precio;
    }

    string Articulo::getNombre() const {
        return nombre;
    }

//setters
    void Articulo::setCodigo(int codigo) {
        this->codigo = codigo;
    }

    void Articulo::setPrecio(double precio) {
        this->precio = precio;
    }

    void Articulo::setNombre(string nombre) {
        this->nombre = nombre;
    }

//destructor
    Articulo::~Articulo() {
        //no se necesita liberar memoria dinamica, por lo que el destructor esta vacio
    }

//el metodo virtual no se implementa aqui ya que la clase es abstracta, se implementara en las clases derivadas que hereden de Articulo
    

//sobrecarga de operadores
    bool Articulo::operator==(const Articulo& otro) const {
        //dos articulos son iguales si tienen el mismo codigo
        return this->codigo == otro.codigo;
    }
