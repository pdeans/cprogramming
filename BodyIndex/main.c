/****************************************************************************
 Program Name:      bmi.c
 Author:            Patrick Stearns
 Compiler:          Xcode 5
 OS:                OS X 10.9.1
 Description:       Measure the BMI (Body Mass Index) of an in individual
                    based upon their height and weight.
 Input Files:       None
 Output Files:      csis.txt
 ****************************************************************************/

#include <stdio.h>

FILE *csis;

void calculateBMI();

int main(void)
{
    int i;

    csis = fopen("csis.txt", "w");

    for (i = 1; i <= 4; ++i) {
        calculateBMI();
    }

    fclose(csis);

    return 0;
}

/**
 *  Calculates the BMI
 *  Prompts user for values and outputs to terminal
 **/
void calculateBMI()
{
    int height = 0,
        weight = 0;
    double bmi = 0;

    // Set weight and height
    printf("Enter weight (lbs) and height (in): ");
    scanf("%d %d", &weight, &height);

    // Output to file
    fprintf(csis, "Enter weight (lbs) and height (in): %d %d\n", weight, height);

    // Calculate BMI
    bmi = (weight * 703) / (height * height);

    // Output BMI values
    if (bmi < 18.5){
        printf("BMI: %.1f Underweight\n", bmi);
        fprintf(csis, "BMI: %.1f Underweight\n", bmi);
    }
    else if (bmi >= 18.5 && bmi < 25.0){
        printf("BMI: %.1f Normal\n", bmi);
        fprintf(csis, "BMI: %.1f Normal\n", bmi);
    }
    else if (bmi >= 25.0 && bmi < 30.0){
        printf("BMI: %.1f Overweight\n", bmi);
        fprintf(csis, "BMI: %.1f Overweight\n", bmi);
    }
    else if (bmi >= 30.0){
        printf("BMI: %.1f Obese\n", bmi);
        fprintf(csis, "BMI: %.1f Obese\n", bmi);
    }

}


