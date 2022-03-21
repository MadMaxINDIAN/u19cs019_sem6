%GCD 
gcd(X,0,X). 
gcd(X,Y,Z):- 
R is mod(X,Y), 
gcd(Y,R,Z). 
%LCM 
lcm(X,Y,LCM):-gcd(X,Y,GCD), LCM is X*Y//GCD.