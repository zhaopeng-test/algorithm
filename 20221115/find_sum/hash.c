#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node *next;
	int data;
	int key;
};


int list_insert(int key, int data, struct node *pnode)
{
	struct node *pnew;

	pnew = malloc(sizeof(struct node));
	pnew->data = data;
	pnew->key = key;
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

#define HASH_LEN 128

struct *node hash_table_init()
{
	struct *node hash_head = NULL;
	int i = 0;

	hash_head = malloc(siezof(struct node)*HASH_LEN);
	if (NULL == hash_head)
		return NULL;
	
	for (; i < HASH_LEN; i ++){
		p[i]->next = NULL;
		p[i]->data = 0;
		p[i]->key = 0;
	}

	return hash_head;

}	

int hash_insert(int key, int data, struct node *phash_head)
{
	id = key % HEAD_LEN;

	list_insert(key, data, &phead_head[id]);

	return 0;
}

struct node *hash_find(int key, struct node *phash)
{
	id = key % HEAD_LEN;
	while ()

}

int hash_print(struct node *phead)
{
	int i = 0;
	for(; i < HASH_LEN; i ++){
		print_list(&phead[i]);
	}

}


int main_ori()
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

int main()
{


}


