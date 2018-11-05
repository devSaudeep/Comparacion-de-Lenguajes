(*
 * my_list_fns.fs
 * By Antonio F. Huertas
 * This program defines some list functions.
 *)

// isEmpty : 'a list -> bool
// Determines whether the given list is empty.
let isEmpty = function
    | [] -> true
    | _::_ -> false

// head : 'a list -> 'a
// Returns the first element of the given list.
let head = function
    | [] -> failwith "empty list"
    | hd::_ -> hd

// tail : 'a list -> 'a list
// Returns the list that remains after removing the head of the given list.
let tail = function
    | [] -> failwith "empty list"
    | _::tl -> tl

// length : 'a list -> int
// Returns the number of elements in the given list.
let rec length = function
    | [] -> 0
    | _::tl -> 1 + length tl

// length_v2 : 'a list -> int
// Returns the number of elements in the given list.
// Uses a helper tail-recursive function.
let length_v2 lst =
    let rec helper acc = function
        | [] -> acc
        | _::tl -> helper (acc + 1) tl

    helper 0 lst

// sum : int list -> int
// Returns the sum of the elements in the given list.
let rec sum = function
    | [] -> 0
    | hd::tl -> hd + sum tl

// sum_v2 : int list -> int
// Returns the sum of the elements in the given list.
// Uses a helper tail-recursive function.
let sum_v2 lst =
    let rec helper acc = function
        | [] -> acc
        | hd::tl -> helper (acc + hd) tl

    helper 0 lst

// rev : 'a list -> 'a list
// Returns a new list with the elements of the given list in reverse order.
let rec rev lst =
    match lst with
    | [] -> lst
    | hd::tl -> (rev tl)@[hd]

// rev_v2 : 'a list -> 'a list
// Returns a new list with the elements of the given list in reverse order.
// Uses a helper tail-recursive function.
let rev_v2 lst =
    let rec helper acc = function
        | [] -> acc
        | hd::tl -> helper (hd::acc) tl

    helper [] lst 

// append : 'a list -> 'a list -> 'a list
// Returns a new list that contains the elements of the first list 
// followed by elements of the second.
let rec append lst1 lst2 =
    match lst1 with
    | [] -> lst2
    | hd1::tl1 -> hd1::(append tl1 lst2)

// append_v2 : 'a list -> 'a list -> 'a list
// Returns a new list that contains the elements of the first list 
// followed by elements of the second. Uses a helper tail-recursive function.
let append_v2 lst1 lst2 =
    let rec helper acc = function
        | [] -> acc
        | hd::tl -> helper (hd::acc) tl
        
    helper lst2 (rev_v2 lst1)

// ( ++ ) : ('a list -> 'a list -> 'a list)
// Defines the '++' binary operator as an alias of append_v2.
let ( ++ ) = append_v2

// nth : 'a list -> int -> 'a
// Returns the element at the nth index of the given list.  First index is 0.
let rec nth lst idx =
    match lst, idx with
    | _, idx when idx < 0 -> failwith "out-of-range index"
    | [], _ -> failwith "out-of-range index"
    | hd::_, 0 -> hd
    | _::tl, _ -> nth tl (idx - 1)

// contains : 'a list -> 'a -> bool when 'a : equality
// Returns true if the given list contains the given element.
let rec contains lst elem =
    match lst with
    | [] -> false
    | hd::_ when elem = hd -> true
    | _::tl -> contains tl elem

// quickSort : 'a list -> 'a list when 'a : comparison
// Returns a new list that contains the sorted elements of the given list.
let rec quickSort = function
    | [] -> []
    | hd::tl -> let smaller = [for a in tl do if a <= hd then yield a]
                let larger =  [for b in tl do if b > hd then yield b]
                quickSort smaller @ [hd] @ quickSort larger

// start: unit -> unit
// Serves as an entry point for the program.
let start () =
    let lst = [30;40;10;50;20]
    printfn "This is the list: %A" lst
    printfn "It is empty? %b" (isEmpty lst)
    printfn "The head is %d" (head lst)
    printfn "The tail is %A" (tail lst)
    printfn "The length is %d" (length lst)
    printfn "\tAgain, the length is %d" (length_v2 lst)
    printfn "The sum of the elements is %d" (sum lst)
    printfn "\tAgain, the sum of the elements is %d" (sum_v2 lst)
    printfn "The elements in reverse order: %A" (rev lst)
    printfn "\tAgain, the elements in reverse order: %A" (rev_v2 lst)

    printfn "\nSearching and sorting..."
    printfn "The element at index #2 is %d" (nth lst 2)
    printfn "Does the list contain 50? %b" (contains lst 50)
    printfn "The elements, sorted in ascending order: %A" (quickSort lst)

    printfn "\nConstructing and appending..."
    let lst2 = 55::[60..10..100]
    printfn "A list with 55 and values from 60 to 100 with a step of 10: %A" lst2
    printfn "Appending the two lists: %A" (append lst lst2)
    printfn "\tAgain, appending the two lists: %A" (append_v2 lst lst2)
    printfn "\tAgain, appending the two lists using ++: %A" (lst ++ lst2)

start ()