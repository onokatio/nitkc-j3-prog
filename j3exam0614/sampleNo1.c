#include <stdio.h>

#define LIST_SIZE 5

void printList(int myList[]);
void insertValueToList(int myList[]);
void shiftValueToList(int myList[], int m);
void deleteValueToList(int myList[]);
void clearList(int myList[]);

int main(void)
{
	int menuNum;
	int myList[LIST_SIZE + 1];

	myList[0] = -1;

	for( ; ; ) {
		printf("\nMENU:  select number\n");
		printf("1:Print, 2:Insert, 3:Delete, 4:Initialize, 5:Exit\n");
		scanf("%d", &menuNum);
		if ( menuNum == 1 ) {
			printList( myList );
		} else if ( menuNum == 2 ) {
			insertValueToList( myList );
		} else if ( menuNum == 3 ) {
			deleteValueToList( myList );
		} else if ( menuNum == 4 ) {
			clearList( myList );
		} else if ( menuNum == 5 ) {
			break;
		}
	}

	printf("\nBye!\n\n");

	return 0;
}

void printList(int myList[])
{
	int i;

	printf("\n");
	for ( i = 0; myList[i] != -1; i++) {
		printf("%d ", myList[i]);
	}
	printf("\n\n");
}

void insertValueToList(int myList[])
{
	int data;
	
	printf("Input data: ");
	scanf("%d", &data);
	
	shiftValueToList(myList, 0);
	myList[0] = data;
}

void shiftValueToList(int myList[], int m)
{
	int i;
	
	for ( i = 0; myList[i] != -1; i++);
	for ( ; i >= m; i--) {
		myList[ i + 1 ] = myList[i];
	}
}

void deleteValueToList(int myList[])
{
	//You can write program here.
}

void clearList(int myList[])
{
	//You can write program here.
}