hoi(1,X,Y,_):- write(Y),write(' to '),write(X), nl.

hoi(N,X,Y,Z):-
    N>1,
    M is N-1,
    hoi(M,X,Z,Y),
    hoi(1,X,Y,Z),
    hoi(M,Z,Y,X).

check_number(H,[H|_]).
check_number(H,[_|T]):- check_number(H,T).

add_element(N,L,[N|L]).

concact_list([],L2,L2).
concact_list([H|T],L2,[H|L3]):-concact_list(T,L2,L3).

delete(N,[N|T],T).
delete(N,[H|T],[H|T2]) :- delete(N,T,T2).

sum([],0).
sum([H|T],S):- sum(T,S1), S is S1+H.