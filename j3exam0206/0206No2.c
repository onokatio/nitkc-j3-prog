#include <stdio.h>

#define N 5
#define M 10

void myDistributionCountingSortNotStable( int a1[], int a2[] );
void myPrintArray( int a[], int n );

int main(void)
{
	int a1[N] = { 3, 7, 5, 1, 5 };
	int a2[N];
	
	printf("\nBefore Sorting...\n");
	myPrintArray( a1, N );

	myDistributionCountingSortNotStable( a1, a2 );

	printf("\nAfter Sorting...\n");
	myPrintArray( a2, N );
	printf("\n");		

	return 0;		
}

void myDistributionCountingSortNotStable( int a1[], int a2[] )
{
	int f[M + 1];
	int i;

	for ( i = 0; i < M + 1; i++ ) {
		f[i] = 0;
	}

	for ( i = N -1 ; i >= 0; i-- ) {
		f[a1[i]]++;
	}

	for ( i = 1; i < M + 1; i++ ) {
		f[i] = f[i - 1] + f[i];
	}

	printf("\nYou can check accumrated freqency as follows!\n");
	myPrintArray( f, M + 1 );
	
	//You can modify program here
	for ( i = 0; i < N; i++ ) {
		a2[--f[a1[i]]] = a1[i];
	}
}

void myPrintArray( int a[], int n )
{
	int i;

	for ( i = 0; i < n; i++ ) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
