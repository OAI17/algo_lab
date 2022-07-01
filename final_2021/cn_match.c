#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "cn_match.h"
#include "card.h"

struct _s_match {
  card mazo;
  cn_match next;
};

cn_match match_new(void) {
  cn_match mt = NULL;
  return mt;
}

cn_match match_add(cn_match match, card c) {
  cn_match new_node;
  new_node = malloc(sizeof(struct _s_match));
  new_node->mazo = c;   
  
  new_node->next = match;
  
 
  return new_node;
}

unsigned int match_size(cn_match match) {
  unsigned int s = 0u;
  cn_match aux = match;

  while(aux != NULL){
    aux = aux->next;
    s = s + 1u;
  }
  assert((int)s >= 0);
  return s;
}

unsigned int match_length(cn_match match) {
  unsigned int length = 0u;
  if (match != NULL){
    
    //Caso de la partida correcta
    if (is_match_correct(match)){
      length = match_size(match)/2;
    }
  }
  assert((int)length >= 0);
  return length;
}

bool is_match_correct(cn_match match) {
  bool status = true;
  cn_match aux = match;
  cn_match prev_ref;
  unsigned int contador = 0u;
  while(aux != NULL){
    prev_ref = aux;
    aux = aux->next;
    contador = contador + 1u;

    //Las tiradas sean intercaladas 
    if (aux != NULL){
      status = (card_player(prev_ref->mazo) != card_player(aux->mazo)) ? status && true : false;
      
    } 
  }  
  //La primera carta la jugo el jugador 1
  status = (card_player(prev_ref->mazo) == 1u) ? status && true : false;
  
  //Cantidad de cartas par
  status = (contador % 2 == 0u) ? status && true : false;
  return status;
}


unsigned int winner_total_points(cn_match match) {
  unsigned int points = 0;
  match = match;
  
  if(is_match_correct(match)){

    unsigned int len = match_length(match);
    cn_match aux = match;
    cn_match prev_ref;

    unsigned int c1 = 0;
    unsigned int c2 = 0;
  
    if (len >= 1){
      prev_ref = match;
      aux = aux->next;
      len = len -1;
      c1 = c1 + card_pair_points(aux->mazo,prev_ref->mazo,1);
      c2 = c2 + card_pair_points(aux->mazo,prev_ref->mazo,2);
    }

    while(len > 0){
      //card fst, card snd, unsigned int player
      prev_ref = aux->next;
      aux = prev_ref->next;
      len = len - 1;  
      c1 = c1 + card_pair_points(aux->mazo,prev_ref->mazo,1);
      c2 = c2 + card_pair_points(aux->mazo,prev_ref->mazo,2);
    } 

    points = (c1 > c2) ? c1 : c2;
  }
  
  assert((int)points >=0);
  return points;
}

card * match_to_array(cn_match match) {
  unsigned int size = match_size(match);
  card *array = calloc(size,sizeof(card));
  cn_match aux = match;

  for (unsigned int i = size-1; (int)i >= 0; i--){
    array[i] = aux->mazo;
    aux = aux->next;
  }
  assert(array != NULL);
  return array;
}

void match_dump(cn_match match) {
  card *array = match_to_array(match);
  for (unsigned int i=0u; i < match_size(match); i++) {
    card_dump(array[i]);
  }
  free(array);
}

cn_match match_destroy(cn_match match) {
  cn_match aux = match;
  cn_match prev_ref;

  while(aux != NULL){
    prev_ref = aux;
    aux = aux->next;
    card_destroy(prev_ref->mazo);
    free(prev_ref);
  }  
  match = NULL;
  assert(match == NULL);
  return match;
}
