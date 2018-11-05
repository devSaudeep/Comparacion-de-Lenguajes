(*
 * student_eval.fs
 * By Antonio F. Huertas
 * This program displays the average for a course taken by some students.
 *)

// Defines the record type for a student.
type Student = {
    id : string
    name : string
    exams : int list
}

let average lst =
    float (List.sum lst) / float (List.length lst)

let show_data std =
    printfn "ID: %s" std.id
    printfn "Name: %s" std.name
    printfn "Exams: %A" std.exams
    printfn "Average: %.1f" (average std.exams)

// start: unit -> unit
// Serves as an entry point for the program.
let start () =
    let std1 = { id = "111"; name = "John Doe"; exams = [90; 94; 86] }
    printfn "This is the first student:"
    show_data std1

    let std2 = { id = "4567"; name = "Jane Doe"; exams = [80; 85; 73] }
    printfn "\nThis is another student:"
    show_data std2