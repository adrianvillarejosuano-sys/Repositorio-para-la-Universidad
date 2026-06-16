#include "pelicula.h"

//constructor
    Pelicula::Pelicula(std::string genero, int fecha , bool prestada) {
        this->genero = genero;
        this->fecha = fecha;
        this->prestada = prestada;
    }

//getters
    std::string Pelicula::getGenero() {
        return genero;
    }

    int Pelicula::getFecha() {
        return fecha;
    }

    bool Pelicula::getPrestada() {
        return prestada;
    }

//setters

    void Pelicula::setGenero(std::string genero) {
        this->genero = genero;
    }

    void Pelicula::setFecha(int fecha) {
        this->fecha = fecha;
    }

    void Pelicula::setPrestada(bool prestada) {
        this->prestada = prestada;
    }

//excepciones:

    void Pelicula::prestarPelicula() {
        if (prestada) {
            throw "La pelicula ya esta prestada";
        } else {
            prestada = true;
        }
    }


//sobrecarga de operadores , comparar genero
    bool Pelicula::operator==(const Pelicula& otraPelicula) {
        return genero == otraPelicula.genero;
    }



