#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        exit(EXIT_FAILURE);
    }

    result = argv[1];
    return result;
}


static void sort(unsigned int indexes, char letters[], char sorted[],unsigned int length){
    unsigned int i=0;
    while (sorted tenga la cantidad de lenght)
    for (unsigned int j=0u; j <= length;){
        if (indexes[j] = i){
            sorted[i] = letters[i];
            i = i+1;
        }
    }
}

static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

unsigned int data_from_file(const char *path,unsigned int indexes[],char letters[],unsigned int max_size){
        FILE *file;
        file = fopen(path,"r");
        if (file != NULL){
            unsigned int elem=0;

            while(feof(file) == 0 && elem < max_size){
                fscanf(file, "%u ",&indexes[elem]);
                fscanf(file, "'%c'\n", &letters[elem]);
                elem = elem +1; 
            }
            fclose(file);
            return elem;
        }
        else{
            printf("Error abriendo el archivo \n");
            return EXIT_FAILURE;
        }
    }


int main(int argc, char *argv[]) {
    
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length=0; 
    
    char *pointer_file = NULL;

    pointer_file = parse_filepath(argc,argv);
    
    length = data_from_file(pointer_file,indexes,letters,MAX_SIZE);

    dump(letters, length); 
    //printf("%u\n", length);
    return EXIT_SUCCESS;
}


