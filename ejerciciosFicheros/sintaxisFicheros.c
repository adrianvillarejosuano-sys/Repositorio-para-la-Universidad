#include <stdio.h>

int main() {

FILE *fichero;

// Abre un fichero en modo escritura.
    fichero = fopen("fichero_escritura.txt","w");

//Abre un fichero en modo lectura.
    fichero = fopen("fichero_lectura.txt","r");

//Abre un fichero en modo lectura y escritura, sin borrar el contenido , podemos leer y modificarlo.
    fichero = fopen("fichero_escrituraLectura.txt","r+");

//Abre un fichero en modo lectura y escritura , borrando el contenido , si no existia se crea.
    fichero = fopen("fichero_escrituraLectura","w+");

//freopen permite direccionar una salida del programa a un fichero especifico.
//Abrir un fichero en modo escritura direccionandolo a la salida estandar(standar output).
    fichero = freopen("ficheroDireccionado.txt","w","stdout");

//Abrir un fichero en modo lectura direccionada a la entrada estandar(standar imput).
    fichero = freopen("ficheroDireccionado.txt","r","stdin");

//Abrir un fichero en modo lectura y escritura direccionado a un error en pantalla.
    fichero = freopen("ficheroDireccionado.txt","r+","stderr");

//Leer una cadena en un fichero
    char linea[100];
    fgets(linea,100,fichero);

//escribir en un fichero:
    fprintf(fichero,"hola");

//limpiar errores del fichero:
    clearerr(fichero);

//comprobacion de errores:
    if(ferror(fichero))
     {

         printf("error en el fichero");

     }

//mensaje de error estandar(muestra la causa del error):
    perror("Ha habido un error en el fichero");

//fread nos permite leer en binario desde un fichero, aqui un ejemplo explicado

//Vamos a reservar una variable en memoria donde se leera el dato añadido:
    int x;

// &x es la direeccion de memoria de la variable donde se guardan los datos (buffer), la escribimos asi para leerla directamente.
// Sizeof(int) nos dira el tamaño del dato a leer que normalmente seran 4 bits.
// 1 es el numero de datos a leer , se puede modificar para cadenas , arrays , o structs.
// "fichero" es el nombre del fichero a leer.

    fread(&x,sizeof(x),1,fichero);

//ejemplo 2 mas completo:

     FILE *fichero1 = NULL;
     char cadenaDatos[36];
     fichero1 = fopen("fichero_ejemplo","rb");
        if (fichero1=NULL)
            {
                printf("error al abrir archivo");
                return 1;
            }   
     fread(cadenaDatos,sizeof(cadenaDatos)-1,1,fichero1);
     // hay que poner el '\0' para que el array no continue sin encontrar el fin de la cadena.
     cadenaDatos[35]='\0';

// fwrite nos permite escribir un bloque de byte sin tener en cuenta el tipo de dato.
// la sintaxis es igual que el read , a continuacion un ejemplo:

     char texto[50];
     fread(&texto,sizeof(texto),1,fichero1);

// importante cerrar los ficheros con fclose(nombre del fichero) antes de terinar el programa porque sino se quedan abiertos:
     fclose(fichero);
     fclose(fichero1);



// equivalencia entre [fgets] y [fread]:

            fread(&cadenaDatos, sizeof(cadenaDatos)-1, 1, fichero1);//esto es binario.
            fgets(cadenaDatos, sizeof(cadenaDatos), fichero1);// hace lo mismo pero en texto.(aqui no hace falta reservar el byte final)

//equivalencia entre [fputs] y [fwrite]:

            fwrite(&cadenaDatos,sizeof(cadenaDatos),1,fichero1);//binario
            fputs(cadenaDatos,fichero1);                        //texto




// Como recorrer un fichero de principio a fin:

     feof(fichero1);

// Posicion de punteros 

     int posicionFichero=0;
     posicionFichero = ftell(fichero1);//En posicion fichero se almacenara la direccion del puntero de fichero1.

     posicionFichero = fseek(fichero1, 10, SEEK_SET); //mueve el puntero 10 bytes desde el origen.
     posicionFichero = fseek(fichero1, -4, SEEK_END); // 4 bytes antes del final
     posicionFichero = fseek(fichero1, 5, SEEK_CUR); // 5 bytes desde la posición actual
     
// fscanf : 

int fscanf(FILE *fichero, const char *formato, ...); // almacena los datos segun el formato y almacena los valores leidos en las variables  



//fin.
}