#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};

stack stack_empty(){
    stack new_stack;
    new_stack->capacity = 0u;
    new_stack->elems = 0u;
    new_stack->elems = malloc(sizeof(stack_elem));
    return new_stack;
}
