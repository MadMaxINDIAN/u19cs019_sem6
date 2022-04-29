/*lex code to count the number of lines,
	tabs and spaces used in the input*/

%{
#include<stdio.h>
%}

/*Rule Section*/
%%
"+91-"+[7-9][0-9]{9} {printf("Valid mobile number: \t%s", yytext);}
.+ {printf("Invalid mobile number \t\t");}
%%

int yywrap(void) {
	return 1;
}

int main()
{
	// The function that starts the analysis
    printf("Enter mobile number: \t");
	yylex();
}
