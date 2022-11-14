#include <stdio.h>

int g_index = 0;

void quick_sort(int value, int *left, int *right)
{
	int r_flag = 1;
	int l_flag = 0;
	int *ori_left = left;
	int *ori_right = right;


	printf("start in g_index %d left %d right %d\n", g_index, *left, *right);
	//if (g_index == 2)
	//		return ;

	if (left >= right)
		return ;

	//addr is same
	while (left < right){
	
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

		if (left >= right)
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

		
	if (ori_left < left)
	{
		printf("end left %d right %d\n", *left, *right);
		g_index ++;
		printf("end in g_index %d *ori_left %d *(left - 1) %d\n", g_index, *ori_left, *(left - 1));
		quick_sort(*ori_left, ori_left, left - 1);
	}	
	
	if (right < ori_right){
		quick_sort(*(left + 1), left + 1, ori_right);
	}
	
	return ;

}

#define ARR_NUM(a) sizeof(a)/sizeof(a[0])

int main()
{
	int i = 0;
	int a[ ] = {10,4,8,2,6,1,9,5,2,6,8,4,1};
	
	for (; i < ARR_NUM(a); i ++)
		printf("%d ", a[i]);
	printf("\n");

	quick_sort(a[0], &a[0], &a[ARR_NUM(a) - 1]);
	
	for (i = 0; i < ARR_NUM(a); i ++)
		printf("%d ", a[i]);

	printf("\n");
}


