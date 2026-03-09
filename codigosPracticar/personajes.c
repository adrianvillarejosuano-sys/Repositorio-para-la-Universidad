#include <stdio.h>
#include <stdlib.h>

int main()
{
    typedef struct  
    {
    char nombre[50];                // struct de los personajes
    int nivel;
    int poder;
    char clase;
    } Personaje;

    Personaje *personajes = NULL;  // lista dinámica
    int cantidad = 0;              // cuántos hay realmente
    int masPoder = 0;
    int masNivel = 0;
    int numMasPoder = 0;
    int numMasNivel = 0;

    char eleccion; // El usuario elegira una opcion del menu.
    while(1)
    {
        printf("\n\t---MENU DEL JUEGO---\n");
        printf("Selecciona una opcion:\n Registrar un nuevo personaje(r)\n mostrar la lista de personajes(p)\n Mostrar el personaje con mayor poder(m) \n Personaje con nivel mas alto(l) \n");
        printf("\n O pulsa q para salir \n");
        scanf(" %c", &eleccion);

        if(eleccion == 'q')
        {
            break;
        }
        if (eleccion == 'r')            // Creacion de personajes
        {
            cantidad++;
            Personaje *temp = realloc(personajes, cantidad * sizeof(Personaje));
            if (temp == NULL) 
            {
            printf("Error de memoria\n");
            free(personajes);
            return 1;
            }
            personajes = temp;


            printf("\nhora de crear un nuevo personaje: \n");
            printf("Nombre: ");
            scanf(" %49[^\n]", personajes[cantidad - 1].nombre);

            printf("\nnivel: ");
            scanf("%d", &personajes[cantidad - 1].nivel);

            printf("\npoder: ");
            scanf("%d", &personajes[cantidad - 1].poder);

            printf("\nClase : (guerrero = g) (arquero = a) (mago = m) ");
            scanf(" %c", &personajes[cantidad-1].clase);

            if(personajes[cantidad-1].clase != 'g' && personajes[cantidad-1].clase != 'a' && personajes[cantidad-1].clase != 'm')
            {
                personajes[cantidad-1].clase = 's';   //sin clase
            }
 
        }

        if (eleccion == 'p')                //Lista de personajes
        {
            printf("\nlista de jugadores\n");
            if(cantidad = 0)
            {
                printf("no hay personajes creados aun\n");

            }
            for(int i=0 ; i<cantidad ; i++)
            {
                printf("Personaje %d\n",i);
                printf("nombre: %s", personajes[i].nombre);
                printf("nivel: %s", personajes[i].nivel);
                printf("poder: %s", personajes[i].poder);
                if(personajes[i].clase == 'g')
                {
                    printf("clase : guerrero\n");
                }

                else if(personajes[i].clase == 'a')
                {
                    printf("clase : arquero\n");
                }
                else if(personajes[i].clase == 'm')
                {
                    printf("clase : mago\n");
                }
                else if(personajes[i].clase == 's')
                {
                    printf("clase : --- \n");
                }
            }
        }

        if(eleccion == 'm')
        {
            masPoder = personajes[0].poder;
            for(int j = 0 ; j<cantidad ; j++)
            {
                if (masPoder < personajes[j].poder)
                {
                    masPoder = personajes[j].poder;
                    numMasPoder = j;
                }

            }

            printf("\n\tEl personaje con mas poder es %s con %d de poder", personajes[numMasPoder].nombre , masPoder);
        }

        if(eleccion == 'l')
        {
            masPoder = personajes[0].poder;
            for(int k = 0 ; k<cantidad ; k++)
            {
                if (masPoder < personajes[k].poder)
                {
                    masNivel = personajes[k].nivel;
                    numMasNivel = k;
                }

            }

            printf("\n\tEl personaje con mas nivel es %s con nivel %d", personajes[numMasPoder].nombre , masNivel);
        }

        
    }
    return 0;
}
