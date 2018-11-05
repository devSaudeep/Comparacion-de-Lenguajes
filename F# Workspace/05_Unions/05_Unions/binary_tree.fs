(*
 * binary_tree.fs
 * By Antonio F. Huertas
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
    | Node (root, lft, _) 
            when elem < root -> contains_tree lft elem
    | Node (root, _, rgt) 
            when elem > root -> contains_tree rgt elem
    | _ -> true

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
    | _ -> bst

// show_tree : IntTree -> unit
// Shows the elements in the given tree using inorder.
let rec show_tree = function
    | Nil -> ()
    | Node (root, lft, rgt) -> show_tree lft
                               printf "%d " root
                               show_tree rgt

// start : unit -> unit
let start () =
    let bst = Nil
    let bst1 = add_tree bst 30
    let bst2 = add_tree bst1 40
    let bst3 = add_tree bst2 10
    let bst4 = add_tree bst3 50
    let bst5 = add_tree bst4 20

    printf "This is the tree: "
    show_tree bst5
    printfn "\nThis is the tree, internally: %A" bst5
    printfn "The sum of its elements is %d" (sum_tree bst5)
    printfn "Does it contain 50? %b" (contains_tree bst5 50)