#include <stdlib.h>
#include <stdio.h>

#define TAM 12
#define AGUA 'A'
#define BARCO 'B'

void salir ();
void jugar ();
void clasificaciones ();
void tablero();
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

void mostrarTablero (char t[TAM][TAM]){
    int i, j;
    printf("   ");
    for (i = 0; i < TAM; i++)
    printf("%2d ", i + 1);
    printf("\n");


    for (i = 0; i < TAM; i++){
        printf("%2d ", i + 1);
        for (j = 0; j < TAM; j++){
            if (t[i][j] == AGUA)
            printf(" * ");
            else
            printf(" %c ", t[i][j]);
        }
        printf("\n");
    }
}

void inicializarTablero (char t[TAM][TAM]){

    for (int i = 0; i < TAM; i++)//Con esto estoy definiendo los tamaños de cada lado del tablero
    for (int j = 0; j < TAM; j++)
    t[i][j] = AGUA;
}

int main() {
   
    char opcionElegida;

    printf("\t BIENVENIDO A HUNDIR LA FLOTA\n\n");

    printf("\t\t MENU DE INICIO \n\n \t Selecciona una opcion : \n\n\t Empezar a jugar (p) \n\t Ver mejores puntuaciones (m)\n\t Salir del juego (s) \n\t");

    scanf(" %c" , &opcionElegida);
    printf("\n");

    while(opcionElegida != 's' && opcionElegida != 'p' && opcionElegida != 'm'){

        printf("selecciona una opcion valida (m), (s), (p): ");
        scanf(" %c" , &opcionElegida);

    }

    if(opcionElegida == 's'){

        salir();

    }
    else if (opcionElegida == 'p'){

        jugar();

    }
    else if (opcionElegida == 'm'){

        clasificaciones();

    }
    return 0;
}

void salir() {

    printf("\n\thasta la proxima!");
    exit(0);
}

void jugar(){

    printf(" El apartado de jugar no esta completo aún mostrara un tablero con los barcos en posicion fija sobre el tablero :\n\n ");

    tablero();

}

void tablero(){

    int posiciones[12][12]= {0};
    printf("\n\t El barco de 4 casillas es el portaviones ");
    posiciones[1][1] = 1;
    posiciones[1][2] = 1;
    posiciones[1][3] = 1;
    posiciones[1][4] = 1;

    printf("\n\t Los barcos de tres posiciones son cruceros ");
    posiciones[3][4] = 1;
    posiciones[3][5] = 1;
    posiciones[3][6] = 1;

    posiciones[3][7] = 1;
    posiciones[4][7] = 1;
    posiciones[5][7] = 1;

    printf("\n\t Los barcos de 2 posiciones son patrulleros ");
    posiciones[11][11] = 1;
    posiciones[10][11] = 1;
    
    posiciones[9][9] = 1;
    posiciones[8][9] = 1;

    posiciones[2][3] = 1;
    posiciones[2][4] = 1;

    printf("Aqui esta el tablero fijo, los 1 representan la ubicacion de los barcos y los 0 son el mar :\n\n\t");

    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++){
        printf("%d", posiciones[i][j]);
        };
        printf("\n\t");

    }


}

void clasificaciones(){

    printf("no estan las clasificaciones implementadas aún");

}