(*
 * stack_alg.fs
 * By Antonio F. Huertas
 * Source (implementation) file for a generic stack.
 * This file contains the private implementation of the stack as an
 * algebraic data type.
 * NOTE: The implementation source file MUST have the same name as the
 *       corresponding signature file.
 *       The implementation source file MUST appear before the corresponding
 *       client source file in the Solution Explorer.
 *)

// Indicates the namespace that contains the Stack module.
namespace FunctionalCollections

// Defines the EmptyStack exception.
exception EmptyStack of string

// Defines the Stack module.
module Stack =
    // Defines the stack type as an algebraic data type.
    type 'a Stack = Nil | Node of 'a * 'a Stack

    // Returns a new empty stack.
    let empty = Nil

    // Determines whether a stack is empty.
    let isEmpty = function
        | Nil -> true
        | _ -> false

    // Adds an element to the top of a stack.
    let push elem stk = Node (elem, stk)

    // Removes the element at the top of a stack.
    let pop = function
        | Nil -> raise (EmptyStack "stack is empty")
        | Node (_, rest) -> rest

    // Returns the element at the top of a stack.
    let peek = function
        | Nil -> raise (EmptyStack "stack is empty")
        | Node (top, _) -> top

    // Iterates through a stack using a visit function.
    let rec iter visit = function
        | Nil -> ()
        | Node (top, rest) -> visit top
                              iter visit rest
