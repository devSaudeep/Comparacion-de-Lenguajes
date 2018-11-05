(*
 * currying_demo.fs
 * By Antonio F. Huertas
 * This program demonstrates currying and partial function application.
 *)

// add : int -> int -> int
// Returns the sum of two integers.  
let add num1 num2 = num1 + num2

// subtract : int -> int -> int
// Returns the difference of two integers.
let subtract num1 num2 = num1 - num2

// multiply : int -> int -> int
// Returns the product of two integers.
// NOTE: Creates an alias for an anonymous function.
let multiply =
    fun num1 num2 -> num1 * num2

// divide : int -> int -> int
// Returns the quotient of two integers.  
// NOTE: Uses currying for the parameters.
let divide = 
    fun num1 -> fun num2 -> num1 / num2

// successor : (int -> int)
// Returns the successor of the given integer.
// Note: Uses a partial function application.
let successor = add 1

// start : int -> int -> unit
// Serves as the entry-point of the program.
let start num1 num2 =
    printfn "The numbers are %d and %d" num1 num2
    printfn "Their sum is %d" (add num1 num2)
    printfn "Their difference is %d" (subtract num1 num2)
    printfn "Their product is %d" (multiply num1 num2)
    printfn "Their quotient is %d" (divide num1 num2)
    printfn "The successor of %d is %d" num1 (successor num1)
    printfn "The successor of %d is %d" num2 (successor num2)

