/*
  @file main.c
  @brief Defines main program function
*/

/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Load flight data from a given file in disk.\n"
           "\n"
           "The input file must exist in disk and every line in it must have the following format:\n\n"
           "<code> <arrival-hour> <amount-boxes> <arrival-hour> <amount-letters>\n\n"
           "Those elements will be copied into the multidimensional array 'a'.\n"
           "\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    FILE *file = fopen(filepath, "r");
    
    int num;
    int res = fscanf(file,"%d\n",&num);

    if (res != 1){
        printf("error");
        exit(EXIT_FAILURE);
    }
    
    char array[num];
    int i = 0;
    int suma = 0;
    int resta = 0;
    int aux;
    while(feof(file) == 0){
        int res = fscanf(file,"%c ",&array[i]);
        
        if (res != 1){
            exit(EXIT_FAILURE);
        }

        fscanf(file,"%d ",&aux);
        suma = suma + aux;
        fscanf(file,"%d\n",&aux);
        resta = resta + aux;
        printf("arreglo en pos %d es %c\n",i,array[i]);
        i = i + 1;    
    
    }

    printf("suma total %d \n", suma);
    printf("suma total de la resta %d \n", resta);
    printf("Total %d \n", suma-resta);

    fclose(file);
    return (EXIT_SUCCESS);
}
