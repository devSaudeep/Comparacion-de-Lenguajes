(*
 * circle_calc_io.fs
 * By Antonio F. Huertas
 * This program displays the area and circumference of a circle.
 *)

open System    // for .NET Console and Math class methods

// area_circle : float -> float
// Returns the area of the circle with the given radius.
let area_circle rad = Math.PI * Math.Pow (rad, 2.0)

// circum_circle : float -> float
// Returns the circumference of the circle with the given radius. 
let circum_circle rad = 2.0 * Math.PI * rad

// main : unit -> unit
// Serves as an entry point for the program.
let main () =
    Console.Write "Enter the radius of the circle: "
    let radius = Console.ReadLine () |> float
    Console.WriteLine ()
    Console.WriteLine ("The area is {0:0.000} and the circumference is {1:0.000}",
        (area_circle radius), (circum_circle radius))
    Console.ReadKey () |> ignore       // to pause the console window

// Calls the "main" function.
main ()