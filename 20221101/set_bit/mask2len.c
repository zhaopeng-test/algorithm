#include <stdio.h>
#include <stdint.h>


void mask2len(uint32_t mask, uint32_t *len)
{
	int size = sizeof(mask) * 8;
	int i = 0;
	//int num = 0;

	for(; i < size; i ++){
		printf("%d : %x\n", i, (mask >> i & 0x1));
		if (mask >> i & 0x1)
		 	(*len) ++;
	} 
	
	//*len = num;

	return ;
}

int main()
{
	uint32_t m = 0xf000001;
	uint32_t tmp = 0;

	mask2len(m, &tmp);
	
	printf("mask len %d\n", tmp);

	return 0;
}




