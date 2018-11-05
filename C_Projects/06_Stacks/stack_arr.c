/*
 * stack_arr.c
 * By Antonio F. Huertas
 * Source file for a generic stack implemented using an array.
 */

#include "stack.h"   // for Stack and its functions
#include <stddef.h>  // for NULL
#include <stdlib.h>  // for malloc and free

// Defines the stack structure.
struct stack {
    int capacity;  // current capacity of internal array
    void **data;   // pointer to array of pointers to generic data
    int top;       // index of top element
};

// Declares a local function using a prototype.
static void ensure_capacity(Stack *stk);

// Returns a new empty stack.
Stack *create_stack(void) {
    Stack *stk = malloc(sizeof(Stack));
    stk->capacity = 10;
    stk->data = malloc(stk->capacity * sizeof(void *));
    stk->top = -1;
    return stk;
}

// Determines whether the given stack is empty.
bool is_empty_stack(const Stack *stk) {
    return stk->top == -1;
}

// Adds an element to the top of the given stack.
void push(Stack *stk, const void *elem) {
    ensure_capacity(stk);
    stk->data[++stk->top] = elem;
}

// Ensures that the given stack has the capacity for addition.
static void ensure_capacity(Stack *stk) {
    if (stk->top + 1 == stk->capacity) {
        stk->capacity *= 2;
        void **temp = malloc(stk->capacity * sizeof(void *));

        for (int curr = stk->top; curr >= 0; curr--)
            temp[curr] = stk->data[curr];
        free(stk->data);
        stk->data = temp;
    }
}

// Removes and returns the element at the top of the given stack.
// Returns NULL if the stack is empty.
void *pop(Stack *stk) {
    if (is_empty_stack(stk))
        return NULL;
    return stk->data[stk->top--];
}

// Iterates through the given stack using a visit function.
void iterate_stack(const Stack *stk,
                   void (*visit)(const void *elem)) {
    for (int curr = stk->top; curr >= 0; curr--)
        (*visit)(stk->data[curr]);
}

// Deallocates the memory of the given stack.
void destroy_stack(Stack *stk) {
    free(stk->data);
    free(stk);
}
