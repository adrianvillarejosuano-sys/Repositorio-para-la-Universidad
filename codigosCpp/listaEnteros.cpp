#include <iostream>
#include <string>
#include "listaEnteros.h"

void listaEnteros::concatena(int valor)
{
    //control de errores : Si esta entero no hace nada 
    if (longitud == 100){
        return;
    }
    elementos[longitud] = valor;
    longitud++;

}
void listaEnteros::inserta(int indice , int valor)
{
    //control de errores : no hace nada en un indice invalido 
    if (indice < 0 || longitud <= indice){
        return;
    }
    //control de errores : si el array esta completo no hace nada
    if (longitud == 100){
        return;
    }

    //hay que desplazar los elementos que estan a partir de "indice" para hacer espacio al nuevo elemento

    desplaza_arriba(indice);
    elementos[indice]=valor;
    longitud++;

}
void listaEnteros::extrae(int indice)
{
    //control de errores : no hace nada en un indice invalido 
        if (indice < 0 || longitud <= indice){
            return;
        }

    //hay que desplazar los elementos de indice + 1 para que ocupen el lugar de indice

    desplaza_abajo(indice + 1);
    longitud--;

}
void listaEnteros::desplaza_arriba(int indice)
{

    for(int i = longitud ; i >= indice ; --i){

        elementos[i+1] = elementos [i];

    }


}
void listaEnteros::desplaza_abajo(int indice)
{
    for(int i = longitud ; i <= indice ; ++i){

        elementos[i-1] = elementos[i];
    }
}