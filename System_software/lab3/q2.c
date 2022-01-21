#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// function to remove white space from the beginning of a string
void remove_white_space(char *str) {
    int i = 0;
    while (str[i] == ' ') {
        i++;
    }
    strcpy(str, str + i);
}

int main () {
    char line[100];
    printf("Enter a line of text: ");
    fgets(line, 100, stdin);
    remove_white_space(line);
    if (strncmp(line, "//", 2) == 0) {
        printf("The line is a comment.\n");
    } else {
        printf("The line is not a comment.\n");
    }
    printf("The program is finished.\n");
    return 0;
}