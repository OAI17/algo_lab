#include <stdlib.h>
#include <stdbool.h>

#include <assert.h>
#include "card.h"

struct s_card {
    int num;
    color_t color;
    type_t type;
};

static bool invrep(card_t c) {
    // Invariante de representación
    bool valid = false;
    if (c != NULL){
        if ((c->color==red || c->color==green || c->color==blue || c->color==yellow)){
            if (c->type==normal  || c->type==change_color || c->type==skip){
                if (c->num < 10){
                    valid = true;
                }
            }
        }
    
    }
    return valid;
}

card_t card_new(int num, color_t color, type_t s) {
    card_t card;
    card = malloc(sizeof(struct s_card));
    card->num = (s != 0) ? 0 : num;    
    card->color = color;
    card->type = s;
    assert(invrep(card));
    return card;
}


unsigned int card_get_number(card_t card) {
    assert(invrep(card));
    return card->num;
}

color_t
card_get_color(card_t card) {
    assert(invrep(card));
    return card->color;
}

type_t card_get_type(card_t card) {
    assert(invrep(card));
    return card->type;
}

bool card_samecolor(card_t c1, card_t c2) {
    return c1->color == c2->color;
}


bool card_samenum(card_t c1, card_t c2) {
    return c1->num == c2->num;
}

bool card_compatible(card_t new_card, card_t pile_card) {
    bool compatible = false;
    assert(invrep(new_card) && invrep(pile_card));
    
    //Las dos sean normales
    if (card_get_type(new_card) == 0  && card_get_type(pile_card) == 0){
        //Carta del mismo color y/o mismo numero
        if (card_samecolor(new_card,pile_card) || card_samenum(new_card,pile_card))
        compatible = true;
    }

    //Carta boqueo y comun
    //Veo si hay una carta bloqueo y una normal 
    else if ((card_get_type(new_card) == 0  || card_get_type(pile_card) == 0) && (card_get_type(new_card) == 2  || card_get_type(pile_card) == 2)){
        //Veo que sean del mismo color
        if (card_samecolor(new_card,pile_card)){        
                compatible = true;
        }
    }

    //Doble carta bloque
    else if (card_get_type(new_card) == 2  && card_get_type(pile_card) == 2){
        compatible = true;
    }

    //Carta color y normal 
    else if ((card_get_type(new_card) == 0 || card_get_type(pile_card) == 0) && (card_get_type(new_card) == 1  || card_get_type(pile_card) == 1)){
        //New card sea del mismo color 
        if (card_get_color(new_card) == card_get_color(pile_card)){
            compatible = true;
        }
    }

    //Carta color y bloqueo 
    else if ((card_get_type(new_card) == 2  || card_get_type(pile_card) == 2) && (card_get_type(new_card) == 1 || card_get_type(pile_card) == 1)){
        if (card_get_color(new_card) == card_get_color(pile_card)){
            compatible = true;
        }
    }

    //Doble cambia color
    else if (card_get_type(new_card) == 1  || card_get_type(pile_card) == 1){
        compatible = true;
    }

    return compatible;
}

card_t card_destroy(card_t card) {
    free(card);
    //card = NULL;
    return card;
}


