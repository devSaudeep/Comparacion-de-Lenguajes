(*
 * stack_menu.fs
 * By Antonio F. Huertas
 * This program manages a menu of common stack operations.
 *)

open FunctionalCollections    // for the Stack module functions
open System                   // for the .NET Console class methods

// Process the push element menu option.
let process_push stk =
    Console.Write "Enter a character: "
    let elem = Console.ReadLine () |> char
    Console.WriteLine ("Pushing {0} into the stack.", elem)
    Stack.push elem stk

// Process the pop element menu option.
let process_pop stk =
    try
        let elem = Stack.peek stk |> char
        Console.WriteLine ("Popping {0} from the stack.", elem)
        Stack.pop stk
    with
        EmptyStack msg -> Console.WriteLine ("Cannot pop: {0}", msg)
                          stk

// Process the view contents menu option.
let process_view stk =
    if Stack.isEmpty stk then
        Console.WriteLine "Cannot show: stack is empty."
    else
        Console.Write "Contents of the stack: "
        Stack.iter (printf "%c ") stk
        Console.WriteLine ()

// Shows the menu options.
let show_menu () =
    Console.WriteLine "\nStack Menu\n"
    Console.WriteLine "1. Push an element"
    Console.WriteLine "2. Pop an element"
    Console.WriteLine "3. View the contents"
    Console.WriteLine "4. Exit"

// Manages the menu selection on the stack.
let rec process_menu stk =
    show_menu ()
    Console.Write "Enter selection (1-4): "
    match (Console.ReadLine () |> int) with
    | 1 -> stk |> process_push |> process_menu
    | 2 -> stk |> process_pop |> process_menu
    | 3 -> process_view stk
           process_menu stk
    | 4 -> Console.WriteLine "Thanks for using this program!"
    | _ -> Console.WriteLine "Error! Selection must be between 1 and 4."
           process_menu stk

// Serves as the entry point of the program.
let main () =
    process_menu Stack.empty
    Console.ReadKey () |> ignore

// Calls the main function.
main()