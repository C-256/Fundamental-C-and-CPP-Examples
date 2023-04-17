/* factorial.c */
/* 阶乘的计算，循环语句的典型案例 */
/* 为了方便起见，本程序略去了输入验证 */

#include <stdio.h>

int main(void)
{
	unsigned int temp, i = 0;			// temp和i都是临时变量
	unsigned long long num, result = 1; // num为用户输入的数值，result为结果

	printf("Please enter a positive integer: ");

	// 使用scanf的返回值和do-while语句进行输入验证
	do
	{
		if (i)
		{
			printf("Illegal input, please try again: ");
		}
		i = 1;
		temp = scanf("%u", &num);
	} while (temp);

	// 使result不断地乘n, n-1, ... , 2
	// 对于0和1不会进入这个循环，result保持为1，不影响结果
	for (i = num; i > 1; i--)
	{
		result *= i;
	}

	printf("%llu! = %llu", num, result);

	return 0;
}
