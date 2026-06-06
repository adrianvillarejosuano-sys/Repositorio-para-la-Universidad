#include "anual.h"
#include <string>

    using namespace std;
    
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

        string Anual::diaSemanaToString(enum DiaSemana dia) {
        switch (dia) {
            case lunes:
                return "lunes";
            case martes:
                return "martes";
            case miercoles:
                return "miercoles";
            case jueves:
                return "jueves";
            case viernes:
                return "viernes";
            case sabado:
                return "sabado";
            case domingo:
                return "domingo";
            default:
                return "dia no valido";
        };
    }