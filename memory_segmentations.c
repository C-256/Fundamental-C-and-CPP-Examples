/* memory_segmentations.c */
/* 该程序展示了字符串常量、局部变量、动态分布区域的内存地址区域差别，并解释了字符串常量不可被修改的原因。 */

/* 注：由于程序在不同计算机上运行时内存分配情况不同，不同计算机运行结果也一般不同，但是可以发现内存地址的位置差异。 */

#include <stdio.h>
#include <stdlib.h>

int main(void)										// 主函数
{
	char *a = "Braised Intestines in Brown Sauce";	// 字符串常量
	char b = ' ';									// 局部变量
	char c[10];										// 局部变量数组
	char *d = (char *)malloc(1);					// 动态分配内存区域

	printf("a    = %p\n", a);						// 字符串常量位于代码段
	printf("&b   = %p\n", &b);						// 局部变量位于栈中
	printf("c    = %p\n", c);						// 局部变量数组也位于栈中
	printf("d    = %p\n", d);						// 动态分配的内存位于堆中
	printf("main = %p\n", main);					// 主函数位于代码段
	printf("%s", a);

	return 0;
}
