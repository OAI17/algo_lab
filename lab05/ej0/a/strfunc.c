#include "strfunc.h"

size_t string_length(const char *str){
    unsigned int c=0;
    while(str[c] != '\0'){
        printf("a %s",str[c]);
        c = c + 1;
        
    }
    return sizeof(c);
}

/*
const char concat_str(const char base, const char *new_char){
    unsigned int i;
    size_t len = string_length(base);
    i = len;
    char new_str[i+1];

    for (unsigned int j=0; j < i; j++){
        new_str[j] = base[j];
    }
    new_str[i] = new_char;
    return new_str; 
}

char *string_filter(const char *str, char c){
    char *aux_str;
    char resp;

    while(str != '\0'){
        if (str != c){
            aux_str = str;
        } 
        resp = concat_str(resp,aux_str);
    return resp;
    }
}
*/
/*devuelve una nueva cadena en memoria dinámica que se obtiene tomando los caracteres de str que son distintos del caracter c.*/
