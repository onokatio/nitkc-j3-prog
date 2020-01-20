#include<stdio.h>
#include<stdlib.h>

typedef struct CELL {
	int value;
	struct CELL *next;
} CELL;

CELL *enq(CELL *r, int enqValue);
CELL *deq(CELL *f, int *deqvalue);

int main(void)
{
	CELL *f;
	CELL *r;
	int menu = 0;
	int enqValue;
	int deqValue;
	
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
				r = enq(r, enqValue);
				break;
			case 2:
				if ( f == r ) {
					printf("\nQ is empty, so you can not deq !!!\n");
				} else {
					f = deq(f, &deqValue);
					printf("\ndeqValue = %d\n", deqValue);
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

CELL *enq(CELL *r, int enqValue)
{
	r->next = (CELL *)malloc(sizeof(CELL));
	r = r->next;
	r->value = enqValue;
	
	return r;
}

CELL *deq(CELL *f, int *deqValue)
{
	// You can write program here !!!
	f = f->next;
	*deqValue = f->value;

	return f;
}
