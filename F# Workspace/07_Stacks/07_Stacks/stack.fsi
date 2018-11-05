(*
 * stack.fsi
 * By Antonio F. Huertas
 * Signature (interface) file for a generic stack.
 * This file contains the public interface of the stack.
 * NOTE: The signature file MUST appear before the corresponding implementation 
 *       source file in the Solution Explorer.
 *)

// Indicates the namespace that contains the Stack module.
namespace FunctionalCollections

// Defines the EmptyStack exception.
exception EmptyStack of string

// Declares the Stack module.
module Stack =
    // Declares the stack opaque type.  Its implementation is elsewhere.
    type 'a Stack

    // Returns a new empty stack.
    val empty : 'a Stack

    // Determines whether a stack is empty.
    val isEmpty : 'a Stack -> bool

    // Adds an element to the top of a stack.
    val push : 'a -> 'a Stack -> 'a Stack

    // Removes the element at the top of a stack.
    // Raises EmptyStack exception if needed.
    val pop : 'a Stack -> 'a Stack

    // Returns the element at the top of a stack.
    // Raises EmptyStack exception if needed.
    val peek : 'a Stack -> 'a

    // Iterates through a stack using a visit function.
    val iter : ('a -> unit) -> 'a Stack -> unit

