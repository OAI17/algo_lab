/*
int usa %d
float usa %f
char usa %d
strings usa %s
*/


#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

void complete(int a[], int n)
{
    //assert(long > 0);
    int i,temp;
    i = 0;

    printf("Completemos el array \n");
    while (i < n)
    {
        printf("Ingreses un valor para la posision %d del array \n",i);
        scanf("%d", &temp);
        a[i] = temp;
        i = i+1;
    }
}

//max_min_result identificador 
typedef struct {
    //tipo y nombre del atributo 
    int max_value;
    int min_value;
    unsigned int max_position;
    unsigned int min_position;
}max_min_result;
//ya tengo creado un nuevo tipo de datos 

//como usar el max_min_result

//"struct max_min_result" hace referencia el tipo que va a tener el funcion 

max_min_result compute_max_min(int array[], unsigned int length)
{
    int i,min_value,max_value,min_position,max_position;
    max_min_result resp; 
    i = 0;

    min_value = array[0];
    max_value = array[0];
    min_position = array[0];
    max_position = array[0];

    while (i < length)
    {
        //max
        if (array[i] > max_value){
            max_value = array[i];
            max_position = i;
        }  
        //min
        if (array[i] < min_value){
            min_value = array[i];
            min_position = i;
        }
        i = i+1;

    }   
    
    resp.min_value = min_value;
    resp.max_value = max_value;
    resp.min_position = min_position;
    resp.max_position = max_position;
    
    return resp;
}

int main(void)
{
    int n;
    max_min_result rta;
    printf("Ingrese de que tamano es el array \n");
    scanf("%d",&n);
    int array[n];


    complete(array,n);
    rta = compute_max_min(array,n);
    printf("El minimo valor del array es %d en la posision %d \n", rta.min_value,rta.min_position);
    printf("El maximo valor del array es %d en la posision %d \n", rta.max_value,rta.max_position);
    return 0;
}


