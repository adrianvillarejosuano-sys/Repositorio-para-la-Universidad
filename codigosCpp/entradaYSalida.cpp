#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

    //si el archivo no existe lo crea
    ofstream salida {"salida.txt"};

    //revisamos que se haya creado o exista
    if (! salida){
        cout << "error al abrir el archivo\n";
        return -1;
    }
    salida << "Saludos desde c++\n";
    //se produce la llamada al destructor de salida y se cierra el archivo
    salida.close();

    //ahora la entrada
    ifstream entrada {};
    entrada.open("salida.txt");

    //para saber que se abrio correctamente
    if(! entrada){
        cout << "error al leer el archivo\n";
        return -1;
    }

    //para leer una linea completa se usa `getline´
    // se puede usar el operador >> pero solo lee hasta el primer espacio en blanco
    string cadena{};
    getline (entrada,cadena);

    //cierra el archivo
    entrada.close();

    //mostrar el contenido
    cout << cadena << "\n";

    return 0;
}

