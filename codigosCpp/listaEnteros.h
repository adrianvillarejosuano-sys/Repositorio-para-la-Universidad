// Lista de enteros

//directiva del preprocesador que evita duplicar el codigo de la cabecera
#pragma once

class listaEnteros
{

public:

    //constructor
    listaEnteros();

    //constructor que establece un numero inicial de elementos, todos ellos 0
    listaEnteros(int longitud);

    //destructor
    ~listaEnteros();

    //obtiene la longitud de la lista
    int longitud;

    //obtiene el elemento cuyo indice se indica
    int getElemento(int indice);

    //establece el valor del elemento indicado
    void setElemento(int indice,int valor);

    //concatena un elemento al final de la lista
    void concatena(int valor);
   
    //inserta un elemento en la posicion indicada por indice
    void inserta(int indice , int valor);

    //extrae el elemento de la lista en la posicion indicada
    void extrae(int indice);



private:

    //longitud del array "elementos"
    int capacidad;

    //array de capacidad enteros
    //es un puntero que se usa como un array
    int * elementos;

    //longitud de la lista
    //los elementos van desde [0]...[longtd-1]
    int longtd;

    //amplia cuando es necesario
    void ampliar();

    //desplaza arriba
    void desplaza_arriba(int indice);

    //desplaza abajo
    void desplaza_abajo(int indice);
    
};


