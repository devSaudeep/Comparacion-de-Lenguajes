/*
 * stack_lnk.c
 * By Antonio F. Huertas
 * Source file for a generic stack implemented using a linked list.
 */

#include "stack.h"   // for Stack and its functions
#include <stddef.h>  // for NULL definition
#include <stdlib.h>  // for malloc and free

// Defines Node as an alias for the node structure.
typedef struct node Node;

// Declares the node structure.
struct node {
    void *data;   // pointer to generic data
    Node *next;   // pointer to the next node in the internal linked list
};

// Defines the stack structure.
struct stack {
    Node *top;    // pointer to the top element
};

// Returns a new empty stack.
Stack *create_stack(void) {
    Stack *stk = malloc(sizeof(Stack));
    stk->top = NULL;
    return stk;
}

// Determines whether the given stack is empty.
bool is_empty_stack(const Stack *stk) {
    return stk->top == NULL;
}

// Adds an element to the top of the given stack.
void push(Stack *stk, const void *elem) {
    Node *temp = malloc(sizeof(Node));
    temp->data = elem;
    temp->next = stk->top;
    stk->top = temp;
}

// Removes and returns the element at the top of the given stack.
// Returns NULL if the stack is empty.
void *pop(Stack *stk) {
    if (is_empty_stack(stk))
        return NULL;

    Node *temp = stk->top;
    void *elem = temp->data;
    stk->top = temp->next;
    free(temp);
    return elem;
}

// Iterates through the given stack using a visit function.
void iterate_stack(const Stack *stk,
                   void (*visit)(const void *elem)) {
    for (Node *curr = stk->top; curr != NULL; curr = curr->next)
        visit(curr->data);
}

// Deallocates the memory of the stack.
void destroy_stack(Stack *stk) {
    while (stk->top != NULL) {
        Node *curr = stk->top;
        stk->top = curr->next;
        free(curr);
    }
    free(stk);
}
