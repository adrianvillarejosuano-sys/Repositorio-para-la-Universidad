#include <stdio.h>
#include <stdlib.h>
#define cuadrado(x) (x*x)

int main(){

printf("dime un numero que quieras elevar al cuadrado:\n");
int numero;
scanf(" %d", &numero);

printf("el cuadrado de %d es %d\n", numero , cuadrado(numero));
return 0;
}