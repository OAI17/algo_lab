/**
*  @file stack.h
*  @brief TAD Stack definition
*/
#ifndef __STACK_H__
#define __STACK_H__

#include <stdbool.h>


/**
* @brief Stack type definition
*/
typedef struct _s_stack *stack;

/**
* @brief Stack elements type definition
*/
typedef int stack_elem;


/*New implementation*/

typedef struct base_s *base;

typedef unsigned int base_size;
/**
* @brief Creates an empty stack
* @return An empty stack
*/
base stack_empty();

/**
* @brief Inserts an element at the top of the stack
* @param s A stack
* @param e An element to push into the stack
* @return The new stack with 'e' at the top
*/
base stack_push(base s, stack_elem e);

/**
* @brief Removes the element at the top of the stack
* @param s A stack
* @return The new stack with the top element removed
* @note Only applies to non-empty stacks
*/
base stack_pop(base s);

/**
* @brief Returns the size of the stack
* @param s A stack
* @return The size of the stack
*/
unsigned int stack_size(base s);

/**
* @brief Returns the element at the top of the stacks
* @param s A stacks
* @return The element at the top of the stack
* @note Only applies to non-empty stacks
*/
stack_elem stack_top(base s);

/**
* @brief Check if the given stack is empty
* @param s A stack
* @return true if the stack is empty, false otherwise
*/
bool stack_is_empty(base s);

/**
* @brief Creates an array with all the elements of the stack
* @param s A stack
* @return An array containing all the elements of the stack. The stack top element
* becomes the rightmost element of the array. The size of the resulting
* array is determined by 'stack_size(s)'
*/
stack_elem *stack_to_array(base s);

/**
* @brief Destroys the stack
* @param s A stack
* @note All memory resources are freed
*/
base stack_destroy(base s);


#endif
