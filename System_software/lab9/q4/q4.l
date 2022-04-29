/*lex code to count the number of lines,
	tabs and spaces used in the input*/

%{
#include<stdio.h>
int n = 0, p = 0, z = 0;
/*Global variables*/
%}

/*Rule Section*/
%%
-[0-9]+ {n++;}
[1-9]+[0-9]* {p++;}
0+ {z++;}
%%
int yywrap(void) {
	return 1;
}

int main(int argc, char* argv[])
{
	// The function that starts the analysis
	yylex();

    printf("Negative numbers %d\n", n);
    printf("Positive numbers %d\n", p);
    printf("Zero numbers %d\n", z);
}
