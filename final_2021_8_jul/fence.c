#include <stdlib.h>
#include "fence.h"
#include <assert.h>

struct _fence_t {
    fence_t next;
    type_t type;
};

static bool inverp(fence_t f){
    return f != NULL;
}

fence_t fence_P(){
    fence_t fp = malloc(sizeof(struct _fence_t));
    fp->next = NULL;
    fp->type = 0;
    return fp;
}

fence_t fence_add_P(fence_t fence){
    assert(inverp(fence));
    fence_t np = malloc(sizeof(struct _fence_t));
    np->next = NULL;
    np->type = 0;
    
    fence_t aux = fence;
    while(aux->next != NULL){
        aux = aux->next;
    }
    aux->next = np;
    return fence;
}

fence_t fence_add_A(fence_t fence){
    assert(inverp(fence));
    fence_t na = malloc(sizeof(struct _fence_t));
    na->next = NULL;
    na->type = 1;
    
    fence_t aux = fence;
    while(aux->next != NULL){
        aux = aux->next;
    }
    aux->next = na;
    return fence;
}

fence_t fence_add_H(fence_t fence){
        assert(inverp(fence));
    fence_t nh = malloc(sizeof(struct _fence_t));
    nh->next = NULL;
    nh->type = 2;
    
    fence_t aux = fence;
    while(aux->next != NULL){
        aux = aux->next;
    }
    aux->next = nh;
    return fence;
}

fence_t fence_add_T(fence_t fence){
    assert(inverp(fence));
    fence_t nt = malloc(sizeof(struct _fence_t));
    nt->next = NULL;
    nt->type = 3;
    
    fence_t aux = fence;
    while(aux->next != NULL){
        aux = aux->next;
    }
    aux->next = nt;
    return fence;
}
 
bool fence_is_correct(fence_t fence){
    assert(inverp(fence));
    fence_t aux = fence->next;
    fence_t prev_ref = fence;
    int t = 1;
    bool status = true;
    
    while(aux != NULL){
                
        // P --- P
        if (aux->type == 3 || aux->type == 2 || aux->type == 1){
            //Chequeo de tranquera
            t = (aux->type == 3) ? t - 1 : t;
            if (aux->next != NULL){
                if (prev_ref->type == 0 && aux->next->type == 0){
                    status = true && status;
                }
                else{
                    status = false;
                }
            }
            else{
                status = false;
            }
        }
        prev_ref = aux;
        aux = aux->next;
    }

    //chequeado que primer el sea un poste
    status = (fence->type != 0) ? false : true && status; 
    //chequeado que el ultimo sea un poste
    status = (prev_ref->type != 0) ? false : true && status; 
    //chequeo que haya al menos una tranquera
    status = (t <= 0) ? true && status : false;
    return status;    

}

unsigned int fence_perimeter(fence_t fence){
    assert(inverp(fence));
    fence_t aux = fence;
    unsigned int per = 0u; 
    while(aux != NULL){
        per = (aux->type != 0) ? per + 3 : per;
        aux = aux->next;
    }
    return per;
}

unsigned int fence_size(fence_t fence){
    fence_t aux = fence;
    unsigned int size = 0u; 
    while(aux != NULL){
        size = size + 1;
        aux = aux->next;
    }
    return size;
}

type_t *fence_to_array(fence_t fence){
    assert(inverp(fence));
    unsigned int size = fence_size(fence);
    type_t *array = calloc(size,sizeof(type_t));
    fence_t aux = fence;

    for (unsigned int i = size -1; (int)i >= 0; i--){
        array[i] = aux->type;
        aux = aux->next;
    }
    return array;
}
fence_t fence_destroy(fence_t fence){
    assert(inverp(fence));
    fence_t aux;
    while(fence != NULL){
        aux = fence->next;
        fence->next = NULL;
        free(fence);
        fence = aux;
    }
    return fence;
}
