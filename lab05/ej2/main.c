#include "stack.h"
#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#include <stdio.h>



void array_dump(int a[], unsigned int length) {
    fprintf(stdout, "[");
    for (unsigned int i = 0u; i < length; ++i) {
        fprintf(stdout, "%d", a[i]);
        if (i < length - 1) {
            fprintf(stdout, ", ");
        } else {
            fprintf(stdout, "]\n");
        }
    }
}

/*Falta probar el stack_to_array y poner los asersts*/
int main(void){
    stack new_stack;
    new_stack = stack_empty();
    new_stack = stack_push(new_stack,2);
    unsigned int len = stack_size(new_stack);
   
    printf("primero elento %d\n",stack_top(new_stack)); 
    new_stack = stack_pop(new_stack);
    printf("Cantidad de elementos despues del pop con un elemento %d\n",len);
    printf("Si tiene cero elementos y is_empty anda devuelo un 1 -> %d\n",stack_is_empty(new_stack));
    new_stack = stack_destroy(new_stack);


    
    return 0;
}