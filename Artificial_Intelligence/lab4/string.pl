%finding length of the list 
len([],0). 
len([_|T], N) :- 
 len(T,N1), 
 N is N1 + 1. 

%finding last element 
last([H|[]],H). 
last([_|T],L) :- 
 last(T,L). 

%finding first element 
first([H|_],H). 

%finding find member of list 
find(H,1,[H|_]). 
find(X,N,[_|L]) :- 
 find(X,N1,L), 
 N is N1+1. 

%incrementing each element by 1 
inc([], []). 
inc([H|T], [X|Y]) :- 
 inc(T,Y), 
 X is H+1. 

%reversing list 
rev([], Y, Y). 
rev([H|T] , Y, R) :- 
 rev(T, [H|Y], R). 

%if a list has an even number of elements.
odd([_|T]):- 
 even(T). 
even([]). 
even([_|T]) :- 
 odd(T). 

%To count vowels in the list 
vowel(X):- member(X,[a,e,i,o,u]). 
countv([],0). 
countv([X|T],N):- vowel(X),countv(T,N1), N is N1+1,!. 
countv([X|T],N):- countv(T,N). 

%removing duplicates 
rem([], []). 
rem([Head | Tail], Result) :- 
 member(Head, Tail), !, 
 rem(Tail, Result). 
rem([Head | Tail], [Head | Result]) :- 
 rem(Tail, Result). 
