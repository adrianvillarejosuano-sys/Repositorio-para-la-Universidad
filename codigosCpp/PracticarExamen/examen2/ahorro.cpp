#include "ahorro.h"
#include <string>

using namespace std;

//constructor
    Ahorro::Ahorro(int numeroCuenta, string titular, double saldoInicial) : Cuenta(numeroCuenta, titular, saldoInicial) {}


//metodo para añadir intereses
    void Ahorro::anadirIntereses() {
        double intereses = getSaldo() * 0.1; //calcula el 10% de intereses
        setSaldo(getSaldo() + intereses); //añade los intereses al saldo actual
    }