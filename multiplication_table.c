/* multiplucation_table.c */
/* 该程序可以输出九九乘法表，循环嵌套的典型案例 */

#include <stdio.h>

int main(void)
{
	int i, j;
	for (i = 1; i <= 9; i++) // 外层循环：用于输出九九乘法表的行，i表示乘法表的第二个数
	{
		for (j = 1; j <= i; j++) // 内层循环：用于输出九九乘法表每一行的各个等式，j表示乘法表的第一个数
		{
			printf("%d * %d = %d\t", j, i, j * i); // 输出等式，同时用制表符实现对齐
		}

		printf("\n"); // 输出完一行后对代码进行换行
	}

	return 0;
}
