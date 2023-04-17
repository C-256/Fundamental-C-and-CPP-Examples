/* swap.c */
/* 交换两个数 */
/* 使用指针作为参数 */

#include <stdio.h>

void Swap1(int a, int b);
void Swap2(int *a, int *b);

int main(void)
{
	int a = 1, b = 2;
	printf("Before Swap1():   a = %d, b = %d", a, b);

	Swap1(a, b);
	printf("\nAfter Swap1():    a = %d, b = %d", a, b); // 根据输出可知此处a和b没有被交换
	// 向函数传递变量，被调函数只能处理传入的两个参数，不会改变主调函数用于传参的变量的值

	Swap2(&a, &b);
	printf("\nAfter Swap2():    a = %d, b = %d", a, b); // 根据输出可知此处a和b已经被交换
	// 向函数传递指针，被调函数不会改变主调函数中两个指针指向的位置（不会改变用于传参的变量的值）
	// 但被调函数可以通过指针改变指针所指向的变量

	return 0;
}

void Swap1(int a, int b)
{
	int t;
	t = a;
	a = b;
	b = t;
}

void Swap2(int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
