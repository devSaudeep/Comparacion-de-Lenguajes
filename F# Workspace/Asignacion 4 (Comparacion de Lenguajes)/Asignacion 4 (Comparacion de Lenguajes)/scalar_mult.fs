module scalar_mult
(*
 * scalar_mult.fs
 * Por Saulo Almeda Nieves
 * 841-13-0170
 * 11/14/2015
 * Este programa determina la multiplicación escalar de un número entero y una
 * lista de números enteros.
 *)

//Calculates the scalar multiplication of the received list (lst) with the
//number (num), using a pattern matching expression.
//Returns a list with the results of the scalar multiplication.
let scalar_mult_v3 num lst =
    match lst with
    | [] -> failwith "Empty list."
    | hd::tl -> List.map (fun elem -> elem * num) lst

//Calculates the scalar multiplication of the received list (lst) with the
//number (num), using a helper function with a pattern matching expression.
//Returns a list with the results of the scalar multiplication.
let scalar_mult_v2 num lst =
    let rec helper lst lstacc =
        match lst with
        | [] -> lstacc
        | hd::tl -> helper tl lstacc @ [hd * num]
    List.rev (helper lst [])

//Calculates the scalar multiplication of the received list (lst) with the
//number (num), using recursion with a pattern matching expression.
//Returns a list with the results of the scalar multiplication.
let rec scalar_mult num lst =
    match lst with
    | [] -> []
    | hd::tl -> (num*hd)::(scalar_mult num tl)

//Serves as starting point
let start num lst =
    if List.isEmpty lst then printfn "The list is empty. Can't make scalar
     multiplication."
    else
        printfn "Using the List.map function: \n    The scalar multiplication
         is %A" (scalar_mult_v3 num lst)
        printfn "Using a tail-recursive helper function: \n    The scalar
         multiplication is %A" (scalar_mult_v2 num lst)
        printfn "Using regular recursion: \n    The scalar multiplication is %A" (scalar_mult num lst)