male(i).
male(f).
male(s1).
male(s2).

female(w).
female(d).

married(i,w).
married(w,i).
married(f,d).
married(d,f).

parent(w,d).
parent(i,d).
parent(f,i).
parent(i,s1).
parent(w,s1).
parent(f,s2).
parent(d,s2).
parent(d,i).

sibling(X,Y) :- parent(Z,X),parent(Z,Y),not(X==Y).
father_in_law(X,Y) :- parent(X,Z),male(X),married(Y,Z).
mother_in_law(X,Y) :- parent(X,Z),female(X),married(Y,Z).
son_in_law(X,Y) :- married(X,Z),parent(Y,Z),male(X).
brother_in_law(X,Y) :- married(Y,Z),sibling(X,Z),male(X).
uncle(X,Y):- parent(Z,Y),sibling(X,Z),male(X).
grandparent(X,Y):- parent(X,Z),parent(Z,Y).