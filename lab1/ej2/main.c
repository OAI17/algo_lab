/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

unsigned int array_from_file(int array[],unsigned int max_size) {
    int n;
    printf("Ingrese de que tamaño va a ser el arreglo: \n");
    scanf("%d", &n);
    max_size = n;
    
    if (max_size == 0){
        printf("Dato no valido, intertar otro numero mayor a cero");}

    for (unsigned int i =0; i < max_size; i++){
        printf("Ingrese un valor para la posicion %d del arreglo: \n", i);
        scanf("%d", &array[i]);
    }    
    printf("\n");
    return max_size;    
    }

void array_dump(int a[], unsigned int length) {
    printf("%d \n", length);

    for (unsigned int i=0; i < length; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main(void) {
    
    int array[MAX_SIZE];
    
    unsigned int length = array_from_file(array, MAX_SIZE);
    
    
    array_dump(array, length);
    
    return EXIT_SUCCESS;
}