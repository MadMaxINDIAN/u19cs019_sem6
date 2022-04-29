/*lex code to count the number of lines,
	tabs and spaces used in the input*/

%{
#include<stdio.h>
int lc = 0, wc = 0, ch = 0; /*Global variables*/
%}

/*Rule Section*/
%%
\n lc++; //line counter
[^ \n\t]+ {wc++, ch = ch + yyleng;} // word counter
. ch++;	 //characters counter
%%

int main()
{
	// The function that starts the analysis
	yylex();
	
	printf("\nNo. of lines=%d", lc);
	printf("\nNo. of words=%d", wc);
	printf("\nNo. of other characters=%d\n", ch);
	
}
