#include<stdlib.h>
#include<stdio.h>

void fwhile(int num);
void dowhile(int num);

int main()
    {
        int x = 100001; // Numero introducido por teclado
        char y = '.'; // caracter usado para elegir el tipo de bucle 

        while(x < -100000 || x > 100000)
        {
            printf("introduce un entero para ver su tabla de multiplicar: ");
            scanf(" %d", &x);
            printf("\n");

        }
        while(y != 'w' && y != 'd')
        
        {

            printf("que tipo de bucle quieres usar , while (w) o do while(d) , pulsa la tecla en parentesis \n");
            scanf(" %c", &y);
            if(y == 'w')
                {
                    fwhile(x);
                }
            else if(y == 'd')
                {
                    dowhile(x);
                }


        }

        return 0;
    }

void fwhile(int num)
    {
        int i = 1; // contador
        int resultado;
        printf("la tabla de los 10 primeros multiplos de %d es: \n", num);
        while(i<=10)
            {
                resultado = num * i;
                printf(" %d * %d = %d \n",num , i , resultado);
                i++;

            }
    }

void dowhile(int num2)
    {
        int j = 1; //contador
        int resultado;

        printf("La tabla de %d es : \n", num2);
        do 
            {
                resultado = num2 * j;
                printf(" %d * %d = %d \n",num2 , j , resultado);
                j++;   

            } while(j <= 10);

    }