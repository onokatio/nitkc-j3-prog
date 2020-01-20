#include<stdio.h>
#include<stdlib.h>

typedef struct CELL {
	int value;
	struct CELL *next;
} CELL;

void enq(CELL **r, int enqValue);
int deq(CELL **f);

int main(void)
{
	CELL *f;
	CELL *r;
	int menu = 0;
	int enqValue;
		
	f = (CELL *)malloc(sizeof(CELL));
	r = f;

	while ( menu != 3 ) {
	
		printf("\n[Menu] 1: Enq  2: Deq  3: Exit\n");
		printf("\nInput menu number : ");
		scanf("%d", &menu);
	
		switch ( menu ) {
			case 1 :
				printf("\nInput enqValue : ");
				scanf("%d", &enqValue);
				enq(&r, enqValue);
				break;
			case 2:
				if ( f == r ) {
					printf("\nQ is empty, so you can not deq !!!\n");
				} else {
					printf("\ndeqValue = %d\n", deq(&f));
				}
				break;
			case 3:
				printf("\nBye !!!\n\n");
				break;
			default:
				break;
		}

	}

	return 0;
}

void enq(CELL **r, int enqValue)
{
	// You can write program here !!!
	(**r).next = (CELL *)malloc(sizeof(CELL));
	*r = (*r)->next;
	(*r)->value = enqValue;
}

int deq(CELL **f)
{
	*f = (*f)->next;
	return (*f)->value;
}
