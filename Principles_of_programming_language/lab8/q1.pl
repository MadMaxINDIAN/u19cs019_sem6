%predicates
female(mary).
female(sandra).
female(juliet).
female(lisa).
male(peter).
male(paul).
male(dick).
male(bob).
male(harry).
parent(bob, lisa).
parent(bob, paul).
parent(bob, mary).
parent(juliet, lisa).
parent(juliet, paul).
parent(juliet, mary).
parent(peter, harry).
parent(lisa, harry).
parent(mary, dick).
parent(mary, sandra).
husband(peter,lisa).
husband(bob,juliet).

%rules
child(X,Y) :- parent(Y,X).
mother(X,Y) :- parent(X,Y),female(X).
father(X,Y) :- parent(X,Y),male(X).
wife(X,Y) :- husband(Y,X).
son(X,Y) :- child(X,Y),male(X).
daughter(X,Y) :- child(X,Y),female(X).
brother(X,Y) :- parent(Z,X), parent(Z,Y),male(X), X \= Y.
sister(X,Y) :- parent(Z,X), parent(Z,Y),female(X), X \= Y.
uncle(X,Y) :- parent(Z,Y),male(X), brother(X,Z). 
aunt(X,Y) :- parent(Z,Y),female(X), sister(X,Z).
nephew(X,Y) :- parent(Z,X), male(X),(brother(Y,Z);sister(Y,Z)).
niece(X,Y) :- parent(Z,X), female(X),(brother(Y,Z);sister(Y,Z)).