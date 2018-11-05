module fibonacci
(*
 * fibonacci.fs
 * Por Saulo Almeda Nieves
 * 841-13-0170
 * 11/13/2015
 * Este programa calcula el enesimo elemento de la sucesion de Fibonacci.
 *)

let rec sum lst =
    match lst with
    | [] -> 0
    | hd::tl -> hd + sum tl

//Calculates the nth number of the fibonacci sequence using a regular
//recursion.
//Receives a number (num) and returns the nth number of the sequence.
let rec fibonacci num =
    if num = 0 then 0
    else if num = 1 then 1
    else fibonacci (num - 1) + fibonacci (num - 2)

//Calculates the nth number of the fibonacci sequence using a pattern matching
//expression.
//Receives a number and returns the nth number of the sequence.
let rec fibonacci_v2 num =
    match num with
    | 0 -> 0
    | 1 -> 1
    | _ -> fibonacci_v2 (num - 1) + fibonacci_v2 (num - 2)

//Calculates the nth number of the fibonacci sequence using a pattern matching
//function.
//Receives a number and returns the nth number of the sequence.
let rec fibonacci_v3 = function
    | 0 -> 0
    | 1 -> 1
    | num -> fibonacci_v3 (num - 1) + fibonacci_v3 (num - 2)

//Calculates the nth number of the fibonacci sequence using a tail-recursive
//helper function.
//Receives a number (num) and returns the nth number of the sequence. 
let fibonacci_v4 num =
    let rec helper acc num =
        match num with
        | 0 -> 0
        | 1 -> 1
        | _ -> helper (acc - num) (num - 1) + helper (acc - num) (num - 2)
    helper 1 num

//Starting point
//Receives a number
let start num =
    printfn "The number is %d" num
    if num < 0 then printfn "Error! Negative integer."
    else
        printfn "Using a tail-recursive helper function: "
        printfn "The %d-th number in the Fibonacci sequence is %d" num (fibonacci_v4 num)
        printfn "Using a pattern matching function: "
        printfn "The %d-th number in the Fibonacci sequence is %d" num (fibonacci_v3 num)
        printfn "Using a pattern matching expression: "
        printfn "The %d-th number in the Fibonacci sequence is %d" num (fibonacci_v2 num)
        printfn "Using an if expression: "
        printfn "The %d-th number in the Fibonacci sequence is %d" num (fibonacci num)