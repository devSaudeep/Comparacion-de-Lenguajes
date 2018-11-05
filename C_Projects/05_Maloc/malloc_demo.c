/*
 * malloc_demo.c
 * By Antonio F. Huertas
 * This program demonstrates dynamic memory allocation and deallocation
 * of primitives, structured values and arrays.
 */

#include <stdio.h>   // for fprintf, printf, scanf, puts
#include <stddef.h>  // for NULL
#include <stdlib.h>  // for malloc, free, exit

// Defines a data structure.
typedef struct {
    float x, y;
} Point;

// Starts the execution of the program.
int main(void) {
    int *ptr_int = malloc(sizeof(int));
    if (ptr_int == NULL) {
        fprintf(stderr, "Error! Cannot allocate memory for an integer.");
        exit(1);
    }
    puts("An integer has been created in the heap.");

    printf("\nEnter the value for the integer: ");
    scanf("%d", ptr_int);
    printf("The integer is %d\n", *ptr_int);

    (*ptr_int)++;
    printf("After incrementing, the integer is %d\n\n", *ptr_int);

    Point *ptr_point = malloc(sizeof(Point));
    if (ptr_point == NULL) {
        fprintf(stderr, "Error! Cannot allocate memory for a point.");
        exit(1);
    }
    puts("A point has been created in the heap.");

    printf("\nEnter the x,y coordinates for the point: ");
    scanf("%f %f", &ptr_point->x, &ptr_point->y);
    printf("The point is (%.1f, %.1f)\n", ptr_point->x, ptr_point->y);

    ptr_point->x++, ptr_point->y++;
    printf("After incrementing, the point is (%.1f, %.1f)\n\n",
           ptr_point->x, ptr_point->y);

    int arr_length;
    printf("Enter the length of the array: ");
    scanf("%d", &arr_length);

    int *ptr_arr = malloc(arr_length * sizeof(int));
    if (ptr_arr == NULL) {
        fprintf(stderr, "Error! Cannot allocate memory for an array.");
        exit(1);
    }
    puts("An array has been created in the heap.");

    printf("\nEnter %d elements: ", arr_length);
    for (int idx = 0; idx < arr_length; idx++)
        scanf("%d", &ptr_arr[idx]);

    printf("The array is [ ");
    for (int idx = 0; idx < arr_length; idx++)
        printf("%d ", ptr_arr[idx]);
    puts("]");

    for (int idx = 0; idx < arr_length; idx++)
        ptr_arr[idx]++;

    printf("After incrementing the elements, the array is [ ");
    for (int idx = 0; idx < arr_length; idx++)
        printf("%d ", ptr_arr[idx]);
    puts("]");

    free(ptr_int);
    ptr_int = NULL;
    puts("\nThe integer has been deallocated.");

    free(ptr_point);
    ptr_point = NULL;
    puts("The point has been deallocated.");

    free(ptr_arr);
    ptr_arr = NULL;
    puts("The array has been deallocated.");
    return 0;
}
