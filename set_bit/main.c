#include <stdio.h>
#include <math.h>

write_bit(unsigned char *pmem, int offset, unsigned char *data, int len)
{
	int i = 0;
	int nbyte = offset / 8;
	int nbit = offset % 8;
	int mask = 0;
	int nbyte2 = (len - nbit) / 8;
	int nbit2 = (len - nbit) % 8;
	int mask2;

	int filed = nbit2

	if (0 != nbit){
		mask = pow(2, nbit);
		if (len + nbit < 8){
			pmem[nbyte] = ((mask - 1) << (8 - nbit)) & data[0] << (8 - (nbit + len));
		}else{
			pmem[nbyte] = ((mask - 1) << (8 - nbit)) & data[0];
			remain_bits = len - (8 - nbit);
			nbyte2 = remain_bits / 8;
			nbits2 = remain_bits % 8;
			if (0 < nbyte2){
				
			
			}

			if (len - (8 - nbit) > 8)
			memcpy(&pmem[nbype + 1], , nby);
		}


	}	


	if (0 == ntybe2)
		

	pmem[nbyte] 
	printf("nbyte = %d, nbit = %d\n", nbyte, nbit);
}


int main()
{
	unsigned char buf[40] = {0};
	unsigned int data = 1;

	write_bit(buf, 3, &data, 1);
	write_bit(buf, 9, &data, 2);
	write_bit(buf, 17, &data, 3);
	write_bit(buf, 28, &data, 4);

	return 0;
}
