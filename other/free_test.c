#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *str;
	char *p0;
	char *p1; 
	char *p2;

	str = (char *)malloc(sizeof(char) * 7);
	if (str == NULL)
		return (0);
	strcpy(str, "Hello!");
	p0 = &str[0];
	p1 = &str[1];
	p2 = &str[2];
	printf("string: %s\n", str);
	printf("address: %p\n", str);
	printf("what is written in the addresses: %c, %c, %c, %c, %c, %c, %c.\n", str[0], str[1], str[2], str[3], str[4], str[5], str[6]);
	printf("what is written in str %p: %s\n", str, str);
	printf("what is written in str[0] %p: %c\n", p0, *p0);
	printf("what is written in str[1] %p: %c\n", p1, *p1);
	printf("what is written in str[2] %p: %c\n", p2, *p2);
	printf("freeing takes place\n");
	free(str);
	printf("what is written in str %p: %s\n", str, str);
	printf("what is written in str[0] %p: %c\n", p0, *p0);
	printf("what is written in str[1] %p: %c\n", p1, *p1);
	printf("what is written in str[2] %p: %c\n", p2, *p2);
	printf("NULLing takes place\n");
	str = NULL;
	printf("what is written in str %p: %s\n", str, str);
	printf("what is written in str[0] %p: %c\n", p0, *p0);
	printf("what is written in str[1] %p: %c\n", p1, *p1);
	printf("what is written in str[2] %p: %c\n", p2, *p2);
	return(0);
}
