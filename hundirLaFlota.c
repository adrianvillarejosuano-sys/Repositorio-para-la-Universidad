#include <stdlib.h>
#include <stdio.h>

void salir ();
void jugar ();
void clasificaciones ();

void tablero();

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