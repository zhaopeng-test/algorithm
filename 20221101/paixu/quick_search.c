#include <stdio.h>


int quck_search(int *arr, int len)
{
	int dst = arr[0];
	int i = 1;
	int j = 0;
	int tmp = 0;


	for (; i < len; i ++){
		if (arr[i] < arr[j]){
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			j = i;
		}
		printf("i %d j %d\n", i, j);
	}

		
	return 0;
}

int modify(int *b, int id)
{
	printf("id %d = %d\n", id, b[id]);
	b[id] = 12;
	printf("id %d = %d\n", id, b[id]);

	return 0;
}


int main()
{
	int i = 0;
	int a[6] = {3,7,1,8,2,5};
	
	quck_search(a, sizeof(a)/sizeof(a[0]));
	//modify(&a, 1);
	for (; i < sizeof(a)/sizeof(int); i ++)
		printf("a[%d] = %d ", i, a[i]);

	printf("\n");

	return 0;
}


