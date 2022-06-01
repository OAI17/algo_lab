#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#include <stdio.h>

#define START_VALUE 0

//int* ptr = (int*)calloc(5,sizeof(int))

struct _s_stack{
    stack_elem value;
    struct _s_stack *next;
};

stack stack_empty(){
    stack new_stack;
    new_stack = malloc(sizeof(struct _s_stack));
    new_stack->next = NULL;
    new_stack->value = START_VALUE;
    return new_stack;
}

stack stack_push(stack s, stack_elem e){
    stack new_element;
    new_element = malloc(sizeof(struct _s_stack));
    new_element->next = s;
    new_element->value = e;
    return new_element;
}

stack stack_pop(stack s){
    stack temp;
    unsigned int len = stack_size(s);
    if (len > 1){
        temp = s->next;
        s->next = NULL;
        free(s);
    }
    else{ 
        if(len == 1){
        free(s);
        temp = NULL;
        }
    }


    return temp;
}

unsigned int stack_size(stack s){
    stack walk_stack,aux;
    unsigned int counter = 0; 
    walk_stack = s;
    
    if (walk_stack != NULL){
        if (walk_stack->next != NULL){
            while(walk_stack->next){
                counter = counter + 1;
                aux = walk_stack->next;
                walk_stack = aux;
            }           
        }
        else{
            counter = counter +1;
        }
    }
    return counter;
}

stack_elem stack_top(stack s){
    assert(s != NULL);
    return s->value;
}

bool stack_is_empty(stack s){
    bool status;
    status = (s->next == NULL) ? true : false;
    return status;
}

stack_elem *stack_to_array(stack s){
    unsigned int len = stack_size(s);
    stack_elem *array_stack;

    array_stack = (stack_elem*)calloc(len,sizeof(stack_elem));
    
    stack walk_stack,aux;

    walk_stack = s;
    if (len != 0){
        for (unsigned int i=0; i < len;  i++){
            array_stack[len-i-1] = walk_stack->value;
            aux = walk_stack->next;
            walk_stack = aux;
        }

    }

    else{
        array_stack = NULL;
    }

    return array_stack;
}


stack stack_destroy(stack s){
    stack walk,aux;
    walk = s;
    while(walk != NULL){
        aux = walk->next;
        free(walk);
        walk = aux;    
    }
    free(walk);
    return NULL;
}


void print_stack(stack s){
    unsigned int len = stack_size(s);
    stack walk,aux;
    walk = s;
    for (unsigned int i=0; i < len; i++){
        aux = walk->next;
        walk = aux;
    }
}

