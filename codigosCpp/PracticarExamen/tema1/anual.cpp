#include "anual.h"

    
    //constructor
    Anual::Anual(int ano) {
        this->ano = ano;
        this->esBisiesto = bisiesto(ano);
        this->primerDia = primerDiaAno(ano);
    }


    //getters
    int Anual::getAno() {
        return this->ano;
    }

    int Anual::anoRef = 1900;
    DiaSemana Anual::diaRef = sabado;

    bool Anual::bisiesto(int ano){

        if ((ano % 4 == 0 && ano % 100 != 0) ) {
            return true;
        } else {
            return false;
        }
        }

    DiaSemana Anual::primerDiaAno(int ano) {
        int diasTranscurridos = 0;

        for (int i = Anual::anoRef; i < ano; i++) {
            if (bisiesto(i)) {
                diasTranscurridos += 366;
            } else {
                diasTranscurridos += 365;
            }
        }

        int diaSemanaIndex = (Anual::diaRef + diasTranscurridos) % 7;
        return (DiaSemana) diaSemanaIndex;
    }

    int Anual::primerDiaNum(enum DiaSemana dia) {
        return (int) dia;
    }