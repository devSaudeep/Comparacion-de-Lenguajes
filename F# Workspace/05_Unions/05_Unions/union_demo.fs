(*
 * union_demo.fs
 * By Antonio F. Huertas
 * This program demonstrates some how to create and use discriminated
 * unions.
 *)

// Defines a discriminated union type for a light dimmer with three
// possible states: off, on, or level of brightness percentage.
type Dimmer =
    | Off
    | On
    | BrightLevel of float

// show_dimmer : Dimmer -> unit
// Shows the state of the given dimmer.
let show_dimmer = function
    | Off -> printfn "The dimmer is off."
    | On -> printfn "The dimmer is on."
    | BrightLevel(percent) -> printfn "The dimmer is %.3f%% bright." 
                                      percent

// toggle_dimmer : Dimmer -> Dimmer
// Toggles the state of the given dimmer.
let toggle_dimmer = function
    | Off -> On
    | On -> Off
    | BrightLevel(percent) -> let pivot = 0.5
                              if percent <= pivot then
                                    BrightLevel(percent + pivot)
                              else
                                    BrightLevel(percent - pivot)

// start : unit -> unit
// Starts the execution of this program.
let start () =
     let dim1 = Off
     printfn "This is dim1: %A" dim1
     show_dimmer dim1

     printf "Toggling dim1: "
     show_dimmer (toggle_dimmer dim1)

     let dim2 = On
     printfn "\nThis is dim2: %A" dim2
     show_dimmer dim2

     printf "Toggling dim2: "
     show_dimmer (toggle_dimmer dim2)

     let dim3 = BrightLevel(0.25)
     printfn "\nThis is dim3: %A" dim3
     show_dimmer dim3

     printf "Toggling dim3: "
     show_dimmer (toggle_dimmer dim3)