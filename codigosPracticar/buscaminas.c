#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define minas 5
#define filas 10
#define columnas 10
//Juego del buscaminas

int main()
    {
        char campo[filas][columnas];
        int minasColocadas = 0;
        int turno = (filas * columnas) - minas;
        int fila;
        int col;

        printf("bienvenido a buscaminas\n");
        for(int i=0;i<=9;i++)
            {
                for(int j=0;j<=9;j++)
                {
                    campo[i][j] = 'x';
                    printf("%c",campo[i][j]);                    
                }
                printf("\n");
            }

        while(minasColocadas<minas)
            {
                int f = rand() % 10;
                int c = rand() % 10;

                if(campo[f][c] != 'M')
                    {
                        campo[f][c] = 'M';
                        minasColocadas++;
                    }
            }
        while(turno >= 0)
        {
           
            printf("\n\n Donde quieres revisar , marca las coordenadas:\n");
            printf("Fila: ");
            scanf(" %d", &fila);
            while(fila < 0 || fila > 10)
                {
                    printf("\npon una Fila entre 1 y 10: ");
                    scanf(" %d", &fila);
                }
            printf("\nColumna: ");
            scanf(" %d", &col);
            while(col < 0 || col > 10)
                {
                    printf("\npon una columna entre 1 y 10: ");
                    scanf(" %d", &col);
                }
            if(campo[fila][col] == 'x')
                {
                    printf("\n Ahi no habia una mina");
                    turno--;
                }
            else if(campo[fila][col] == 'M')
            {
                printf("\nHas pisado una mina");
                turno = -1;
                minasColocadas = 0;
            }

            
        }
        if (turno == 0 && minasColocadas == 5)
        {
            printf("\n Has ganado !");
        }
        return 0;
    }