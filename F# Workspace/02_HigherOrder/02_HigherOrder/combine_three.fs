(*
 * combine_three.fs
 * By Antonio F. Huertas
 * This program displays the the result of combining three integers.
 *)

// sum : int -> int -> int
// Returns the sum of two integers.
let sum val1 val2 =  val1 + val2

// product : int -> int -> int
// Returns the product of two integers.
let product val1 val2 =  val1 * val2

// minimum : 'a -> 'a -> 'a when 'a : comparison
// Returns the minimum of two values.
let minimum val1 val2 =
    if val1 < val2 then val1 else val2

// combine_three : 'a -> 'b -> 'b -> ('a -> 'b -> 'a) -> 'a
// Returns the result of combining three values.
let combine_three val1 val2 val3 combine_two =
    let result = combine_two val1 val2
    combine_two result val3

// start : int -> int -> int -> unit
// Serves as the entry-point of the program.
let start val1 val2 val3 =
    printfn "The numbers are %d, %d and %d" val1 val2 val3
    printfn "The sum of the values is %d" 
        (combine_three val1 val2 val3 sum)
    printfn "The product of the values is %d" 
        (combine_three val1 val2 val3 product)
    printfn "The minimum value is %d" 
        (combine_three val1 val2 val3 minimum)