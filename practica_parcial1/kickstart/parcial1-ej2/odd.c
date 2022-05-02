#include <stdbool.h>
#include <stdio.h>
#include "odd.h"

static bool impar(unsigned int elem){
    bool resp;
    resp = ((elem % 2) == 0) ? true : false;
    printf("%d" , resp);
    return resp; 
}

bool is_odd_sorted(int array[], unsigned int length) {
    bool status=true;
    int valor;
    unsigned j;
    j = (length == 0) ? 0u : 1u;
    valor = array[0];
    impar(j) ? 
    while(valor != array[j] && j < length && status){
        if (!(valor <= array[j])){
            status = false;
        }
        valor = array[j];
        j++;
    }

    return status;
}

int main(void){
    int a[6] = {5, 1, 8, 2, 3, 4}; 
    bool result;
    
    //result = is_odd_sorted(a,6u);
    //no terminado pero casi
    printf("%s", (result == 1) ? "True" : "False");
    return 0;
}