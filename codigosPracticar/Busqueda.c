#include <stdio.h>
#include <stdlib.h>
#include <time.h>




    void jugar()
{
    // declaro las variables de la funcion jugar
    srand(time(NULL));
    int tesoro = rand() % 5 + 1;        // numero aleatorio entre 1 y 5 
    int eleccion = 0;                   // variable para que elija que hacer
    int posicionActual = 1;             // variable que guarda su posicion con un entero , tambien podria hacerse con un array pero asi lo vi mas comodo
    int vidas = 3;                      // vidas , podria hacerse con un define pero necesitariamos igualmente una variable contador
    int victoria = 0;                   // variable que decide si ganamos o perdemos

    while(victoria == 0 && vidas > 0)    // condición para que siga el juego adelante
    {
        eleccion = 0;                     // reinicio en cada iteracion la variable eleccion para que no se quede en bucle con la misma
        
        while(eleccion <= 0 || eleccion >= 4)
        {
            printf("\n\ttoma tu decision, pulsa 1 para avanzar , 2 para retroceder o 3 para abrir el cofre\n\t");
            scanf("%d", &eleccion);
            
        }

        
        if(eleccion == 1)
        {
            if(posicionActual < 5)      // nos fijamos de que no se pase de 5
            {
                posicionActual++;
                printf("\nestas en la sala numero %d", posicionActual);
            }
            else
            {
                printf("\nno puedes avanzar mas");
            }
        }

        else if(eleccion == 2)
        {
            if(posicionActual > 1)      // nos fijamos que no retroceda de mas
            {
                posicionActual--;
                printf("\nestas en la sala numero %d", posicionActual);
            }
            else
            {
                printf("\nno puedes retroceder mas");
            }
        }

        else if(eleccion == 3)
        {
            if(posicionActual == tesoro)        // revisamos que este ahi el tesoro
            {
                printf("\nencontraste el tesoro!");     // jugador gana
                victoria = 1;
            }
            else    
            {
                printf("\n has fallado y has perdido una vida\n");
                vidas--;
                printf("te quedan %d vidas", vidas);
                if(vidas == 0)
                {
                    victoria = -1;                      // jugador pierde
                }           
            }
        }
    }

    if(victoria == 1)
    {
        printf("\nhas ganado!");
    }
    else if(victoria == -1)
    {
        printf("\nhas perdido , te quedaste sin vidas.");
    }
}


int main() 
{
     // variables de la funcion main
    char eleccion;         // caracter que pondra el usuario por teclado
    int salida = 0;        // variable entera que dependiendo de su valor saldra del programa
    int nuevaPartida = 0;  // variable para jugar varias partidas

    while(salida == 0)
    {
        printf("Bienvenido al juego de buscar el tesoro pulsa (p) para jugar o (s) para salir\n");      // menu de juego
        scanf(" %c", &eleccion);

        if(eleccion == 'p')
        {
            jugar();

            while(nuevaPartida == 0)
            {
                printf("\n\t Quieres jugar de nuevo? pulsa 1 para si o cualquier otro numero (que no sea 0) para no \n\t");    // menu interno tras terminar una partida
                scanf(" %d", &nuevaPartida);
                if (nuevaPartida == 1)
                {

                    jugar();            // si quiere jugar otra partida vuelve a la funcion jugar
                    nuevaPartida = 0;   // volvemos a poner esto a 0 por si quiere jugar mas aun

                }
                else 
                {

                    salida = 1;         // si el jugador no quiere jugar mas sale de los bucles y acaba el programa

                }
            }
        }
        else if (eleccion == 's')       // si el jugador pulsa s en el menu saldra del bucle y terminara el programa
        {
            salida = 1;

        }

    }

    return 0;


}