#include "strfunc.h"

size_t string_length(const char *str){
    size_t counter = 0;
    char c = '\0';

    while(str[counter] != c){
        counter = counter + 1;
    }

    //printf("%ld",counter);
    return counter;
}


char *string_filter(const char *str, char c){
    size_t len = string_length(str);
    char *new_str;
    unsigned int count=0;
    unsigned int j = 0;

    for (unsigned int k=0u; k < len; k++){
        if (str[k] != c){
            count = count + 1;
        }
    }

    new_str = malloc(count * sizeof(char));
    
    for (unsigned int i=0; i < len; i++){
        if (str[i] != c){
            new_str[j] = str[i];
            j = j + 1;
        }    
        
    }

    return new_str;
}

/*devuelve una nueva cadena en memoria dinámica que se obtiene tomando los caracteres de str que son distintos del caracter c.*/
