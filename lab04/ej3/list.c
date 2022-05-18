#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <stdbool.h>

typedef struct list node;

struct list{
    list_elem valor;
    struct list *next;
};

/*---------------Constructors---------------*/

int destroy(list_pointer l){
    free(l);
    return EXIT_SUCCESS;
}


list_pointer create_node(){
    list_pointer new_node;
    new_node = malloc(sizeof(list_pointer));
    new_node->next = NULL;
    new_node->valor = 0;
    return new_node;
}

list_pointer addl(list_pointer l, list_elem elem){
    list_pointer new_node;
    new_node = create_node();
    new_node->valor = elem;
    new_node->next = l;
    //free(l);
    return new_node;
}

/*---------------Functions---------------*/



list_pointer create_node_withE(list_elem elem){
    list_pointer new_node;
    new_node = malloc(sizeof(list_pointer));
    new_node->next = NULL;
    new_node->valor = elem;
    return new_node;
}


bool is_empty(list_pointer l){
    bool status;
    status = (l->next != NULL) ? false : true;
    return status;
}


list_elem head(list_pointer l){
    list_elem first_elem;
    if (!is_empty(l)){
        first_elem = l->valor;
    }
    else{
        first_elem = l->valor;
    }
    return first_elem;
}

list_pointer tail(list_pointer l){
    list_pointer pointer_aux1;
    assert(!is_empty(l));   
    pointer_aux1 = l->next;
    return pointer_aux1;
}

int length(list_pointer l){
    int counter = 0;
    list_pointer pointer_aux1,pointer_aux2;
    pointer_aux1 = l;

    while(pointer_aux1->next != NULL){
        counter = counter + 1;
        pointer_aux2 = pointer_aux1->next;
        pointer_aux1 = pointer_aux2;
    }
    return counter;
}

list_elem index(list_pointer l, unsigned int n){
    unsigned int len = length(l);
    list_elem n_value; 
    list_pointer pointer_aux1,pointer_aux2;
    pointer_aux1 = l;
    assert(len > n);
    
    for (unsigned int i=0u; i <= n; i++){
        pointer_aux2 = pointer_aux1->next;
        pointer_aux1 = pointer_aux2;
    }
    n_value = pointer_aux1->valor;
    
    return n_value;
}


list_pointer take(list_pointer l, unsigned int n){
    list_pointer pointer_aux1,pointer_aux2;
    pointer_aux1 = l;
    for (unsigned int i=0u; i <= n; i++){
        if (i > n ){
            pointer_aux2 = pointer_aux1->next;
            //free(pointer_aux1);
            pointer_aux1 = pointer_aux2;
            //free(pointer_aux2);
        }
        else{
            if (i == n){
                pointer_aux2 = pointer_aux1->next;
                pointer_aux1 = NULL;
                pointer_aux1 = pointer_aux2;
            }
            else{
            pointer_aux2 = pointer_aux1->next;
            pointer_aux1 = pointer_aux2;
            }
        }
    }   
    return l;
}


list_pointer drop(list_pointer l, unsigned int n){
    list_pointer pointer_aux1,pointer_aux2;
    pointer_aux1 = l;
    for (unsigned int i=0u; i <= n; i++){
        pointer_aux2 = pointer_aux1->next;
        //free(pointer_aux1);
        pointer_aux1 = pointer_aux2;
    }
    pointer_aux2 = pointer_aux1->next;
    //free(pointer_aux1);
    return pointer_aux2;
    
}

list_pointer copy_list(list_pointer l){
    list_pointer walk_l,walk_copy,copy,aux1,aux2,new_node;

    copy = create_node();
  
    walk_l = l;
    walk_copy = copy;

    while(walk_l->next != NULL){ 
        new_node = create_node();
        walk_copy->valor = walk_l->valor;
        walk_copy->next = new_node;

        aux1 = walk_copy->next;
        walk_copy = aux1;

        aux2 = walk_l->next;
        walk_l = aux2;
    }
    walk_copy->valor = walk_l->valor;
    return copy;
}

list_pointer concat(list_pointer l1, list_pointer l2){
    list_pointer walk_l1,aux;
    walk_l1 = l1;

    while(walk_l1->next != NULL){
        aux = walk_l1->next;
        walk_l1 = aux;
        free(aux);
    }

    walk_l1->next = l2;
    return l1;
    
}


list_pointer addr(list_pointer l, list_elem elem){
    list_pointer aux,walk_l,new_node;
    
    new_node = create_node();
    new_node->valor = elem;

    walk_l = l;
    while(walk_l->next != NULL){
        aux = walk_l->next;
        walk_l = aux;
        
    }

    walk_l->next = new_node;
    return l;
}
