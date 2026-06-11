#pragma once
#include "cuenta.h"

class vista : public Cuenta {   
public:

    //constructor
    vista(int numeroCuenta, std::string titular, double saldoInicial) : Cuenta(numeroCuenta, titular, saldoInicial) {}

    //destructor
    ~vista() override = default; //destructor virtual por defecto, necesario para liberar memoria correctamente

    //metodo para añadir intereses
    void anadirIntereses() override {}; //sobrescribe el metodo virtual puro de la clase base

};


