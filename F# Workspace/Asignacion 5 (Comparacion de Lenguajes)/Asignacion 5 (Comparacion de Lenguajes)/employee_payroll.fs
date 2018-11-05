(*
 * employee_payroll.fs
 * By Saulo Almeda Nieves
 * 841-13-0170
 * 11/27/2015
 * This program creates a list of at least five different kinds of employees
 * and displays their data, including their weekly salary with the appropiate
 * format.
 *)

//Defines a discriminated union type for Employee.
type Employee =
    | HourlyEmployee of string * string * float * float
    | SalesEmployee of string * string * float * float

//Calculates the weekly salary of the given employee.
let weekly = function
    | HourlyEmployee (_, _, payrate, hrsworked) ->
        if hrsworked > 40.00 then ((hrsworked - 40.00) * payrate * 1.5) + (40.00 * payrate)
        else payrate * hrsworked
    | SalesEmployee (_, _, commrate, salesamount) ->
        commrate * salesamount

// show_emplyee : Employee -> unit
// Displays the data of the given employee.
let show_employee emp =
    match emp with
    | HourlyEmployee (id, name, payrate, hrsworked) ->
        printfn "ID: %s" id
        printfn "Name: %s" name
        printfn "Pay rate: %.2f" payrate
        printfn "Hours worked: %.2f" hrsworked
    | SalesEmployee (id, name, commrate, salesamount) ->
        printfn "ID: %s" id
        printfn "Name: %s" name
        printfn "Commission rate: %.2f" (commrate * 100.00)
        printfn "Sales amount: $%.2f" salesamount

    printfn "Weekly salary: $%.2f\n" (weekly emp)

//Serves as starting point of the app.
let start () =
    let lst = [
        HourlyEmployee ("1234", "Saulo", 7.25, 35.00); 
        SalesEmployee ("2345", "Saul", 0.50, 6000.00);
        HourlyEmployee ("3456", "Raquel", 8.00, 45.00);
        SalesEmployee ("4567", "Rebeca", 0.30, 1500.00);
        HourlyEmployee ("5678", "Judith", 32.00, 40.00)]

    printfn "These are the employees:"
    List.iter (fun elem -> printfn "Employee Data..."; show_employee elem) lst