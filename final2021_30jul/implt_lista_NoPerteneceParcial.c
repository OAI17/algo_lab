#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef int tipo;
typedef struct _node *node;
 
struct _node {
    tipo elem;
    node next;
};

bool inverp(node a){
    bool status = false;
    if (a != NULL){
        status = true; 
    }
    return status;
}

node empty_list(){
    node array = malloc(sizeof(struct _node));
    array->next = NULL;
    array->elem = 0;
    return array;
}
    
node addl(node a, tipo e){
    assert(inverp(a));
    node new_node = malloc(sizeof(struct _node));
    new_node->elem = e;
    new_node->next = a;
    return new_node;
}

node destroy(node a){
    node aux = a;
    node aux2;
    while(aux->next != NULL){
        aux2 = aux->next;
        free(aux);
        aux = aux2;
    }
    free(aux);
    aux = NULL;
    assert(aux == NULL);
    return aux;
}


unsigned int lenght(node a){
    assert(inverp(a));
    node aux = a;
    unsigned int contador = 0;
    while(aux->next != NULL){
        aux = aux->next;
        contador = contador + 1;
    }
    assert((int)contador >= 0);
    return contador;
}

node drop(node a, unsigned int n){
    assert(inverp(a));
    unsigned int size = lenght(a);
    assert(n <= size);
    node aux;
    for (unsigned int i = 0u; i < n; i++){
        aux = a->next;
        free(a);
        a = aux;
    }
    return a;
}


bool is_empty(node a){
    assert(inverp(a));
    return a->next == NULL;
}

node concat(node l1, node l2){
    assert(inverp(l2));
    assert(inverp(l1));
    node a;
    node aux = l1;
    if (l1 != NULL){
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = l2;
        a = l1;
    }
    
    else{
        a = l2; 
    }
    return a;
}

node tail(node a){
    assert(!is_empty(a));
    node aux = a->next;
    a->next = NULL;
    destroy(a);
    return aux;  
}
tipo index(unsigned int n, node a){
    assert(inverp(a));
    unsigned int size = lenght(a);
    assert(n <= size);
    node aux = a;
    for (unsigned int j = 0u; j != n; j++){
        aux = aux->next;
    }
    return aux->elem;
}
node intercala(node l1, node l2){
    assert(inverp(l1));
    assert(inverp(l2));
    assert(lenght(l1) == lenght(l2));
    assert(lenght(l1) % 2 == 0);

    unsigned int size = lenght(l1);
    node new_a = empty_list();
    tipo e;
    for (unsigned int i = size-1; (int)i >= 0; i--){
        e = (i % 2 == 0) ? index(i,l1) : index(i,l2);
        new_a = addl(new_a,e);
    }   
    return new_a;
}

void print(node l1){
    assert(inverp(l1));
    unsigned int size = lenght(l1);
    node aux = l1;
    //printf("%d",size);
    for (unsigned int i = 0u; i < size; i++){
        printf("%d",aux->elem);
        aux = aux->next;
    }   
}

int main(void){
    node l1 = empty_list();
    l1 = addl(l1,2);
    l1 = addl(l1,2);
    l1 = addl(l1,2);
    l1 = addl(l1,2);

    node l2 = empty_list();
    l2 = addl(l2,3);
    l2 = addl(l2,3);
    l2 = addl(l2,3);
    l2 = addl(l2,3);
    
    node l3 = intercala(l1,l2);
    print(l3);
    
    l1 = destroy(l1);
    l2 = destroy(l2);
    l3 = destroy(l3);
    return 0;
}