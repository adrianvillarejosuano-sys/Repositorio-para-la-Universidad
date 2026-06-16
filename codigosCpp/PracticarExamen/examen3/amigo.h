#pragma once
#include <string>
#include "pelicula.h"


class Amigo {
private:
    //atributos
    std::string nombre;
    int telefono;

    //este atributo es para comunicar las clases
    Pelicula peliculaPrestada;

public:

    //constructor
    Amigo(std::string nombre, int telefono , Pelicula peliculaPrestada){}

    //getters
    std::string getNombre(){} 
    int getTelefono() {} 
    Pelicula getPeliculaPrestada() {}

    //setters
    void setNombre(std::string nombre){}
    void setTelefono(int telefono){}
    void setPeliculaPrestada(Pelicula peliculaPrestada){}


};