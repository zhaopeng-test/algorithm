#include <stdio.h>
#include <stdint.h>

//len is bit num
void set_bit(uint8_t *dst_addr, uint8_t *data, int offset, int len)
{
	int i = 0;
	int byte_n = 0;
	uint8_t *dst_pos = NULL;
	uint8_t *src_pos = NULL;
	int dbit=0;
	int sbit=0;
	int temp1 = 0;
	int temp2 = 0;

	for (; i < len; i ++){
		byte_n = (offset + i)/8;	
		dbit = (offset + i) % 8;
		dst_pos = &dst_addr[byte_n];
		
		src_pos = &data[i/8];
		sbit = i % 8;

		temp1 = *dst_pos | (1 << dbit);
		temp2 = ((1<< dbit) ^ 0xff);

		*dst_pos = temp1 & (temp2 | ((*src_pos >> sbit) & 0x1) << dbit);
		printf("i %d dbit %d, sbit %d, temp1 0x%x, dst_pos 0x%x\n", i, dbit, sbit, temp1, *dst_pos);	
	}
}

int main()
{
	uint32_t dst = 0;
	uint32_t src = 0xf;
	
	set_bit(&dst, &src, 22, 4);

	printf("0x%x\n", dst);
	return 0;
}


