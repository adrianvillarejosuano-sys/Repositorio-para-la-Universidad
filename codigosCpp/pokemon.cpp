#include <iostream>
#include <string>
using namespace std;

class pokemon 
    {
        public:
        //nombre del pokemon
        string nombre{"desconocido"};

        //tipo del pokemon
        string tipo{"???"};

        //nivel
        int nivel{0};

        //vida
        double vida{1};

        //ataque
        double ataque{0};

        //defensa
        double defensa{1};

        //combate del pokemon
        void combate(pokemon& amigo , pokemon& enemigo){

            double daño = (amigo.ataque / enemigo.defensa);
            enemigo.vida -= daño ;

            if (enemigo.vida < 0)
                enemigo.vida = 0;
            
                cout << amigo.nombre << " ataca a " << enemigo.nombre << "/n";
                cout << "inflige " << daño << "puntos de daño \n";

        }

        //constructor por defecto y parametrizado 
        pokemon(string nombre,string tipo, int nivel , double vida, double ataque, double defensa )
        {
            this->nombre = nombre ;
            this->tipo = tipo;
            this-> nivel = nivel;
            this->vida = vida;
            this-> ataque = ataque;
            this-> defensa = defensa;

        }

        //destructor
        ~pokemon(){
            cout << "dtor pokemon" << endl;
        }

        //revisa si sigue vivo el pokemon
        bool estaDebilitado(){
            return vida <= 0;
        }
    };

int main()
{

   

    return 0;
}