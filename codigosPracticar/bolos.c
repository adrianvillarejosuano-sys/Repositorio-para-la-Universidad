#include <stdlib.h>
#include <stdio.h>

int main()
{
    struct jugador
    {
        char nombre[50];
        int puntosRondas[10];
        int puntosTotales;
    };
    int jugadores = -1;
    int suma;
    int ganador = 0;

    while(jugadores <= 0 || jugadores > 10)
    {
        printf("cuantos jugadores quieres que participen (10 maximo) : ");
        scanf(" %d", &jugadores);
    }

    printf("\n\n\t hay un total de %d jugadores", jugadores);

    struct jugador numero[jugadores];
    int comparador = numero[0].puntosTotales;

    for(int i = 0; i<jugadores ; i++)
    {
        printf("\n\n Escribe el nombre del jugador numero %d ",i+1);
        scanf(" %49[^\n]", numero[i].nombre);

        printf("\n Escribe sus puntos para cada ronda : ");
        for(int j = 0;j<10;j++)
        {
            printf("\n Ronda %d : ",j+1);
            scanf(" %d", &numero[i].puntosRondas[j]);
            suma = suma + numero[i].puntosRondas[j];
        }
        numero[i].puntosTotales = suma;
        suma = 0;
        
    }

    printf("\ntabla de clasificacion\n");

    for(int k = 0; k<jugadores;k++)
    {
        printf("\njugador : %s", &numero[k].nombre);
        printf("\n sus puntuaciones son :");
        for(int q = 0; q<10;q++)
        {
            printf("En la Ronda %d gano %d puntos , ", q+1 , numero[k].puntosRondas[q]);
        }
        printf("\npuntuacion total = %d ", numero[k].puntosTotales);
        
    }

   
    for(int r = 0 ; r < jugadores ; r++)
    {
        if (comparador < numero[r].puntosTotales)
        {
            comparador = numero[r].puntosTotales;
            ganador = r ;
        }

    }
    printf("\n\nel ganador es %s", numero[ganador].nombre);

    return 0;
}