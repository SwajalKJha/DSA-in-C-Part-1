/*
Q3. Write C/C++ prgram which allocate and deallocate memory dynamically.
(a) Allocating 1D array dynamically and access the elements
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	printf("Enter Size of Array: ");
	scanf("%d", &n);
	int *arr = (int *)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
	{
		printf("Enter Value for Array location %d: ", i + 1);
		scanf("%d", &arr[i]);
	}
	printf("*************************\n");
	printf("Array is: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", *(arr + i));
	}
	printf("\n");
	return 0;
}
