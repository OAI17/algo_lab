#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "abb.h"

struct _s_abb {
    abb_elem elem;
    struct _s_abb *left;
    struct _s_abb *right;
};

/*
static bool elem_eq(abb_elem a, abb_elem b) {
    return a == b;
}

static bool elem_less(abb_elem a, abb_elem b) {
    return a < b;
}
*/

static bool invrep(abb tree) {
    bool status = true;
    if (tree != NULL){
        abb sub_tree;
        if(tree->left != NULL){
            /*Compara*/
            sub_tree = tree->left;
            status = status && (tree->elem > sub_tree->elem); 
            /*Recursion*/
            status = status && invrep(sub_tree);
        }

        if (tree->right != NULL){
            /*Compara*/ 
            sub_tree = tree->right;
            status = status && (tree->elem < sub_tree->elem);
            /*Recursion*/ 
            status = status && invrep(sub_tree);
        }
    }
    return status;
}

abb abb_empty(void) {
    abb tree;
    tree =  NULL;
    assert(invrep(tree) && abb_is_empty(tree));
    return tree;
}

static abb create_leaf(abb_elem e){
    /*Crear nuevo nodo*/
    abb new_node = abb_empty();
    new_node = malloc(sizeof(struct _s_abb));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->elem = e;
    return new_node;
}

abb abb_add(abb tree, abb_elem e) {
    assert(invrep(tree));
    
    if (tree == NULL){         
        tree = create_leaf(e);
    }            
    else if(tree->elem < e){
        tree->right = abb_add(tree->right,e);
    }
    else if(tree->elem > e){ 
        tree->left = abb_add(tree->left,e); 
    }

    assert(invrep(tree) && abb_exists(tree, e)); 
    return tree;
}

bool abb_is_empty(abb tree) {
    bool is_empty=false;
    assert(invrep(tree));
    is_empty = (tree == NULL) ? true : false;
    return is_empty;
}

bool abb_exists(abb tree, abb_elem e) {
    bool exists=false;
    assert(invrep(tree));
    
    if(tree != NULL){
        abb_elem root = tree->elem;
        
        if (root == e){
            exists = true;
        }

        else{
            if(e < root){
                /*Lo busco a la izq*/
                exists = exists | abb_exists(tree->left,e);
            }
            else{
                /*Lo busco a la der*/
                exists = exists | abb_exists(tree->right,e);
            }
        }
    }
    return exists;
}

unsigned int abb_length(abb tree) {
    unsigned int length=0;
    assert(invrep(tree));

    if (tree != NULL){
        length += 1u;
        if (tree->left != NULL){
            length = length + abb_length(tree->left);
        }
        if (tree->right != NULL){
            length = length + abb_length(tree->right);
        }
    }

    assert(invrep(tree) && (abb_is_empty(tree) || length > 0));
    return length;
}

abb delete_max(abb tree){
    abb aux1,aux2;
    aux1 = tree;
    while(aux1->right != NULL){
        aux2 = aux1->right;
        aux1 = aux2;
    }
    free(aux1);
    aux1 = NULL;
    return tree;
}

abb abb_remove(abb tree, abb_elem e) {
    assert(invrep(tree));
    if (!abb_is_empty(tree)){
        abb_elem root = tree->elem;
        if (root == e){
            
            
            /*Identificar en que caso de nodo estoy*/
                /*Caso 1*/
            if (tree->left == NULL && tree->right == NULL){
                free(tree);
                tree = NULL;
            }

            else if (tree->left == NULL && tree->right != NULL){
                /*Caso 2*/
                abb aux1,aux2;
                aux2 = tree;
                aux1 = tree->right;
                tree = aux1;
                free(aux2);
                aux2 = NULL;
            }
            
            else if (tree->right == NULL && tree->left != NULL){
                /*Caso 3*/
                abb aux1,aux2;
                aux2 = tree;
                aux1 = tree->left;
                tree = aux1;
                free(aux2);
                aux2 = NULL;
            }
            
            else if (tree->left != NULL && tree->right != NULL){
                /*Caso 4*/
                /*Busco el max de los min*/
                abb_elem max = abb_max(tree->left);
                
                /*Eliminar al max del arbol*/
                tree->left = abb_remove(tree->left,max);

                /*Remplazo el nodo a borrar por el max de los min*/
                tree->elem = max;
            }
            
        }

        else if (root > e){
            tree->left = abb_remove(tree->left,e);
        }

        else{
            tree->right = abb_remove(tree->right,e);
        }

    }
    assert(invrep(tree) && !abb_exists(tree, e));
    return tree;
}


abb_elem abb_root(abb tree) {
    abb_elem root;
    assert(invrep(tree) && !abb_is_empty(tree));
    root = tree->elem;
    assert(abb_exists(tree, root));
    return root;
}

abb_elem abb_max(abb tree) {
    abb_elem max_e;
    assert(invrep(tree) && !abb_is_empty(tree));

    /*Por def se que el max es el que esta mas a la der*/    
    max_e = tree->elem;
    if (tree->right != NULL){
        max_e = abb_max(tree->right);
    }
    
    
    assert(invrep(tree) && abb_exists(tree, max_e));
    return max_e;
}


abb_elem abb_min(abb tree) {
    abb_elem min_e;
    assert(invrep(tree) && !abb_is_empty(tree));

    /*Por def se que el min es el que esta mas a la izq*/    
    min_e = tree->elem;
    if (tree->left != NULL){
        min_e = abb_min(tree->left);
    }
    
    assert(invrep(tree) && abb_exists(tree, min_e));
    return min_e;
}

void abb_dump(abb tree) {
    assert(invrep(tree));
    if (tree != NULL) {
        printf("%d ", tree->elem);
        abb_dump(tree->left);
        abb_dump(tree->right);
    }
}

abb abb_destroy(abb tree) {
    assert(invrep(tree));
    
    if (tree != NULL){
        abb sub_treeR,sub_treeL;
        /*Guardo los siguientes*/
        sub_treeL = tree->left;
        sub_treeR = tree->right;
        
        /*Free de la riaz*/
        free(tree);

        /*Recursion a las dos ramas*/
        tree = abb_destroy(sub_treeL);
        tree = abb_destroy(sub_treeR);    

    }
    assert(tree == NULL);
    return tree;
}

