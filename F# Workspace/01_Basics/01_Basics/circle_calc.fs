(*
 * circle_calc.fs
 * By Antonio F. Huertas
 * This program calculates and displays the area and circumference of the
 * circle with the given radius.
 *)

// pi : float
// Defines the value of pi.
let pi = 3.14159

// area_circle : float -> float
// Returns the area of the circle with the given radius.
let area_circle rad = pi * rad ** 2.0

// circum_circle : float -> float
// Returns the circumference of the circle with the given radius. 
let circum_circle rad = 2.0 * pi * rad

// start : float -> unit
// Serves as an entry point for the program.
let start rad =
    printfn "The radius of the circle is %.3f" rad
    if rad < 0.0 then
        printfn "Error! Negative radius."
    else
        printfn "The area is %.3f" (area_circle rad)
        printfn "The circumference is %.3f" (circum_circle rad)