/*
 * array_demo.c
 * By Antonio F. Huertas
 * Edited by Saulo Almeda Nieves
 * 10/13/15
 * 841-13-0170
 * This program defines some basic array functions.
 */

#include <stdio.h>    // for printf, scanf

// Defines a symbolic constant
#define LENGTH 5

// Declares functions using prototypes.
void read_array(int *arr, int len);
void show_array(const int *arr, int len);
int sum_array(const int *arr, int len);
void insertion_sort(int arr[], int len,
                    int (*compare)(int a, int b));
int binary_search(int key, const int arr[], int len,
                    int (*compare)(int a, int b));
int ascending(int a, int b);
int descending(int a, int b);
int linear_search(int arr[], int len, int elem);
void selection_sort(int arr[], int len,
    int (*compare)(int val1, int val2));

// Starts the execution of the program.
int main(void) {
    int arr1[LENGTH];

    printf("Enter %d elements for arr1: ", LENGTH);
    read_array(arr1, LENGTH);
    printf("\n");

    printf("This is arr1: ");
    show_array(arr1, LENGTH);
    printf("\n");

    printf("The sum of its elements is %d\n",
           sum_array(arr1, LENGTH));
    printf("\n");

    insertion_sort(arr1, LENGTH, &ascending);
    printf("This is arr1, sorted in ascending order: ");
    show_array(arr1, LENGTH);
    printf("\n");

    int value;
    printf("Enter a value to search: ");
    scanf("%d", &value);

    int index = binary_search(value, arr1, LENGTH, &ascending);
    if (index == -1)
        printf("The value was not found.\n");
    else
        printf("The value was found at index #%d\n", index);
    printf("\n");

    insertion_sort(arr1, LENGTH, &descending);
    printf("This is arr1, sorted in descending order: ");
    show_array(arr1, LENGTH);
    printf("\n");

    index = binary_search(value, arr1, LENGTH, &descending);
    if (index == -1)
        printf("The value was not found.\n");
    else
        printf("The value was found at index #%d\n", index);

    printf("--------------------------------------------------------------\n");
    printf("Enter a value to search: ");
    scanf("%d", &value);

    index = linear_search(arr1, LENGTH, value);
    if (index == -1)
        printf("The value was not found.\n");
    else
        printf("The value was found at index #%d\n", index);
    printf("\n");
    return 0;
}

//Devuelve la posicion del elemento que se esta buscando.
int linear_search(int arr[], int len, int elem) {
    for(int idx = 0; idx < len; idx++) {
        if(elem == arr[idx])
            return idx;
    }
    return -1;
}

// Reads the contents of the given array.
void read_array(int *arr, int len) {
    for (int idx = 0; idx < len; idx++)
        scanf("%d", arr + idx);
}

// Displays the contents of the given array.
void show_array(const int *arr, int len) {
    for (int idx = 0; idx < len; idx++)
        printf("%d ", *(arr + idx));
    printf("\n");
}

// Returns the sum of the elements in the given array.
int sum_array(const int *arr, int len) {
    int sum = 0;
    for (int idx = 0; idx < len; idx++)
        sum += arr[idx];   // alt.: sum += *(arr + idx);
    return sum;
}

// Sorts the elements of the given array.
void insertion_sort(int arr[], int len,
                    int (*compare)(int a, int b)) {

    for (int idx = 1; idx < len; idx++) {
        int  temp = arr[idx], pos = idx;
        int cmp = (*compare)(arr[pos - 1], temp);
        while (pos > 0 && cmp > 0) {
            arr[pos] = arr[pos - 1];
            pos--;
            cmp = (*compare)(arr[pos - 1], temp);
        }
        arr[pos] = temp;
    }
}

// Returns the index of a key in the given array.
int binary_search(int key, const int arr[], int len,
                    int (*compare)(int a, int b)) {
    int lo = 0, hi = len - 1;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int cmp = (*compare)(key, arr[mid]);
        if (cmp < 0)
            hi = mid - 1;
        else if (cmp > 0)
            lo = mid + 1;
        else
            return mid;   // found at mid
    }
    return -1;            // not found
}

// Returns the result of an ascending comparison.
int ascending(int a, int b) {
    return a - b;
}

// Returns the result of a descending comparison.
int descending(int a, int b) {
    return b - a;
}
