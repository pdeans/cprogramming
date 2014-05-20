/****************************************************************************
 Program Name:      database.c
 Author:            Patrick Stearns
 Compiler:          Xcode 5
 OS:                OS X 10.9.1
 Description:       Retrieves and manipulates a company's payroll database.
 Input Files:       payfile.txt
 Output Files:      csis.txt
 ****************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *csis, *fp;
#define SIZE 14

typedef struct {
    char first[7];
    char initial[1];
    char last[9];
    char street[16];
    char city[11];
    char state[2];
    char zip[5];
    int age;
    char sex[1];
    int tenure;
    double salary;
} Employee;

void strsub(char buf[], char sub[], int start, int end);
void getEmployees(Employee workers[]);
void showEmployees(Employee workers[]);
void males(Employee workers[]);
void highestFemale(Employee workers[]);
void lowestMale(Employee workers[]);
double averageSalary(Employee workers[]);
void femalesUnderAverage(Employee workers[], double avg);
void maleRatio(Employee workers[], double avg);
void superEmployee(Employee workers[]);
void setRaise(Employee workers[]);

int main(void)
{
    double average;
    Employee workers[SIZE];

    if (!(fp = fopen("payfile.txt", "r"))) {
        printf("payfile.txt could not be opened for input.");
        exit(1);
    }
    if (!(csis = fopen("csis.txt", "w"))) {
        printf("csis.txt could not be opened for output.");
        exit(1);
    }

    getEmployees(workers);
    showEmployees(workers);
    males(workers);
    highestFemale(workers);
    lowestMale(workers);
    average = averageSalary(workers);
    femalesUnderAverage(workers, average);
    maleRatio(workers, average);
    superEmployee(workers);
    setRaise(workers);

    fclose(fp);
    fclose(csis);

    return 0;
}

void strsub(char buf[], char sub[], int start, int end)
{
    int i, j;

    for (j = 0, i = start; i <= end; i++, j++) {
        sub[j] = buf[i];
    }
    sub[j] = '\0';
}

void getEmployees(Employee workers[])
{
    char buffer[100];
    int i = 0;
    char ageTemp[3];
    char tenureTemp[2];
    char salaryTemp[7];

    while (!feof(fp)) {
        fgets(buffer, 100, fp);
        strsub(buffer, workers[i].first, 0, 6);
        strsub(buffer, workers[i].initial, 8, 8);
        strsub(buffer, workers[i].last, 10, 18);
        strsub(buffer, workers[i].street, 20, 35);
        strsub(buffer, workers[i].city, 37, 47);
        strsub(buffer, workers[i].state, 49, 50);
        strsub(buffer, workers[i].zip, 52, 56);
        strsub(buffer, ageTemp, 58, 59);
        strsub(buffer, workers[i].sex, 61, 61);
        strsub(buffer, tenureTemp, 63, 63);
        strsub(buffer, salaryTemp, 65, 70);
        workers[i].age = atoi(ageTemp);
        workers[i].tenure = atoi(tenureTemp);
        workers[i].salary = atof(salaryTemp);
        i++;
    }
}

void showEmployees(Employee workers[])
{
    printf("%7s %7s %9s %16s %11s %5s %5s %3s %3s %6s %6s\n",
               "First","Initial","Last","Street","City","State","Zip","Age","Sex","Tenure","Salary");
    printf("%7s %7s %9s %16s %11s %5s %5s %3s %3s %6s %6s\n",
               "-----","-------","----","------","----","-----","---","---","---","------","------");
    fprintf(csis, "%7s %7s %9s %16s %11s %5s %5s %3s %3s %6s %6s\n",
               "First","Initial","Last","Street","City","State","Zip","Age","Sex","Tenure","Salary");
    fprintf(csis, "%7s %7s %9s %16s %11s %5s %5s %3s %3s %6s %6s\n",
               "-----","-------","----","------","----","-----","---","---","---","------","------");
    for (int i = 0; i < SIZE; i++) {
        printf("%s %s %s %s %s %s %s %d %s %d %6.2lf\n",
               workers[i].first, workers[i].initial, workers[i].last, workers[i].street, workers[i].city,
               workers[i].state, workers[i].zip, workers[i].age, workers[i].sex, workers[i].tenure,
               workers[i].salary);
        fprintf(csis, "%s %s %s %s %s %s %s %d %s %d %6.2lf\n",
               workers[i].first, workers[i].initial, workers[i].last, workers[i].street, workers[i].city,
               workers[i].state, workers[i].zip, workers[i].age, workers[i].sex, workers[i].tenure,
               workers[i].salary);
    }
}

void males(Employee workers[])
{
    printf("\nMales on payroll: \n");
    fprintf(csis, "\nMales on payroll: \n");
    for (int i = 0; i < SIZE; i++) {
        if (strcmp(workers[i].sex, "M") == 0) {
            printf("%s %s\n", workers[i].first, workers[i].last);
            fprintf(csis, "%s %s\n", workers[i].first, workers[i].last);
        }
    }
}

void highestFemale(Employee workers[])
{
    Employee highest;
    Employee females[SIZE];
    int j = 0;

    for (int i = 0; i < SIZE; i++) {
        if (strcmp(workers[i].sex, "F") == 0) {
            females[j] = workers[i];
            j++;
        }
    }
    females[0] = highest;
    for (int i = 1; i < j; i++) {
        if (females[i].salary > highest.salary) {
            highest = females[i];
        }
    }
    printf("\nHighest paid female: \n");
    fprintf(csis, "\nHighest paid female: \n");
    printf("%s %s\n", highest.first, highest.last);
    fprintf(csis, "%s %s\n", highest.first, highest.last);
}

void lowestMale(Employee workers[])
{
    Employee lowest;
    Employee males[SIZE];
    int j = 0;

    for (int i = 0; i < SIZE; i++) {
        if (strcmp(workers[i].sex, "M") == 0) {
            males[j] = workers[i];
            j++;
        }
    }
    males[0] = lowest;
    for (int i = 1; i < j; i++) {
        if (males[i].salary < lowest.salary) {
            lowest = males[i];
        }
    }
    printf("\nLowest paid male: \n");
    fprintf(csis, "\nLowest paid male: \n");
    printf("%s %s\n", lowest.first, lowest.last);
    fprintf(csis, "%s %s\n", lowest.first, lowest.last);
}

double averageSalary(Employee workers[])
{
    double sum = 0.0;

    for (int i = 0; i < SIZE; i++) {
        sum += workers[i].salary;
    }
    printf("\nAverage salary: \n");
    fprintf(csis, "\nAverage salary: \n");
    printf("$%6.2lf\n", sum / SIZE);
    fprintf(csis, "$%6.2lf\n", sum / SIZE);

    return (sum / SIZE);
}

void femalesUnderAverage(Employee workers[], double avg)
{
    Employee females[SIZE];
    int j = 0;

    for (int i = 0; i < SIZE; i++) {
        if (strcmp(workers[i].sex, "F") == 0) {
            females[j] = workers[i];
            j++;
        }
    }
    printf("\nFemales earning less than average: \n");
    fprintf(csis, "\nFemales earning less than average: \n");
    for (int i = 0; i < j; i++) {
        if (females[i].salary < avg) {
            printf("%s %s\n", females[i].first, females[i].last);
            fprintf(csis, "%s %s\n", females[i].first, females[i].last);
        }
    }
}

void maleRatio(Employee workers[], double avg)
{
    Employee males[SIZE];
    int j = 0;
    int high = 0;
    int low = 0;

    for (int i = 0; i < SIZE; i++) {
        if (strcmp(workers[i].sex, "M") == 0) {
            males[j] = workers[i];
            j++;
        }
    }
    for (int i = 0; i < j; i++) {
        if (males[i].salary > avg) {
            high++;
        }
    }
    for (int i = 0; i < j; i++) {
        if (males[i].salary < avg) {
            low++;
        }
    }
    printf("\nRatio of males earning more than average: %.2lf\n", (double)high / j);
    printf("\nRatio of males earning less than average: %.2lf\n", (double)low / j);
    fprintf(csis, "\nRatio of males earning more than average: %.2lf\n", (double)high / j);
    fprintf(csis, "\nRatio of males earning less than average: %.2lf\n", (double)low / j);
}

void superEmployee(Employee workers[])
{
    printf("\nSuper employees: \n");
    fprintf(csis, "\nSuper employees: \n");
    for (int i = 0; i < SIZE; i++) {
        if (((workers[i].salary * 52) > 35000) && (workers[i].tenure >= 5) && (workers[i].age > 30)) {
            printf("%s %s\n", workers[i].first, workers[i].last);
            fprintf(csis, "%s %s\n", workers[i].first, workers[i].last);
        }
    }
}

void setRaise(Employee workers[])
{
    printf("\nEmployee raises: \n");
    fprintf(csis, "\nEmployee Raises: \n");
    for (int i = 0; i < SIZE; i++) {
        if (workers[i].salary < 350.00) {
            workers[i].salary *= 0.10;
            printf("%s %s $%.2lf\n", workers[i].first, workers[i].last, workers[i].salary);
            fprintf(csis, "%s %s $%.2lf\n", workers[i].first, workers[i].last, workers[i].salary);
        }
    }
}
