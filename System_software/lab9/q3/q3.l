/*lex code to count the number of lines,
	tabs and spaces used in the input*/

%{
#include<stdio.h>
/*Global variables*/
%}

/*Rule Section*/
%%
\/\/.{1,} { printf("Single line comment: %s\n", yytext); }
\/\*[.{1,}\n{1,}]*\*\/ { printf("Multi line comment: %s\n", yytext); }
%%
int yywrap(void) {
	return 1;
}

int main(int argc, char* argv[])
{
    yyin = fopen(argv[1], "r");
	yylex();
}
