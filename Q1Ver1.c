/*
Q1. Write a C/C++ program that declares an array of length N containing integers between 1 and N. Implement menu driven
    program using switch case for below mentioned functionalities.
(a) insert element at index
(b) delete element at index
(c) find min val
(d) find max val
(e) display array element
(f) reverse display array element
(g) search element in array
(h) array element count
(i) avg of all array element
(j) determine if array contains any duplicates.
(k) reverse array element
*/

// static array
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void insertElement(int arr[], int *size);
void deleteElement(int arr[], int *size);
void minVal(int arr[], int size);
void maxVal(int arr[], int size);
void display(int arr[], int size);
void reverseDisplay(int arr[], int size);
void searchInArray(int arr[], int size);
void countElement(int arr[], int size);
void avgElement(int arr[], int size);
int duplicate(int arr[], int size);
void reverseElement(int arr[], int size);

int main()
{
    char choice;
    int arr[MAX_SIZE];
    int n;

    printf("Enter the size of the array (n): ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE)
    {
        printf("Invalid array size.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d (between 1 and %d): ", i + 1, n);
        scanf("%d", &arr[i]);
        if (arr[i] < 1 || arr[i] > n)
        {
            printf("Element must be between 1 and %d.\n", n);
            return 1;
        }
    }

    while (1)
    {
        printf("\nPick one choice:\n (a) Insert Element at Index\n (b) Delete Element at Index\n (c) Find Min Val\n (d) Find Max Val\n (e) Display Array Element\n (f) Reverse Display Array Element\n (g) Search Element in Array\n (h) Array Element Count\n (i) Avg of all Array Element\n (j) Determine if Array contains any Duplicates \n (k) Reverse Array Element\n (q) Quit\n");
        printf("Enter Choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case 'a':
            insertElement(arr, &n);
            break;
        case 'b':
            deleteElement(arr, &n);
            break;
        case 'c':
            minVal(arr, n);
            break;
        case 'd':
            maxVal(arr, n);
            break;
        case 'e':
            display(arr, n);
            break;
        case 'f':
            reverseDisplay(arr, n);
            break;
        case 'g':
            searchInArray(arr, n);
            break;
        case 'h':
            countElement(arr, n);
            break;
        case 'i':
            avgElement(arr, n);
            break;
        case 'j':
            printf("Contains duplicates: %s\n", duplicate(arr, n) ? "Yes" : "No");
            break;
        case 'k':
            reverseElement(arr, n);
            break;
        case 'q':
            return 0;
        default:
            printf("Wrong Input\n");
        }
    }
    return 0;
}

void insertElement(int arr[], int *size)
{
    if (*size >= MAX_SIZE)
    {
        printf("Cannot insert, array is full.\n");
        return;
    }
    int index, value;
    printf("Enter index to insert at (0 to %d): ", *size);
    scanf("%d", &index);
    if (index < 0 || index > *size)
    {
        printf("Invalid index.\n");
        return;
    }
    printf("Enter value to insert: ");
    scanf("%d", &value);

    for (int i = *size; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    (*size)++;
}

void deleteElement(int arr[], int *size)
{
    if (*size == 0)
    {
        printf("Cannot delete, array is empty.\n");
        return;
    }
    int index;
    printf("Enter index to delete from (0 to %d): ", *size - 1);
    scanf("%d", &index);
    if (index < 0 || index >= *size)
    {
        printf("Invalid index.\n");
        return;
    }

    for (int i = index; i < *size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void minVal(int arr[], int size)
{
    if (size == 0)
    {
        printf("Array is empty.\n");
        return;
    }
    int min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    printf("Minimum value: %d\n", min);
}

void maxVal(int arr[], int size)
{
    if (size == 0)
    {
        printf("Array is empty.\n");
        return;
    }
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("Maximum value: %d\n", max);
}

void display(int arr[], int size)
{
    if (size == 0)
    {
        printf("Array is empty.\n");
        return;
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void reverseDisplay(int arr[], int size)
{
    if (size == 0)
    {
        printf("Array is empty.\n");
        return;
    }
    for (int i = size - 1; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void searchInArray(int arr[], int size)
{
    if (size == 0)
    {
        printf("Array is empty.\n");
        return;
    }
    int value;
    printf("Enter value to search for: ");
    scanf("%d", &value);
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            printf("Value %d found at index %d.\n", value, i);
            return;
        }
    }
    printf("Value not found in the array.\n");
}

void countElement(int arr[], int size)
{
    printf("Number of elements in the array: %d\n", size);
}

void avgElement(int arr[], int size)
{
    if (size == 0)
    {
        printf("Array is empty.\n");
        return;
    }
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    printf("Average of elements: %.2f\n", (float)sum / size);
}

int duplicate(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                return 1;
            }
        }
    }
    return 0;
}

void reverseElement(int arr[], int size)
{
    if (size == 0)
    {
        printf("Array is empty.\n");
        return;
    }
    for (int i = 0; i < size / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
    printf("Array reversed.\n");
}
