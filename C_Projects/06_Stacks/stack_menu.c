/*
 * stack_menu.c
 * By Antonio F. Huertas
 * This program manages a menu of common stack operations.
 */

#include "stack.h"   // for Stack and its functions
#include <stdio.h>   // for printf, scanf, getchar, puts
#include <stddef.h>  // for NULL definition
#include <stdlib.h>  // for malloc, free

// Declares functions using prototypes.
void show_menu(void);
int read_selection(void);
void process_selection(int sel, Stack *stk);
void process_push(Stack *stk);
void process_pop(Stack *stk);
void process_view(const Stack *stk);
void show_character(const void *elem);
void destroy_character(const void *elem);

// Starts the execution of the program.
int main(void) {
    Stack *stk = create_stack();
    puts("A stack has been created.");

    int sel = 0;
    do {
        show_menu();
        sel = read_selection();
        process_selection(sel, stk);
    } while (sel != 0);

    iterate_stack(stk, &destroy_character);
    destroy_stack(stk);
    stk = NULL;
    puts("The stack has been deallocated.");
    return 0;
}

// Shows the menu options.
void show_menu(void) {
    puts("\nStack Menu\n");
    puts("1. Push an element");
    puts("2. Pop an element");
    puts("3. View the contents");
    puts("0. Exit");
}

// Returns the menu option selected.
int read_selection(void) {
    int sel;
    printf("Enter your selection: ");
    scanf("%d", &sel);
    while (getchar() != '\n');  // flush keyboard buffer
    return sel;
}

// Processes the given menu selection and updates the stack.
void process_selection(int sel, Stack *stk) {
    switch (sel) {
        case 1: process_push(stk); break;
        case 2: process_pop(stk); break;
        case 3: process_view(stk); break;
        case 0: puts("Thanks for using this program."); break;
        default: puts("Error! Selection must be between 0 and 3.");
    }
}

// Process the push element menu option.
void process_push(Stack *stk) {
    char *elem = malloc(sizeof(char));
    printf("Enter a character: ");
    scanf("%c", elem);
    push(stk, elem);
    printf("%c has been pushed into the stack.\n", *elem);
}

// Process the pop element menu option.
void process_pop(Stack *stk) {
    char *elem = pop(stk);
    if (elem == NULL)
        puts("Could not pop.  Stack is empty.");
    else {
        printf("%c has been popped from the stack.\n", *elem);
        free(elem);
    }
}

// Process the view contents menu option.
void process_view(const Stack *stk) {
    if (is_empty_stack(stk))
        puts("Cannot show.  Stack is empty.");
    else {
        printf("These are the contents of the stack: ");
        iterate_stack(stk, &show_character);
        printf("\n");
    }
}

// Displays a character.
void show_character(const void *elem) {
    printf("%c ", *(char *)elem);
}

// Deallocates the memory of a character.
void destroy_character(const void *elem) {
    free((char *)elem);
}
