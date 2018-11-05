/*
 * travel.pl
 * By Antonio F. Huertas
 * Edited by Saulo Almeda Nieves
 * This is a knowledge base of fictitious travel information.
 */

% byCar(?Origin, ?Destination)
% True if Destination is reachable from Origin by car.
byCar(bayamon, guaynabo).
byCar(guaynabo, san_juan).
byCar(san_juan, carolina).
byCar(aguadilla, mayaguez).
byCar(mayaguez, san_german).

% byTrain(?Origin, ?Destination)
% True if Destination is reachable from Origin by train.
byTrain(bayamon, aguadilla).
byTrain(aguadilla, cabo_rojo).
byTrain(san_german, ponce).
byTrain(carolina, fajardo).
byTrain(carolina, ponce).

% byPlane(?Origin, ?Destination)
% True if Destination is reachable from Origin by plane.
byPlane(carolina, orlando).
byPlane(carolina, new_york).
byPlane(carolina, paris).
byPlane(paris, tokio).
byPlane(new_york, san_antonio).
byPlane(san_antonio, san_francisco).

travelByCar(Dest1, Dest2) :-
                     byCar(Dest1, Dest2).

travelByCar(Dest1, Dest2) :-
                     byCar(Dest1, OtherDest),
                     travelByCar(OtherDest, Dest2).
                     
travelByTrain(Dest1, Dest2) :-
                     byTrain(Dest1, Dest2).
                     
travelByTrain(Dest1, Dest2) :-
                     byTrain(Dest1, OtherDest),
                     travelByTrain(OtherDest, Dest2).
                     
travelByPlane(Dest1, Dest2) :-
                     byPlane(Dest1, Dest2).

travelByPlane(Dest1, Dest2) :-
                     byPlane(Dest1, OtherDest),
                     travelByPlane(OtherDest, Dest2).
                     
travel(Origin, Dest1) :-
               travelByCar(Origin, Dest2),
               travelByTrain(Dest2, Dest1) ;
               travelByCar(Origin, Dest4),
               travelByPlane(Dest4, Dest1).