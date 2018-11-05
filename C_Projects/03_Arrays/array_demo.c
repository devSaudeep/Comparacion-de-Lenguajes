/*
 * array_demo.c
 * By Antonio F. Huertas
 * This program demonstrates some basic array operations.
 */

#include <stdio.h>    // for printf, scanf
#include <stdlib.h>   // for bsearch, qsort

// Defines a symbolic constant
#define LENGTH 5

// Declares functions using prototypes.
void read_array(int arr[], int len);
void show_array(const int arr[], int len);
int ascending(const void *a, const void *b);
int descending(const void *a, const void *b);

// Starts the execution of the program.
int main(void) {
    int arr1[LENGTH];

    printf("Enter %d elements for arr1: ", LENGTH);
    read_array(arr1, LENGTH);
    printf("\n");

    printf("This is arr1: ");
    show_array(arr1, LENGTH);
    printf("\n");

    qsort(arr1, LENGTH, sizeof(int), &ascending);
    printf("After ascending sorting, this is arr1: ");
    show_array(arr1, LENGTH);
    printf("\n");

    int value;
    printf("Enter the value to search in arr1: ");
    scanf("%d", &value);

    int *ptr =
        bsearch(&value, arr1, LENGTH, sizeof(int), &ascending);
    if (ptr == NULL)
        printf("The value was not found.\n");
    else
        printf("The value was found at index #%d\n", ptr - arr1);
    printf("\n");

    int arr2[] = {20, 7, 56, 13, 42, 8, 39};
    int arr2_length = sizeof(arr2) / sizeof(int);

    printf("This is arr2: ");
    show_array(arr2, arr2_length);
    printf("\n");

    qsort(arr2, arr2_length, sizeof(int), &descending);
    printf("After descending sorting, this is arr2: ");
    show_array(arr2, arr2_length);
    return 0;
}

// Reads the contents of the given array.
void read_array(int arr[], int len) {
    for (int idx = 0; idx < len; idx++)
        scanf("%d", &arr[idx]);
}

// Displays the contents of the given array.
void show_array(const int arr[], int len) {
    for (int idx = 0; idx < len; idx++)
        printf("%d ", arr[idx]);
    printf("\n");
}

// Returns the result of an ascending comparison.
int ascending(const void *a, const void *b) {
   return *(int*)a - *(int*)b;
}

// Returns the result of a descending comparison.
int descending(const void *a, const void *b) {
   return *(int*)b - *(int*)a;
}
