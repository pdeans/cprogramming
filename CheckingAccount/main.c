/****************************************************************************
 Program Name:      check.c
 Author:            Patrick Stearns
 Compiler:          Xcode 5
 OS:                OS X 10.9.1
 Description:       Outputs a bank statement summarizing monthly transactions
 Input Files:       None
 Output Files:      csis.txt
 ****************************************************************************/

#include <stdio.h>

FILE *fp, *csis;

void outputHeaders();
void initialBalance(double amount, double *balance, double *service, double *openBalance);
void deposit(double amount, double *balance, double *service, int *numDeposit, double *amtDeposit);
void check(double amount, double *balance, double *service, int *numCheck, double *amtCheck);
void outputSummary(int numDeposit, double amtDeposit, int numCheck, double amtCheck, double openBalance, double service, double closeBalance);


int main(void)
{
    char code;
    double amount, service, balance;
    double amtCheck, amtDeposit, openBalance, closeBalance;
    int numCheck, numDeposit;

    if (!(fp = fopen("account.txt", "r"))) {
        printf("account.txt could not be opened for input.");
        exit(1);
    }
    if (!(csis = fopen("csis.txt", "w"))) {
        printf("csis.txt could not be opened for output.");
        exit(1);
    }

    amount       = 0;
    service      = 0;
    balance      = 0;
    amtCheck     = 0;
    amtDeposit   = 0;
    openBalance  = 0;
    closeBalance = 0;
    numCheck     = 0;
    numDeposit   = 0;

    outputHeaders();

    while (!feof(fp)) {
        fscanf(fp, "%c %lf\n", &code, &amount);
        if (code == 'I') {
            initialBalance(amount, &balance, &service, &openBalance);
        }
        else if (code == 'D') {
            deposit(amount, &balance, &service, &numDeposit, &amtDeposit);
        }
        else {
            check(amount, &balance, &service, &numCheck, &amtCheck);
        }
    }

    closeBalance = balance - service;
    outputSummary(numDeposit, amtDeposit, numCheck, amtCheck, openBalance, service, closeBalance);

    fclose(csis);
    fclose(fp);

    return 0;
}

void outputHeaders()
{
    printf("Transaction\t\t   Deposit\t\t Check\t\t Balance\n");
    printf("-----------\t\t   -------\t\t -----\t\t -------\n");
    fprintf(csis, "Transaction\t\t   Deposit\t\t Check\t\t Balance\n");
    fprintf(csis, "-----------\t\t   -------\t\t -----\t\t -------\n");
}

void initialBalance(double amount, double *balance, double *service, double *openBalance)
{
    *openBalance = amount;
    *balance = *openBalance;
    *service = 3.00;

    printf("Initial Balance\t \t \t \t \t\t\t\t%8.2lf\n", *openBalance);
    fprintf(csis, "Initial Balance\t \t \t \t \t\t\t\t%8.2lf\n", *openBalance);
}

void deposit(double amount, double *balance, double *service, int *numDeposit, double *amtDeposit)
{
    *balance += amount;
    *amtDeposit += amount;
    *numDeposit += 1;
    *service += 0.03;

    printf("Deposit\t\t\t %8.2lf\t \t\t\t\t%8.2lf\n", *amtDeposit, *balance);
    fprintf(csis, "Deposit\t\t\t %8.2lf\t \t\t\t\t%8.2lf\n", *amtDeposit, *balance);
}

void check(double amount, double *balance, double *service, int *numCheck, double *amtCheck)
{
    *balance -= amount;
    *amtCheck += amount;
    *numCheck += 1;

    if (*balance < 0.00) {
        *service += 5.00;
    }
    else {
        *service += 0.06;
    }

    printf("Check\t\t\t\t\t\t %9.2lf\t\t%8.2lf\n", *amtCheck, *balance);
    fprintf(csis, "Check\t\t\t\t\t\t %9.2lf\t\t%8.2lf\n", *amtCheck, *balance);
}

void outputSummary(int numDeposit, double amtDeposit, int numCheck, double amtCheck, double openBalance, double service, double closeBalance)
{
    printf("\nTotal number deposits: %d\n", numDeposit);
    printf("Total amount deposits: $%.2lf\n", amtDeposit);
    printf("\tTotal number checks: %d\n", numCheck);
    printf("\tTotal amount checks: $%.2lf\n", amtCheck);
    printf("Total service charge: $%.2lf\n", service);
    printf("\tOpening balance: $%.2lf\n", openBalance);
    printf("\tClosing balance: $%.2lf\n", closeBalance);

    fprintf(csis, "\nTotal number deposits: %d\n", numDeposit);
    fprintf(csis, "Total amount deposits: $%.2lf\n", amtDeposit);
    fprintf(csis, "\tTotal number checks: %d\n", numCheck);
    fprintf(csis, "\tTotal amount checks: $%.2lf\n", amtCheck);
    fprintf(csis, "Total service charge: $%.2lf\n", service);
    fprintf(csis, "\tOpening balance: $%.2lf\n", openBalance);
    fprintf(csis, "\tClosing balance: $%.2lf\n", closeBalance);
}


