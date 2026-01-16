#include <stdio.h>

double cambioF(double num)
    {
        double f;

        f = (num * 9.0 / 5.0) + 32;
        return f;

    }

double cambioC(double num)
    {
        double c;

        c = (num - 32) * 5.0 / 9.0;
        return c;

    }
int main() {

    char eleccion;
    char salida = 0;
    double num;
  
    while(salida != 's')
        {
            printf("Esto es un conversor de grados entre farenheit y celsius,\n\t que cambio quieres hacer, pulsa f para cambio a farenheit , pulsa c para cambio a celsius o pulsa s para salir:");
            scanf(" %c", &eleccion);
            if(eleccion == 's'){
                salida = 's';
                continue;
            }
            printf("\n\tdime un numero para convertir\n\t");
            scanf("%lf",&num);
            switch(eleccion){

             case 'f' :
             printf("tu numero en farenheit es : %f", cambioF(num));

             break;

             case 'c' :
             printf("tu numero en celsius es : %f \n\t",cambioC(num));

             break;

             case 's' :
             salida = 's';

             break;

             default : 
             printf("opcion no valida tigre\n\n\t");
             break;
            }


        }






    return 0;
}