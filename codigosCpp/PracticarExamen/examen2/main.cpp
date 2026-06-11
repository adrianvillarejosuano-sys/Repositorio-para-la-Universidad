#include <stdlib.h>
#include <iostream> 
#include <string>
#include "cuenta.h"
#include "ahorro.h"
#include "vista.h"

using namespace std;

int main(){

    //creamos una cuenta de ahorro y una cuenta vista
        Cuenta* ahorro1 = new Ahorro(001, "Juan", 1000); //creamos una cuenta de ahorro

        Cuenta* vista1 = new vista(002, "Maria", 2000); //creamos una cuenta vista

    //mostramos el saldo inicial de ambas cuentas
        cout << "Saldo inicial de la cuenta de ahorro: " << ahorro1->getSaldo() << endl;
        cout << "Saldo inicial de la cuenta vista: " << vista1->getSaldo() << endl;

    //añadimos intereses a ambas cuentas
        ahorro1->anadirIntereses(); //añade intereses a la cuenta de ahorro
        vista1->anadirIntereses(); //añade intereses a la cuenta vista

    //mostramos el saldo después de añadir intereses
        cout << "Saldo después de añadir intereses a la cuenta de ahorro: " << ahorro1->getSaldo() << endl;
        cout << "Saldo después de añadir intereses a la cuenta vista: " << vista1->getSaldo() << endl;

    //usamos la sobrecarga de operadores para transferir dinero de la cuenta vista a la cuenta de ahorro
        *vista1 >> *ahorro1; //transfiere 500 de la cuenta vista a la cuenta de ahorro

    //mostramos el saldo después de la transferencia
        cout << "Saldo después de transferir 500 de la cuenta vista a la cuenta de ahorro: " << endl;
        cout << "Cuenta de ahorro: " << ahorro1->getSaldo() << endl;    
        cout << "Cuenta vista: " << vista1->getSaldo() << endl;

    return 0;

}