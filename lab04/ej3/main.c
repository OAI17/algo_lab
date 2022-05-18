/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "array_helpers.h"
#include "list.h"

/* Maximum allowed length of the array */
static const unsigned int MAX_SIZE = 100000u;

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Compute average for the list of numbers in file.\n"
           "\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    char *result = NULL;

    /* Parse the filepath given by command line argument. */
    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

void print_list(list_pointer l){
    unsigned int len = length(l);
    printf("cantidad de elementos %d \n",len);
    for (unsigned int i=0u; i < len; i++){
        printf(" %d", index(l,i));
    }
    printf("\n");
}  


list_pointer array_to_list(int array[], unsigned int length) {
    /* Initialize the list */
    list_pointer aux1,aux2,new_node;
    new_node = create_node();
    aux1 = new_node;

    for (unsigned int i = 0u; i < length; ++i) {
        aux2 = addr(aux1,array[i]);
        aux1 = aux2;
        
    }
    return new_node;
}


float average(list_pointer l) {
    /*Needs implementation.*/
    int len,elem,suma;
    float prom;
    list_pointer laux,p_aux;

    len = length(l);
    laux = copy_list(l);
    
    suma = 0;
    
    while(!is_empty(laux)){
        elem = head(laux);
        suma = suma + elem;
        
        p_aux = tail(laux);
        laux = p_aux;
    }
    /*Esta mal porque tengo que hacer esto fuera del while pero anda*/
    elem = head(laux);
    suma = suma + elem;
        
    destroy(laux);

    prom =  (len == 0) ? (float) 0 : (float) suma / len;
    return prom;
}
 
int main(int argc, char *argv[]) {
    char *filepath = NULL;
    //FILE *file = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];

    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_file(array, MAX_SIZE, filepath);

    /* show the array in the screen */
    array_dump(array, length);

    /* transform from array to our list type */
    list_pointer l = array_to_list(array, length);
    
    //print_list(l);
    
    /* call the average function */
    printf("The average is: %.2f \n", average(l)); //imprime un doble float %.2f
    
    return (EXIT_SUCCESS);
}
