#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000

static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}


unsigned int data_from_file(const char *path,unsigned int indexes[],char letters[],unsigned int max_size){
        path = fopen(*path,"r");
        if (path != NULL){
            int elem=max_size;
            int unsigned j=0;
            char p;
            
            char p;
            //fscanf devuelve EOF cuando se alcanza el final de la entrada
            while(fscanf(*path, "%c", p) != E0F){
                printf("%s \n",p);
                  
                //indexes[j] = agrege al indexes los numeros
                //letters[j] = agrege al letters las letras
                j = j+1;
                elem = elem -1; 
                
                
            }
            fclose(path);
            elem = max_size - (max_size-elem);
            //asigne el ultimo i a una variable que va a ser la que devuelvo (max_size-indexes[ultima posicion])
            return elem;
        }
        else{
            printf("Error abriendo el archivo \n");
            return EXIT_FAILURE;
        }
    }

int main(int argc, char *argv[]) {
    FILE *file;
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    //char sorted[MAX_SIZE];
    unsigned int length=0; 
    
    
    //  .----------^
    //  :
    // Debe guardarse aqui la cantidad de elementos leidos del archivo
    
    /* -- completar -- */


    length = data_from_file(file,indexes,letters,MAX_SIZE);

    //dump(sorted, length); 

    return EXIT_SUCCESS;
}

