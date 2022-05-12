#include "pair.h"

pair_t pair_new(int x, int y){
    pair_t par;
    par.fst = x;
    par.snd = y;
    return par;
}


int pair_first(pair_t p){
    int x = p.fst;
    return x;
}

int pair_second(pair_t p){
    int y = p.snd;
    return y;
}

pair_t pair_swapped(pair_t p){
    pair_t new_par;
    new_par.fst = p.snd;
    new_par.snd = p.fst;
    return new_par; 
}

pair_t pair_destroy(pair_t p){
    return p;
}
    

