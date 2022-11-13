#include <stdio.h>


void quick_sort(int value, int *left, int *right)
{
	int r_flag = 1;
	int l_flag = 0;
	int *ori_left = left;
	int *ori_right = right;

	if (left == right)
		return ;

	//addr is same
	while (left != right){
	
		printf("left %d right %d\n", *left, *right);
		if (r_flag){
		if ((*right < value)){
			*left = *right;
			left ++;	
			l_flag = 1;
			//break;
		}else{
			right --;
			l_flag = 0;
		}
		}

		if (left == right)
			break;

		if (l_flag){
		if ((*left > value)){
			*right = *left;
			right --;
			r_flag = 1;
		}else{
			left ++;
			r_flag = 0;
		}
		}

	}
	
	*left = value;

	quick_sort(*ori_left, ori_left, left - 1);
	quick_sort(*(left + 1), left + 1, ori_right);

}

#define ARR_NUM(a) sizeof(a)/sizeof(a[0])

int main()
{
	int i = 0;
	int a[6] = {4,8,2,6,1,9};
	
	for (; i < ARR_NUM(a); i ++)
		printf("%d ", a[i]);
	printf("\n");

	quick_sort(a[0], &a[0], &a[5]);
	
	for (i = 0; i < ARR_NUM(a); i ++)
		printf("%d ", a[i]);

	printf("\n");
}


