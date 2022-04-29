/*lex code to count the number of lines,
	tabs and spaces used in the input*/

%{
#include<stdio.h>
/*Global variables*/
%}

/*Rule Section*/
%%
"0x"{1}[0-9A-Fa-f]+ {printf("Hexdecimal number => %s\n", yytext);}
[0-7]+ {printf("Octal number => %s\nHexdecimal number => %s\n", yytext, yytext);}
[0-9A-Fa-f]+ {printf("Hexdecimal number => %s\n", yytext);}
%%
int yywrap(void) {
	return 1;
}

int main(int argc, char* argv[])
{
    yyin = fopen(argv[1], "r");
    printf("Enter hex ot octal number: ");
	// The function that starts the analysis
	yylex();
}
