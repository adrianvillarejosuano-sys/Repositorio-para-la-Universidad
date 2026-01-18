#include <stdio.h>
#include <stdlib.h>

// Comprueba si quedan barcos en un tablero
int quedanBarcos(char tablero[12][12]) {
    int i, j;
    for (i = 0; i < 12; i++) {
        for (j = 0; j < 12; j++) {
            if (tablero[i][j] == 'B') {
                return 1;
            }
        }
    }
    return 0;
}

// Paso 3: mecánica de disparos
void mecanicaDisparos(char jugador[12][12], char maquina[12][12]) {

    int turnoJugador = 1;
    int fila, col;
    int acierto;

    while (quedanBarcos(jugador) && quedanBarcos(maquina)) {

        if (turnoJugador) {

            do {
                printf("Introduce fila: ");
                scanf("%d", &fila);
                printf("Introduce columna: ");
                scanf("%d", &col);

                if (maquina[fila][col] == 'X' || maquina[fila][col] == 'A') {
                    acierto = 0;
                }
                else if (maquina[fila][col] == 'B') {
                    maquina[fila][col] = 'X';
                    acierto = 1;
                }
                else {
                    maquina[fila][col] = 'A';
                    acierto = 0;
                }

            } while (acierto && quedanBarcos(maquina));

            turnoJugador = 0;

        } else {

            do {
                fila = rand() % 12;
                col = rand() % 12;

                if (jugador[fila][col] == 'X' || jugador[fila][col] == 'A') {
                    acierto = 1;
                }
                else if (jugador[fila][col] == 'B') {
                    jugador[fila][col] = 'X';
                    acierto = 1;
                }
                else {
                    jugador[fila][col] = 'A';
                    acierto = 0;
                }

            } while (acierto && quedanBarcos(jugador));

            turnoJugador = 1;
        }
    }
}