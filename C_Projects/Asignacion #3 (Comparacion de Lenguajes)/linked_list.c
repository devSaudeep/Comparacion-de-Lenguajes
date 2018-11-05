/*
 * linked_list.c
 * By Antonio F. Huertas
 * Edited by Saulo Almeda Nieves
 * 841-13-0170
 * 11 / 2 / 2015
 * This program defines and manipulates a linked list.
 */

#include <stdio.h>   // for puts, printf, scanf
#include <stdbool.h> // for bool, true, false;
#include <stddef.h>  // for NULL
#include <stdlib.h>  // for malloc, free

// Defines an alias for the node structure.
typedef struct node Node;

// Declares a structure for nodes.
struct node {
    int data;
    Node *next;
};

// Defines the data structure for a list.
typedef struct {
    Node *head;
} List;

// Declares functions using prototypes.
List *create_list(void);
void add_list(List *lst, int val);
void show_list(const List *lst);
int sum_list(const List *lst);
bool search_list(const List *lst, int val);
void destroy_list(List *lst);

//Added function prototypes
int length_list(const List *lst);
int minimum_list(const List *lst);

// Starts the execution of the program.
int main(void) {
    List *lst = create_list();
    puts("A linked list has been created.");

    add_list(lst, 40);
    add_list(lst, 10);
    add_list(lst, 20);
    add_list(lst, 50);
    add_list(lst, 30);

    printf("After adding some elements, the linked list is ");
    show_list(lst);
    printf("\nThe sum of its elements is %d\n\n", sum_list(lst));

    int num;
    printf("Enter a number to be searched: ");
    scanf("%d", &num);

    bool found = search_list(lst, num);
    if (found)
        puts("The number was found!");
    else
        puts("The number was NOT found.");

    printf("\nEnter a number to be added to the list: ");
    scanf("%d", &num);
    add_list(lst, num);

    printf("After adding a new element, the linked list is ");
    show_list(lst);
    printf("\nThe sum of its elements is %d\n\n", sum_list(lst));

    printf("\nThe length of the linked list is: %d\n\n", length_list(lst));

    printf("\nThe minimum element of the linked list is: %d\n\n", minimum_list(lst));

    destroy_list(lst);
    lst = NULL;
    puts("The linked list has been deallocated.");
    return 0;
}

//Returns the number of elements in the given list.
int length_list(const List *lst) {
    int len = 1;
    Node *curr = lst->head;
    while(curr->next != NULL) {
        curr = curr->next;
        len++;
    }
    return len;
}

//Returns the minimum element in the given list.
int minimum_list(const List *lst) {
    int min = lst->head->data;
    Node *curr = lst->head->next;
    while(curr->data < min) {
        min = curr->data;
        curr = curr->next;
    }
    return min;
}

// Returns a new empty list.
List *create_list(void) {
    List *lst = malloc(sizeof(List));
    lst->head = NULL;
    return lst;
}

// Adds a new value to the given list.
void add_list(List *lst, int val) {
    Node *temp = malloc(sizeof(Node));
    temp->data = val;
    temp->next = lst->head;
    lst->head = temp;
}

// Shows the contents of the given list.
void show_list(const List *lst) {
    for (Node *curr = lst->head; curr != NULL; curr = curr->next)
        printf("%d ", curr->data);
}

// Returns the sum of the given list.
int sum_list(const List *lst) {
    int sum = 0;
    for (Node *curr = lst->head; curr != NULL; curr = curr->next)
        sum += curr->data;
    return sum;
}

// Determines whether the given list contains the given value.
bool search_list(const List *lst, int val) {
    for (Node *curr = lst->head; curr != NULL; curr = curr->next)
        if (val == curr->data)
            return true;
    return false;
}

// Frees the memory allocated for the given list.
void destroy_list(List *lst) {
    while (lst->head != NULL) {
        Node *curr = lst->head;
        lst->head = lst->head->next;
        free(curr);
    }
    free(lst);
}
