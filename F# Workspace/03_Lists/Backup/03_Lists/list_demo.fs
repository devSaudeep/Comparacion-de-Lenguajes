(*
 * list_demo.fs
 * By Antonio F. Huertas
 * This program demonstrates how to work with list using some operators and
 * functions from the automatically-imported List module.  It also 
 * demonstrates list comprehensions.
 *)

// start: unit -> unit
// Serves as an entry point for the program.
let start () =
    let lst = [30;40;10;50;20]
    printfn "This is the list: %A" lst
    printfn "It is empty? %b" (List.isEmpty lst)
    printfn "The head is %d" (List.head lst)
    printfn "The tail is %A" (List.tail lst)
    printfn "The length is %d" (List.length lst)
    printfn "The sum of the elements is %d" (List.sum lst)
    printfn "The elements in reverse order: %A" (List.rev lst)

    printfn "\nSearching and sorting..."
    printfn "The element at index #2 is %d" (List.nth lst 2)
    printfn "The elements, sorted in ascending order: %A" (List.sort lst)

    lst |> List.sort
        |> List.rev
        |> printfn "The elements, sorted in descending order: %A"

    printfn "\nConstructing and appending..."
    let lst2 = 60::70::80::90::100::[]
    printfn "Constructing a list using '::': %A" lst2
    printfn "Appending the two lists: %A" (List.append lst lst2)
    printfn "Appending the two lists using '@': %A" (lst @ lst2)

    lst |> List.append lst2
        |> List.sort
        |> printfn "The elements of both lists, sorted: %A"

    printfn "\nDemostrating list comprehensions..."
    let lst3 = [1..10]            // using a range
    printfn "The list from 1 to 10: %A" lst3

    let lst4 = [10..5..50]        // using a range with step
    printfn "The list from 10 to 50 with a step of 5: %A" lst4

    let lst5 = [50..-5..10]       // using a range with a negative step
    printfn "The list from 50 to 10 with a step of -5: %A" lst5

    let lst6 = [for n in 1..10 do yield n * n]      // using a generator
    printfn "The list of the first 10 squares: %A" lst6

    let lst7 = [for n in 1..20 do                   // using a generator
                    if n % 2 = 0 then yield n * n]  // and a filter
    printfn "The list of the first 10 even squares: %A" lst7

start ()