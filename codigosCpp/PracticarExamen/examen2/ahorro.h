#pragma once
#include "cuenta.h"

class Ahorro : public Cuenta {

public:

    //constructor
    Ahorro(int numeroCuenta, std::string titular, double saldoInicial);

    //destructor
    ~Ahorro() override = default; //destructor virtual por defecto, necesario para liberar memoria correctamente

    //metodo para añadir intereses
    void anadirIntereses() override {}; //sobrescribe el metodo virtual puro de la clase base

};