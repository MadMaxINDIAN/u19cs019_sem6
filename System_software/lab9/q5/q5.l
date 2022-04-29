/*lex code to count the number of lines,
	tabs and spaces used in the input*/

%{
#include<stdio.h>
/*Global variables*/
%}

/*Rule Section*/
%%
^aa[a-zA-Z]*bcd$ {printf("Valid string =>\t %s\n", yytext);}
. {}
%%
int yywrap(void) {
	return 1;
}

int main(int argc, char* argv[])
{
	// The function that starts the analysis
	yylex();
}
