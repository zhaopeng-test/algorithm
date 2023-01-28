#include <stdio.h>

int main()
{

	unsigned char a = 0x2;
	int off = 1;
	int len = 2;

	printf("%b \n", a);

	printf("%b \n", a << (8 - (off + len)));

}


