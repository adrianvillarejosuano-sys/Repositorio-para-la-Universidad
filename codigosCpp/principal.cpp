#include <iostream>
#include <string>
#include "listaEnteros.h"

int main(){

    //creamos una instancia de la lista de numeros
    listaEnteros lista1{};

    //bucle que lee la lista
    bool termina = false;

    while(!termina)
        {
            int numero;

            //lee un numero de la entrada por consola y lo deja en numero
            //para terminar la entrada de numeros pulsa cntrl + D o cntrl + Z y pulsa enter
            std::cin >> numero ;

            if(!std::cin)
            {

                termina = true;

            }
            else
            {

                //concatena el numero leido a la lista y incrementa longitud
                lista1.concatena(numero);

                //control de errores : no entran mas en la lista
                if(lista1.longitud == 100)
                {
                    termina = true;
                }

            }
        }

    //Se escriben los numeros leidos.

    std::cout << "\n";

    for(int indice = 0 ; indice <= lista1.longitud ; indice++)
    {
        std::cout << lista1.elementos[indice] << "\n";
    }


}