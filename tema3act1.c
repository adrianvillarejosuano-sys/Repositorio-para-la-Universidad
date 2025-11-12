#include <stdlib.h>
#include <stdio.h>


int main(){

int i;
for(i=1;i<=10;i++){
    if (i==5)
     {
        goto salida;
     };
    };

salida:
printf("ha salido del bucle tras llegar a %d", i);
return 0;
}