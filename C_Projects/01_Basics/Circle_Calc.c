/*
circle_calc
by Saulo Almeda Nieves
Septiembre 21, 2015
This program calculates the area and circunference of the
cirle with the given radius.
*/

#include <stdio.h>          //for printf and scanf
#include <math.h>           //for pow

const float PI = 3.14159;   //global named constant

//Prototype (function declaration: interface)
float area(float rad);
float circumference(float rad);

//Starts the execution of this program
int main(void) {
    float radius;

    printf("Enter the radius: ");
    scanf("%f", &radius);

    if(radius < 0.0)
        printf("Error! Negative radius.\n");
    else {
        printf("The area is %.3f\n", area(radius));
        printf("The circumference is %.3f\n", circumference(radius));
    }

return 0;
}

//Returns the area of the circle w/ the given radius.
float area(float rad) {
    return PI * pow(rad, 2);
}

//Returns the circumference of the circle w/ the given radius.
float circumference(float rad) {
    return 2 * PI * rad;
}
