// archivo: Pokemon.h

#pragma once

#include <iostream>
#include <string>

using namespace std;

namespace poo {

    class Pokemon {
    public:

        //constructor añadiendo lo que faltaba
        
        Pokemon();
        Pokemon(int NUMBER, int CODE, int SERIAL, string NAME, string TYPE1, string TYPE2,
                string COLOR, string ABILITY1, string ABILITY2, string ABILITY_HIDDEN,
                int GENERATION, int LEGENDARY, int MEGA_EVOLUTION,
                double HEIGHT, double WEIGHT, int HP, int ATK, int DEF,
                int SP_ATK, int SP_DEF, int SPD, int TOTAL);

        ~Pokemon();

        //getters y setters
        //numero de la pokedex
        int getNUMBER();
        void setNUMBER(int NUMBER);
        //code en el csv se refiere a la forma del pokemon ya sea la habitual o la regional
        int getCODE();
        void setCODE(int CODE);
        //el serial es un entero formado por su numero de la pokedex con su forma detras
        int getSERIAL();
        void setSERIAL(int SERIAL);
        //nombre
        string getNAME();
        void setNAME(string NAME);
        //tipo 1
        string getTYPE1();
        void setTYPE1(string TYPE1);
        //tipo 2
        string getTYPE2();
        void setTYPE2(string TYPE2);
        //color
        string getCOLOR();
        void setCOLOR(string COLOR);
        //habilidad 1
        string getABILITY1();
        void setABILITY1(string ABILITY1);
        //habilidad 2
        string getABILITY2();
        void setABILITY2(string ABILITY2);
        //habilidad oculta
        string getHIDDEN();
        void setHIDDEN(string HIDDEN);
        //generacion 
        int getGENERATION();
        void setGENERATION(int GENERATION);
        //es legendario? 
        int getLEGENDARY();
        void setLEGENDARY(int LEGENDARY);
        //puede megaevolucionar?
        int getMEGA();
        void setMEGA(int MEGA);
        //altura
        double getHEIGHT();
        void setHEIGHT(double HEIGHT);
        //peso
        double getWEIGHT();
        void setWEIGHT(double WEIGHT);
        //vida
        int getHP();
        void setHP(int HP);
        //ataque fisico
        int getATK();
        void setATK(int ATK);
        //defensa fisica
        int getDEF();
        void setDEF(int DEF);
        //ataque especial
        int getSP_ATK();
        void setSP_ATK(int SP_ATK);
        //defensa especial
        int getSP_DEF();
        void setSP_DEF(int SP_DEF);
        //speed
        int getSPD();
        void setSPD(int SPD);
        //suma de estadisticas
        int getTOTAL();
        void setTOTAL(int TOTAL);

        //funcion de ataque
        void attack();

    private:
            //aqui declaramos las 22 variables
        int m_NUMBER{};
        int m_CODE{};
        int m_SERIAL{};
        string m_NAME{};
        string m_TYPE1{};
        string m_TYPE2{};
        string m_COLOR{};
        string m_ABILITY1{};
        string m_ABILITY2{};
        string m_ABILITY_HIDDEN{};
        int m_GENERATION{};
        int m_LEGENDARY{};
        int m_MEGA_EVOLUTION{};
        double m_HEIGHT{};
        double m_WEIGHT{};
        int m_HP{};
        int m_ATK{};
        int m_DEF{};
        int m_SP_ATK{};
        int m_SP_DEF{};
        int m_SPD{};
        int m_TOTAL{};
    };

    //Constructor por defecto
    inline Pokemon::Pokemon() {}

    //Constructor por parametro
    inline Pokemon::Pokemon(int NUMBER, int CODE, int SERIAL, string NAME, string TYPE1, string TYPE2,
                           string COLOR, string ABILITY1, string ABILITY2, string ABILITY_HIDDEN,
                           int GENERATION, int LEGENDARY, int MEGA_EVOLUTION,
                           double HEIGHT, double WEIGHT, int HP, int ATK, int DEF,
                           int SP_ATK, int SP_DEF, int SPD, int TOTAL)
        : m_NUMBER(NUMBER), m_CODE(CODE), m_SERIAL(SERIAL), m_NAME(NAME), m_TYPE1(TYPE1),
          m_TYPE2(TYPE2), m_COLOR(COLOR), m_ABILITY1(ABILITY1), m_ABILITY2(ABILITY2),
          m_ABILITY_HIDDEN(ABILITY_HIDDEN), m_GENERATION(GENERATION),
          m_LEGENDARY(LEGENDARY), m_MEGA_EVOLUTION(MEGA_EVOLUTION),
          m_HEIGHT(HEIGHT), m_WEIGHT(WEIGHT), m_HP(HP), m_ATK(ATK),
          m_DEF(DEF), m_SP_ATK(SP_ATK), m_SP_DEF(SP_DEF),
          m_SPD(SPD), m_TOTAL(TOTAL) {}

