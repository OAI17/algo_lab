/*
PUNTEROS
int x =1;
tuple m = {age,name};
int a[] = {0,1,2,3};

int *n = NULL;
tuple *p = NULL;

n = &x;
*n = 9;

p = &m;
*p.age = 100;


n = &a[1];
*n =42;


prinf("%d",x)
prinf("(%d,%c)",m.age,m.name)
prinf("d",a[1])

ROBOSTO
int res =0;
res = fscanf(file,"%u",size) //devuelve la cantidad de caracteres que lleyo bien

if (res != 1){
    printf(steder, "error")
    return exit_succes 
}
*/


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


static void sort(unsigned int indexes[], char letters[], char sorted[],unsigned int length){
    unsigned int i;
    for (unsigned int j=0u; j < length; j++){        
        i = indexes[j]; 
        sorted[i] = letters[j];   
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
            //feof devuelve un valor dif de 0 cuando el puntero apunta a null (se fija a que apunta)
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

    sort(indexes,letters,sorted,length);
    dump(sorted, length); 
    //printf("%u\n", length);
    return EXIT_SUCCESS;
}


