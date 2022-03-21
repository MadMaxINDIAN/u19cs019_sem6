fact(0,X):- X=1.
fact(M,X):- M>0, M1 is M-1,fact(M1,X1),X is X1*M .