/*
Factorial_First
by Saulo Almeda Nieves
Septiembre 21, 2015
This program calculates the area and circunference of the
cirle with the given radius.
*/

#include <stdio.h>          //for printf and scan

//Pototype
int factorial(int num);
int factorial_v2(int num);
int factorial_v3(int num);

//Starts the execution of this program
int main(void) {
    int number;

    printf("Enter a non-negative integer: ");
    scanf("%d", &number);

    if(number < 0.0)
        printf("Error the integer is negative!");
    else {
        printf("Using while, the factorial is %d\n", factorial(number));
        printf("Using for, the factorial is %d\n", factorial_v2(number));
        printf("Using recursion, the factorial is %d\n", factorial_v3(number));
    }
    return 0;
}

//Returns the factorial of the given non-integer number
//NOTE: While
int factorial(int num) {
    int acc = 1;

    while(num > 0)
        acc *= num--;
    return acc;
}

//Returns the factorial of the given non integer number
//NOTE: For
int factorial_v2(int num) {
    int acc = 1;

    for(int ctr = num; ctr > 0; ctr--)
        acc*= ctr;
    return acc;
}

//Returns the factorial of the given non integer number
//NOTE: Recursion
int factorial_v3(int num) {
    if(num = 0)
        return 1;
    else
        return num * factorial_v3(num - 1);
}
