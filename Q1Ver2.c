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
// dynamic array
#include <stdio.h>
#include <stdlib.h>

void insertElement(int *arr, int *size);
void deleteElement(int *arr, int *size);
void minVal(int *arr, int size);
void maxVal(int *arr, int size);
void display(int *arr, int size);
void reverseDisplay(int *arr, int size);
void searchInArray(int *arr, int size);
void countElement(int *arr, int size);
void avgElement(int *arr, int size);
int duplicate(int *arr, int size);
void reverseElement(int *arr, int size);

int main()
{
    char choice;
    int size;

    printf("\nEnter size: ");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Invalid array size.\n");
        return 1;
    }

    int *arr = malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    while (1)
    {
        printf("\nPick one choice:\n (a) Insert Element at Index\n (b) Delete Element at Index\n (c) Find Min Val\n (d) Find Max Val\n (e) Display Array Element\n (f) Reverse Display Array Element\n (g) Search Element in Array\n (h) Array Element Count\n (i) Avg of all Array Element\n (j) Determine if Array contains any Duplicates \n (k) Reverse Array Element\n (q) Quit\n");
        printf("Enter Choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case 'a':
            insertElement(arr, &size);
            break;
        case 'b':
            deleteElement(arr, &size);
            break;
        case 'c':
            minVal(arr, size);
            break;
        case 'd':
            maxVal(arr, size);
            break;
        case 'e':
            display(arr, size);
            break;
        case 'f':
            reverseDisplay(arr, size);
            break;
        case 'g':
            searchInArray(arr, size);
            break;
        case 'h':
            countElement(arr, size);
            break;
        case 'i':
            avgElement(arr, size);
            break;
        case 'j':
            printf("Contains duplicates: %s\n", duplicate(arr, size) ? "Yes" : "No");
            break;
        case 'k':
            reverseElement(arr, size);
            break;
        case 'q':
            free(arr);
            return 0;
        default:
            printf("Wrong Input\n");
        }
    }
    free(arr);
    return 0;
}

void insertElement(int *arr, int *size)
{
    int index, value;
    printf("Enter index to insert: ");
    scanf("%d", &index);
    if (index < 0 || index >= *size)
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

void deleteElement(int *arr, int *size)
{
    int index;
    printf("Enter index to delete: ");
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

void minVal(int *arr, int size)
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

void maxVal(int *arr, int size)
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

void display(int *arr, int size)
{
    if (size == 0)
    {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void reverseDisplay(int *arr, int size)
{
    if (size == 0)
    {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements in reverse: ");
    for (int i = size - 1; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void searchInArray(int *arr, int size)
{
    int value;
    printf("Enter value to search: ");
    scanf("%d", &value);
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
        {
            printf("Value found at index: %d\n", i);
            return;
        }
    }
    printf("Value not found in the array.\n");
}

void countElement(int *arr, int size)
{
    printf("Total elements in array: %d\n", size);
}

void avgElement(int *arr, int size)
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
    printf("Average of array elements: %.2f\n", (double)sum / size);
}

int duplicate(int *arr, int size)
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

void reverseElement(int *arr, int size)
{
    if (size == 0)
    {
        printf("Array is empty.\n");
        return;
    }
    for (int i = 0; i < size / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
    printf("Array has been reversed.\n");
}
