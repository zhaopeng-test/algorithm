#include <stdio.h>

#define ARR_NUM(a) sizeof(a)/sizeof(a[0])

int maopao(int *b, int arr_len)
{
	int i = 0;
	int t = 0;

	while (arr_len > 1){
		for (i = 0; i < arr_len - 1; i ++){
			
			if (b[i] > b[i + 1]){
				t = b[i];
				b[i] = b[i + 1];
				b[i + 1] = t;	
			}
		
		}
		arr_len --;
	}

	return 0;
}


int main()
{
	int i = 0;
	int a[6] = {4,9,1,5,3,7};

	maopao(a, ARR_NUM(a));
	for (; i  < ARR_NUM(a); i ++){
		printf("a[%d]=%d ", i, a[i]);
	}	

	printf("\n");

}

