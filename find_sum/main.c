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

int binary_search(int *a, int len, int value)
{
	int id = 0;
	int val_id = 0;

	if (len < 1){
		return -1;
	}

	id = len / 2;

	if (a[id] == value){
		return id;
	}
	
	if (id == 0){
		return -1;
	}
	
	if (a[id] > value){
		val_id = binary_search(a, id, value);

	}else {
		val_id = binary_search(&a[id + 1], (len - (id + 1)), value);
	
	}

	return val_id;
}

void find_sum(int *a, int len, int sum)
{
	int i = 0;
	int j = 0;


	for (; i < len; i ++){
		printf("i a[%d] %d\n", i, a[i]);
		for (j = i + 1; j < len; j ++){
		   printf("j a[%d] %d\n", j, a[j]);
		   if (a[j] == sum - a[i]){
			printf("i %d, j %d\n", i, j);
			return ;
		   }
		}
	}
	
}




#define ARR_NUM(a) sizeof(a)/sizeof(a[0])

int main_ori()
{
	int i = 0;
	//int a[ ] = {10,4,8,2,6,1,9,5,2,6,8,4,1};
	//int a[ ] = {2,7,11,5};
	int a[ ] = {3,2,4};
	int target = 6;
	int index = 0;

	for (; i < ARR_NUM(a); i ++)
		printf("%d ", a[i]);
	printf("\n");

	quick_sort(a[0], &a[0], &a[ARR_NUM(a) - 1]);
	
	for (i = 0; i < ARR_NUM(a); i ++)
		printf("%d ", a[i]);

	printf("\n");
	printf("start binary search :\n");
	for (i = 0; i < ARR_NUM(a); i ++){
		index = binary_search(a, ARR_NUM(a), target - a[i]);
		if (index != -1)
			break;
	}

	printf("find %d \n", index);
}

int main()
{

	int a[ ] = {10,4,11,2, 5,1,6,7};
	int target = 9;

	find_sum(a, ARR_NUM(a), target);

	return 0;
}

