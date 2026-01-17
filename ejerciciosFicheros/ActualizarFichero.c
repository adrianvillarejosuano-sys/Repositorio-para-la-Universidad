#include <stdio.h>


void tablaF(int eleccion , int turn)
   //Esta funcion se llamara para ver las puntuaciones a partir de un fichero 
   //Se la debe llamar al usar tabla de puntuaciones en el menu de la aplcacion.
   //Se le debe llamar cada vez que alguien gane una patida.

   // la variable eleccion sera para marcar si hemos entrado desde el menu de puntuaciones o desde el final de una partida.
   // la variable turn recibira el numero de turnos que ha durado la partida , si se llama desde el menu se debe escribir como 0.

    {
        #define MAX_RESULTADOS 3 // Constante que define el maximo de resultados del ranking.

        typedef struct // struct que marca lo que va recibir nuestro fichero para apuntarlo.
            {
                int ganador; // marcara 1 si gano el jugador y 2 si gano la maquina
                int turno;

            }resultado;
        
        FILE *f; // f es un puntero que se dirige al fichero que contendra el ranking.
        
        int total = 0;      // contador para llevar el numero de resultados almacenados hasta 3
        int i;              // contador para mostrar resultados actuales
        int j;              // contador para comparar nuevos resultados y ordenar la lista
        int k;              // igual que j
        int l;              // contador para escribir los nuevos resultados
        //contadores

        resultado ranking[MAX_RESULTADOS +1]; //he puesto +1 para que guarde 4 datos de manera que borre el peor sin saturarse cuando ya tenga 3.
           
        if (eleccion == 0) // cuando entremos mediante el menu.
            {
                printf("\n=== MEJORES RESULTADOS ===\n");
                f = fopen("ranking.txt","r");
                if (f != NULL) // revisa que el archivo existe,si abres rankings sin haaber jugado no mostrara nada.
                    {
                        while(fscanf(f, "%d %d", &ranking[total].ganador, &ranking[total].turno) == 2) // bucle que lee los resultados de las 3 mejores partidas 
                            { 
                                total++; 
                            }
                        fclose(f); // una vez leido cierra el fichero
                    }
                for(i = 0 ; i <total ; i++)
                    {
                        printf("%d. %s - %d turnos \n", i+1 , ranking[i].ganador == 1 ? "jugador" : "Maquina", ranking[i].turno); //Muestra el puesto en el podio , escribe si es maquina o jugador y pone sus turnos.
                    }
            }

        if (eleccion == 1 || eleccion == 2) // volvemos a leer los resultados
            {
                f = fopen("ranking.txt","r");
                if (f != NULL) 
                    {
                        while(fscanf(f, "%d %d", &ranking[total].ganador, &ranking[total].turno) == 2) 
                            { 
                                total++; 
                            }
                        fclose(f);  
                    }

                ranking[total].ganador = eleccion;  // decide el ganador de la partida
                ranking[total].turno = turn; // marca los turnos
                total++; // pasa al siguiente 


                 for ( j = 0; j < total - 1; j++)
                    {
                        for (j = k + 1; k < total; k++) 
                            {
                                if (ranking[k].turno < ranking[j].turno) // usamos un bucle de 2 contadores con un struct temporaral para ordenar los resultados
                                        {
                                        resultado temp = ranking[j];
                                        ranking[j] = ranking[k];
                                        ranking[k] = temp;
                                        }
                             }
                    }

                    if (total > MAX_RESULTADOS) // conserva solo los 3 mejores resultados.
                        {
                         total = MAX_RESULTADOS;
                        }

                    f = fopen("ranking.txt","w");
                        for(l = 0; l < total ; l++) // escribe los nuevos resultados.
                            {
                                fprintf(f, "%d %d", ranking[l].ganador , ranking[l].turno);

                            }
                    fclose(f);

            }
    }