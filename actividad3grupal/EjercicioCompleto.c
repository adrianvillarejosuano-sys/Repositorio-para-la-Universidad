#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#define TAM 12
#define AGUA 'A'
#define BARCO 'B'
#define Tocado 'X'
#define mar '*'

void tablaF(int eleccion , int turn)
   //Esta funcion se llamara para ver las puntuaciones a partir de un fichero 
   //Se la debe llamar al usar tabla de puntuaciones en el menu de la aplcacion.
   //Se le debe llamar cada vez que alguien gane una patida.

   // la variable eleccion sera para marcar si hemos entrado desde el menu de puntuaciones o desde el final de una partida.
   // la variable turn recibira el numero de turnos que ha durado la partida , si se llama desde el menu se debe escribir como 0.

    {
        #define MAX_RESULTADOS 3 // Constante que define el maximo de resultados del ranking.

        typedef struct // struct que marca lo que va recibir nuestro fichero para apuntarlo.
            {
                int ganador; // marcara 1 si gano el jugador y 2 si gano la maquina
                int turno;

            }resultado;
        
        FILE *f; // f es un puntero que se dirige al fichero que contendra el ranking.
        
        int total = 0;      // contador para llevar el numero de resultados almacenados hasta 3
        int i;              // contador para mostrar resultados actuales
        int j;              // contador para comparar nuevos resultados y ordenar la lista
        int k;              // igual que j
        int l;              // contador para escribir los nuevos resultados
        //contadores

        resultado ranking[MAX_RESULTADOS +1]; //he puesto +1 para que guarde 4 datos de manera que borre el peor sin saturarse cuando ya tenga 3.
           
        if (eleccion == 0) // cuando entremos mediante el menu.
            {
                printf("\n=== MEJORES RESULTADOS ===\n");
                f = fopen("ranking.txt","r");
                if (f != NULL) // revisa que el archivo existe,si abres rankings sin haaber jugado no mostrara nada.
                    {
                        while(fscanf(f, "%d %d", &ranking[total].ganador, &ranking[total].turno) == 2) // bucle que lee los resultados de las 3 mejores partidas 
                            { 
                                total++; 
                            }
                        fclose(f); // una vez leido cierra el fichero
                    }
                for(i = 0 ; i <total ; i++)
                    {
                        printf("%d. %s - %d turnos \n", i+1 , ranking[i].ganador == 1 ? "jugador" : "Maquina", ranking[i].turno); //Muestra el puesto en el podio , escribe si es maquina o jugador y pone sus turnos.
                    }
            }

        if (eleccion == 1 || eleccion == 2) // volvemos a leer los resultados
            {
                f = fopen("ranking.txt","r");
                if (f != NULL) 
                    {
                        while(fscanf(f, "%d %d", &ranking[total].ganador, &ranking[total].turno) == 2) 
                            { 
                                total++; 
                            }
                        fclose(f);  
                    }

                ranking[total].ganador = eleccion;  // decide el ganador de la partida
                ranking[total].turno = turn; // marca los turnos
                total++; // pasa al siguiente 


                 for ( j = 0; j < total - 1; j++)
                    {
                        for (j = k + 1; k < total; k++) 
                            {
                                if (ranking[k].turno < ranking[j].turno) // usamos un bucle de 2 contadores con un struct temporaral para ordenar los resultados
                                        {
                                        resultado temp = ranking[j];
                                        ranking[j] = ranking[k];
                                        ranking[k] = temp;
                                        }
                             }
                    }

                    if (total > MAX_RESULTADOS) // conserva solo los 3 mejores resultados.
                        {
                         total = MAX_RESULTADOS;
                        }

                    f = fopen("ranking.txt","w");
                        for(l = 0; l < total ; l++) // escribe los nuevos resultados.
                            {
                                fprintf(f, "%d %d", ranking[l].ganador , ranking[l].turno);

                            }
                    fclose(f);

            }
    }

void salir ();

void jugar ();

void clasificaciones ();

void tablero();

void inicializarTablero (char t[TAM][TAM]){

    for (int i = 0; i < TAM; i++)//Con esto estoy definiendo los tamaños de cada lado del tablero
    for (int j = 0; j < TAM; j++)
    t[i][j] = mar;
}

void inicializarTablero2 (char t[TAM][TAM]){

    for (int i = 0; i < TAM; i++)//Con esto estoy definiendo los tamaños de cada lado del tablero
    for (int j = 0; j < TAM; j++)
    t[i][j] = mar;
}

int quedanBarcos(char tablero[TAM][TAM]) {
    int i, j;
    for (i = 0; i < 12; i++) {
        for (j = 0; j < 12; j++) {
            if (tablero[i][j] == 'B') {         // Revisa si quedan barcos para el tablero que se le introduzca.
                return 1;
            }
        }
    }
    return 0;
}

