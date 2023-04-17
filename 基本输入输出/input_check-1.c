/* input_check_1.c */
/* 这个程序可以通过"scanf()"的返回值来判断数据是否成功输入 */

#include <stdio.h>

int main()
{
	int temp, yr;

	temp = scanf("%d", &yr); // scanf()函数的返回值是成功输入的变量个数

	if (!temp) // 直接使用!temp，相当于 if (temp == 0)
	{
		printf("Error\n");
	}

	return 0;
}
