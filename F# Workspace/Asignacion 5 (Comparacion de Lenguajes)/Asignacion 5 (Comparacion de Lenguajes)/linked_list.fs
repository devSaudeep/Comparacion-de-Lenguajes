(*
 * linked_list.fs
 * By Antonio F. Huertas
 * Edited by Saulo Almeda Nieves
 * 841-13-0170
 * 11/28/2015
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

// length_list : IntList -> int
// Returns the number of elements in the given list.
let rec length_list = function
    | Nil -> 0
    | Cons (hd, tl) -> 1 + length_list tl

// minimum_list : IntList -> int
// Returns the minimum element of the given list.
let rec minimum_list = function
    | Nil -> failwith "Error, empty list"
    | Cons (hd, Nil) -> hd
    | Cons (hd, tl) when hd < (minimum_list tl) -> hd
    | Cons (hd, tl) -> (minimum_list tl)

// append_list : IntList -> IntList -> IntList
// Returns the concatenation of the given lists.
let rec append_list lst lst2 =
    match lst with
    | Nil -> lst2
    | Cons (hd, Nil) -> Cons (hd, lst2)
    | Cons (hd, tl) -> Cons (hd, append_list tl lst2)

// reverse_list : IntList -> IntList
// Returns the given list in reversed order.
let rec reverse_list = function
    | Nil -> Nil
    | Cons (hd, Nil) -> Cons (hd, Nil)
    | Cons (hd, tl) -> append_list (reverse_list tl) (Cons (hd, Nil))

// remove_list : -> IntList -> int -> IntList
// Returns a list with a removed element.
let rec remove_list lst elem =
    match lst with
    | Nil -> failwith "Error, empty list."
    | Cons (hd, tl) when hd = elem -> tl
    | Cons (hd, tl) -> (append_list (Cons (hd, Nil)) (remove_list tl elem))

// start : unit -> unit
let start () =
    let lst = Cons (20, Cons (50, Cons (10, Cons (40, Cons (30, Nil)))))

    printf "This is the list: "
    show_list lst
    printfn "\nThis is the list, internally: %A" lst
    printfn "The sum of its elements is %d" (sum_list lst)
    printfn "Does it contain 50? %b" (contains_list lst 50)
    printfn "The length of the list is: %d" (length_list lst)
    printfn "The minimum of the list is: %d" (minimum_list lst)
    printfn "The reversed list: %A" (reverse_list lst)

    printfn "Creating a second list..."
    let lst2 = Cons (23, Cons (50, Cons (11, Cons (41, Cons (30, Nil)))))
    printf "This is the list #2: "
    show_list lst2
    printfn "\n"
    printf "This are the two lists concatenated together: "
    (show_list (append_list lst lst2))
    printf "\nThis is the concatenated list without the number 50 is: " 
    show_list (remove_list (append_list lst lst2) 50)
    printf "\n"