/*
Q2. Create an employee structure with the following members empid, employee name, salary, year of joining etc.
    Accept the data for certain no. o of employees and find their total, average, max, min salary.
    Also find out the employees with maximum, minimum service,use a function to find service for each employee element in the array.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee
{
    int empid;
    char *name;
    float salary;
    int joining_year;
};

struct employee *emp;
int num, count = 0;
void insert();
int calculateService(int);
void findServiceInfo();

int main()
{
    float total = 0.0, min, max;

    printf("Define number of employees -> ");
    scanf("%d", &num);

    emp = (struct employee *)malloc(num * sizeof(struct employee));

    insert();

    for (int i = 0; i < num; i++)
    {
        total += emp[i].salary;
    }

    printf("\n\nTotal salary -> %.2f\n", total);

    printf("Average salary -> %.2f\n", total / num);

    min = emp[0].salary;
    for (int i = 1; i < num; i++)
    {
        if (emp[i].salary < min)
        {
            min = emp[i].salary;
        }
    }
    printf("Minimum salary -> %.2f\n", min);

    max = emp[0].salary;
    for (int i = 1; i < num; i++)
    {
        if (emp[i].salary > max)
        {
            max = emp[i].salary;
        }
    }
    printf("Maximum salary -> %.2f\n", max);

    findServiceInfo();

    for (int i = 0; i < num; i++)
    {
        free(emp[i].name);
    }
    free(emp);
    return 0;
}

void insert()
{
    for (int i = 0; i < num; i++)
    {
        char temp[100];
        printf("*** Employee-%d ***\n", count + 1);
        printf("EMPID -> ");
        scanf("%d", &emp[count].empid);

        printf("Employee Name -> ");
        getchar();
        fgets(temp, sizeof(temp), stdin);
        emp[count].name = (char *)malloc(strlen(temp) + 1);
        strcpy(emp[count].name, temp);

        printf("Employee salary -> ");
        scanf("%f", &emp[count].salary);

        printf("Employee year of joining -> ");
        scanf("%d", &emp[count].joining_year);

        count++;
    }
}

int calculateService(int joining_year)
{
    int current_year = 2024;
    return current_year - joining_year;
}

void findServiceInfo()
{
    int min_service = calculateService(emp[0].joining_year);
    int max_service = calculateService(emp[0].joining_year);
    struct employee *min_service_emp = &emp[0];
    struct employee *max_service_emp = &emp[0];

    for (int i = 1; i < count; i++)
    {
        int service = calculateService(emp[i].joining_year);

        if (service < min_service)
        {
            min_service = service;
            min_service_emp = &emp[i];
        }

        if (service > max_service)
        {
            max_service = service;
            max_service_emp = &emp[i];
        }
    }

    printf("\nEmployee with Maximum Service: %s (EMPID: %d, Service: %d years)\n",
           max_service_emp->name, max_service_emp->empid, max_service);

    printf("Employee with Minimum Service: %s (EMPID: %d, Service: %d years)\n",
           min_service_emp->name, min_service_emp->empid, min_service);
}
