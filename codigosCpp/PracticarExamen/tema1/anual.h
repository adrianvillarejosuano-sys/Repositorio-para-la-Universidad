#pragma once
#include "diaSemana.h"

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
        bool bisiesto(int ano){};
        int primerDiaNum(enum DiaSemana dia);

        //metodos estaticos
        DiaSemana primerDiaAno(int ano);

    
};