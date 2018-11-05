(*
 * linked_list.fs
 * By Antonio F. Huertas
 * This program defines and manipulates a linked list of integers.
 *)

// Defines a discriminated union type for a linked list.   
type IntList =
    | Nil
    | Cons of int * IntList

// sum_list : IntList -> int
// Returns the sum of the elements in the given list.
let rec sum_list = function
    | Nil -> 0
    | Cons (hd, tl) -> hd + sum_list tl

// contains_list : IntList -> int -> bool
// Returns true if the given list contains the given element.    
let rec contains_list lst elem =
    match lst with
    | Nil -> false
    | Cons (hd, _) when elem = hd -> true
    | Cons (hd, tl) -> contains_list tl elem

// show_list : IntList -> unit
// Shows the elements in the given list.
let rec show_list = function
    | Nil -> ()
    | Cons (hd, tl) -> printf "%d " hd
                       show_list tl

// start : unit -> unit
let start () =
    let lst = Cons (20, Cons (50, Cons (10, Cons (40, Cons (30, Nil)))))

    printf "This is the list: "
    show_list lst
    printfn "\nThis is the list, internally: %A" lst
    printfn "The sum of its elements is %d" (sum_list lst)
    printfn "Does it contain 50? %b" (contains_list lst 50)