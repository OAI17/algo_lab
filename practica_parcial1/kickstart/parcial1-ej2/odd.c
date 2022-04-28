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
    
    unsigned int j=0u,temp;
    bool status=true,imp;
    
    while (j<length && status){
        
        imp = impar(j);
        (imp==true) ? temp=j : j++;
        
        if (imp){
            if (!(array[temp] < array[j])){
                status = false;
                
            }
            j++;
        }
        
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