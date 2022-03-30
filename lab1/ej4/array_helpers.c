#include "array_helpers.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Loads an array given in a file in disk and prints it on the screen."
           "\n\n"
           "The input file must have the following format:\n"
           " * The first line must contain only a positive integer,"
           " which is the length of the array.\n"
           " * The second line must contain the members of the array"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "<amount of array elements>\n"
           "<array elem 1> <array elem 2> ... <array elem N>\n\n",
           program_name);
}


char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;
    // Program takes exactly two arguments
    // (the program's name itself and the input-filepath)
    bool valid_args_count = (argc == 2);

    if (!valid_args_count) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}

unsigned int array_from_file(int array[],unsigned int max_size,const char *filepath) {

    FILE *myFile; 
    myFile = fopen(filepath, "r");

    if (myFile == NULL){
        printf("Error opening the file");}

    fscanf(myFile,"%u\n",&max_size);
    
    for (unsigned int i =0; i < max_size; i++){
        fscanf(myFile,"%d",&array[i]);} 

    fclose(myFile); 
    return max_size;    
    }

void array_dump(int a[], unsigned int length) {
    printf("%d \n", length);
    if (length == 0){
        printf("No hay arreglo");}

    for (unsigned int i=0; i < length; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

bool array_is_sorted(int a[], unsigned int length){
    //bool True = true; //toma valor 1
    //bool False = false; //toma valor 0
    bool Break = true;
    unsigned int end = length -1;
    
    for (unsigned int i=0; ((i < end) && Break); i++){
        
        if ((a[i] <= a[i+1])){
            Break = Break;}

        else{
            Break = false;} 
    }

    if (Break == false){
        printf("El arraglo no esta ordenado \n");
    }

    else{
        printf("El arraglo esta ordenado \n");
    }

    return Break;
}