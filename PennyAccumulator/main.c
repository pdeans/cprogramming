/*************************************************************************************
 Program Name:      penny.c
 Author:            Patrick Stearns
 Compiler:          Xcode 5
 OS:                OS X 10.9.1
 Description:       Determines how many days it will take to reach a chosen amount
                    of money, starting with 1 penny and doubling the balance each day.
 Input Files:       None
 Output Files:      csis.txt
 *************************************************************************************/

#include <stdio.h>

FILE *csis;

void tableHeader();
int determineDays(double amount);

int main(void)
{
    int numDays;
    double accumulate;
    csis = fopen("csis.txt", "w");

    printf("Enter amount to accumulate: $ ");
    scanf("%lf", &accumulate);
    fprintf(csis, "Enter amount to accumulate: $%.2lf\n", accumulate);

    tableHeader();
    numDays = determineDays(accumulate);

    printf("\nIt took %d days to accumulate at least $%.2lf\n", numDays, accumulate);
    fprintf(csis, "\nIt took %d days to accumulate at least $%.2lf\n", numDays, accumulate);

    fclose(csis);

    return 0;
}

void tableHeader()
{
    printf("\nDAY\t\t DEPOST\t\t\t BALANCE\n");
    printf("---\t\t ------\t\t\t -------\n");
    fprintf(csis, "\nDAY\t\t DEPOST\t\t\t BALANCE\n");
    fprintf(csis, "---\t\t ------\t\t\t -------\n");
}

int determineDays(double amount)
{
    int     day = 1;
    double  initialAmt = 0.01,
            balance,
            deposit;

    deposit = initialAmt;
    for (balance = initialAmt; balance <= amount; balance += deposit) {
        printf("%d\t\t $%.2lf\t\t\t $%.2lf\n", day, deposit, balance);
        fprintf(csis, "%d\t\t $%.2lf\t\t\t $%.2lf\n", day, deposit, balance);

        deposit *= 2;
        day++;
    }
    printf("%d\t\t $%.2lf\t\t\t $%.2lf\n", day, deposit, balance);
    fprintf(csis, "%d\t\t $%.2lf\t\t\t $%.2lf\n", day, deposit, balance);

    return day;
}
