#include <stdio.h>
#include <stdlib.h>

typedef struct CELL {
	int value;
	struct CELL *next;
} CELL;

void printList(CELL *p);
void insertValueToList(CELL *p);
void deleteValueToList(CELL *p);
void clearList(CELL *p);

int main(void)
{
	int menuNum;
	CELL root;
	CELL *p = &root;

	root.next = NULL;

	for( ; ; ) {
		printf("\nMENU:  select number\n");
		printf("1:Print, 2:Insert, 3:Delete, 4:Initialize, 5:Exit\n");
		scanf("%d", &menuNum);
		if ( menuNum == 1 ) {
			printList( root.next );
		} else if ( menuNum == 2 ) {
			insertValueToList( p );
		} else if ( menuNum == 3 ) {
			deleteValueToList( p );
		} else if ( menuNum == 4 ) {
			clearList( p );
		} else if ( menuNum == 5 ) {
			break;
		}
	}

	clearList( p );

	printf("\nBye!\n\n");

	return 0;
}

void printList(CELL *p)
{
	for ( ; p != NULL; p = p->next ) {
		printf( "%d ", p->value );
	}
	printf("\n");
}

void insertValueToList(CELL *p)
{
	int data;
	int basyo;
	int i;
	CELL *q;
	
	printf("Input data: ");
	scanf("%d", &data);
	printf("Input basyo: ");
	scanf("%d", &basyo);

	for ( i = 0; i < basyo; i++) {
		p = p->next;
	}

	q = p->next;
	p->next = (CELL *)malloc(sizeof(CELL));
	p->next->value = data;
	p->next->next = q;
}

//You can modify only this function at this question.
void deleteValueToList(CELL *p)
{
	CELL *q;

	q = p->next;
	p->next = p->next->next;
	free(q);
}

void clearList(CELL *p)
{
	CELL *q;
	
	while ( p->next != NULL ) {
		q = p->next;
		p->next = p->next->next;
		free(q);
	}
}
