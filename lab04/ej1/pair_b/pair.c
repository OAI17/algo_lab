#include "pair.h"
#include <stdlib.h>  
#include <stdio.h>

pair_t pair_new(int x, int y){
    pair_t new_par=NULL;
    new_par = malloc(sizeof(struct s_pair_t));
    new_par->fst = x;
    new_par->snd = y;
    return new_par;
}
    
int pair_first(pair_t p){
    int fst_par; 
    fst_par = p->fst;
    return fst_par;
}
    
int pair_second(pair_t p){
    int scd_par;
    scd_par = p->snd;
    return scd_par;
}

pair_t pair_swapped(pair_t p){
    pair_t data_aux=NULL;
    data_aux = malloc(sizeof(struct s_pair_t));
    data_aux->fst = p->fst;
    data_aux->snd = p->snd;
    return data_aux;
}

pair_t pair_destroy(pair_t p){
    free(p);
    return NULL;
}