#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#include <stdio.h>

#define INITAIL_CAPACITY 1

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};

stack stack_empty(){
    stack new_stack;
    new_stack = malloc(sizeof(stack));
    new_stack->capacity = (unsigned int)INITAIL_CAPACITY;
    new_stack->size = 0u;
    new_stack->elems = (stack_elem*)calloc(INITAIL_CAPACITY,sizeof(stack_elem));
    return new_stack;
}


stack stack_push(stack s, stack_elem e){
    //reasigno el espacio que habia mas dos elementos mas
    unsigned int old_capacity = s->capacity;
    
    if (s->size == old_capacity){
        s->elems = (stack_elem*)realloc(s->elems, (old_capacity*sizeof(stack_elem))+(2*sizeof(stack_elem)));
        
    }
    s->elems[s->size] = e;
    
    s->capacity = old_capacity + 2 ;
    s->size = s->size + 1 ;
    
    return s;
}


stack stack_pop(stack s){
    unsigned int size = s->size;
    s->size = size -1;
    return s;
}


unsigned int stack_size(stack s){
    return s->size;
}


stack_elem stack_top(stack s){
    unsigned int top_ind;
    top_ind = s->size - 1; 
    return s->elems[top_ind];
}


bool stack_is_empty(stack s){
    bool status;
    status = (s->size == 0) ? true : false;
    return status;
}

stack stack_destroy(stack s){
    free(s);
    return s; 
}

stack_elem *stack_to_array(stack s){
    return s->elems;
}
