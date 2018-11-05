module my_list_higher_fns
(*
 * my_list_higher_fns.fs
 * By Antonio F. Huertas
 * This program defines some list functions.
 *)

// iter : ('a -> unit) -> 'a list -> unit
// Applies an action to each element of a list.
let rec iter fn = function
    | [] -> ()
    | hd::tl -> fn hd
                iter fn tl

// fold : ('a -> 'b -> 'a) -> 'a -> 'b list -> 'a
// Applies a function to each element of a list, accumulating a result
// based on an initial value.
let rec fold fn acc = function
    | [] -> acc
    | hd::tl -> fold fn (fn acc hd) tl

// map : ('a -> 'b) -> 'a list -> 'b list
// Applies a function to each element of a list, creating a new list.
let rec map fn = function
    | [] -> []
    | hd::tl -> (fn hd)::(map fn tl)

// exists : ('a -> bool) -> 'a list -> bool
// Tests if there is an element of the list that satisfies a predicate.
let rec exists pred = function
    | [] -> false
    | hd::tl when pred hd -> true
    | hd::tl -> exists pred tl

// filter : ('a -> bool) -> 'a list -> 'a list
// Creates a new list with those elements of the original for which a 
// predicate is satisfied.
let rec filter pred = function
    | [] -> []
    | hd::tl when pred hd -> hd::(filter pred tl)
    | hd::tl -> filter pred tl

// start: unit -> unit
// Serves as an entry point for the program.
let start () =
    let lst = [1..10]
    printfn "This is the list: %A" lst
    iter (fun elem -> printfn "%d" elem) lst 
                // Atl.: iter (printfn "%d") lst

    let sum = fold (fun acc elem -> acc + elem) 0 lst
                // Alt.: fold (+) 0 lst
    printfn "\nThe sum of the elements is %d" sum

    let hasEven = exists (fun elem -> elem % 2 = 0) lst
    printfn "Does the list contains even elements? %b" hasEven

    let lst2 = map (fun elem -> elem * elem) lst
    printfn "\nThe list of the first 10 squares: %A" lst2

    let lst3 = filter (fun elem -> elem % 2 = 0) lst
    printfn "\nThe list of the first 5 even elements: %A" lst3
