#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOMBRE_ARCHIVO "text.txt" //defino el archivo que voy a leer
#define LONGITUD_MAX 1000 //defino el tomaNo maximo por linea


void read_array(void){
    int i;
    FILE *myFile = fopen(NOMBRE_ARCHIVO, "r");
    char line[LONGITUD_MAX],n;
    n = fgets(line,LONGITUD_MAX,myFile);
    char array[4];
    i = 0;
    while (fgets(line,LONGITUD_MAX,myFile))
    {
        array[i] = line;
        i = i + 1;

    }
    
}



int main(void){
    read_array();
    return 0;
}

/*preguntas
que hace el * antes de file 
*/









/*    FILE *archivo = fopen(NOMBRE_ARCHIVO,"r"); 
    char bufer[LONGITUD_MAX]; //defino tamaNo maximo para memoria temporal, variable que guarda temporalmente una linea del doc
    while (fgets(bufer, LONGITUD_MAX,archivo)) //mientras me siga devolviendo caracteres .. (osea hasta que lea todo el doc)
    {
        //strtok(bufer, "\n"); lo que hace es eliminar el segundo argumento del primero 
        printf("%s",bufer); //en 
    } */