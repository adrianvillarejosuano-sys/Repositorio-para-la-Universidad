#pragma once
#include <string>

class Cuenta {
private:

    //atributos
    double saldo;
    int numeroCuenta;
    std::string titular;

public:

    //constructor
    Cuenta(int numeroCuenta, std::string titular, double saldoInicial);

    //destructor virtual
    virtual ~Cuenta() = default; //destructor virtual por defecto, necesario para liberar memoria correctamente en clases derivadas
   
    //getters
    double getSaldo() const;
    int getNumeroCuenta() const;
    std::string getTitular() const;

    //setters
    void setSaldo(double saldo);
    void setNumeroCuenta(int numeroCuenta);
    void setTitular(std::string titular);

    //metodo para pasar dinero a otra cuenta
    void transferir(Cuenta& otraCuenta, double cantidad) {
        if (cantidad > 0 && cantidad <= saldo) { //verifica que la cantidad sea positiva y no exceda el saldo actual
            saldo -= cantidad; //resta la cantidad al saldo actual
            otraCuenta.setSaldo(otraCuenta.getSaldo() + cantidad); //añade la cantidad al saldo de la otra cuenta
        }
    }

    //sobrecarga de operadores
    void operator>>(Cuenta& otraCuenta) { //sobrecarga del operador de transferencia
       transferir(otraCuenta, 500); //transfiere una cantidad fija de 500, se puede modificar para aceptar diferentes cantidades
        }
    


    //metodo virtual
    virtual void anadirIntereses() = 0; //metodo puro virtual, hace que la clase sea abstracta

};
