(*
 * composition_demo.fs
 * By Antonio F. Huertas
 * This program demonstrates function composition and related operators.
 *)

// double : int -> int
// Returns the double of the given integer.
let double num = 2 * num

// successor : int -> int
// Returns the successor of the given integer.
let successor num = num + 1

// compose : ('a -> 'b) -> ('c -> 'a) -> 'c -> 'b
// Returns the composition of functions fn1 and fn2.
let compose fn1 fn2 =
    fun x -> fn1 (fn2 x)

// start : int -> unit
// Serves as an entry-point for the program.
let start num =
    printfn "The number is %d" num

    printfn "\nUsing nested calls for function composition..."
    printfn "The successor of the double is %d"
        (successor (double num))

    printfn "\nUsing the compose function..."
    printfn "The successor of the double is %d"
        ((compose successor double)(num))

    printfn "\nUsing the '<<' (left composition) operator..."
    printfn "The successor of the double is %d" 
        ((successor << double) num)

    printfn "\nUsing the '>>' (right composition) operator..."
    printfn "The successor of the double is %d" 
        ((double >> successor) num)

    printfn "\nUsing the '|>' (pipe) operator..."
    num |> double
        |> successor
        |> printfn "The successor of the double is %d"

    printfn "\nUsing '|>' and anonymous functions (lambdas)..."
    num |> fun num -> 2 * num
        |> fun num -> num + 1
        |> printfn "The successor of the double is %d"