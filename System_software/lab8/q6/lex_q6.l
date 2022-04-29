/*lex code to count the number of lines,
	tabs and spaces used in the input*/

%{
#include<stdio.h>
#include<string.h>
char *token;
%}

/*Rule Section*/
%%
[0-9]+"+"[0-9]+ {printf("Addition: \t%d", atoi(strtok(yytext, "+")) + atoi(strtok(NULL, "+")));}
[0-9]+"-"[0-9]+ {printf("Subtraction: \t%d", atoi(strtok(yytext, "-")) - atoi(strtok(NULL, "-")));}
[0-9]+"*"[0-9]+ {printf("Multiplication: \t%d", atoi(strtok(yytext, "*")) * atoi(strtok(NULL, "*")));}
[0-9]+"/"[0-9]+ {printf("Division: \t%d", atoi(strtok(yytext, "/")) / atoi(strtok(NULL, "/")));}
.+ {printf("Invalid operation");}
%%

int yywrap(void) {
	return 1;
}

int main()
{
	// The function that starts the analysis
    printf("Enter calculator command: \t");
	yylex();
}
