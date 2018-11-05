/*
 * shapes_calc.c
 * By Antonio F. Huertas
 * This program displays the data of an array of shapes.  It manipulates
 * a union inside a structure.
 */

#include <stdio.h>   // for printf, scanf
#include <math.h>    // for pow

// Defines a global symbolic constant.
const float PI = 3.14159;

// Defines enumeration types for shape kinds and colors.
typedef enum {CIRCLE, RECTANGLE} ShapeKind;
typedef enum {WHITE, RED, GREEN, BLUE, YELLOW, BLACK} Color;

// Defines data structures for points, circles, rectangles and shapes.
typedef struct {
    float x, y;
} Point;

typedef struct {
    float radius;
} Circle;

typedef struct {
    float width, height;
} Rectangle;

typedef struct {
    ShapeKind kind;
    Color color;
    Point location;
    union {
        Circle circle;
        Rectangle rectangle;
    };
} Shape;

// Declares functions using prototypes.
void show_data(const Shape *shp);
char *kind_str(ShapeKind kind);
char *color_str(Color clr);
float area(const Shape *shp);
float perimeter(const Shape *shp);

// Starts the execution of the program.
int main(void) {
    Shape arr[] = {
        {RECTANGLE, YELLOW, {8.0, 3.0}, .rectangle = {4.0, 9.0}},
        {CIRCLE, RED, {2.0, 1.0}, .circle = {5.0}},
        {RECTANGLE, GREEN, {10.0, 15.0}, .rectangle = {4.0, 2.0}},
        {CIRCLE, BLUE, {4.0, 5.0}, .circle = {7.0}}
    };
    int arr_length = sizeof(arr) / sizeof(Shape);

    printf("These are the shapes:\n\n");
    for (int idx = 0; idx < arr_length; idx++) {
        show_data(&arr[idx]);
        printf("\n");
    }
    return 0;
}

// Shows the data of the given shape, including its area and perimeter.
void show_data(const Shape *shp) {
    printf("Kind = %s, Color = %s, Location = (%.1f, %.1f)\n",
        kind_str(shp->kind), color_str(shp->color),
        shp->location.x, shp->location.y);

    switch (shp->kind) {
        case CIRCLE:
            printf("Radius = %.1f\n", shp->circle.radius);
            break;
        case RECTANGLE:
            printf("Width = %.1f, Height = %.1f\n",
                shp->rectangle.width, shp->rectangle.height);
            break;
    }
    printf("Area = %.1f, Perimeter = %.1f\n",
        area(shp), perimeter(shp));
}

// Returns a string representation for the shape kind.
char *kind_str(ShapeKind kind) {
    char *str[] = {"Circle", "Rectangle"};
    return str[kind];
}

// Returns a string representation for the shape color.
char *color_str(Color clr) {
    char *str[] = {"White", "Red", "Green", "Blue", "Yellow", "Black"};
    return str[clr];
}

// Returns the area of a shape.
float area(const Shape *shp) {
    switch (shp->kind) {
        case CIRCLE:
            return PI * pow(shp->circle.radius, 2);
        case RECTANGLE:
            return shp->rectangle.width * shp->rectangle.height;
    }
}

// Returns the perimeter of a shape.
float perimeter(const Shape *shp) {
    switch (shp->kind) {
        case CIRCLE:
            return 2 * PI * shp->circle.radius;
        case RECTANGLE:
            return 2 * (shp->rectangle.width + shp->rectangle.height);
    }
}
