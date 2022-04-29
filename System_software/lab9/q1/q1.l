/*lex code to count the number of lines,
	tabs and spaces used in the input*/

%{
#include<stdio.h>
/*Global variables*/
%}

/*Rule Section*/
%%
if|else|while|do|int {printf("Keyword => %s\n", yytext);}
[a-zA-Z_]+[a-zA-Z_0-9]*{30} {printf("Indentifier => %s\n", yytext);}
[0-9]*"."{1}?[0-9]+ {printf("Constant => %s\n", yytext);}
%%
int yywrap(void) {
	return 1;
}

int main(int argc, char* argv[])
{
    yyin = fopen(argv[1], "r");
	// The function that starts the analysis
	yylex();
}
