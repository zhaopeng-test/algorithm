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

struct node *find_list_k(struct node *head, int k)
{

	struct node *p1 = NULL;
	struct node *p2 = NULL;
	int i = 0;

	p1 = head->next;
	p2 = head->next;
	printf("p1 data %d, p2 data %d\n", p1->data, p2->data);

	for (; i < (k - 1) && p1->next != NULL; i ++){
		p1 = p1->next;
	}

	printf("p1 data %d, p2 data %d\n", p1->data, p2->data);
	while (p1->next != NULL){
		p1 = p1->next;
		p2 = p2->next;
	}

	printf("last k %d\n", p2->data);
	return p2;
}


int list_is_have_ring(struct node *head)
{

	struct node *p1;
	struct node *p2;

	p1 = head->next;
	p2 = head->next;

	while(p1->next != NULL && p2->next != NULL){
		p1 = p1->next;
		p2 = p2->next;
		if (p2->next != NULL)
			p2 = p2->next;
		else
			break;

		if (p1 == p2)
			return 1;
	}

	return 0;
}

void list_set_ring(struct node *head, struct node *k_node)
{
	
	struct node *pnode;

	pnode = head;
	while(pnode->next != NULL){
		pnode = pnode->next;
	}

	pnode->next = k_node;
}

int main(void)
{
	struct node *head;
	head = list_init();
	int ret = 0;
	struct node *pnode;

	int i = 1;
	for (; i < 10; i ++){
		list_insert(i,  head);
	}
	print_list(head);
	//list_del(12, head);
	//print_list(head);
	ret = list_is_have_ring(head);
	printf("ret %d\n", ret);
	pnode = find_list_k(head, 6);
	list_set_ring(head, pnode);
	ret = list_is_have_ring(head);
	printf("ret %d\n", ret);

	return 0;
}
