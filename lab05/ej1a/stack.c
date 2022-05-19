#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#include <stdio.h>

#define START_VALUE 0

struct _s_stack{
    stack_elem value;
    struct _s_stack *next;
};

stack stack_empty(){
    stack new_stack;
    new_stack = malloc(sizeof(stack));
    //new_stack->next = NULL;
    //new_stack->value = START_VALUE;
    return new_stack;
}

stack stack_push(stack s, stack_elem e){
    stack new_element;
    new_element = malloc(sizeof(stack));
    new_element->next = s;
    new_element->value = e;
    return new_element;
}

stack stack_pop(stack s){
    stack temp;
    if (s != NULL){
        temp = s->next;
        free(s);
    }
    return temp;
}

unsigned int stack_size(stack s){
    stack walk_stack,aux;
    unsigned int counter = 0; 
    walk_stack = s;
    
    if (walk_stack != NULL){
        
        while(walk_stack->next){
            counter = counter + 1;
            aux = walk_stack->next;
            walk_stack = aux;
        }
    }

    return counter;
}

stack_elem stack_top(stack s){
    return s->value;
}

bool stack_is_empty(stack s){
    bool status;
    status = (s->next == NULL) ? true : false;
    return status;
}

stack_elem *stack_to_array(stack s){
    unsigned int len = stack_size(s);
    stack_elem array_stack[len];
    stack walk_stack,aux;
    stack_elem *pointer_array;

    walk_stack = s;
    for (unsigned int i=0; i < len; i++){
        array_stack[i] = walk_stack->value;
        
        aux = walk_stack->next;
        walk_stack = aux;
    }
    pointer_array = array_stack;
    return pointer_array;
}


stack stack_destroy(stack s){
    free(s);
    return s;
}


void print_stack(stack s){
    unsigned int len = stack_size(s);
    stack_elem e;
    stack walk,aux;
    walk = s;
    for (unsigned int i=0; i < len; i++){
        e = walk->value;
        printf("%d",e);
        aux = walk->next;
        walk = aux;
    }
}