void mostrarTablero (char t[TAM][TAM]){
    int i, j;
    printf("   ");
    for (i = 0; i < TAM; i++)           // Usamos un bucle para escribir los numeros de las casillas.
    printf("%2d ", i + 1);
    printf("\n");


    for (i = 0; i < TAM; i++){
        printf("%2d ", i + 1);
        for (j = 0; j < TAM; j++){      // Usamos otro bucle respecto a 2 contadores para mostrar cada casilla 12x12.
            if (t[i][j] == mar)
            printf(" * ");
            else
            printf(" %c ", t[i][j]);
        }
        printf("\n");
    }
}

void mostrarTableroCPU (char t[TAM][TAM]){      
    int i, j;
    printf("   ");
    for (i = 0; i < TAM; i++)                       // Igual que en mostrarTablero marcamos los numeros de filas y columnas
    printf("%2d ", i + 1);
    printf("\n");


    for (i = 0; i < TAM; i++){
        printf("%2d ", i + 1);
        for (j = 0; j < TAM; j++)
        {
            if (t[i][j] == BARCO)
                printf(" * ");
            if (t[i][j] == Tocado)                  // Mostramos el tablero de la maquina , inicialmente solo mostrara el mar.
                printf(" X ");                      // Mostrara si los tiros son agua o tocado.
            if(t[i][j] == mar)
                printf(" * ");
            else if (t[i][j] == AGUA)
                printf(" A ");
            

        }
        printf("\n");
    }
}

void colocarBarcosJugador(char t[TAM][TAM]){
    int barcos [6] = {4, 3, 3, 2, 2, 2};            // Definimos las casillas que ocupa cada barco dentro del tablero
    int fila, col, dir, filaHum, colHum;
    int i, b;
    int valido;
    

    for (b = 0; b < 6; b++){
        valido = 0;                                                 // Variable para ver si la posicion es valida

        while (!valido){
            
            printf("\nColocar barco de tamaño %d\n", barcos[b]);
            printf("Fila inicial: ");
            scanf("%d", &filaHum);                                   // Definimos como se va a realizar la colocación de los barcos
            printf("\nColumna inicial: ");
            scanf("%d", &colHum);
            fila = filaHum - 1;
            col = colHum - 1;

            printf("\nOpciones disponibles:\n");

            if (col + barcos[b] <= TAM)
            printf("0 - Horizontal hasta (%d,%d)\n", filaHum, colHum + barcos[b] - 1);      //revisa si se puede colocar en horizontal.

            if (fila + barcos[b] <= TAM)
            printf("1 - Vertical hasta (%d,%d)\n", filaHum + barcos[b]  - 1, colHum);       // revisa si se puede colocar en vertical.

            printf("Elige la orientacion del barco:\n ");                                   // Elige la direccion con 1 y 0
            scanf("%d", &dir);

            valido = 1;
            // Aqui revisamos que los barcos no salgan del tamaño de tablero.
            if (dir == 0){
                if (col + barcos[b] > TAM)
                valido = 0;

                else{
                    for (i = 0; i < barcos[b]; i++)
                    if (t[fila][col + i] != mar)                       
                    valido = 0;

                    if (valido)
                    for (i = 0; i < barcos[b]; i++)
                    t[fila][col + i] = BARCO;
                }
            }
            else if (dir == 1){
                if (fila + barcos[b] > TAM)
                valido = 0;
                else {
                    for (i = 0; i < barcos[b]; i++)
                    if (t[fila + i][col] != mar)
                    valido = 0;

                    if (valido)
                    for (i = 0; i < barcos[b]; i++)
                    t[fila + i][col] = BARCO;
                }
            }
            else{
                valido = 0;
            }

            if (!valido)
            printf("Posicion no valida. Pruebe otra diferente.\n"); 

        }
    }
}

void colocarBarcosCPU(char t[TAM][TAM]){
    int barcos[6] = {4, 3, 3, 2, 2, 2};                 // Tamaño de los barcos.
    int x, y, dir;                                      // Variables.
    int i, b;
    int colocado;

    for (b = 0; b < 6; b++){
        colocado = 0;


        while (!colocado){
            x = rand() % TAM;                           // Define las posiciones de forma aleatoria.
            y = rand() % TAM;
            dir = rand() % 2; // Dirección aleatoria
            colocado = 1;
            //revisa que el barco no se salga 
            if (dir == 0){
                if (y + barcos[b] > TAM)
                colocado = 0;
                else {
                    for (i = 0; i < barcos[b]; i++)
                    if (t[x][y + i] != mar)
                    colocado = 0;

                    if (colocado)
                    for (i = 0; i < barcos[b]; i++)
                    t[x][y + i] = BARCO;
                }
            }
            else{
                if (x + barcos[b] > TAM)
                colocado = 0;

                else{
                    for (i = 0; i < barcos[b]; i++)
                    if (t[x + i][y] != mar)
                    colocado = 0;


                    if (colocado)
                    for (i = 0; i < barcos[b]; i++)
                    t[x + i][y] = BARCO;
                }
            }
        }
    }
}

