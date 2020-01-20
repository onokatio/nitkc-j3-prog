#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	struct NODE *left;
	int value;
	struct NODE *right;
} NODE;

void addNode(NODE **p, int data);
NODE *myAllocNode(int data);
void inorder(NODE *p);

int main(void)
{
	NODE *root = NULL;
	int data;

	printf("\nNow You can make Binary Tree with inserting data!\n");
	printf("And you will finish making bTree if you input 0 or negative integer!\n");

	printf("\nInput data : ");
	scanf("%d", &data);
	while ( data > 0 ) {
		addNode(&root, data);
		printf("Input data : ");
		scanf("%d", &data);
	}
	printf("\nYou've finished making bTree, so now we show you the data with inorders\n");

	printf("\ninorder : ");
	inorder(root);

	printf("\n\nBye!\n\n");
		
	return 0;
}
 
void addNode(NODE **p, int data)
{
	while (*p != NULL) {
		if ( data > (*p)->value ) {
			p = &(*p)->right;
		} else {
			p = &(*p)->left;
		}
	}

	*p = myAllocNode(data);
}

NODE *myAllocNode(int data)
{
	NODE *p = (NODE *)malloc(sizeof(NODE));
	
	p->value = data;
	p->left = p->right = NULL;
	
	return p;
}

void inorder(NODE *p)
{
	if ( p != NULL) {
		inorder( p->right );
		printf("%d ", p->value);
		inorder( p->left );
	}
}
