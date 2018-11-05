(*
 * tuple_demo.c
 * By Antonio F. Huertas
 * This program demonstrates some how to create and use tuples.
 *)

// show_item : string * string * float * int -> unit
// Shows the data of the given item.
let show_item itm =
    let (id, desc, price, onHand) = itm
    printfn "\tId = %s" id
    printfn "\tDescription = %s" desc
    printfn "\tPrice = $%.2f" price
    printfn "\tQuantity on Hand = %d" onHand
    printfn ""

// start: unit -> unit
// Serves as an entry point for the program.
let start () =
    let item1 = ("1234", "Hammer", 8.99, 5)
    printfn "This is item1: %A" item1

    let clone = item1
    printfn "\nThis is a clone of item1: %A" clone

    let lst = [
        ("1234", "Hammer", 8.99, 5);
        ("5678", "Saw", 12.99, 10);
        ("9012", "Screwdriver", 4.99, 20)
     ]

    printfn "\nThis is a list of items..."
    List.iter (fun elem -> printf "Data:" ; show_item elem) lst

    if item1 = (List.nth lst 0) then
        printfn "\nItems item1 and the first element are the same"
    else
        printfn "\nItems item1 and the first element are NOT the same"