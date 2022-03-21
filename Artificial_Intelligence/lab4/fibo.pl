fibo(1,Y):- Y is 1.
fibo(2,Y):- Y is 1.

fibo(X,Result):- X>2,X1 is X-1, X2 is X-2,fibo(X1,R1),fibo(X2,R2),Result is R1+R2.
