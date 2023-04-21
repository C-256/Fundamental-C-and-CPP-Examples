/* embedded_definition_of_structure.c */
/* 结构的嵌套定义 */

#include <stdio.h>

typedef enum
{
	male,
	female,
} SEX;

typedef struct
{
	int year;
	int month;
	int date;
} BIRTHDAY;

typedef struct
{
	char *name;
	SEX sex;
	BIRTHDAY birthday;
	// 结构的成员不仅可以是一般的变量，也可以是枚举(enum)、结构(struct)、联合(union)
	char *address;
} CLERK;

int main(void)
{
}
