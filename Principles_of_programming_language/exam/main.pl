memCount(_, [], 0).

memCount(Alist, [Head|Tail], Result) :-
    is_list(Head), !,
    memCount(Alist, Head, Result1),
    memCount(Alist, Tail, Result2),
    Result is Result1 + Result2.

memCount(Alist, [Alist|Tail], Result) :-
    memCount(Alist, Tail, Result1),
    Result is Result1 + 1.

memCount(Alist, [_|Tail], Result) :-
    memCount(Alist, Tail, Result).

main(Char, Alist) :-
    memCount(Char, Alist, N),
    write("No of occurences is "), write(N), !.