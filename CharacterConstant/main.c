/****************************************************************************
 Program Name:      char.c
 Author:            Patrick Stearns
 Compiler:          Xcode 5
 OS:                OS X 10.9.1
 Description:       Print the numerical value of special character constants
 Input Files:       None
 Output Files:      csis.txt
 ****************************************************************************/

#include <stdio.h>

FILE *csis;

int main(void)
{
    csis = fopen("csis.txt", "w");

    // Output character constants and calculate
    printf("Char Constant\t Description\t\t Value\n");
    fprintf(csis, "Char Constant\t Description\t\t Value\n");

    // Newline output
    printf("'\\n'\t\t\t newline\t\t\t %d\n", '\n');
    fprintf(csis, "'\\n'\t\t\t newline\t\t\t %d\n", '\n');

    // Horizontal tab output
    printf("'\\t'\t\t\t horizontal tab\t\t %d\n", '\t');
    fprintf(csis, "'\\t'\t\t\t horizontal tab\t\t %d\n", '\t');

    // Vertical tab output
    printf("'\\v'\t\t\t vertical tab\t\t %d\n", '\v');
    fprintf(csis, "'\\v'\t\t\t vertical tab\t\t %d\n", '\v');

    // Backspace output
    printf("'\\b'\t\t\t backspace\t\t\t %d\n", '\b');
    fprintf(csis, "'\\b'\t\t\t backspace\t\t\t %d\n", '\b');

    // Carriage return output
    printf("'\\r'\t\t\t carriage return\t %d\n", '\r');
    fprintf(csis, "'\\r'\t\t\t carriage return\t %d\n", '\r');

    // Form feed output
    printf("'\\f'\t\t\t form feed\t\t\t %d\n", '\f');
    fprintf(csis, "'\\f'\t\t\t form feed\t\t\t %d\n", '\f');

    // Backslash output
    printf("'\\""\\'\t\t\t backslash\t\t\t %d\n", '\\');
    fprintf(csis, "'\\""\\'\t\t\t backslash\t\t\t %d\n", '\\');

    // Single quote output
    printf("'\\'""'\t\t\t single quote\t\t %d\n", '\'');
    fprintf(csis, "'\\'""'\t\t\t single quote\t\t %d\n", '\'');

    // Double quote output
    printf("'\\""\"'\t\t\t double quote\t\t %d\n", '\"');
    fprintf(csis, "'\\""\"'\t\t\t double quote\t\t %d\n", '\"');

    // null output
    printf("'\\0'\t\t\t null\t\t\t\t %d\n", '\0');
    fprintf(csis, "'\\0'\t\t\t null\t\t\t\t %d\n", '\0');

    fclose(csis);

    return 0;
}


