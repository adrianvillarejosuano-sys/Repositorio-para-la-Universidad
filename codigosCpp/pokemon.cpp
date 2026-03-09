#include <iostream>
#include <string>


class pokemon 
    {
        public:
        //nombre del pokemon
        std::string nombre;

        //tipo del pokemon
        std::string tipo;

        //nivel
        int nivel;

        //vida
        double vida;

        //ataque del pokemon
        void ataque(pokemon& enemigo){

            enemigo.vida = enemigo.vida * 0.9;

        };
    };

int main()
{

    pokemon pikachu;

        pikachu.vida = 70.0;
        pikachu.nombre = "pikachu";
        pikachu.tipo = "electrico";
        pikachu.nivel = 25;

    pokemon charmander;

        charmander.vida = pikachu.vida;
    
   pikachu.ataque(charmander);

   charmander.ataque(pikachu);

   std::cout << pikachu.nombre << " tiene " << pikachu.vida << " de vida\n";
   std::cout << charmander.nombre << " tiene " << charmander.vida << " de vida\n";

   // esperar antes de cerrar la consola
    std::cout << "Presiona ENTER para salir...";
    std::cin.get();

    return 0;
}