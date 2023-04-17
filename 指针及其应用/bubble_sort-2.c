/* bubble_sort-2.c */
/* 冒泡排序（二），利用指针进行对不确定长度的“数组”排序 */
/* 为了简单起见，本程序中略去了输入验证 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int length, temp, i, j, *start = NULL;
	// 最好在指针在声明时（或声明后）立即将其定义，避免野指针的产生

	printf("Please enter the length of the array: ");
	scanf("%d", &length);

	start = malloc(length * sizeof(int));
	// 使用malloc()函数分配内存地址（变长“数组”的实现）
	// 对于数组与指针的“等价”性，可参考2_dimensional_array_and_pointer.c

	// 以下代码为输入“数组”中的每一个元素
	printf("Please enter each integer of this array: ");
	for (i = 0; i < length; i++)
	{
		scanf("%d", start + i);
	}

	// 以下为冒泡排序，本程序以升序排列为例
	// 冒泡排序算法的思路是：先从后往前依次遍历相邻元素的组合
	// 若一个组合的大小关系不符合排序要求（前一个元素比后一个元素大），则调换这个组合中的两个元素的位置
	// 这样一来，最小的元素就会一直和前一个元素交换，成为第一个元素
	// 这个过程就像水中的泡泡上浮，所以这种排序方法称为“冒泡排序”
	// 接下来，就是把第二个元素以后的最小元素“冒泡”到第二个元素的位置，以此类推
	for (i = 0; i < length - 1; i++)
	{
		for (j = length - 1; j >= i; j--)
		{
			if (*(start + j) > *(start + j + 1))
			{
				temp = *(start + j);
				*(start + j) = *(start + j + 1);
				*(start + j + 1) = temp;
			}
		}
	}

	// 输出
	for (i = 0; i < length; i++)
	{
		printf("%d\t", *(start + i));
	}

	// malloc()分配的空间需要在使用结束后释放，以免内存被持续占用，导致“内存泄漏”
	free(start);

	// 使用free()函数释放内存时，指针指向的位置已经不再被这个程序使用，再次成为野指针
	// 所以此后需要把start再次设置为NULL，防止出现意外
	start = NULL;

	return 0;
}
