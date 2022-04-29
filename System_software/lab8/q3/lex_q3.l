/*lex code to count the number of lines,
	tabs and spaces used in the input*/

%{
#include<stdio.h>
%}

/*Rule Section*/
%%
[a-z] {printf("%c", yytext[0]-32);}
. {printf("%c", yytext[0]);}
%%

int yywrap(void) {
	return 1;
}

int main()
{
	// The function that starts the analysis
	yylex();
}
