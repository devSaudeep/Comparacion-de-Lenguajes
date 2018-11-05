(*
 * factorial_vers.fs
 * By Antonio F. Huertas
 * This program calculates and displays the factorial of the
 * given non negative integer.
 *)

// Uses an if experssion.
let rec factorial num =
    if num = 0
        then 1
        else num * factorial (num - 1)

// Uses a pattern matching expression.
let rec factorial_v2 num =
    match num with
    | 0 -> 1
    | _ -> num * factorial_v2 (num - 1)

// Uses a pattern matching function.
let rec factorial_v3 = function
    | 0 -> 1
    | num -> num * factorial_v3 (num - 1)

// Uses a tail recursive helper function.
let factorial_v4 num =
    let rec helper acc num =
        match num with
        | 0 -> acc
        | _ -> helper (acc * num) (num - 1)
    helper 1 num

// start : int -> unit
// Serves as an entry point for the program.
let start num =
    printfn "The number is %d" num
    if num < 0 then
        printfn "Error! Negative integer."
    else
        printfn "Using a tail-recursive helper, the factorial is %d" 
            (factorial_v4 num)
        printfn "Using a pattern matching function, the factorial is %d"
            (factorial_v3 num)
        printfn "Using a pattern matching expression, the factorial is %d" 
            (factorial_v2 num)
        printfn "Using an if expression, the factorial is %d"
            (factorial num)