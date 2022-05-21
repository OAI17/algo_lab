#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#include <stdio.h>

#define START_VALUE 0u

struct _s_stack{
    stack_elem value;
    struct _s_stack *next;
};

struct base_s{
    base_size size;
    stack next;
};

base stack_empty(){
    base new_stack;
    new_stack = malloc(sizeof(base));
    new_stack->next = NULL;
    new_stack->size = START_VALUE;
    assert(stack_size(new_stack) == 0);
    return new_stack;
}

base stack_push(base s, stack_elem e){
    stack new_element,aux;
    unsigned int len = stack_size(s);

    aux = s->next;


    new_element = malloc(sizeof(stack));
    new_element->value = e;
    new_element->next = aux;

    s->next = new_element;

    s->size = s->size + 1u;

    assert(len < stack_size(s));
    return s;
}

base stack_pop(base s){
    stack aux;
    unsigned int len = stack_size(s);
    assert(len != 0);
    if (len > 1){
        aux = s->next;
        s->next = aux->next;
        
        free(aux);
        aux = NULL;
    }

    else{ 
        aux = s->next;
        free(aux);
        aux = NULL;
    }

    s->size = s->size - 1;
    assert(len > stack_size(s));
    return s;
}

unsigned int stack_size(base s){
    unsigned int counter = s->size;
    return counter;
}

stack_elem stack_top(base s){
    assert(s != NULL);
    stack temp;
    temp = s->next;
    return temp->value;
}

bool stack_is_empty(base s){
    bool status;
    status = (s->size == 0) ? true : false;
    return status;
}

stack_elem *stack_to_array(base s){
    unsigned int len = stack_size(s);
    stack_elem *array_stack;

    array_stack = (stack_elem*)calloc(len,sizeof(stack_elem));
    
    stack walk_stack,aux;
    stack_elem *pointer_array;

    walk_stack = s->next;
    if (len != 0){
        for (unsigned int i=0; i < len;  i++){
            array_stack[len-i-1] = walk_stack->value;
            aux = walk_stack->next;
            walk_stack = aux;
        }

        pointer_array = array_stack;
    }

    else{
        pointer_array = NULL;
    }

    return pointer_array;
}

base tack_destroy(base s){
    s->size = 0;
    free(s->next);
    return s;
}

