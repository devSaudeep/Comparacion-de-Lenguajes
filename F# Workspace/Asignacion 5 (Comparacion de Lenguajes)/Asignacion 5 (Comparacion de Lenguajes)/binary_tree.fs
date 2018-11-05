(*
 * binary_tree.fs
 * By Antonio F. Huertas
 * Edited by Saulo Almeda Nieves
 * 841-13-0170
 * 12/2/15
 * This program defines and manipulates a binary search tree of 
 * integers.
 *)

// Defines a discriminated union type for a binary tree.   
type IntTree =
    | Nil
    | Node of int * IntTree * IntTree

// sum_tree : IntTree -> int
// Returns the sum of the elements in the given tree.
let rec sum_tree = function
    | Nil -> 0
    | Node (root, lft, rgt) -> sum_tree lft + root + sum_tree rgt

// contains_tree : IntTree -> int -> bool
// Returns true if the given tree contains the given element.    
let rec contains_tree bst elem =
    match bst with
    | Nil -> false
    | Node (root, lft, rgt) 
            when elem < root -> contains_tree lft elem
    | Node (root, lft, rgt) 
            when elem > root -> contains_tree rgt elem
    | Node (root, lft, rgt) -> true

// add_tree : IntTree -> int -> IntTree
// Returns the tree that results by adding the given element to the
// given tree.
let rec add_tree bst elem =
    match bst with
    | Nil -> Node (elem, Nil, Nil)
    | Node (root, lft, rgt) 
            when elem < root -> Node (root, (add_tree lft elem), rgt)
    | Node (root, lft, rgt) 
            when elem > root -> Node (root, lft, (add_tree rgt elem))
    | Node (root, lft, rgt) -> bst

// show_tree : IntTree -> unit
// Shows the elements in the given tree using inorder.
let rec show_tree = function
    | Nil -> ()
    | Node (root, lft, rgt) -> show_tree lft
                               printf "%d " root
                               show_tree rgt

// construct_tree : int list -> IntTree
// Returns the binary search tree that correspond to the given list.
let construct_tree lst =
    let rec helper bst lst =
        match lst with
        | [] -> bst
        | hd::[] -> Node (hd, Nil, Nil)
        | hd::tl when tl.Head < hd -> Node (hd, helper (Node (tl.Head, Nil, Nil)) tl, Nil)
        | hd::tl -> Node (hd, Nil, helper (Node (tl.Head, Nil, Nil)) tl)
    helper Nil lst

// size_tree : IntTree -> int
// Returns the number of elements in the given IntTree.
let rec size_tree = function
    | Nil -> 0
    | Node (root, Nil, Nil) -> 1
    | Node (root, lft, rgt) -> size_tree lft + size_tree rgt + 1
    
// minimum_tree : IntTree -> int
// Returns the minimum element of the given IntTree.
let minimum_tree bst =
    let rec helper min bst =
        match bst with
        | Nil -> min
        | Node (root, Nil, Nil) -> root
        | Node (root, lft, rgt) -> helper root lft 
    helper 0 bst 


// start : unit -> unit
let start () =
    let bst = Nil
    let bst1 = add_tree bst 30
    let bst2 = add_tree bst1 40
    let bst3 = add_tree bst2 10
    let bst4 = add_tree bst3 5
    let bst5 = add_tree bst4 20

    printf "This is the tree: "
    show_tree bst5
    printfn "\nThis is the tree, internally: %A" bst5
    printfn "The sum of its elements is %d" (sum_tree bst5)
    printfn "Does it contain 50? %b" (contains_tree bst5 50)
    printfn "The size of the tree is: %d" (size_tree bst5)
    printfn "The minimum element of the tree is: %d" (minimum_tree bst5)

    let lst = [154;35;63;2;5;6;7]
    printfn "Constructing tree..."
    printfn "Here is the tree: %A" (construct_tree lst)