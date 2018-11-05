(*
 * queue.fsi
 * By Antonio F. Huertas
 * Signature file for a generic queue.
 * This file contains the public interface of the queue.
 * NOTE: The signature file MUST appear before the corresponding implementation
 *       source file in the Solution Explorer.
 *)

// Indicates the namespace that contains the Queue module.
namespace FunctionalCollections

// Defines the EmptyQueue exception.
exception EmptyQueue of string

// Declares the Queue module.
module Queue =
    // Declares the queue data type.
    type 'a Queue

    // Returns a new empty queue.
    val empty : 'a Queue

    // Determines whether a queue is empty.
    val isEmpty : 'a Queue -> bool

    // Adds an element to the front of a queue.
    val add : 'a -> 'a Queue -> 'a Queue

    // Removes the element at the front of a queue.
    // Raises EmptyQueue exception if needed.
    val remove : 'a Queue -> 'a Queue

    // Returns the element at the top of a queue.
    // Raises EmptyQueue exception if needed.
    val peek : 'a Queue -> 'a

    // Iterates through a queue using a visit function.
    val iter : ('a -> unit) -> 'a Queue -> unit