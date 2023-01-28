#include <stdio.h>
#include <stdlib.h>

struct list{
	struct list *pre;
	struct list *pnext;
};

struct node{
	struct node *next;
	int data;
};


int list_insert(int data, struct node *pnode)
{
	struct node *pnew;

	pnew = malloc(sizeof(struct node));
	pnew->data = data;
	pnew->next = pnode->next;
	pnode->next = pnew;

	return 0;
}

int list_del(int data, struct node *phead)
{
	struct node *p;
	struct node *ptmp;

	for (p = phead; p->next != NULL; p = p->next){
		ptmp = p->next;
		if (ptmp->data == data){
			p->next = ptmp->next;
			free(ptmp);
		}
	}
}

struct node *list_init(void)
{
	struct node *p;

	p = malloc(sizeof(struct node));
	p->next = NULL;
	p->data = 0;

	return p;
}

void print_list(struct node *head)
{
	struct node *p;
	
	for(p = head->next; p != NULL; p = p->next){
	
		printf("data %d\n", p->data);
	}

}

void find_corss_point(struct node *head, int len, struct node *head2, int len2)
{

	struct node *p1;
	struct node *p2;
	struct node *p;

	int i = 0;
	int k = 0;

	if (len2 > len){
		k = len2 - len;
		p1 = head2->next;
		p2 = head->next;	
	}else {
		k = len - len2;
		p1 = head->next;
		p2 = head2->next;
	}

	for (; i < k && p1->next != NULL; i ++){
		p1 = p1->next;
	}
		
	while (p1->next != p2->next && p1->next != NULL && p2->next != NULL){
		p1 = p1->next;
		p2 = p2->next;
	
	}

	if (p1->next == p2->next && p1->next != NULL){
		p = p1->next;
		printf("find corss data %d\n", p->data);
	}

	return ;
}

int list_set_corss(struct node *head, struct node *head2)
{
	struct node *p = head->next;
	struct node *p2 = head2->next;
	int count = 1;


	while (p != NULL && p->next != NULL){
		p = p->next;
		count ++;
		if (count == 5)
			break;
	}

	printf("set corss data = %d\n", p->data);
	while (p2->next != NULL){
		p2 = p2->next;
	}

	p2->next = p;
}

int list_get_size(struct node *head)
{
	struct node *p;
	int count = 1;
	p = head->next;
	while(p->next != NULL){
		p = p->next;
		count ++;
	}
	
	printf("size = %d\n", count);
	return count;
}

int main(void)
{
	struct node *head;
	struct node *head2;
	int len = 0;
	int len2 = 0;

	head = list_init();
	int i = 1;
	for (; i < 10; i ++){
		list_insert(i,  head);
	}

	print_list(head);
	len = list_get_size(head);
	head2 = list_init();
	i = 10;
	for (; i < 15; i ++){
		list_insert(i,  head2);
	}


	list_set_corss(head, head2);

	print_list(head2);
	len2=list_get_size(head2);
	print_list(head2);
	
	find_corss_point(head, len, head2, len2);

	
	//list_del(12, head);
	//print_list(head);


	return 0;
}
