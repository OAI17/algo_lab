#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "domino_line.h"
#include "domino.h"

struct _s_line {
    domino ficha;
    domino_line next;
    domino_line back;
};

domino_line line_new(domino first) {
    assert(domino_is_double(first));
    domino_line new_line = malloc(sizeof(struct _s_line));
    new_line->ficha = first;
    new_line->next = NULL;
    new_line->back = NULL;
    return new_line;
}

domino_line line_add(domino_line line, domino t) {
    domino_line aux = line;
    
    domino_line new_ficha = malloc(sizeof(struct _s_line));
    new_ficha->ficha = t;
    new_ficha->next = NULL;
    
    //Recorrer hasta su posicion
    while(aux->next != NULL){
        aux = aux->next;
    }
    
    aux->next = new_ficha; //Nuevo elemento
    new_ficha->back = aux;
    return line;
}

unsigned int line_length(domino_line line) {
    unsigned int size = 0u;
    domino_line aux = line;
    
    while(aux != NULL){
        aux = aux->next;
        size = size + 1;
    }
    assert(size > 0);
    return size;
}

bool line_n_correct(domino_line line, unsigned int n) {
    unsigned int size = line_length(line);
    assert(n < size);
    bool status;
    domino_line aux = line;

    //Posicionarme en el n elemento
    for (unsigned int i = 0u; i != n; i++){
        aux = aux->next;
    }

    //Caso unica ficha
    if (aux->back == NULL && aux->next == NULL){
        status = true;
    }

    //domino_matches(domino t_top, domino t_botton)
    //Caso primer elemento
    else if (aux->back == NULL && aux->next != NULL){
        status = domino_matches(aux->ficha,aux->next->ficha);
    }

    //Ultimo elemento
    else if (aux->back != NULL && aux->next == NULL){
        status = domino_matches(aux->back->ficha,aux->ficha);
    }

    //Elemento del medio 
    else{
        status = domino_matches(aux->back->ficha,aux->ficha) && domino_matches(aux->ficha,aux->next->ficha);
    }
    return status;
}

int line_total_points(domino_line line) {
    int contador = 0;
    domino_line aux = line;
    
    while(aux != NULL){
        contador = contador + domino_down(aux->ficha) + domino_up(aux->ficha);
        aux = aux->next;
    }
    assert(contador >= 0);
    return contador;
}

domino * line_to_array(domino_line line) {
    unsigned int size = line_length(line);
    domino *array = calloc(size, sizeof(domino));
    domino_line aux = line;

    for (unsigned int i = 0u; i < size && aux != NULL; i++){
        array[i] = aux->ficha;
        aux = aux->next;
    }
    assert(array != NULL);
    return array;
}

void line_dump(domino_line line) {
    domino *array=line_to_array(line);
    for (unsigned int i=0u; i < line_length(line); i++) {
        domino_dump(array[i]);
    }
    free(array);
}

domino_line line_destroy(domino_line line) {
    domino_line aux = (line != NULL) ? line->next : line ; 
    while(aux != NULL){
            
        domino_destroy(line->ficha);
        free(line);
        line = aux;
        aux = aux->next;
        }    
    domino_destroy(line->ficha);
    free(line);
    line = aux;
    return line;
}

