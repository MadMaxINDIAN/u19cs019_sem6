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

% Relationships
father_of(X,Y):-male(X),parent(X,Y).
siblings(X,Y):-parent(Z,X),parent(Z,Y),X\==Y.
sister(X,Y):-siblings(X,Y),female(Y),X\==Y.
grandmother(X,Y):-parent(X,Z),parent(Z,Y),female(X).
cousin(A,B):- parent(X,A),parent(Y,B),siblings(X,Y).