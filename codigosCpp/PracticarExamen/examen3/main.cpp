#include <iostream>
#include <string>
#include "pelicula.h"
#include "amigo.h"

using namespace std;

int main () {

//creamos varias peliculas
    Pelicula pelicula1("Accion", 2020, false);
    Pelicula pelicula2("Comedia", 2019, false);
    Pelicula pelicula3("Drama", 2021, false);
    Pelicula pelicula4("Accion", 2022, false);

//creamos varios amigos
//le doy una pelicula a cada amigo 

    Amigo amigo1("Juan", 123456789 , pelicula1);
    Amigo amigo2("Maria", 987654321, pelicula2);
    Amigo amigo3("Pedro", 456789123, pelicula3);

//marcamos las peliculas como prestadas
    
    pelicula1.setPrestada(true);
    pelicula2.setPrestada(true);
    pelicula3.setPrestada(true);

//el ususario va a crear su perfil como amigo
    std::string nombreUsuario;
    int telefonoUsuario;
    Pelicula peliculaUsuario;
    int eleccionPelicula;

    std::cout << "Ingrese su nombre: ";
    std::cin >> nombreUsuario;
    std::cout << "Ingrese su telefono: ";
    std::cin >> telefonoUsuario;
    std::cout << "elige una de las 4 peliculas: 1. Accion(2020) 2. Comedia(2019) 3. Drama(2021) 4. Accion(2022):" ;
    std::cin >> eleccionPelicula;

    switch (eleccionPelicula) {
        case 1:
            peliculaUsuario = pelicula1;
            break;
        case 2:
            peliculaUsuario = pelicula2;
            break;
        case 3:
            peliculaUsuario = pelicula3;
            break;
        case 4:
            peliculaUsuario = pelicula4;
            break;
        default:
            std::cout << "Opción no válida." << std::endl;
            return 1;
    }

    //aplicamos la excepcion para ver si podemos prestar la pelicula elegida

    
    try {
        peliculaUsuario.prestarPelicula();
        std::cout << "La pelicula ha sido prestada exitosamente." << std::endl;
    } catch (const char* msg) {
        std::cout << "Error: " << msg << std::endl;
    }

    //en caso de que esta prestada repetiremos el proceso hasta que el usuario elija una pelicula que no este prestada
    while (peliculaUsuario.getPrestada()) {
        std::cout << "La pelicula que elegiste ya esta prestada, elige otra: 1. Accion(2020) 2. Comedia(2019) 3. Drama(2021) 4. Accion(2022):" ;
        std::cin >> eleccionPelicula;

        switch (eleccionPelicula) {
            case 1:
                peliculaUsuario = pelicula1;
                break;
            case 2:
                peliculaUsuario = pelicula2;
                break;
            case 3:
                peliculaUsuario = pelicula3;
                break;
            case 4:
                peliculaUsuario = pelicula4;
                break;
            default:
                std::cout << "Opción no válida." << std::endl;
                return 1;
        }

        try {
            peliculaUsuario.prestarPelicula();
            std::cout << "La pelicula ha sido prestada exitosamente." << std::endl;
        } catch (const char* msg) {
            std::cout << "Error: " << msg << std::endl;
        }
    }
   
    //finalmente creamos el usuario
    Amigo usuario(nombreUsuario, telefonoUsuario, peliculaUsuario);

    //mostramos los datos del usuario y la pelicula que eligio
    std::cout << "Usuario creado: " << usuario.getNombre() << ", Telefono: " << usuario.getTelefono() << std::endl;
    std::cout << "Pelicula elegida: " << usuario.getPeliculaPrestada().getGenero() << ", Fecha: " << usuario.getPeliculaPrestada().getFecha() << std::endl;

    //comparamos la pelicula del usuario con las peliculas de los amigos
    if (usuario.getPeliculaPrestada() == amigo1.getPeliculaPrestada()) {
        std::cout << "Tu pelicula es del mismo genero que la de tu amigo " << amigo1.getNombre() << std::endl;
    } else if (usuario.getPeliculaPrestada() == amigo2.getPeliculaPrestada()) {
        std::cout << "Tu pelicula es del mismo genero que la de tu amigo " << amigo2.getNombre() << std::endl;
    } else if (usuario.getPeliculaPrestada() == amigo3.getPeliculaPrestada()) {
        std::cout << "Tu pelicula es del mismo genero que la de tu amigo " << amigo3.getNombre() << std::endl;
    } else {
        std::cout << "Tu pelicula no es del mismo genero que la de ninguno de tus amigos" << std::endl;
    }


    return 0;
}




