/*
 * enum_demo.c
 * By Antonio F. Huertas
 * This program demonstrates how to define and use enumerations.
 */

#include <stdio.h>   // for printf, scanf

// Declares a color enumeration.
enum color {WHITE, RED, GREEN, BLUE, YELLOW, BLACK};

// Defines an alias for the color enumeration.
typedef enum color Color;

// Declares a function using a prototype.
char *color_str(Color clr);

// Starts the execution of this program.
int main(void) {
    enum color c1 = RED;
    Color c2 = YELLOW;

    printf("c1 = %d\n", c1);
    printf("c2 = %d\n", c2);
    printf("\n");

    printf("c1 = %s\n", color_str(c1));
    printf("c2 = %s\n", color_str(c2));
    printf("\n");

    printf("Comparing c1 and c2: ");
    if (c1 < c2)
        printf("c1 goes before c2.\n");
    else if (c1 > c2)
        printf("c1 goes after c2.\n");
    else
        printf("c1 and c2 are the same color.\n");
    printf("\n");

    c1++;
    printf("After incrementing, c1 = %s\n", color_str(c1));
    printf("\n");

    c1 = c2 = WHITE;
    printf("After clearing...\n");
    printf("c1 = %s\n", color_str(c1));
    printf("c2 = %s\n", color_str(c2));
    printf("\n");

    printf("These are the available colors:\n");
    for (Color c = WHITE; c <= BLACK; c++)
        printf("%s\n", color_str(c));
    return 0;
}

// Returns a string representation for the shape color.
char *color_str(Color clr) {
    char *str[] = {"White", "Red", "Green", "Blue", "Yellow", "Black"};
    return str[clr];
}
