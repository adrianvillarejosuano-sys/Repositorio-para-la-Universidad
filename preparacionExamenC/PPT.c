#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int eleccionIA();                   // declaramos la función que decidira que usa la IA.

int conversorEleccion(char e);      // Declaramos la funcion que convertira nuestra decision en un entero.

void jugar(int jugador , int maquina);   // encargada del juego.

int main()
    {
        srand(time(NULL));          // Usaremos esto para que la ia tome decisiones aleatorias.

        char eleccion = 'a';
        int valido = 0;

        
        while(eleccion != 'e')
            {
                printf("\n\t\t=====BIENVENIDO A PIEDRA , PAPEL O TIJERA =====\n");
                printf("\n\t Elige tu opción : \n\t piedra(r) \n\t papel(p) \n\t tijeras(t)\n\t O pulsa (e) para salir: \n\t");
                valido = 0;
                while (!valido) 
                    {
             
                        scanf(" %c", &eleccion);  // espacio antes de %c para ignorar saltos de linea

                        if (eleccion == 'r' || eleccion == 'p' || eleccion == 't') 
                            {
                                valido = 1;
                            } 
                        else
                            {
                                printf("Opcion incorrecta. Intentalo de nuevo.\n");
                            }
                    }
        
                jugar(conversorEleccion(eleccion),eleccionIA());

            }
            return 0;
    }

int eleccionIA()
    {
        int decision;
        decision = rand() % 3 + 1;
        return decision;

    }
int conversorEleccion(char e)
    {
        int decision = 0;

        if(e == 'r')
            {
                decision = 1;
            }
        else if(e == 'p')
            {
                decision = 2;
            }
        else if(e == 't')
            {
                decision = 3;
            }
        return decision;

    }
void jugar(int jugador , int maquina)
    {
         char eleccionM[50];
         char jugadorC[50];

         if (maquina == 1)
         strcpy(eleccionM, "piedra");
         else if (maquina == 2)
         strcpy(eleccionM, "papel");
         else if (maquina == 3)
         strcpy(eleccionM, "tijeras");

        printf("La maquina ha elegido %s\n", eleccionM);

         if (jugador == 1)
         strcpy(jugadorC, "piedra");
         else if (jugador == 2)
         strcpy(jugadorC, "papel");
         else if (jugador == 3)
         strcpy(jugadorC, "tijeras");

    printf("El jugador ha elegido %s\n", jugadorC);

        if(jugador == 1 && maquina == 3 
        || jugador == 2 && maquina == 1
        || jugador == 3 && maquina == 2)
            {
                printf("gana el jugador\n\n");   //piedra gana a tijeras , tijeras a papel y papel a piedra
            }
        else if(jugador == maquina)
            {
                printf("habeis empatado \n\n");

            }
        else
        printf("gana la maquina\n\n");
        
    }
