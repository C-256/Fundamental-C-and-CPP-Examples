/* bubble_sort-1.c */
/* 冒泡排序（一） */
/* 为了方便起见，本程序略去了输入验证 */

#define LENGTH 6

#include <stdio.h>

int main(void)
{
	int temp, i, j, arr[LENGTH];

	// 以下代码为输入数组中的每一个元素
	printf("Please enter 6 integers: ");
	for (i = 0; i < LENGTH; i++)
	{
		scanf("%d", &arr[i]);
	}

	// 以下为冒泡排序，本程序以升序排列为例
	// 冒泡排序算法的思路是：先从后往前依次遍历相邻元素的组合
	// 若一个组合的大小关系不符合排序要求（前一个元素比后一个元素大），则调换这个组合中的两个元素的位置
	// 这样一来，最小的元素就会一直和前一个元素交换，成为第一个元素
	// 这个过程就像水中的泡泡上浮，所以这种排序方法称为“冒泡排序”
	// 接下来，就是把第二个元素以后的最小元素“冒泡”到第二个元素的位置，以此类推
	for (i = 0; i < LENGTH - 1; i++)
	{
		for (j = LENGTH - 1; j >= i; j--)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	// 输出
	for (i = 0; i < LENGTH; i++)
	{
		printf("%d\t", arr[i]);
	}

	return 0;
}
