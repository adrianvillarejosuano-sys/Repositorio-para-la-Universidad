#include <stdlib.h>
#include <iostream>
#include <string>
#include "anual.h"


using namespace std;

int main() {

    //prueba de anual
    int ano;

    //recibe un año por teclado
    cout << "Introduce un año: ";
    cin >> ano;

    //contructor de anual
    Anual ano1(ano);

    cout << "su primer dia del año es un " << ano1.diaSemanaToString(ano1.primerDia) << " que numericamente es el " << ano1.primerDia  << " dia " << endl;
  

    return 0;
}