#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ngx_rbtree.h"

ngx_rbtree_t              ngx_event_timer_rbtree;
static ngx_rbtree_node_t  ngx_event_timer_sentinel;


struct my_rbtree_data{
	ngx_rbtree_node_t node;
	char data[64];
};




ngx_rbtree_node_t *my_rbtree_lookup(int hash, char *pdata)
{
	
	ngx_rbtree_node_t  *node, *root, *sentinel;
	struct my_rbtree_data *pnode;

	node = ngx_event_timer_rbtree.root;
	sentinel = ngx_event_timer_rbtree.sentinel;

	while (node != sentinel){
	
		if (hash < node->key){
			node = node->left;
			continue;
		}

		if (hash > node->key){
			node = node->right;
			continue;
		}

		pnode = (struct my_rbtree_data *)node;

		if (0 == strcmp(pdata, pnode->data)){
			printf("my rbtree find  %s\n", pnode->data);
			return node;
		}
	}

	printf("my rbtree not find %s\n", pdata);

	return NULL;
}

unsigned int get_hash(char *pdata)
{
	int i = 0;
	int len = strlen(pdata);
	unsigned int k = 0;

	for (;i < len; i ++){
		k += *pdata++; 
	}

	k = k & 0xffffffff;

	return k;
}


static void
my_rbtree_insert_value(ngx_rbtree_node_t *temp,
    ngx_rbtree_node_t *node, ngx_rbtree_node_t *sentinel)
{
    ngx_rbtree_node_t       **p;
    struct my_rbtree_data    *file, *file_temp;

    for ( ;; ) {

        if (node->key < temp->key) {

            p = &temp->left;

        } else if (node->key > temp->key) {

            p = &temp->right;

        } else { /* node->key == temp->key */

            file = (struct my_rbtree_data *) node;
            file_temp = (struct my_rbtree_data *) temp;

            p = (strcmp(file->data, file_temp->data) < 0)
                    ? &temp->left : &temp->right;
        }

        if (*p == sentinel) {
            break;
        }

        temp = *p;
    }

    *p = node;
    node->parent = temp;
    node->left = sentinel;
    node->right = sentinel;
    ngx_rbt_red(node);
}

void my_rbtree_insert(ngx_rbtree_t *root, char *pdata)
{
	struct my_rbtree_data *pnode = NULL;

	pnode = malloc(sizeof(*pnode));
	memset(pnode, 0, sizeof(*pnode));

	pnode->node.key = get_hash(pdata);
	memcpy(pnode->data, pdata, strlen(pdata));

	ngx_rbtree_insert(root, &pnode->node);

	return ;
}

int main(void)
{
	ngx_rbtree_node_t  *node, *root, *sentinel;

	ngx_rbtree_init(&ngx_event_timer_rbtree, &ngx_event_timer_sentinel,
                    my_rbtree_insert_value);

	my_rbtree_insert(&ngx_event_timer_rbtree, "ni hao world");
	my_rbtree_insert(&ngx_event_timer_rbtree, "hello world");
	
	my_rbtree_lookup(get_hash("hello world"), "hello world");
	my_rbtree_lookup(get_hash("ni hao world"), "ni hao world");
	my_rbtree_lookup(get_hash("ni hao world1"), "ni hao world1");
	
	return 0;
}
