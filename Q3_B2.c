/*
Q3. Write C/C++ prgram which allocate and deallocate memory dynamically.
(b) Allocating 2D array dynamically
    (2) Non contiguous rows with variable no.of columns
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of cols: ");
    scanf("%d", &cols);

    int **arr = (int **)malloc(rows * sizeof(int *));
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < rows; i++)
    {
        arr[i] = (int *)malloc(cols * sizeof(int));
        if (arr[i] == NULL)
        {
            printf("Memory allocation for row %d failed\n", i);
            for (int k = 0; k < i; k++)
            {
                free(arr[k]);
            }
            free(arr);
            return 1;
        }

        for (int j = 0; j < cols; j++)
        {
            printf("Enter Value for (%d,%d): ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
        printf("\n");
    }

    printf("*************************\n");
    for (int i = 0; i < rows; i++)
    {
        printf("Row: %d\n", i + 1);
        for (int j = 0; j < cols; j++)
        {
            printf("Column: %d\n", j + 1);
            printf("--> %d\n", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
