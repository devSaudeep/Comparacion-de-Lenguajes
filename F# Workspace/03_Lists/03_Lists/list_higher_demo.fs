(*
 * list_higher_demo.fs
 * By Antonio F. Huertas
 * This program demonstrates some higher order list functions from the 
 * automatically-imported List module.
 *)

// start: unit -> unit
// Serves as an entry point for the program.
let start () =
    let lst = [1..10]
    printfn "This is the list: %A" lst
    List.iter (fun elem -> printfn "%d" elem) lst 
                // Atl.: List.iter (printfn "%d") lst

    let len = List.fold (fun acc _ -> acc + 1) 0 lst
    printfn "\nThe length is %d" len

    let sum = List.fold (fun acc elem -> acc + elem) 0 lst
                // Alt.: List.fold (+) 0 lst
    printfn "The sum of the elements is %d" sum

    let rev = List.fold (fun acc elem -> elem::acc) [] lst
    printfn "The elements in reverse order: %A" rev

    let has30 = List.exists (fun elem -> elem = 30) lst
    printfn "Does the list contains 30? %b" has30

    let hasEven = List.exists (fun elem -> elem % 2 = 0) lst
    printfn "Does the list contains even elements? %b" hasEven

    let lst2 = List.map (fun elem -> elem * 3) lst
    printfn "\nThe list of the first 10 multiples of 3: %A" lst2

    let lst3 = List.map (fun elem -> elem * elem) lst
    printfn "\nThe list of the first 10 squares: %A" lst3

    let lst4 = List.filter (fun elem -> elem > 5) lst
    printfn "\nThe list from 6 through 10: %A" lst4

    let lst5 = List.filter (fun elem -> elem % 2 = 0) lst
    printfn "\nThe list of the first 5 even elements: %A" lst5

    [1..5] |> List.fold (*) 1
            |> printfn "\nThe factorial of 5 is %d"

    [1..20] |> List.map (fun elem -> elem * elem)
            |> List.filter (fun elem -> elem % 2 = 0)
            |> printfn "\nThe list of the first 10 even squares: %A"
    
start ()