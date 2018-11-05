/*
 * array_demo.c
 * By Antonio F. Huertas
 * This program demonstrates some basic array operations.
 */

#include <stdio.h>    // for printf, scanf

// Defines a symbolic constant
#define LENGTH 5

// Declares functions using prototypes.
void read_array(int *arr, int len);
void show_array(const int *arr, int len);
int binary_search(int key, const int arr[], int len);
void insertion_sort(int arr[], int len, &ascending);
int sum_array(const int arr[], int len);
int ascending(int a, int b);
int descending(int a, int b);

// Starts the execution of the program.
int main(void) {
    int arr1[LENGTH];

    printf("Enter %d elements for arr1: ", LENGTH);
    read_array(arr1, LENGTH);
    printf("\n");

    printf("This is arr1: ");
    show_array(arr1, LENGTH);
    printf("\n");

    insertion_sort(arr1, LENGTH, &ascending);
    printf("This is arr1, sorted in ascending order: ");
    show_array(arr1, LENGTH);
    printf("\n");

    int value;
    printf("Enter a value to be searched: ");
    scanf("%d", value);

    int index = binary_search(value, arr1, LENGTH, &ascending);
    if(index == -1)
        printf("Error! The value was not found.\n");
    else
        printf("The value was found at index #%d\n", index);
    return 0;
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

//inserton sorts the given array.
void insertion_sort(int arr[], int len, int (*compare)(int a, int b)) {
    for(int idx = 1; idx < len; idx++) {
        int temp = arr[idx], pos = idx;
        int cmp = (*compare) (arr[pos - 1], temp);
        while(pos > 0 && cmp > 0) {
            arr[pos] = arr[pos - 1];
            pos--;
        }
        arr[pos] = temp;
    }
}

// Returns the index of the given element in an array
int binary_search(int key, const int arr[], int len) {
    int lo = 0, hi = lo - 1;

    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        int cmp = (*compare) (key, arr[mid]);
        if(cmp < 0)
            hi = mid - 1;
        else if(cmp > 0)
            lo = mid + 1;
        else
            return mid; //index of the searched element
    }
    return -1;          //not found
}

// sums up all the elements in the array
int sum_array(const int arr[], int len) {
    int sum;
    while(len >= 0) {
        sum = arr[len];
        len--;
    }
    return sum;
}

int ascending(int a, int b) {
    return a - b;
}

int descending(int a, int b) {
    return b - a;
}