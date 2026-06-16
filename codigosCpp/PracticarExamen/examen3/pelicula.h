#pragma once
#include <string>

class Pelicula {
private:

    std::string genero;
    int fecha; 
    bool prestada; //atributo para saber si la pelicula esta prestada o no

public:

    //constructor
    Pelicula(std::string genero = "", int fecha = 0, bool prestada = false){}

    //getters
    std::string getGenero(){} 
    int getFecha() {} 
    bool getPrestada() {}

    //setters
    void setGenero(std::string genero){}
    void setFecha(int fecha){}
    void setPrestada(bool prestada){}

    //excepciones:

    void prestarPelicula(){} //si la pelicula esta prestada, lanza una excepcion


    //sobrecarga de operadores , comparar genero
    bool operator==(const Pelicula& otraPelicula) {}

};
