
/*
 * combine_three.c
 * By Antonio F. Huertas
 * This program displays the the result of combining three integers
 * using different methods.
 */

#include <stdio.h>
// for printf, scanf

// Declares functions using prototypes.
int sum(int val1, int val2);
int product(int val1, int val2);
int minimum(int val1, int val2);
int combine_three(int val1, int val2, int val3,
                  int (*combine_two)(int val1, int val2));

// Starts the execution of the program.
int main(void) {
    int value1, value2, value3;
    printf("Enter three integers: ");
    scanf("%d %d %d", &value1, &value2, &value3);

    printf("The sum of the values is %d\n",
           combine_three(value1, value2, value3, &sum));
    printf("The product of the values is %d\n",
           combine_three(value1, value2, value3, &product));
    printf("The minimum value is %d\n",
           combine_three(value1, value2, value3, &minimum));

    return 0;
}

// Returns the sum of two integers.
int sum(int val1, int val2) {
    return val1 + val2;
}

// Returns the product of two integers.
int product(int val1, int val2) {
    return val1 * val2;
}

// Returns the minimum of two integers.
int minimum(int val1, int val2) {
    return (val1 < val2)? val1 : val2;
}

// Returns the result of combining three integers.
int combine_three(int val1, int val2, int val3,
                  int (*combine_two)(int val1, int val2)) {
    int result = (*combine_two)(val1, val2);
    return (*combine_two)(result, val3);
}
