/*
 * shapes_calc.pl
 * By Antonio F. Huertas
 * This program displays the data, including the area and perimeter,
 * of a list of shapes.
 */

%% pi(?ValuePi)
%  Defines the value of pi.
pi(3.14159).

%% color(?ValueColor)
%  Defines the different colors.
color(white).
color(red).
color(green).
color(blue).
color(yellow).
color(black).

%% area(+Shape, ?Area)
%  Computes the area of the given shape.
area(circle(_, _, Radius), Area) :-
    pi(ValuePi),
    Area is ValuePi * Radius ** 2.0.

area(rectangle(_, _, Height, Width), Area) :-
    Area is Height * Width.

%% perimeter(+Shape, ?Perimeter)
%  Computes the perimeter of the given shape.
perimeter(circle(_, _, Radius), Perimeter) :-
    pi(ValuePi),
    Perimeter is 2 * ValuePi * Radius.

perimeter(rectangle(_, _, Height, Width), Perimeter) :-
    Perimeter is 2 * (Height + Width).

%% write_data(+Shape)
%  Displays the data of the given shape.
write_data(Shape) :-
    Shape = circle(point(X, Y), color(Color), Radius),
    write('\tLocation = '), write(X), write(', '), write(Y),
    write(', Color = '), write(Color), nl,
    write('\tType = circle, Radius = '), write(Radius), nl,
    write_results(Shape), nl.

write_data(Shape) :-
    Shape = rectangle(point(X, Y), color(Color), Height, Width),
    write('\tLocation = '), write(X), write(', '), write(Y),
    write(', Color = '), write(Color), nl,
    write('\tType = rectangle, Height = '), write(Height),
    write(', Width = '), write(Width), nl,
    write_results(Shape), nl.

%% write_results(+Shape)
%  Displays the area and perimeter of the given shape.
write_results(Shape) :-
    area(Shape, Area),
    write('\tArea = '), write(Area),

    perimeter(Shape, Perimeter),
    write(', Perimeter = '), write(Perimeter).

%% write_list(+List)
%  Displays the elements of the given list.
write_list([Head|Tail]) :-
    write_data(Head), nl,
    write_list(Tail).

write_list([]).

%% start
%  Serves as an entry point for the program.
start :-
    List = [
        circle(point(1.0, 2.0), color(red), 5.0),
        rectangle(point(10.0, 15.0), color(green), 4.0, 2.0),
        circle(point(9.0, 3.0), color(blue), 6.0) ],
    write('These are the shapes:\n'),
    write_list(List), nl.

/*
 * Sample interactive run:
 * ?- start.
 */