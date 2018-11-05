module list_min
(*
 * list_min.fs
 * Por Saulo Almeda Nieves
 * 841-13-0170
 * 11/15/2015
 * Este programa determina el elemento mínimo en una lista de números enteros.
 *)

//Using regular recursion, receives a list (lst) and returns the minimum
// element in it.
let rec min_v4 lst =
    match lst with
    | [] -> failwith "Empty list."
    | hd::[] -> hd
    | hd::tl when hd < min_v4 tl -> hd
    | _::tl -> min_v4 tl

//Using a tail-recursive helper function, receives a list (lst) and returns the
// minimum element in it.
let min_v3 lst =
    let rec helper min lst =
        match lst with
        | [] -> min
        | hd::tl when hd < min -> helper hd tl
        | _::tl -> helper min tl
    helper (List.head lst) lst

//Using List.fold, receives a list (lst) and returns the
// minimum element in it.
let min_v2 lst =
    match lst with
    | [] -> failwith "Empty list."
    | hd::tl -> List.fold (fun hd elem -> if hd < elem then hd else elem) hd lst

//Using List.min, receives a list (lst) and returns the
// minimum element in it.
let min lst =
    match lst with
    | [] -> failwith "Empty list."
    | _ -> List.min lst

//Serves as starting point
let start lst =
    if List.isEmpty lst then printfn "The list is empty. Can't calculate 
    minimum element in the list."
    else
        printfn "Using the List.min function: \n    The minimum element is %d"
         (min lst)
        printfn "Using the List.fold function: \n   The minimum element is %d"
         (min_v2 lst)
        printfn "Using a tail-recursive helper function: \n     The minimum
         element is %d" (min_v3 lst)
        printfn "Using regular recursion: \n    The minimum element is %d" (min_v4 lst)