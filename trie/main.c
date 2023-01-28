#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct trie_node{
	char is_end;
	char value;
	struct trie_node *next[26];
};


struct trie_node *trie_node_malloc(void)
{
	struct trie_node *p = malloc(sizeof(struct trie_node));
	memset(p, 0, sizeof(*p));

	return p;
}

int trie_insert(struct trie_node *node, char *pvalue)
{
	int index = *pvalue - 'a';
	struct trie_node *pnode = trie_node_malloc();

	pnode->value = *pvalue;

	node->next[index] = pnode;
	printf("insert %c\n", *pvalue);

	pvalue ++;
	if (*pvalue != 0)
		trie_insert(node->next[index], pvalue);

	return 0;
}

int search_char(struct trie_node *node, char *pvalue)
{
	if (*pvalue == 0)
		return 0;

	int index = *pvalue - 'a';
	
	if (node->next[index] != NULL){
		node->next[index]->value == *pvalue;
		printf("find %c\n", *pvalue);
		pvalue ++;

		if (*pvalue == 0)
			return 0;
		else
			search_char(node->next[index], pvalue);
	}

	return 0;
}


int main()
{
	struct trie_node *root = trie_node_malloc();
	char *p = "hello";

	trie_insert(root, p);
	search_char(root, p);


	return 0;
}




