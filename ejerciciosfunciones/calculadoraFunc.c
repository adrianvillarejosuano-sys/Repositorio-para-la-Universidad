#include<stdlib.h>
#include<stdio.h>

void suma (int num1 , int num2 , int *res)
    {
        *res = num1+num2;
    }
void resta (int num1 , int num2 , int *res)
    {
        *res = num1 - num2;
    }
void multiplicacion (int num1 , int num2 , int *res)
    {
        *res = num1 * num2;
    }
void division (int num1 , int num2 , int *res)
    {
        *res = num1/num2;
    }
int main() {

    int num1 = 0;
    int num2 = 0;
    int result = 0;
    char eleccion;
    int salida = 0;

while(salida == 0)
{
       printf("\t\n\t CALCULADORA \n\t Elige la operación: + - * / o pulsa 's' para salir.\n\t");
    scanf(" %c", &eleccion);
    switch (eleccion)
    {
    case '+' :
        printf("\n\t dime los dos numeros que quieres sumar\n");

        scanf("%d", &num1);
        scanf("%d", &num2);
        suma(num1, num2 , &result);
        printf("\n el resultado es %d", result);
    break;

    case '-' :
        printf("\n\t dime los dos numeros que quieras restar tal que a - b: \n\t");
        printf("numero 1 : \n\t");
        scanf("%d",&num1);
        printf("numero 2 : ");
        scanf("%d",&num2);
        resta(num1 , num2 , &result);
        printf("el resultado de la resta es: %d", result);
    break;

    case '*' :
        printf("\n\t dime dos numeros que multiplicar \n\t");
        printf("numero 1 : \n\t");
        scanf("%d",&num1);
        printf("numero 2 : ");
        scanf("%d",&num2);
        multiplicacion(num1,num2,&result);
        printf("el resultado de la multiplicación es: %d", result);
    break;

    case '/' :
        printf("\n\t dime dos numeros que dividir \n\t");
        
        printf("numero 1 : \n\t");
        scanf("%d",&num1);
        printf("numero 2 : ");
        scanf("%d",&num2);
        while(num2 == 0)
            {
                printf("recuerda no dividir entre 0 \n\t");
                scanf("%d",&num2);
            }
        division(num1,num2,&result);
        printf("el resultado de la division es : %d", result);

    break;
    
    case 's' : 
    salida = 1;
    break;

    default:
    printf("opcion no valida");
    break;
    }
}
    return 0;
}