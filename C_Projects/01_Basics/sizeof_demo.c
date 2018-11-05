/*
 * sizeof_demo.c
 * By Antonio F. Huertas
 * This program demonstrates the sizeof operator.
 */

#include <stdio.h>    // for printf
#include <stdbool.h>  // for bool, true, false

// Starts the execution of the program.
int main(void) {
    char charVar = 'a';
    bool boolVar = true;
    int intVar = 5;
    float floatVar = 12.345;
    double doubleVar = 1234.56789;

    printf("charVar = %c with %d bytes\n", charVar, sizeof(charVar));
    printf("charVar = %d with %d bytes\n", charVar, sizeof(charVar));

    printf("boolVar = %s with %d bytes\n",
           boolVar? "true" : "false", sizeof(boolVar));
    printf("boolVar = %d with %d bytes\n", boolVar, sizeof(boolVar));

    printf("intVar = %d with %d bytes\n", intVar, sizeof(intVar));
    printf("floatVar = %f with %d bytes\n", floatVar, sizeof(floatVar));
    printf("doubleVar = %f with %d bytes\n", doubleVar, sizeof(doubleVar));

    printf("char is %d bytes\n", sizeof(char));
    printf("bool is %d bytes\n", sizeof(bool));
    printf("int is %d bytes\n", sizeof(int));
    printf("float is %d bytes\n", sizeof(float));
    printf("double is %d bytes\n", sizeof(double));

    return 0;
}
