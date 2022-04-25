memCount(_, [], 0).

memCount(Alist, [H|T], R) :-
    is_list(H), !,
    memCount(Alist, H, R1),
    memCount(Alist, T, R2),
    R is R1 + R2.

memCount(Alist, [Alist|T], R) :-
    memCount(Alist, T, R1),
    R is R1 + 1.

memCount(Alist, [_|T], N) :-
    memCount(Alist, T, N).

main(Char, Alist) :-
    memCount(Char, Alist, N),
    write("No of occurences is "), write(N), !.