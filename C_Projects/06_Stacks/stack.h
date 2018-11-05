/*
 * stack.h
 * By Antonio F. Huertas
 * Header (interface) file for a generic stack.
 */

#ifndef STACK_H       // prevents double inclusion
#define STACK_H

#include <stdbool.h>  // for bool

// Defines Stack as an alias for an opaque structure.
typedef struct stack Stack;

// Returns a new empty stack.
Stack *create_stack(void);

// Determines whether the given stack is empty.
bool is_empty_stack(const Stack *stk);

// Adds an element to the top of the given stack.
void push(Stack *stk, const void *elem);

// Removes and returns the element at the top of the given stack.
// Returns NULL if the stack is empty.
void *pop(Stack *stk);

// Iterates through the given stack using a visit function.
void iterate_stack(const Stack *stk,
                   void (*visit)(const void *elem));

// Deallocates the memory of the given stack.
void destroy_stack(Stack *stk);

#endif
