/***********************************************************************
 Program Name:      weight.c
 Author:            Patrick Stearns
 Compiler:          Xcode 5
 OS:                OS X 10.9.1
 Description:       Computes the weight of a person on the following
                    planets: Mercury, Jupiter, Venus, Mars
 Input Files:       None
 Output Files:      csis.txt
 ***********************************************************************/

#include <stdio.h>

FILE *csis;

int main(void)
{
    // Set weight ratios
    double mercury = 0.27,
           jupiter = 2.64,
           venus = 0.85,
           mars = 0.38;

    csis = fopen("csis.txt", "w");

    // Start program output
    printf("Earth\t Mercury\t Jupiter\t Venus\t Mars\n");
    printf("-----\t -------\t -------\t -----\t ----\n");

    // Output to file
    fprintf(csis, "Earth\t Mercury\t Jupiter\t Venus\t Mars\n");
    fprintf(csis, "-----\t -------\t -------\t -----\t ----\n");

    // Calculate weights and output to terminal and file
    for(int i = 50; i <= 250; i += 50) {
        printf("%d\t\t %.1f\t\t %.1f\t\t %.1f\t %.1f\n", i, i*mercury, i*jupiter, i*venus, i*mars);
        fprintf(csis, "%d\t\t %.1f\t\t %.1f\t\t %.1f\t %.1f\n", i, i*mercury, i*jupiter, i*venus, i*mars);
    }

    fclose(csis);

    return 0;
}
