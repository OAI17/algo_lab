#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

void array_dump(int a[], unsigned int length) {
    fprintf(stdout, "[");
    for (unsigned int i = 0u; i < length; ++i) {
        fprintf(stdout, "%d", a[i]);
        if (i < length - 1) {
            fprintf(stdout, ", ");
        } else {
            fprintf(stdout, "]\n");
        }
    }
}


unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath) {
    FILE *file = NULL;
    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    unsigned int i = 0u;
    unsigned int size = 0u;
    int res = 0;
    res = fscanf(file, " %u ", &size);
    if (res != 1) {
        fprintf(stderr, "Invalid array.\n");
        exit(EXIT_FAILURE);
    }
    if (size > max_size) {
        fprintf(stderr, "Allowed size is %d.\n", max_size);
        exit(EXIT_FAILURE);
    }
    while (i < size) {
        res = fscanf(file," %d ", &(array[i]));
        if (res != 1) {
            fprintf(stderr, "Invalid array.\n");
            exit(EXIT_FAILURE);
        }
       ++i;
    }
    fclose(file);
    return (size);
}

int *invert_array(unsigned int length,int array[], int new_array[]){
    base data_save;
    data_save = stack_empty();

    /*(1) Pedir el espacio de memoria que necesito*/
    new_array = (int*)calloc(length,sizeof(int));

    /*(2) Lleno el stack con los elemntos del array del indice mas chico al mas grade*/
    for (unsigned int i=0; i < length; i++){
        data_save = stack_push(data_save,array[i]);
    }

    /*(3) Ir sacando elementos del stack y ponerlos en el nuevo array*/
    stack_elem aux;
    for (unsigned int j=0; j < length; j++){
        aux = stack_top(data_save);
        data_save = stack_pop(data_save);

        new_array[j] = aux;

    }

    return new_array;
}
