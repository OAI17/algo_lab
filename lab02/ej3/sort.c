#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static unsigned int partition(int a[], unsigned int izq, unsigned int der){
    int piv;
    unsigned int j,i;
    piv = izq;
    i = izq+1;
    j = der;
    
    while(i <= j){
       if (goes_before(a[i],a[piv])){
           i = i+1;
       }
       else{

        if (goes_before(a[piv],a[j])){
                j = j-1;
            }
        else{
            if ((abs(a[i]) > abs(a[piv])) && (abs(a[j]) < abs(a[piv]))){
                swap(a,i,j);
            }
        }

       }
       
   }
    
    swap(a,j,piv);
    piv = j;
    return piv;
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
 /* needs implementation */
    int pivot;

    if (der > izq){
        pivot = partition(a,izq,der); 
        if (pivot == 0){
            quick_sort_rec(a,izq,pivot);
            quick_sort_rec(a,pivot+1,der);
        }
        else{
            quick_sort_rec(a,izq,pivot-1);
            quick_sort_rec(a,pivot+1,der);
        }

    }
}
void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
    
}

