/*lex code to count the number of lines,
	tabs and spaces used in the input*/

%{
#include<stdio.h>
int lc = 0, v = 0, ch = 0; /*Global variables*/
%}

/*Rule Section*/
%%
[aeiouAEIOU] v++; // vowels counter
[a-zA-Z] ch++;	 //characters counter
%%

int main()  
{
	// The function that starts the analysis
	yylex();
	
	printf("\nNo. of lines=%d", lc);
	printf("\nNo. of vowels=%d", v);
	printf("\nNo. of consonants=%d\n", ch);
}
