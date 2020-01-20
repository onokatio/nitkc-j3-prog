#include <stdio.h>
#include <string.h>

#define N 5
#define M 10

typedef struct STUDENT {
	int no;
	char name[5 + 1];
	int score;
} STUDENT;

void myBinSort( STUDENT list[N] ); 
void myPrintArray( STUDENT a[], int size );

int main(void)
{
	STUDENT list[N];
	
	list[0].no = 1;
	strcpy( list[0].name, "Yone" );
	list[0].score = 3;

	list[1].no = 2;
	strcpy( list[1].name, "Mura" );
	list[1].score = 10;

	list[2].no = 3;
	strcpy( list[2].name, "Kei" );
	list[2].score = 5;

	list[3].no = 4;
	strcpy( list[3].name, "Ichi" );
	list[3].score = 0;

	list[4].no = 5;
	strcpy( list[4].name, "Hogen" );
	list[4].score = 6;

	printf("\nBefore sorting...\n");
	myPrintArray( list, N );
	printf("\n");

	myBinSort( list );

	printf("After sorting...\n");
	myPrintArray( list, N );
	printf("\n");

	return 0;		
}

void myBinSort( STUDENT list[N] )
{
	STUDENT b[M+1];
	int i;
	int index = 0;

	for ( i = 0; i < M + 1; i++ ) {
		b[i].no = -1;
		strcpy( b[i].name, "" );
		b[i].score = -1;
	}
	 	
	for ( i = 0; i < N; i++ ) {
		b[list[i].score] = list[i];
	}

	printf("You can check bins as follows!\n");
	myPrintArray( b, M+1 );
	printf("\n");

	//You can write program here
	for ( i = 0; i < M + 1 ; i++){
		if(b[i].score != -1){
			list[index] = b[i];
			index++;
		}
	}
		
	
}

void myPrintArray( STUDENT a[], int size )
{
	int i;

	for ( i = 0; i < size; i++ ) {
		printf(" score : %2d, no : %2d, name : %5s\n", a[i].score, a[i].no, a[i].name );
	}
}
	

