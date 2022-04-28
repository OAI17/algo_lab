#include <stdbool.h>
#include <stdio.h>
#include "pivot.h"

bool is_pivot(int array[], unsigned int length, unsigned int piv) {
    int pto_piv=array[piv];
    bool status=true, status1=true; 
    unsigned int j=0u;
    
    while (j<piv && status){
        if (!(array[j] <= pto_piv)){
            status = false;
        }
        j++;
    }

    j = length-1u;

    while (j>piv && status1 && j<length){
        if (!(array[j] >= pto_piv)){
            status = false;
        }
        j--;
    }

    return (status1 && status);
}

int main(void){
    int a[4] = {1, 2, 6, 5}; 
    bool result;
    
    result = is_pivot(a,4,2u);
    printf("%s", (result == 1) ? "True" : "False");
    return 0;
}