(*
 * queue.fs
 * By Saulo Almeda Nieves
 * Source (implementation) file for a queue.
 * This file contains the private implementation of the queue as a
 * linked list.
 * NOTE: The implementation source file MUST have the same name as the
 *       corresponding signature file.
 *       The implementation source file MUST appear before the corresponding
 *       client source file in the Solution Explorer.
 *)

// Indicates the namespace that contains the Queue module.
namespace FunctionalCollections

// Defines the EmptyQueue exception.
exception EmptyQueue of string

// Defines the Queue module.
module Queue =
    // Defines the queue type as a linked list.
    type 'a Queue = QueueList of 'a list * 'a list

    let empty = QueueList ([], [])

    let isEmpty = function
        | ([], []) -> true
        | _ -> false