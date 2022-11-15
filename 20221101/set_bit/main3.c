#include <stdio.h>
#include <stdint.h>

static void put_as_bytes(uint8_t* dst, uint8_t* src, int offset, int bits)
{
        // printf("\tput_as_bytes: \n\toffset: %d, bits: %d\n\t\t", offset, bits);
        for (int i = 0; i < bits; ++i)
        {
            int src_i = i / 8;
            int src_shift = i % 8;
            uint8_t src_value = (src[src_i] >> src_shift) & 1;

            int dst_i = (offset + i) / 8;
            int dst_shift = (offset + i) % 8;
            uint8_t dst_mask = (1 << dst_shift);
            // printf("\t%d. dst[%d]: %02X <- src[%d]: %02X, src_shited_value: %02X\n", 
            //     i, dst_i, dst[dst_i], src_i, src[src_i], src_value);
            // printf("\tdst_mask: %02X, src_shift: %d\n", dst_mask, src_value);
            if (src_value != 0)
                dst[dst_i] |= dst_mask;
            else
                dst[dst_i] &= ~dst_mask;
            // printf("%d: %02X ", dst_i, dst[dst_i]);
        }
        // printf("\n");
}

int main(void)
{
	unsigned char a[10];
	unsigned char b=0x7;

	put_as_bytes(&a[0], &b, 7, 3);

	printf("%b %b %b\n", a[0], a[1], a[2]);	

	return 0;
}


