#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "cost.h"
#include "graph.h"
#include "mini_set.h"

typedef unsigned int elem_arr;

static vertex_t min_array(set conj, cost_t *arr,unsigned int len){
    vertex_t min = __INT_MAX__;
    unsigned int min_pos = 0u;

    for (unsigned int i=0u; i < len; i++){
        if(set_member((cost_t)i,conj)){         
            if (cost_le(arr[i],(cost_t)min)){
                min = arr[i];
                min_pos = i;
            }
        }
    } 
    return min_pos;
}

static void update_cost(graph_t graph,set conj, cost_t *arr, int c,unsigned int len){
    for (unsigned int j=0u; j < len; j++){
        if (set_member((cost_t)j,conj)) {
            unsigned int cost = graph_get_cost(graph,c,j);
            arr[j] = (cost_le(arr[j],cost_sum(arr[c],cost) )) ? arr[j] : cost_sum(arr[c],cost); 
        }
    }    
}


cost_t *dijkstra(graph_t graph, vertex_t init) {
    unsigned int c = 0u;
    set conj = set_empty();
    unsigned int len = graph_max_vertexs(graph);
    
    cost_t* arr_costo = calloc(len, sizeof(cost_t));

    for (unsigned int i=0u; i < len; i++){
        
        conj = set_add(conj,i);
    
    }

    conj = set_elim(conj,init);

    for (unsigned int j=0u; j < len; j++){
        arr_costo[j] = graph_get_cost(graph,init,j);
    }

    while(!(set_is_empty(conj))){
        c = min_array(conj,arr_costo,len);
        conj = set_elim(conj,c);
        printf("%u",set_cardinal(conj));
        update_cost(graph,conj,arr_costo,c,len);
    }

    set_destroy(conj);
    return arr_costo;
}
