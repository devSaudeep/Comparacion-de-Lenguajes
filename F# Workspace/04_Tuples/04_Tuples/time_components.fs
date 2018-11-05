(*
 * time_components.fs
 * By Antonio F. Huertas
 * This program prints the time components given the elapsed seconds.
 *)

let get_components elapsed_secs =
    let secs_per_hour = 3600
    let hrs = elapsed_secs / secs_per_hour
    let rem_secs = elapsed_secs % secs_per_hour

    let secs_per_min = 60
    let mins = rem_secs / secs_per_min
    let secs = rem_secs % secs_per_min

    (hrs, mins, secs)

// start : int -> unit
// Starts the execution of the program.
let start elapsed_secs =
    printfn "The number of elapsed seconds is %d" elapsed_secs

    if elapsed_secs < 0 then
        printfn "Error! The number of elapsed seconds is negative."
    else
        let (hrs, mins, secs) = get_components elapsed_secs
        printfn "\nAmount of time is %d hours, %d minutes and %d seconds" 
                hrs mins secs