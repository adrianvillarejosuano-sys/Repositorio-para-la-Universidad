#include <stdlib.h>
#include <stdio.h>

int main() {

char personaje;

printf("elige un personaje mago con (m) , guerrero con (g) o arquero con (a):\n");
scanf(" %s", &personaje);

if (personaje != "m" && personaje != "g" && personaje != "a")
    {
    printf("personaje no valido\n");
    }

if (personaje == "m")
    {
        printf("seras un mago\n");
    }
else if (personaje == "g")
    {
        printf("seras un guerrero\n");
    }
else if (personaje == "a")
    {
        printf("seras un arquero\n");
    }
    return 0;
}