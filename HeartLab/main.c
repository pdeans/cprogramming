/************************************************************************************
 Program Name:      heart.c
 Author:            Patrick Stearns
 Compiler:          Xcode 5
 OS:                OS X 10.9.1
 Description:       Calculates how many times an average heart beats in years(50).
 Input Files:       None
 Output Files:      csis.txt
 ************************************************************************************/

#include <stdio.h>

FILE *csis;


int main(void)
{
    int days = 365,             // set number of days in a year
        years = 50,             // set number of years
        beats_per_day = 86400;  // set number the of heartbeats in a day, given in seconds
                                // 24 hours * 60 minutes * 60 seconds = 86,400 seconds

    csis = fopen("csis.txt", "w");

    // calculate number of heart beats for 50 years, output results
    printf("number of heartbeats over 50 year period: %d\n", (days * years)*(beats_per_day));
    fprintf(csis, "Number of heartbeats over 50 years period: %d\n", (days * years)*(beats_per_day));

    fclose(csis);

    return 0;
}


