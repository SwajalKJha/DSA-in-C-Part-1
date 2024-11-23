/*
Q3. Write C/C++ prgram which allocate and deallocate memory dynamically.
(b) Allocating 2D array dynamically
    (1) contiguous rows with fixed no.of cols,
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, cols = 5;
    printf("Column = 5\n");
    printf("Enter number of rows: ");
    scanf("%d", &rows);

    int(*arr)[5] = malloc(rows * sizeof(int[5]));
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < rows; i++)
    {
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
        printf("Row : %d\n", i + 1);
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);
    return 0;
}
