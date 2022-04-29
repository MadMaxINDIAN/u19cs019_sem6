/*lex code to count the number of lines,
	tabs and spaces used in the input*/

%{
#include<stdio.h>
%}

/*Rule Section*/
%%
[a-z0-9]+@[a-z]+".com"|".in" {printf("Valid email: \t%s", yytext);}
.+ {printf("Invalid email");}
%%

int yywrap(void) {
	return 1;
}

int main()
{
	// The function that starts the analysis
    printf("Enter email: \t");
	yylex();
}