void mecanicaDisparos(char jugador[TAM][TAM], char maquina[TAM][TAM]) {

    int ganador = 0;      // decide quien gana.
    int contador = 1;
    int turnoJugador = 1; // decide a quien le toca.
    int fila, col;        
    int acierto = 0;          // decide si ha acertado.

    while (quedanBarcos(jugador) && quedanBarcos(maquina)) {

        if (turnoJugador) {

            do {
                printf("Te toca disparar , Introduce fila: ");          // pide las coordenadas de tu disparo.
                scanf("%d", &fila);
                printf("Introduce columna: ");
                scanf("%d", &col);
                fila--;
                col--;
                if (maquina[fila][col] == Tocado || maquina[fila-1][col-1] == AGUA) {
                    acierto = 0;
                    printf("\nhas fallado\n");
                    if(maquina[fila][col] == AGUA)
                        {
                            maquina[fila][col] = AGUA;                    // Revisa si ha tocado o si ha sido agua.
                        }
                    if(maquina[fila][col] == Tocado)
                        {
                            maquina[fila][col] = Tocado;
                        }
                }
                else if (maquina[fila][col] == BARCO) {
                    maquina[fila][col] = BARCO;
                    acierto = 1;
                    printf("\nha tocado , vuelve a tirar\n");              // Si ha tocado puedes tirar otra vez.
                    
                }
                else {
                    maquina[fila][col] = AGUA;
                    acierto = 0;
                    printf("\nhas fallado\n");
                }
                mostrarTableroCPU(maquina);
                contador++;
            } while (acierto == 1 && quedanBarcos(maquina));

            turnoJugador = 0;
         

        } else {

            do {
                fila = rand() % 12;                                     // Decide las posiciones aleatoriamente.
                col = rand() % 12;

                if (jugador[fila][col] == BARCO || jugador[fila][col] == AGUA) {
                    acierto = 0;
                    printf("\nla maquina ha fallado\n");
                }
                else if (jugador[fila][col] == BARCO) {                 
                    jugador[fila][col] = BARCO;
                    acierto = 1;
                    printf("\nla maquina ha acertado\n");               //revisa si ha acertado la maquina
                }
                else {
                    jugador[fila][col] = AGUA;
                    acierto = 0;
                    printf("\nla maquina ha fallado\n");
                }
                printf("\ntu tablero actual: \n");
                mostrarTablero(jugador);
                contador++;
            } while (acierto == 1 && quedanBarcos(jugador));

            turnoJugador = 1;
        }
    }
    if (quedanBarcos(jugador))
        {
            printf("El jugador ha ganado\n\n");             //si ha ganado el jugador actualiza las estadisticas.
            ganador = 1;
            tablaF(ganador,contador);
        }
    else 
        {
            printf("La maquina ha ganado\n\n");             //si ha ganado la maquina actualiza las estadisticas.
            ganador = 2;
            tablaF(ganador,contador);

        }
}

int main() 
{
   
    srand(time(NULL));
    char opcionElegida;                             // variable para elegir.

    while(opcionElegida != 's')                     // se repite el juego hasta que quieras salir.    
    {
    printf("\t BIENVENIDO A HUNDIR LA FLOTA\n\n");

    printf("\t\t MENU DE INICIO \n\n \t Selecciona una opcion : \n\n\t Empezar a jugar (p) \n\t Ver mejores puntuaciones (m)\n\t Salir del juego (s) \n\t");

    scanf(" %c" , &opcionElegida);
    printf("\n");

    while(opcionElegida != 's' && opcionElegida != 'p' && opcionElegida != 'm'){    //revisa que pongas la opcion bien.

        printf("selecciona una opcion valida (m), (s), (p): ");
        scanf(" %c" , &opcionElegida);

    }

    if(opcionElegida == 's'){

        salir();

    }
    else if (opcionElegida == 'p'){

        jugar();

    }
    else if (opcionElegida == 'm'){

        clasificaciones();

    }
    }
    return 0;
}

void salir() {

    printf("\n\thasta la proxima!");        // Sale del juego.
    exit(0);
}

void jugar(){

    char tablero [TAM][TAM];        //Arrays de dos dimensiones 
    char tablero2 [TAM][TAM];
    
    
    inicializarTablero(tablero);
    inicializarTablero2(tablero2);
    mostrarTablero(tablero);
    mostrarTableroCPU(tablero2);                    // Funciones puestas en orden.
    colocarBarcosJugador(tablero);
    colocarBarcosCPU(tablero2);
    mecanicaDisparos(tablero,tablero2);


}

void clasificaciones(){

    tablaF(0,0);

}