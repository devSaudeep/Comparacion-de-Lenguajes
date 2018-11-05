/*
 * circle_calc.pl
 * By Antonio F. Huertas
 * This program displays the area and circumference of a circle.
 */

%% pi(?ValuePi)
%  Defines the value of pi.
pi(3.14159).

%% area_circle(+Radius, ?Area)
%  Computes the area of the circle with the given radius.
area_circle(Radius, Area) :-
    pi(ValuePi),
    Area is ValuePi * Radius ** 2.0.

%% circumference_circle(+Radius, ?Circum)
%  Computes the circumference of the circle with the given radius.
circumference_circle(Radius, Circum) :-
    pi(ValuePi),
    Circum is 2 * ValuePi * Radius.

%% start(+Radius)
%  Serves as an entry point for the program.
start(Radius) :-
    write('The radius is '), write(Radius), nl,
    Radius >= 0,

    area_circle(Radius, Area),
    write('The area is '), write(Area), nl,

    circumference_circle(Radius, Circum),
    write('The circumference is '), write(Circum), nl.