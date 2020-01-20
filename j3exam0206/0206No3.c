#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define M 10
#define N 15
#define MAX_DIGIT 4
#define MAX_VALUE 1000

typedef struct DIGIT_ARRAY {
	int value;
	int digitNum;
} DIGIT_ARRAY;

void mySetArray( int a[N] );
void myPrintArray( int a[], int n );
void myDistributionCountingSort( DIGIT_ARRAY a1[], int a2[] );
void myCopyArray( int sArray[], DIGIT_ARRAY dArray[] );
void myGetDigitNum( DIGIT_ARRAY a[], int digit );
void myRadixSort( int a1[], int a2[] );

int main(void)
{
	int a1[N], a2[N];
	
	srand((unsigned)time(NULL));

	mySetArray( a1 );

	printf("\nBefore sorting...\n");
	myPrintArray( a1, N );

	myRadixSort( a1, a2 );

	printf("\nSorting has finished!\n");

	printf("\nAfter sorting...\n");
	myPrintArray( a2, N );
	printf("\n");
	
	return 0;	
}

void mySetArray( int a[N] )
{
	int i;

	for ( i = 0; i < N; i++ ) {
		a[i]= rand() % MAX_VALUE + 1;
	}
}

void myPrintArray( int a[], int n )
{
	int i;

	for ( i = 0; i < n; i++ ) {
		printf("%3d ", a[i]);
	}
	printf("\n");
}

void myDistributionCountingSort( DIGIT_ARRAY a1[], int a2[] )
{
	int b[M + 1];
	int i;

	for ( i = 0; i < M + 1; i++ ) {
		b[i] = 0; 
	}

	for ( i = 0; i < N; i++ ) {
		b[a1[i].digitNum]++;
	}
	
	printf("\nbinNum   :");
	for ( i = 0; i < M + 1; i++ ) {
		printf("%3d ", i);
	}
	printf("\n");
	printf("Freqency :");
	myPrintArray( b, M + 1 );

	for ( i = 1; i < M + 1; i++ ) {
		b[i] = b[i - 1] + b[i];
	}
	printf("AccumFreq:");
	myPrintArray( b, M + 1 );

	for ( i = N - 1; i >= 0; i-- ) {
		a2[--b[a1[i].digitNum]] = a1[i].value;
	}
}

void myCopyArray( int sArray[], DIGIT_ARRAY dArray[] )
{
	int i;

	for ( i = 0; i < N; i++ ) {
		dArray[i].value = sArray[i];
	}
}

void myGetDigitNum( DIGIT_ARRAY a[], int digit )
{
	int i,j;
	int tmp;

	for ( i = 0; i < N; i++ ) {
		tmp = a[i].value;
		for(j = 1; j < digit ; j++ ){
			tmp /= 10;
		}
		a[i].digitNum = tmp % 10;
	}

}

void myRadixSort( int a1[], int a2[] )
{
	DIGIT_ARRAY a1_digit[N];
	int i, j;

	myCopyArray( a1, a1_digit );

	for ( i = 1; i <= MAX_DIGIT; i++ ) {
		myGetDigitNum( a1_digit, i );

		//For check use;
		printf("\nWe are now focusing on digit %d\n", i);
		printf(" val digitNum\n");
		for ( j = 0; j < N; j++ ) {
			printf("%4d%9d\n", a1_digit[j].value, a1_digit[j].digitNum);
		}

		myDistributionCountingSort( a1_digit, a2 );

		printf("\nUnder sorting...\n");
		myPrintArray( a2, N );
		printf("\n");

		myCopyArray( a2, a1_digit );
	}	
}
