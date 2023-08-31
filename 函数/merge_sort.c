#include <stdio.h>
#include <stdlib.h>

#define N 35

void MergeSort(int *arr, int n, int depth);

int main(void)
{
	int arr[N] = {215, 65, 984, 651, 165, 93, 155, 486,
				  481, 756, 998, 153, 710, 447, 462, 815,
				  985, 711, 812, 986, 813, 927, 928, 733,
				  929, 1051, 73, 444, 184, 563, 470, 85,
				  939, 811, 701};
	MergeSort(arr, N, 1);

	for (int i = 0; i < N; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}

void MergeSort(int *arr, int n, int unit)
{
	if (unit >= n)
	{
		unit *= 2;
		return;
	}

	int *newArr = (int *)malloc(sizeof(int) * n);

	int index = 0;

	for (int i = 0; i < n; i += 2 * unit)
	{
		if (i + unit >= n)
		{
			break;
		}

		int c1 = 0, c2 = 0;
		while (c1 < unit || (c2 < unit && i + unit + c2 < n))
		{
			if (c1 == unit)
			{
				newArr[index] = arr[i + unit + c2];
				c2++;
			}

			else if (c2 == unit || i + unit + c2 >= n)
			{
				newArr[index] = arr[i + c1];
				c1++;
			}

			else if (arr[i + c1] < arr[i + unit + c2])
			{
				newArr[index] = arr[i + c1];
				c1++;
			}

			else
			{
				newArr[index] = arr[i + unit + c2];
				c2++;
			}

			index++;
		}
	}

	for (int i = 0; i < index; i++)
	{
		arr[i] = newArr[i];
	}

	free(newArr);
	newArr = NULL;

	printf("unit = %d\n", unit);

	for (int i = 0; i < N; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");

	unit *= 2;
	MergeSort(arr, n, unit);
}
