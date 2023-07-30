#include <stdio.h>

void sort(int *arr, int left, int right)
{
	int value = arr[left];
	int pos = left;
	int ori_left = left;
	int ori_right = right;

	if (left >= right)
		return ;

	while (left < right) {
		
		while (left < right && arr[right] > value){
			right --;
		}

		if (left < right && arr[right] < value) {
			arr[pos] = arr[right];
			arr[right] = value;
			pos = right;
			left ++;	
		}
		
		while (left < right && arr[left] < value ) {
			left ++;
		}

		if (left < right && arr[left] > value) {
			arr[pos] = arr[left];
			arr[left] = value;
			pos = left;
			right --;
		}
		
	}
	
	sort(arr, ori_left, pos - 1);
	sort(arr, pos + 1, ori_right);

	return ;
}


int search(int *arr, int len, int data)
{
	int left = 0;
	int right = len;
	int mid = 0;

	while (left < right) {
		mid = (left + right)/2;
		if (arr[mid] == data){
			return mid;
		}else if (arr[mid] > data) {
			right = mid - 1;
		}else if (arr[mid] < data) {
			left = mid + 1;
		}
	}

	return -1;
}

int main(void)
{
	int a[6] = {10,20,8,2,30,15};
	int i = 0;

	sort(a, 0, sizeof(a)/sizeof(int) - 1);	

	for (; i < sizeof(a)/sizeof(int); i ++)
		printf("%d\n", a[i]);

	i = search(a, sizeof(a)/sizeof(int), 30);
	printf("index %d\n", i);
	return 0;
}
