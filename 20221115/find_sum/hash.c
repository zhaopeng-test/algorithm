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
	
		printf("value %d\n", p->key);
		printf("index %d\n", p->data);
	}

}

#define HASH_LEN 128

struct node *hash_table_init()
{
	struct node *phash_head = NULL;
	int i = 0;

	phash_head = malloc(sizeof(struct node)*HASH_LEN);
	if (NULL == phash_head)
		return NULL;
	
	for (; i < HASH_LEN; i ++){
		phash_head[i].next = NULL;
		phash_head[i].data = 0;
		phash_head[i].key = 0;
	}

	return phash_head;

}	

int hash_insert(int key, int data, struct node *phash_head)
{
	int id = key % HASH_LEN;

	list_insert(key, data, &phash_head[id]);

	return 0;
}

struct node *hash_find(int key, struct node *phash)
{
	int id;
	id = key % HASH_LEN;
	while (phash[id].next != NULL){
		if (phash[id].key == key)
			return &phash[id];
	}

	return NULL;
}

int hash_print(struct node *phead)
{
	int i = 0;
	for(; i < HASH_LEN; i ++){
		print_list(&phead[i]);
	}

}

#define ARR_NUM(a) sizeof(a)/sizeof(a[0])

int main()
{
	int a[] = {2, 7, 11, 15};
	int target = 9;
	int i = 0;

	struct node * hash = hash_init();
	if (hash == NULL)
		return -1;

	for (; i < ARR_NUM(a); i ++){
		hash_insert(a[i], i, hash);
	}

	hash_print(hash);
	
	return 0;
}


