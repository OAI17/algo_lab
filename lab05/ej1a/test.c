#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#include <stdio.h>

int main(void){
    stack stack_test;
    unsigned int len;
    stack_elem *arr;

    stack_test = stack_empty();

    /*¿Funciona bien stack_pop() para pilas de tamaño 1?*/
    stack_test = stack_push(stack_test,2); //le añado un elemento para que tenga tamaño 1
    len = stack_size(stack_test);
    printf("El stcak prueba tiene %d elementos\n",len);
    stack_test = stack_pop(stack_test); //le quito un elemento
    len = stack_size(stack_test);
    printf("El stcak prueba tiene %d elementos despues de hacer pop a pilas de tamaño 1\n",len);
    
    
    /*Si la pila queda vacía, ¿puedo volver a insertar elementos?*/
    stack_test = stack_push(stack_test,3);
    len = stack_size(stack_test);
    printf("Despues de quedar vacia le vuelvo a poner %d elementos\n",len);
    

    /*¿La función stack_to_array() devuelve NULL para una pila vacía? ¿Devuelve los elementos en el orden correcto?*/
    stack_test = stack_pop(stack_test); //me queda la pila vacia
    arr = stack_to_array(stack_test);

    bool status = (arr == NULL) ? true:false;
    printf("Si ->%d es 1, esta devolviendo null",status);

    stack_destroy(stack_test);
    free(arr);
    return 0;
}

/*


    for (unsigned int j=0; j < len; j++){
        printf("%d",array_stack[j]);
    }
    
*/