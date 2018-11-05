(*
 * shapes_calc.fs
 * By Antonio F. Huertas
 * This program displays the data, including the area and perimeter,
 * of a list of shapes.
 *)

// Defines a record type for a point.
type point = { x : float; y : float }

// Defines a discriminated union type for a color.
type color = White | Red | Green | Blue | Yellow | Black

// Define a discriminated union for a shape.
type Shape =
        // A circle has color, location and radius
    | Circle of color * point * float
        // A rectangle has color, location, height and width
    | Rectangle of color * point * float * float

// pi : float
// Defines the value of pi.
let pi = 3.14159

// area_shape : Shape -> float
// Returns the area of a shape.
let area_shape = function
    | Circle(_, _, rad) -> pi * rad * rad
    | Rectangle(_, _, hgt, wdt) -> hgt * wdt

// show_shape : Shape -> unit
// Returns the perimeter of a shape.
let perim_shape = function
    | Circle(_, _, rad) -> 2.0 * pi * rad
    | Rectangle(_, _, hgt, wdt) -> 2.0 * (hgt + wdt)

// show_shape : Shape -> unit
// Displays the data of the given shape.
let show_shape shp =
    match shp with
    | Circle(clr, loc, rad) ->
        printfn "Color = %A, Location (%.3f, %.3f)" clr loc.x loc.y
        printfn "Kind = Circle, Radius = %.3f" rad
    | Rectangle(clr, loc, hgt, wdt) ->
        printfn "Color = %A, Location (%.3f, %.3f)" clr loc.x loc.y
        printfn "Kind = Rectangle, Height = %.3f, Width = %.3f" hgt wdt
    
    printfn "Area = %.3f, Perimerter = %.3f\n" 
        (area_shape shp) (perim_shape shp)

// start : unit -> unit
// Serves as an entry point for the program.
let start () =
    let lst = [
        Circle(Red, { x = 1.0; y = 2.0 }, 5.0);
        Rectangle(Green, { x = 10.0; y = 15.0 }, 4.0, 2.0);
        Circle(Blue, { x = 9.0; y = 3.0 }, 6.0)
    ]
    printfn "These are the shapes:"
    List.iter show_shape lst

