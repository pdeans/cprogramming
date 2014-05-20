/***********************************************************************
 Program Name:      speed.c
 Author:            Patrick Stearns
 Compiler:          Xcode 5
 OS:                OS X 10.9.1
 Description:       Calculates the given speed of a car in miles/hour
                    and meters/second.
 Input Files:       None
 Output Files:      csis.txt
 ***********************************************************************/

#include <stdio.h>

FILE *csis;


int main(void)
{
    float distance = 425.5,
          time = 7.5,
          meters = 0,
          seconds = 0;

    csis = fopen("csis.txt", "w");

    // compute and print speed of car in miles/hour
    printf("Speed (mph): %.2f\n", distance/time);
    fprintf(csis, "Speed (mph): %.2f\n", distance/time);

    // convert miles to meters and hours to seconds for meters/second calculation
    meters = distance * 1600;
    seconds = time * 3600;

    // compute and print speed of car in meters/second
    printf("Speed (meters/second): %.2f\n", meters/seconds);
    fprintf(csis, "Speed (meters/second): %.2f\n", meters/seconds);

    fclose(csis);

    return 0;
}
