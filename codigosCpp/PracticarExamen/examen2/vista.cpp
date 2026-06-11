#include "vista.h"
#include <string>

using namespace std;

vista::vista(int numeroCuenta, string titular, double saldoInicial) : Cuenta(numeroCuenta, titular, saldoInicial) {}

//metodo para añadir intereses
void vista::anadirIntereses() {
    double intereses = getSaldo() * 0.05; //calcula el 5% de intereses
    setSaldo(getSaldo() + intereses); //añade los intereses al saldo actual
}