    inline Pokemon::~Pokemon() {}

    //utilizo inline para definir los metodos de la clase dentro de la propia cabecera
    inline int Pokemon::getNUMBER() { return m_NUMBER; }
    inline void Pokemon::setNUMBER(int NUMBER) { m_NUMBER = NUMBER; }

    inline int Pokemon::getCODE() { return m_CODE; }
    inline void Pokemon::setCODE(int CODE) { m_CODE = CODE; }

    inline int Pokemon::getSERIAL() { return m_SERIAL; }
    inline void Pokemon::setSERIAL(int SERIAL) { m_SERIAL = SERIAL; }

    inline string Pokemon::getNAME() { return m_NAME; }
    inline void Pokemon::setNAME(string NAME) { m_NAME = NAME; }

    inline string Pokemon::getTYPE1() { return m_TYPE1; }
    inline void Pokemon::setTYPE1(string TYPE1) { m_TYPE1 = TYPE1; }

    inline string Pokemon::getTYPE2() { return m_TYPE2; }
    inline void Pokemon::setTYPE2(string TYPE2) { m_TYPE2 = TYPE2; }

    inline string Pokemon::getCOLOR() { return m_COLOR; }
    inline void Pokemon::setCOLOR(string COLOR) { m_COLOR = COLOR; }

    inline string Pokemon::getABILITY1() { return m_ABILITY1; }
    inline void Pokemon::setABILITY1(string ABILITY1) { m_ABILITY1 = ABILITY1; }

    inline string Pokemon::getABILITY2() { return m_ABILITY2; }
    inline void Pokemon::setABILITY2(string ABILITY2) { m_ABILITY2 = ABILITY2; }

    inline string Pokemon::getHIDDEN() { return m_ABILITY_HIDDEN; }
    inline void Pokemon::setHIDDEN(string HIDDEN) { m_ABILITY_HIDDEN = HIDDEN; }

    inline int Pokemon::getGENERATION() { return m_GENERATION; }
    inline void Pokemon::setGENERATION(int GENERATION) { m_GENERATION = GENERATION; }

    inline int Pokemon::getLEGENDARY() { return m_LEGENDARY; }
    inline void Pokemon::setLEGENDARY(int LEGENDARY) { m_LEGENDARY = LEGENDARY; }

    inline int Pokemon::getMEGA() { return m_MEGA_EVOLUTION; }
    inline void Pokemon::setMEGA(int MEGA) { m_MEGA_EVOLUTION = MEGA; }

    inline double Pokemon::getHEIGHT() { return m_HEIGHT; }
    inline void Pokemon::setHEIGHT(double HEIGHT) { m_HEIGHT = HEIGHT; }

    inline double Pokemon::getWEIGHT() { return m_WEIGHT; }
    inline void Pokemon::setWEIGHT(double WEIGHT) { m_WEIGHT = WEIGHT; }

    inline int Pokemon::getHP() { return m_HP; }
    inline void Pokemon::setHP(int HP) { m_HP = HP; }

    inline int Pokemon::getATK() { return m_ATK; }
    inline void Pokemon::setATK(int ATK) { m_ATK = ATK; }

    inline int Pokemon::getDEF() { return m_DEF; }
    inline void Pokemon::setDEF(int DEF) { m_DEF = DEF; }

    inline int Pokemon::getSP_ATK() { return m_SP_ATK; }
    inline void Pokemon::setSP_ATK(int SP_ATK) { m_SP_ATK = SP_ATK; }

    inline int Pokemon::getSP_DEF() { return m_SP_DEF; }
    inline void Pokemon::setSP_DEF(int SP_DEF) { m_SP_DEF = SP_DEF; }

    inline int Pokemon::getSPD() { return m_SPD; }
    inline void Pokemon::setSPD(int SPD) { m_SPD = SPD; }

    inline int Pokemon::getTOTAL() { return m_TOTAL; }
    inline void Pokemon::setTOTAL(int TOTAL) { m_TOTAL = TOTAL; }

    //metodo de ataque
    inline void Pokemon::attack() {
        m_HP = m_HP * 0.9; // pierde 10% de vida
    }

}