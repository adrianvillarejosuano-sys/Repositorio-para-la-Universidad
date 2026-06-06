#pragma once
#include "diaSemana.h"
#include <string>


class Anual {
   
    public:

        //constructor
        Anual(int ano);

        //atributos
        int ano;
        bool esBisiesto;
        int getAno();
        enum DiaSemana primerDia;
     

        //atributos estaticos
        static int anoRef;
        static DiaSemana diaRef;

        //metodos
        bool bisiesto(int ano);
        std::string diaSemanaToString(enum DiaSemana dia);

        //metodos estaticos
        DiaSemana primerDiaAno(int ano);

    
};