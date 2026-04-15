// Lista de enteros

//directiva del preprocesador que evita duplicar el codigo de la cabecera
#pragma once

class listaEnteros
{

public:
    //Array de 100 elementos
    int elementos[100];

    //añadimos longitud , los elementos de la lista van de elementos[0] hasta elementos[longitud-1]
    int longitud{0};

    //concatena un elemento al final de la lista
    void concatena(int valor);

    //inserta un elemento en la lista en la posicion indicada por "indice"
    void inserta(int indice , int valor);

    //extrae el elemento de la lista en la posicion seleccionada
    void extrae(int indice);

    //metodos auxiliares
    //desplazar los elementos a una posicion superior o inferior
    void desplaza_arriba(int indice);
    void desplaza_abajo(int indice);

};


