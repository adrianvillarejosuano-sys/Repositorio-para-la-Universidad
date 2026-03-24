#include <iostream>
#include <string>
using namespace std;

class pokemon 
{
public:

    string nombre;
    double vida;
    double ataque;

    //Constructor por defecto
    pokemon();

    //constructor por parametros
    pokemon(string nombre , double vida , double ataque)
    {
        this->nombre = nombre;
        this->vida = vida;
        this->ataque = ataque;
    }

    void ataca();

};

//definicion del constructor por defecto
pokemon::pokemon()
{
nombre = "Desconocido";
vida = 0;
ataque = 0;
}

int main()
{
//Crea una instancia de la clase pokemon
pokemon pikachu;    //usando constructor por defecto
pokemon mew ("mew" , 100 , 100);    //usando constructor por parametros

cout << "nombre = " << pikachu.nombre <<"\n";
cout << "vida = " << pikachu.vida << "\n";
cout << "ataque = " << pikachu.ataque << "\n";

cout << "nombre = " << mew.nombre <<"\n";
cout << "vida = " << mew.vida << "\n";
cout << "ataque = " << mew.ataque << "\n";

}