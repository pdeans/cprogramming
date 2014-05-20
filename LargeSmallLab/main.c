/****************************************************************************
 Program Name:      large-small.c
 Author:            Patrick Stearns
 Compiler:          Xcode 5
 OS:                OS X 10.9.1
 Description:       Compares 4 integers, returns largest and smallest integer
 Input Files:       None
 Output Files:      csis.txt
 ****************************************************************************/

#include <stdio.h>

FILE *csis;

void compare();

int main(void)
{
    int i;

    csis = fopen("csis.txt", "w");

    for (i = 1; i <= 4; ++i){
        compare();
    }

    fclose(csis);

    return 0;
}

/**
*  Prompts user for four int values and outputs largest and smallest int value
**/
void compare()
{
    int largest,
        smallest,
        lrg1,
        sml1,
        lrg2,
        sml2,
        val1,
        val2,
        val3,
        val4;

    // Prompt user for int values
    printf("Enter four integers to compare: ");
    scanf("%d %d %d %d", &val1, &val2, &val3, &val4);

    // Write results to file
    fprintf(csis, "Enter four integers to compare: %d %d %d %d\n", val1, val2, val3, val4);

    // Set value for small and large
    if (val1 < val2) {
        sml1 = val1;
        lrg1 = val2;
    }
    else {
        sml1 = val2;
        lrg1 = val1;
    }
    if (val3 < val4) {
        sml2 = val3;
        lrg2 = val4;
    }
    else {
        sml2 = val4;
        lrg2 = val3;
     }
    if (lrg1 < lrg2)
        largest = lrg2;
    else
        largest = lrg1;
    if (sml1 < sml2)
        smallest = sml1;
    else
        smallest = sml2;

    // Output smallest and largest values to terminal and output file
    printf("Smallest: %d\t Largest: %d\n", smallest, largest);
    fprintf(csis, "Smallest: %d\t Largest: %d\n", smallest, largest);
}

