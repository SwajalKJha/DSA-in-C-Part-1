/*
Q3. Write C/C++ prgram which allocate and deallocate memory dynamically.
(c) Allocate memory for array of structure variables dynamically and access members of each element
*/
#include <stdio.h>
#include <stdlib.h>

struct patient
{
    char name[20];
    int age;
    int ward_num;
};

int main()
{
    int n;
    struct patient *patients;

    printf("Enter the number of patients: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Number of patients must be positive!\n");
        return 1;
    }

    patients = (struct patient *)malloc(n * sizeof(struct patient));
    if (patients == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter details for patient %d:\n", i + 1);
        printf("Name: ");
        scanf("%19s", patients[i].name);
        printf("Age: ");
        scanf("%d", &patients[i].age);
        printf("Ward Number: ");
        scanf("%d", &patients[i].ward_num);
    }
    printf("\nPatient Details:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Patient %d:\n", i + 1);
        printf("Name: %s\n", patients[i].name);
        printf("Age: %d\n", patients[i].age);
        printf("Ward Number: %d\n", patients[i].ward_num);
    }

    free(patients);

    return 0;
}
