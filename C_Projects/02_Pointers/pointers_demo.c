/*
 * pointers_demo.c
 * By Antonio F. Huertas
 * This program demonstrates the use of pointers.
 */

#include <stdio.h>     // for printf
#include <stddef.h>    // for NULL

// Starts the execution of the program.
int main(void) {
    int m = 5, n = 10;
    float x = 8.765;
    printf("m = %d and its address is %p\n", m, &m);
    printf("n = %d and its address is %p\n", n, &n);
    printf("x = %.3f and its address is %p\n\n", x, &x);

    int *p1 = &m;
    int *p2 = &n;
    float *p3 = &x;
    printf("*p1 = %d and p1 = %p\n", *p1, p1);
    printf("*p2 = %d and p2 = %p\n", *p2, p2);
    printf("*p3 = %.3f and p3 = %p\n\n", *p3, p3);

    p1 = p2;
    printf("*p1 = %d and p1 = %p\n", *p1, p1);
    printf("*p2 = %d and p2 = %p\n\n", *p2, p2);

    (*p2)++;
    printf("*p1 = %d and p1 = %p\n", *p1, p1);
    printf("*p2 = %d and p2 = %p\n\n", *p2, p2);

    p1 = p2 = p3 = NULL;
    printf("p1 = %p, p2 = %p and p3 = %p\n\n", p1, p2, p3);

    void *p4 = &m;
    printf("*p4 = %d and p4 = %p\n\n", *(int *)p4, p4);

    p4 = &x;
    printf("*p4 = %.3f and p4 = %p\n\n", *(float *)p4, p4);

    p4 = NULL;
    printf("p4 = %p\n", p4);
    return 0;
}
