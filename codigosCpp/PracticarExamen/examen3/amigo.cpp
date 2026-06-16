#include "amigo.h"

//constructor
    Amigo::Amigo(std::string nombre, int telefono , Pelicula peliculaPrestada) {
        this->nombre = nombre;
        this->telefono = telefono;
        this->peliculaPrestada = peliculaPrestada;
    }

//getters
    std::string Amigo::getNombre() {
        return nombre;
    }

    int Amigo::getTelefono() {
        return telefono;
    }

    Pelicula Amigo::getPeliculaPrestada() {
        return peliculaPrestada;
    }

//setters
    void Amigo::setNombre(std::string nombre) {
        this->nombre = nombre;
    }

    void Amigo::setTelefono(int telefono) {
        this->telefono = telefono;
    }

    void Amigo::setPeliculaPrestada(Pelicula peliculaPrestada) {
        this->peliculaPrestada = peliculaPrestada;
    }
