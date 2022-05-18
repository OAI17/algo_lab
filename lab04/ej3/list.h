#ifndef _LIST_H
#define _LIST_H
#include <stdbool.h>

typedef struct list * list_pointer;
typedef int list_elem;


int destroy(list_pointer l);
/*{- Libera memoria en caso que sea necesario. -}*/

list_pointer create_node(); //empty()
/*{- Crea un nuevo nodo vacio-}*/

list_pointer addl(list_pointer l, list_elem elem);
/*{- agrega el elemento e al comienzo de la lista l. -}*/

list_pointer create_node_withE(list_elem elem);
/* {- Crea un nodo con el valor e. -} */

bool is_empty(list_pointer l);
/* {- Devuelve True si l es vacía. -} */

list_elem head(list_pointer l);
/*  {- Devuelve el primer elemento de la lista l -}
    {- PRE: not is_empty(l) -}*/

list_pointer tail(list_pointer l);
/*  {- Elimina el primer elemento de la lista l -}
    {- PRE: not is_empty(l) -}*/

list_pointer addr(list_pointer l, list_elem elem);
/*  {- agrega el elemento e al final de la lista l. -}*/

int length(list_pointer l);
/*  {- Devuelve la cantidad de elementos de la lista l -}*/

list_pointer concat(list_pointer l1, list_pointer l2);
/*  {- Agrega al final de l todos los elementos de l0 en el mismo orden.-}*/

list_elem index(list_pointer l, unsigned int n);
/*  {- Devuelve el n-ésimo elemento de la lista l -}
    {- PRE: length(l) > n -}*/

list_pointer take(list_pointer l, unsigned int n);
/* {- Deja en l sólo los primeros n elementos, eliminando el resto -} */

list_pointer drop(list_pointer l, unsigned int n);
/* {- Elimina los primeros n elementos de l -} */

list_pointer copy_list(list_pointer l);
 /*{- Copia todos los elementos de l1 en la nueva lista l2 -}*/

#endif