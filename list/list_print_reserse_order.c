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

void print_reverse_order(struct node *head, int *flag)
{
	struct node *p;
	p = head->next;

	if (p->next == NULL){
		printf("data %d\n", p->data);
		*flag = 1;
		return ;
	}	

	print_reverse_order(p, flag);

	if (*flag == 1){
		printf("data %d\n", p->data);
	}

	return ;
}

int main()
{
	struct node *head;
	head = list_init();
	int i = 1;
	int flag = 0;
	for(; i < 10; i ++){
		list_insert(i,  head);
	}
	print_list(head);
	//list_del(12, head);
	printf("reverse order\n");
	print_reverse_order(head, &flag);


	return 0;
}
