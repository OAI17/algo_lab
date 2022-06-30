#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include "unogame.h"
#include "card.h"
#define NO_PLAYER -1

struct s_ugame {
    card_t carta;
    unogame_t next;
    player_t jugador;
};

unogame_t uno_newgame(card_t card) {
    unogame_t uno = malloc(sizeof(struct s_ugame));
    uno->carta = card;
    uno->next = NULL; 
    uno->jugador = NO_PLAYER;
    return uno;
}

card_t uno_topcard(unogame_t uno) {
    return uno->carta;
}

unogame_t uno_addcard(unogame_t uno, card_t c) {
    unogame_t new_node = malloc(sizeof(struct s_ugame));
    new_node->carta = c;
    
    //Es la carta de salto o no 
    new_node->jugador = uno_nextplayer(uno);

    //Apunto al siguiente
    new_node->next = uno;

    //Hago primer nodo a newnode
    uno = new_node;

    return uno;
}

unsigned int uno_count(unogame_t uno) {
    unogame_t aux = uno;
    unsigned int c = 0u;

    while(aux->jugador != NO_PLAYER){
        aux = aux->next;
        c = c + 1u ; 
    }
    return c;
}

bool uno_validpile(unogame_t uno) {
    unogame_t aux = uno;
    bool status = true;

    while(aux->jugador != NO_PLAYER){
        aux = aux->next;
        status = status && card_compatible(uno->carta, uno->next->carta);
    }
    return status; 
}

color_t uno_currentcolor(unogame_t uno) {
    return card_get_color(uno->carta);
}

player_t uno_nextplayer(unogame_t uno) {
    player_t next_p;
    
    if (uno->jugador == 0){
        next_p = (card_get_type(uno->carta) == 2) ? 2 : 1;
    } 

    else if (uno->jugador == 1){
        next_p = (card_get_type(uno->carta) == 2) ? 0 : 2;
    }

    else{
        next_p = (card_get_type(uno->carta) == 2) ? 1 : 0;
    }
    
    assert(0 <= next_p && next_p < NUM_PLAYERS);
    return next_p; 
}



card_t *uno_pile_to_array(unogame_t uno) {
    int size = (int)uno_count(uno);
    unogame_t aux = uno;
    card_t *array = calloc(size,sizeof(card_t));
    if (size != 0){
        for (int i = size-1; i >= 0; i--){
            array[i] = aux->carta;
            aux = aux->next;
        }
    }
    return array;
}

unogame_t uno_destroy(unogame_t uno) {
    unogame_t aux = uno;
    while(aux->jugador != NO_PLAYER){
        aux = aux->next;
        card_destroy(uno->carta);
        free(uno);
        uno = aux;
    }
    card_destroy(uno->carta);
    free(uno);
    //uno = NULL;
    return uno;
}

