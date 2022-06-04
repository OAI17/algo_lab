#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "pstack.h"

//typedef struct s_pstack * pstack;
//typedef unsigned int pstack_elem;


typedef int size_pstack;

struct s_pstack {
    size_pstack size;
    struct s_node *primer_elem;
};

struct s_node {
    pstack_elem elem;
    priority_t p;
    struct s_node *next;        
};

static bool invrep(pstack s) {
    assert(s != NULL);
    bool status = true;
    if (s->primer_elem != NULL){
        /*Recorre los nodos*/
        struct s_node *recorre1,*recorre2;
        recorre1 = s->primer_elem;
        
        while(recorre1->next != NULL){
            recorre2 = recorre1->next;
            status = status & (recorre2->p <= recorre1->p) ? true : false;    
            recorre1 = recorre2;
        }
    }
    return status;
}


pstack pstack_empty(void) {
    pstack s=NULL;
    s = malloc(sizeof(struct s_pstack));
    assert(s != NULL); // Por si no me dan la memoria
    s->primer_elem = NULL;
    s->size = 0;
    return s;
}

static struct s_node * create_node(pstack_elem e, priority_t priority) {
    struct s_node *new_node = NULL;
    new_node = malloc(sizeof(struct s_node));
    assert(new_node!=NULL);
    new_node->elem = e;
    new_node->next = NULL;
    new_node->p = priority;
    return new_node;

}

static struct s_node * destroy_node(struct s_node *node) {
    assert(node != NULL);
    node->next = NULL;
    node = NULL;
    free(node);
    assert(node == NULL);
    return node;
}


pstack pstack_push(pstack s, pstack_elem e, priority_t priority) {
    assert(invrep(s));
    struct s_node *new_node = create_node(e, priority);
    
    s->size = s->size + 1; // actualizar el valor de size
    
    /*Tiene elementos*/
    if (s->primer_elem != NULL){
        struct s_node *recorre1,*recorre2;
        recorre1 = s->primer_elem;
        
        /*Me encuentra la pos*/
        while(recorre1->next != NULL && recorre1->p > priority){
            recorre2 = recorre1->next;
            recorre1 = recorre2;
        }

        struct s_node *pointer_aux1;
        bool dif_prim_elem = false;
        if (s->primer_elem->p <= priority){
            /*Caso en el que lo tengo que meter el principio*/
            pointer_aux1 = s->primer_elem;
            s->primer_elem = new_node;
            new_node->next = pointer_aux1;
            dif_prim_elem = true; 
        }


        if (recorre1->p == priority && !dif_prim_elem){
            /*Poner el nuevo nodo adelante*/
            pointer_aux1 = recorre1->next; //guardo la referencia del siguiente
            recorre1->next = new_node; //meto el nuevo nodo el medio
            new_node->next = pointer_aux1; //hago apuntar al que le sigue

            /*swap de valores manteniendo los punteros*/
            priority_t aux_p = new_node->p;
            pstack_elem aux_e = new_node->elem;

            new_node->elem = recorre1->elem;
            new_node->p = recorre1->p;

            recorre1->elem = aux_e;
            recorre1->p = aux_p;


        }

        else{
            /*Poner el nuevo atras*/
            pointer_aux1 = recorre1->next; //guardo la referencia del siguiente
            recorre1->next = new_node; //meto el nuevo nodo el medio
            new_node->next = pointer_aux1; //hago apuntar al que le sigue
        }
    }

    /*No tiene elementos*/
    else{
        s->primer_elem = new_node;
    }

    return s;
}

bool pstack_is_empty(pstack s) {
    bool status = (s->size == 0u) ? true : false;  //tambien pordria usar pstack_size
    return status;
}

pstack_elem pstack_top(pstack s) {
    //invrep(s);
    struct s_node *first;
    first = s->primer_elem;
    return first->elem;
}

priority_t pstack_top_priority(pstack s) {
    assert(s->primer_elem != NULL);
    struct s_node *first;
    first = s->primer_elem;
    return first->p;
}

unsigned int pstack_size(pstack s) {
    //assert(invrep(s));
    unsigned int size = s->size; //unsigned int size=0; cambio para hacerlo de esta forma
    return size;
}

pstack pstack_pop(pstack s) {
    //invrep(s);
    assert(s != NULL);
    if (s->primer_elem != NULL){
        struct s_node *first,*next_node;

        s->size = s->size - 1; // actualizar el valor de size

        first = s->primer_elem; //guardo ref a primer elemento
        
        if ( first->next != NULL){
            next_node = first->next; //guardo ref a segundo elemento
            s->primer_elem = next_node; //hago que el primer elm sea el segundo
            first->next = NULL;
        }

        destroy_node(first); //libero la memoria del primero
        
    }
    return s;
}

pstack pstack_destroy(pstack s) {
    //invrep(s);
    struct s_node *recorre1,*recorre2;
    assert(s != NULL);
    
    /*Quedan nodos por borrar*/
    if (s->primer_elem != NULL){
        recorre1 = s->primer_elem;
        /*Recorre los nodos*/
        while(recorre1->next != NULL){
            recorre2 = recorre1->next;
            destroy_node(recorre1);
            recorre1 = recorre2;
        }
        destroy_node(recorre1);
    }

    s->primer_elem = NULL;
    s = NULL;
    free(s);
    assert(s == NULL);
    return s;
}

