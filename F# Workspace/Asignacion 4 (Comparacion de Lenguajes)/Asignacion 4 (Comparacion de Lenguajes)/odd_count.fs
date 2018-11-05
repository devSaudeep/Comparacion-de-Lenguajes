module odd_count
(*
 * odd_count.fs
 * Por Saulo Almeda Nieves
 * 841-13-0170
 * 11/17/2015
 * Este programa determina la cantidad de elementos impares en una lista de
 * números enteros.
 *)

//Calculates the number of odd number in the received list (lst) and returns it
// using a pattern matching expression.
let odd lst =
    match lst with
    | [] -> failwith "Empty list."
    | _ -> lst |> List.filter (fun elem -> elem % 2 = 1)
               |> List.length

//Calculates the number of odd number in the received list (lst) and returns it
// using a tail-recursive helper function with a pattern matching expression.
let odd_v2 lst =
    let rec helper odd lst =
        match lst with
        | [] -> odd
        | hd::tl when hd % 2 = 1 -> helper (odd + 1) tl
        | _::tl -> helper odd tl
    helper 0 lst

//Calculates the number of odd number in the received list (lst) and returns it
// using a regular recursion with a pattern matching expression.
let rec odd_v3 lst =
    match lst with
    | [] -> 0
    | hd::tl when hd % 2 = 1 -> 1 + odd_v3 tl
    | hd::tl -> odd_v3 tl

//Serves as starting point
let start lst =
    if List.isEmpty lst then printfn"The list is empty. Can't get the minimum
     element of the list."
     else
        printfn "Using the List.filter and List.length functions: \n    The number of odd elements is %d" (odd lst)
        printfn "Using a tail-recursive helper function: \n The number of odd elements is %d" (odd_v2 lst)
        printfn "Using regular recursion: \n    The number of odd elements is %d" (odd_v3 lst)