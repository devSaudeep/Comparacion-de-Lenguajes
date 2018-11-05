(*
 * record_demo.c
 * By Antonio F. Huertas
 * This program demonstrates some how to create and use records.
 *)

// Defines the record type for an item.
type Item = {
    id : string
    desc : string
    price : float
    onHand : int
}

// show_item : Item -> unit
// Shows the data of the given item.
let show_item itm =
    printfn "\tId = %s" itm.id
    printfn "\tDescription = %s" itm.desc
    printfn "\tPrice = $%.2f" itm.price
    printfn "\tQuantity on Hand = %d" itm.onHand
    printfn ""

// start: unit -> unit
// Serves as an entry point for the program.
let start () =
    let item1 = { id = "1234"; desc = "Hammer"; price = 8.99; onHand = 5 }
    printfn "This is item1: %A" item1

    let clone = item1
    printfn "\nThis is a clone of item1: %A" clone

    let partial = { item1 with id = "4321"; desc = "Small hammer" }
    printfn "\nThis is a partial clone of item1: %A" partial

    let lst = [
        { id = "1234"; desc = "Hammer"; price = 8.99; onHand = 5 };
        { id = "5678"; desc = "Saw"; price = 12.99; onHand = 10 };
        { id = "9012"; desc = "Screwdriver"; price = 4.99; onHand = 20 }
     ]

    printfn "\nThis is a list of items..."
    List.iter (fun elem -> printf "Data:" ; show_item elem) lst

    if item1 = (List.nth lst 0) then
        printfn "\nItems item1 and the first element are the same"
    else
        printfn "\nItems item1 and the first element are NOT the same"