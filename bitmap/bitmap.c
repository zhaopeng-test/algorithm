#include <stdio.h>


unsigned int g_bitmap[1024];

int find_first_no_set()
{
	int i = 0;
	int off = 0;
	int data = 0;

	for (; i < 1023; i ++){
		printf("%x ", g_bitmap[i]);
		if (g_bitmap[i] != 0xffffffff){
			printf("find first no set %d\n", data);
			for(; off < 32; off ++){
				if ((g_bitmap[i] & (1 << off)) == 0){
					data = i*32 + off;
					printf("find first no set %d\n", data);
					return data;
				}
			}	
		}
			
	}
		

}

void bitmap_insert(int data)
{
	int id = data/32;
	int offset = data%32;

	if (id > 1023)
	     return ;

	g_bitmap[id] = g_bitmap[id] | (1 << offset);
	
	return ;
}

int find_num(int data)
{
	int id = data/32;
	int offset = data%32;

	if (id > 1023)
		return -1;

	if (g_bitmap[id] & 1 << offset){
		printf("find %d\n", data);
		return 1;
	}else{
		printf("not find %d\n", data);
		return 0;
	}
}

void show_all()
{
	int id = 0;
	int i = 0;

	for (; i < 1024*32; i ++){
		if (g_bitmap[i/32] & (1 << i))
			printf("%d ", i);
	}
	
	return ;
}

int main()
{
	int a[] = {4,3,17,34,99,22,11,6,16,76};
	int i = 0;

	//for (; i < sizeof(a)/sizeof(a[0]); i ++)
	//	bitmap_insert(a[i]);

	for (; i < 7000; i ++){
		if (i == 6000)
		   continue;
		
		bitmap_insert(i);
	}

	//show_all();
	find_first_no_set();

	find_num(76);
	find_num(3);
	find_num(100);
	
	return 0;
}



