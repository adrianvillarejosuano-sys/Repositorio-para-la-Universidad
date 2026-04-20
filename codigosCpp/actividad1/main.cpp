#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "ListaPokemons.h"
#include "Pokemon.h"
using namespace std;

int main(){

    //Apartado 1: abrir el archivo para la lectura.
    //Hace falta poner la raiz del archivo en tu ordenador para que funcionen ifstream y ofstream.
    ifstream apertura("C:\\Users\\adria\\Documents\\codigos-clase\\Repositorio-para-la-Universidad\\codigosCpp\\actividad1\\pokemon_correcto.csv");


    //Apartado 2: tratamiento de posibles errores al abrirlo.
    if(!apertura){
        cout << "Error al abrir el archivo \n"; 
        return -1;
    }

    //Apartado 5: lista declarada fuera del while para que sea accesible después
    poo::ListaPokemons lista;

    //Apartados 3 y 4: leer el archivo línea a línea, extraer campos y crear pokemons con punteros
    string linea;

    //al leer la cabecera , donde viene lo que es cada cosa me estaba dando error
    //asi que usamos getline para saltarnosla
    getline(apertura, linea);
    

    while(!apertura.eof()){
        getline(apertura, linea);

        //esto salta de linea cuando encuentra un espacio vacio,
        //lo tuve que añadir porque sino entraba en un aparente bucle infinito.
        if(linea.empty()) break;;

        //Instancia de istringstream para extraer los campos
        istringstream entrada(linea);

        //Cadenas para cada campo
        string NUMBER, CODE, SERIAL, NAME, TYPE1, TYPE2, COLOR;
        string ABILITY1, ABILITY2, ABILITY_HIDDEN;
        string GENERATION, LEGENDARY, MEGA;
        string HEIGHT, WEIGHT, HP, ATK, DEF, SP_ATK, SP_DEF, SPD, TOTAL;

        //Extraemos cada campo separado por ','
        getline(entrada, NUMBER, ',');
        getline(entrada, CODE, ',');
        getline(entrada, SERIAL, ',');
        getline(entrada, NAME, ',');
        getline(entrada, TYPE1, ',');
        getline(entrada, TYPE2, ',');
        getline(entrada, COLOR, ',');
        getline(entrada, ABILITY1, ',');
        getline(entrada, ABILITY2, ',');
        getline(entrada, ABILITY_HIDDEN, ',');
        getline(entrada, GENERATION, ',');
        getline(entrada, LEGENDARY, ',');
        getline(entrada, MEGA, ',');
        getline(entrada, HEIGHT, ',');
        getline(entrada, WEIGHT, ',');
        getline(entrada, HP, ',');
        getline(entrada, ATK, ',');
        getline(entrada, DEF, ',');
        getline(entrada, SP_ATK, ',');
        getline(entrada, SP_DEF, ',');
        getline(entrada, SPD, ',');
        getline(entrada, TOTAL, ',');


        //Apartado 4: crear un pokemon usando punteros
        //usamos stoi y stod como dice el enunciado que nos permitira
        //convertir cadenas en enteros o decimales.
        poo::Pokemon* p = new poo::Pokemon{
            stoi(NUMBER), stoi(CODE), stoi(SERIAL), NAME, TYPE1,
            TYPE2, COLOR, ABILITY1, ABILITY2, ABILITY_HIDDEN, stoi(GENERATION),
            stoi(LEGENDARY), stoi(MEGA), stod(HEIGHT), stod(WEIGHT),
            stoi(HP), stoi(ATK), stoi(DEF), stoi(SP_ATK), stoi(SP_DEF),
            stoi(SPD), stoi(TOTAL)
        };

        //Apartado 5: añadimos los pokemons a la lista.
        lista.concatena(p);
    }

    //Cerramos el archivo de lectura , si se deja abierto puede dar errores.
    apertura.close();

    //Apartado 6: crear un archivo que escriba los datos que hemos leido 
    //NOTA IMPORTANTE: a mi sin poner la raiz del archivo en mi ordenador no me lo creaba.
    ofstream nuevo {"C:/Users/adria/Documents/codigos-clase/Repositorio-para-la-Universidad/codigosCpp/actividad1/nuevo.txt"};

    if(!nuevo){
        cout << "error al crear el archivo: " << "\n";
        return -1;
    }

    cout << "archivo creado correctamente\n";


    //Bucle for para escribir los elementos de la lista en el nuevo archivo
    for(int i = 0; i < lista.longitud(); i++){
        poo::Pokemon* p = lista.getElemento(i);
        nuevo << p->getNUMBER() << ","
              << p->getCODE() << ","
              << p->getSERIAL() << ","
              << p->getNAME() << ","
              << p->getTYPE1() << ","
              << p->getTYPE2() << ","
              << p->getCOLOR() << ","
              << p->getABILITY1() << ","
              << p->getABILITY2() << ","
              << p->getHIDDEN() << ","
              << p->getGENERATION() << ","
              << p->getLEGENDARY() << ","
              << p->getMEGA() << ","
              << p->getHEIGHT() << ","
              << p->getWEIGHT() << ","
              << p->getHP() << ","
              << p->getATK() << ","
              << p->getDEF() << ","
              << p->getSP_ATK() << ","
              << p->getSP_DEF() << ","
              << p->getSPD() << ","
              << p->getTOTAL() << "\n";
    }

    // Cerramos el archivo de escritura
    nuevo.close();

    //A la hora de comparar los archivos el nuevo es una linea mas pequeño ya que no cuenta con la primera
    //linea donde viene lo que es cada cosa , si quisieramos obligatoriamente que sean iguales 
    //podriamos eliminar esa linea del .csv , en mi caso le pido al codigo que la salte ya que al leerla 
    //usando stoi da error ya que recibe una string en vez de un numero y da error;
    //creo que se podria poner de alguna manera que el get revise con un if que tipo de valor recibe antes
    //de decidir si usa stoi o no pero no me queda mas tiempo para revisar el codigo bien.

    return 0;
}