#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#include <stdio.h>
#include <string.h>

#define INITAIL_CAPACITY 1

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};

stack stack_empty(){
    stack new_stack = malloc(sizeof(struct _s_stack));
    new_stack->capacity = 0;
    new_stack->size = 0;
    new_stack->elems = NULL;//(stack_elem*)calloc(2*INITAIL_CAPACITY,sizeof(stack_elem));
    return new_stack;
}


stack stack_push(stack s, stack_elem e){
    assert(s != NULL);
    assert(s->capacity >= s->size);

    //reasigno el espacio que habia mas dos elementos mas
    if (s->size == s->capacity){
        size_t new_cap = (s->size == 0) ? 1 : 2*s->size;
        s->elems = realloc(s->elems, new_cap*sizeof(stack_elem));
        s->capacity = new_cap;    
    }

    (s->elems)[s->size] = e;
    ++(s->size);
    return s;
}

stack stack_pop(stack s){
    assert(s != NULL);
    unsigned int size = s->size;
    s->size = size -1;
    return s;
}


unsigned int stack_size(stack s){
    assert(s != NULL);
    return s->size;
}


stack_elem stack_top(stack s){
    assert(s != NULL);
    assert(s->size > 0);
    assert(s->elems != NULL);
    unsigned int top_ind;
    top_ind = s->size - 1; 
    return s->elems[top_ind];
}


bool stack_is_empty(stack s){
    assert(s != NULL);
    return s->size == 0;
}

stack stack_destroy(stack s){
    free(s->elems);
    free(s);
    return s; 
}

stack_elem *stack_to_array(stack s){
    assert(s != NULL);
    stack_elem *arr = NULL;
    if (s->size){
        arr = calloc(s->size, sizeof(stack_elem));
        arr = memcpy(arr, s->elems, s->size*sizeof(stack_elem));
    } 
    return arr;
}
