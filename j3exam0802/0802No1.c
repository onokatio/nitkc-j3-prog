#include <stdio.h>
#include <stdlib.h>

typedef struct CELL {
	int value;
	struct CELL *next;
} CELL;

void insertCELL(CELL *p);
void printList(CELL *p);
int checkLength(CELL *p);

int main(void)
{

	CELL root;
	int menu = 0;
	
	root.next = NULL;

	while ( menu != 4 ) {
	
		printf("\n[Menu] 1: Insert CELL  2: Check Length  3: Print List  4: Exit\n");
		printf("\nInput menu number : ");
		scanf("%d", &menu);
	
		switch ( menu ) {
			case 1 : 
				insertCELL(&root);
				break;
			case 2:
				printf("\nLength is %d\n", checkLength(root.next));
				break;
			case 3:
				printList(root.next);
				break;
			case 4:
				printf("\nBye !!!\n");
				break;
			default:
				break;
		}

	}

	return 0;
}

void insertCELL(CELL *p)
{
	int data;
	int basyo;
	int i;
	CELL *q;

	printf("\nInput basyo ( 0 - %d ) : ", checkLength(p->next));
	scanf("%d", &basyo);

	printf("\nInput data : ");
	scanf("%d", &data);

	for ( i = 0; i < basyo; i++) p = p->next;

	q = p->next;
	p->next = (CELL *)malloc(sizeof(CELL));
	p->next->value = data;
	p->next->next = q;
}

void printList(CELL *p)
{
	printf("\n");

	if ( !p ) {
		printf("List has no CELLs !!!");
	} else { 
		for ( ; p != NULL; p = p->next ) {
			printf("%d ", p->value);
		}
	}
	printf("\n");
}

int checkLength(CELL *p)
{
	int l = 0;

	// You can write program here !!!
	for ( ; p != NULL; p = p->next ) l++;

	return l; 
}
