/*
 * factorial_vers.pl
 * By Antonio F. Huertas
 * This program displays the factorial of a non-negative integer
 * using different versions.
 */

%% factorial(+Number, ?Fact)
%  Computes the factorial of a non-negative integer.
%  NOTE: This version uses regular recursion.
factorial(0, 1).

factorial(Number, Fact) :-
                  Number > 0,
                  Pred is Number - 1,
                  factorial(Pred, FactPred),
                  Fact is Number * FactPred.

%% factorial_v2(+Number, ?Fact)
%  Computes the factorial of a non-negative integer.
%  NOTE: This version uses a helper tail-recursive predicate.
factorial_v2(Number, Fact) :-
                     factorial_v2_helper(Number, 1, Fact).

% factorial_v2_helper(+Number, +Accum, ?Fact)
factorial_v2_helper(Number, Accum, Fact) :-
                            Number > 0,
                            NewAccum is Accum * Number,
                            NewNumber is Number - 1,
                            factorial_v2_helper(NewNumber, NewAccum, Fact).
                            
factorial_v2_helper(0, Accum, Accum).

%% start(+Number)
%  Serves as an entry point for the program.
start(Number) :-
    write('The number is '), write(Number), nl,
    Number >= 0,

    factorial_v2(Number, Fact2),
    write('Tail recursion: the factorial is '), write(Fact2), nl,

    factorial(Number, Fact),
    write('Regular recursion: the factorial is '), write(Fact), nl.
