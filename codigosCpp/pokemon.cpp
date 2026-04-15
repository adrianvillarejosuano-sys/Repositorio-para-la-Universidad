#include <iostream>
#include <string>
using namespace std;

class pokemon 
    {
        public:

        //variables estaticas:

        static int total;

        //metodos estaticos:

        static string informe();

        // Asigno entre corchetes los valores por defecto
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

        //constructor parametrizado 
        pokemon(string nombre,string tipo, int nivel , double vida, double ataque, double defensa )
        {
            this->nombre = nombre ;
            this->tipo = tipo;
            this-> nivel = nivel;
            this->vida = vida;
            this-> ataque = ataque;
            this-> defensa = defensa;

            //Cada vez que creemos un objeto se suma una al total
            total++;
        }

        //destructor
        ~pokemon(){
            cout << "destructor pokemon" << endl;
        }

        

        //revisa si sigue vivo el pokemon
        bool estaDebilitado(){
            return vida <= 0;
        }
    };

    //definicion de la variable estatica iniciada en 0
    int pokemon::total{0};
    
    //definimos el informe
    string pokemon::informe(){
        return " numero de pokemons creados :" + to_string(total);
    }

int main()
{

   //Creamos instancias de los pokemon iniciales
   pokemon pikachu("pikachu","electrico",50,100,120,80);
   pokemon charmander("charmander","fuego",50,90,130,65);
   pokemon bulbasur("bulbasur","planta",50,140,80,100);
   pokemon squirtel("squirtel","agua",50,105,105,100);

   //informe de instancias
   cout << pokemon::informe() << " \n";
   cout << "final del main\n";

    return 0;
}