#include <stdio.h>
#include <stdlib.h>

#define TAM 12
#define AGUA 'A'
#define BARCO 'B'

//Cuando escojamos el tablero de quien usar esto no hara falta, lo pongo simplemente para que funcione el codigo

void inicializarTablero (char t[TAM][TAM]){
    for (int i = 0; i < TAM; i++)//Con esto estoy definiendo los tamaños de cada lado del tablero
    for (int j = 0; j < TAM; j++)
    t[i][j] = AGUA;
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

void mostrarTableroCPU (char t[TAM][TAM]){
    int i, j;
    printf("   ");
    for (i = 0; i < TAM; i++)
    printf("%2d ", i + 1);
    printf("\n");


    for (i = 0; i < TAM; i++){
        printf("%2d ", i + 1);
        for (j = 0; j < TAM; j++){
            if (t[i][j] == AGUA || t[i][j] == BARCO)
            printf(" * ");
            else
            printf(" %c ", t[i][j]);
        }
        printf("\n");
    }
}

void colocarBarcosJugador(char t[TAM][TAM]){
    int barcos [6] = {4, 3, 3, 2, 2, 2};
    int fila, col, dir, filaHum, colHum;
    int i, b;
    int valido;
    

    for (b = 0; b < 6; b++){
        valido = 0;

        while (!valido){
            mostrarTablero(t);
            printf("\nColocar barco de tamaño %d\n", barcos[b]);
            printf("Fila inicial: ");
            scanf("%d", &filaHum);
            printf("Columna inicial: ");
            scanf("%d", &colHum);
            fila = filaHum - 1;
            col = colHum - 1;

            printf("\nOpciones disponibles:\n");

            if (col + barcos[b] <= TAM)
            printf("0 - Horizontal hasta (%d,%d)\n", filaHum, colHum + barcos[b] - 1);

            if (fila + barcos[b] <= TAM)
            printf("1 - Vertical hasta (%d,%d)\n", filaHum + barcos[b]  - 1, colHum);

            printf("Elige la orientacion del barco: ");
            scanf("%d", &dir);

            valido = 1;

            if (dir == 0){
                if (col + barcos[b] > TAM)
                valido = 0;

                else{
                    for (i = 0; i < barcos[b]; i++)
                    if (t[fila][col + i] != AGUA)
                    valido = 0;

                    if (valido)
                    for (i = 0; i < barcos[b]; i++)
                    t[fila][col + i] = BARCO;
                }
            }
            else if (dir == 1){
                if (fila + barcos[b] > TAM)
                valido = 0;
                else {
                    for (i = 0; i < barcos[b]; i++)
                    if (t[fila + i][col] != AGUA)
                    valido = 0;

                    if (valido)
                    for (i = 0; i < barcos[b]; i++)
                    t[fila + i][col] = BARCO;
                }
            }
            else{
                valido = 0;
            }

            if (!valido)
            printf("Posicion no valida. Pruebe otra diferente.\n");

        }
    }
}


void colocarBarcosCPU(char t[TAM][TAM]){
    int barcos[6] = {4, 3, 3, 2, 2, 2};
    int x, y, dir;
    int i, b;
    int colocado;

    for (b = 0; b < 6; b++){
        colocado = 0;


        while (!colocado){
            x = rand() % TAM;
            y = rand() % TAM;
            dir = rand() % 2;
            colocado = 1;

            if (dir == 0){
                if (y + barcos[b] > TAM)
                colocado = 0;
                else {
                    for (i = 0; i < barcos[b]; i++)
                    if (t[x][y + i] != AGUA)
                    colocado = 0;

                    if (colocado)
                    for (i = 0; i < barcos[b]; i++)
                    t[x][y + i] = BARCO;
                }
            }
            else{
                if (x + barcos[b] > TAM)
                colocado = 0;

                else{
                    for (i = 0; i < barcos[b]; i++)
                    if (t[x + i][y] != AGUA)
                    colocado = 0;


                    if (colocado)
                    for (i = 0; i < barcos[b]; i++)
                    t[x + i][y] = BARCO;
                }
            }
        }
    }
}


