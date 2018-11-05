(*
 * stack_lst.fs
 * By Antonio F. Huertas
 * Source (implementation) file for a generic stack.
 * This file contains the private implementation of the stack as a
 * generic list.
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
    // Defines the stack type as a generic list.
    type 'a Stack = StackList of 'a list

    // Returns a new empty stack.
    let empty = StackList ([])

    // Determines whether a stack is empty.
    let isEmpty = function
        | StackList ([]) -> true
        | _ -> false

    // Adds an element to the top of a stack.
    let push elem (StackList elems) = StackList (elem::elems)

    // Removes the element at the top of a stack.
    let pop = function
        | StackList ([]) -> raise (EmptyStack "stack is empty")
        | StackList (_::rest) -> StackList rest

    // Returns the element at the top of a stack.
    let peek = function
        | StackList ([]) -> raise (EmptyStack "stack is empty")
        | StackList (top::_) -> top

    // Iterates through a stack using a visit function.
    let rec iter visit = function
        | StackList ([]) -> ()
        | StackList (top::rest) -> visit top
                                   iter visit (StackList rest)

