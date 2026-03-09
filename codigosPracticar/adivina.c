#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int pequeño()
{    
    int numeros[10];
     for(int i = 0 ; i<10 ; i++)
    {
        numeros[i] = rand() % 100 + 1;          //Definimos los numeros aleatorios con un bucle.
    }
    int masPequeño = numeros[0];

    for(int i = 0 ; i<10 ; i++)
    {
        if(masPequeño > numeros[i])
        {
            masPequeño = numeros[i];
        }
    }

    return masPequeño;
}

int grande()
{   
     int numeros[10];
     for(int i = 0 ; i<10 ; i++)
    {
        numeros[i] = rand() % 100 + 1;          //Definimos los numeros aleatorios con un bucle.
    }
    int masGrande = numeros[0];

    for(int i = 0 ; i<10 ; i++)
    {
        if(masGrande > numeros[i])
        {
            masGrande = numeros[i];
        }
    }
   
}

int main ()
{
    char nuevaPartida = 'n';
    while(nuevaPartida == 'n')
    {
    char eleccion;
    int resultado = 0;
    int numeroElegido;
    int numeroSecreto;
    int intentos = 5;
    srand(time(NULL));

    printf("Elige el reto , ¿quieres adivinar el menor o el mayor?\n");
    printf("\tpulsa (m) para el menor o (M) para el mayor : ");                 // el ususario da la opcion por teclado
    scanf(" %c", &eleccion);

    while(eleccion != 'm' && eleccion != 'M')
    {
        printf("\ncaracter incorrecto prueba otra vez : ");
        printf("\tpulsa (m) para el menor o (M) para el mayor : ");             // revisamos que no ponga mal el caracter
        scanf(" %c", &eleccion);

    }

    if(eleccion == 'm')
    {
        printf("\ntendras que adivinar el numero mas pequeño.\n");
        numeroSecreto = pequeño();

        while(intentos > 0 && resultado == 0)
        {
            printf("\n elige un numero en busca del mas pequeño : ");
            scanf(" %d", &numeroElegido);
            if(numeroElegido == numeroSecreto)
                {
                    printf(" \nAcertaste el numero era %d", numeroSecreto);
                    resultado = 1;
                }
            else if(numeroElegido != numeroSecreto)
                {
                    intentos--;
                    if(intentos > 0)
                    {
                    printf("\nhas fallado vuelve a intentarlo , te quedan %d intentos ",intentos);
                    }
                }

        }

        if(resultado == 0)
        {
            printf("has perdido , el numero era : %d ", numeroSecreto);
        }

    }

    else if(eleccion == 'M')
    {
         printf("\ntendras que adivinar el numero mas grande.\n");
        numeroSecreto = grande();

        while(intentos > 0 && resultado == 0)
        {
            printf("\n elige un numero en busca del mas grande : ");
            scanf(" %d", &numeroElegido);
            if(numeroElegido == numeroSecreto)
                {
                    printf(" \nAcertaste el numero era %d", numeroSecreto);
                    resultado = 1;
                }
            else if(numeroElegido != numeroSecreto)
                {
                    intentos--;
                    if(intentos > 0)
                    {
                    printf("\nhas fallado vuelve a intentarlo , te quedan %d intentos ",intentos);
                    }
                }

        }

        if(resultado == 0)
        {
            printf("has perdido , el numero era : %d ", numeroSecreto);
        }

    }

    printf("\n\t ¿Quieres jugar otra partida con nuevos numeros?, pulsa n para jugar otra partida\n");
    scanf(" %c", &nuevaPartida);
    }
    return 0;
}