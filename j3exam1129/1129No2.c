#include <stdio.h>
#include <stdlib.h>

#define WORD_SIZE 3
#define WORD_LENGTH 10

void setWordsToMyDictionary(char *myDictionary[WORD_SIZE]);
void PrintDictionary(char *myDictionary[WORD_SIZE]);

int myStrCmp(char str1[WORD_LENGTH + 1], char str2[WORD_LENGTH + 1]);
void mySort(char *myDictionary[WORD_SIZE]);

int main(void)
{
	char *myDictionary[WORD_SIZE];

	setWordsToMyDictionary(myDictionary);

	PrintDictionary(myDictionary);

	mySort(myDictionary);

	PrintDictionary(myDictionary);


	return 0;
}

void setWordsToMyDictionary(char *myDictionary[WORD_SIZE])
{
	int i;
	char dummy;
	
	for ( i = 0; i < WORD_SIZE; i++ ) {
		printf("Set word [%d] (less than 10 characters) : ", i );
		myDictionary[i] = (char *)malloc(sizeof(char) * (WORD_LENGTH + 1));
		scanf("%s%c", myDictionary[i] , &dummy);
	}
}

void PrintDictionary(char *myDictionary[WORD_SIZE])
{
	int i;

	for ( i = 0; i < WORD_SIZE; i++ ) {
		printf("%s\n", myDictionary[i]);
	}
} 

int myStrCmp(char str1[WORD_LENGTH + 1], char str2[WORD_LENGTH + 1])
{
	int i;
	
	for (i = 0; str1[i] != '\0'; i++ ) {
		if ( str1[i] != str2[i]) return str1[i] - str2[i];
	}
	return str1[i] - str2[i];
}

void mySort(char *myDictionary[WORD_SIZE])
{
	int i, j;
	char *tmp;

	for ( i = 0; i < WORD_SIZE - 1; i++ ) {
		for ( j = 0; j < WORD_SIZE - 1 - i; j++ ) {
			if ( myStrCmp(myDictionary[j],myDictionary[j + 1] )) {
				tmp = myDictionary[j]; 
				myDictionary[j] = myDictionary[j + 1];
				myDictionary[j + 1] = tmp;
			}
		}
	}
}


	

	
