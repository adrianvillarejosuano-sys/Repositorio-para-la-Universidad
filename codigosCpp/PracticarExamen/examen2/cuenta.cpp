#include "cuenta.h"

using namespace std;

//constructor
    Cuenta::Cuenta(int numeroCuenta, string titular, double saldoInicial) {
        this->numeroCuenta = numeroCuenta;
        this->titular = titular;
        this->saldo = saldoInicial;
    }

//getters
    double Cuenta::getSaldo() const {
        return saldo;
    }   
    int Cuenta::getNumeroCuenta() const {
        return numeroCuenta;
    }
    string Cuenta::getTitular() const {
        return titular;
    }

//setters
    void Cuenta::setSaldo(double saldo) {
        this->saldo = saldo;
    }
    void Cuenta::setNumeroCuenta(int numeroCuenta) {
        this->numeroCuenta = numeroCuenta;
    }
    void Cuenta::setTitular(string titular) {
        this->titular = titular;
    }



