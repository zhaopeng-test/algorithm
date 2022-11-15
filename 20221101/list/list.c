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

main()
{
	struct node *head;
	head = list_init();
	list_insert(10,  head);
	list_insert(11,  head);
	list_insert(12,  head);
	list_insert(13,  head);
	print_list(head);
	list_del(12, head);
	print_list(head);


	return 0;
}
