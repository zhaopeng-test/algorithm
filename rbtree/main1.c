#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ngx_rbtree.h"

ngx_rbtree_t              ngx_event_timer_rbtree;
static ngx_rbtree_node_t  ngx_event_timer_sentinel;


ngx_rbtree_node_t *rbtree_lookup(int key)
{
	
	ngx_rbtree_node_t  *node, *root, *sentinel;

	node = ngx_event_timer_rbtree.root;
	sentinel = ngx_event_timer_rbtree.sentinel;

	while (node != sentinel){
	
		if (key < node->key){
			node = node->left;
			continue;
		}

		if (key > node->key){
			node = node->right;
			continue;
		}

		if (key == node->key){
			printf("find key %d\n", key);
			return node;
		}
	}

	printf("not find %d\n", key);

	return NULL;
}

void my_rbtree_insert(ngx_rbtree_t *root)
{
	int i = 1;
	ngx_rbtree_node_t *pnode = NULL;

	for (; i < 100; i ++){
		pnode = malloc(sizeof(*pnode));
		memset(pnode, 0, sizeof(*pnode));

		pnode->key = i;

		ngx_rbtree_insert(root, pnode);
	}

	return ;
}

int main(void)
{
	ngx_rbtree_node_t   timer = {0};
	ngx_rbtree_node_t   timer1 = {0};
	ngx_rbtree_node_t   timer2 = {0};
	timer.key = 0x8863;
	ngx_rbtree_node_t  *node, *root, *sentinel;

	ngx_rbtree_init(&ngx_event_timer_rbtree, &ngx_event_timer_sentinel,
                    ngx_rbtree_insert_timer_value);

	/*
	ngx_rbtree_insert(&ngx_event_timer_rbtree, &timer);
	timer1.key = 0x886;
	ngx_rbtree_insert(&ngx_event_timer_rbtree, &timer1);
	timer2.key = 0x88567;
	ngx_rbtree_insert(&ngx_event_timer_rbtree, &timer2);

	root = ngx_event_timer_rbtree.root;
    	sentinel = ngx_event_timer_rbtree.sentinel;

    	node = ngx_rbtree_min(root, sentinel);
	*/

	my_rbtree_insert(&ngx_event_timer_rbtree);
	
	root = ngx_event_timer_rbtree.root;
    	sentinel = ngx_event_timer_rbtree.sentinel;

    	node = ngx_rbtree_min(root, sentinel);

	printf("0x%x\n", node->key);

	rbtree_lookup(10);
	rbtree_lookup(93);
	rbtree_lookup(930);

	return 0;
}
