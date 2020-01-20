#include <stdio.h>

int calFromRevPol(char pol[]);
void myPush(int *sp, int stack[], int value);
int myPop(int *sp, int stack[]);


int main(void)
{
	char pol[100];
	char dmy;

	printf("Input Reverse Poland : ");
	scanf("%s%c", pol, &dmy);	
	
	printf("Ans : %d\n", calFromRevPol(pol));

	return 0;
}				

int calFromRevPol(char pol[])
{
	int stack[100];
	int sp = 0;
	int i;
	int j;
	int j2;
	int k = 1;
	int value = 0;
	int _1stValue;
	int _2ndValue;

	for ( i = 0; pol[i] != '\0'; i++) {
		if ( '1' <= pol[i] && pol[i] <= '9' ) {

			// You can write program here !!!			
			k = 1;
			j = 0;
			for(; pol[i+j+1] != ']'; j++){}
			j2 = j;
			_1stValue = 0;
			for( ; j >= 0; j--,k*=10){
				_1stValue += (pol[i+j] - '0') * k;
			}
			myPush(&sp, stack, _1stValue);
			i += j2+1;

		} else {
			if (pol[i] == '+') {
				_2ndValue = myPop(&sp, stack);
				_1stValue = myPop(&sp, stack);
				myPush(&sp, stack, _1stValue + _2ndValue);
			} else if  (pol[i] == '-') {
				_2ndValue = myPop(&sp, stack);
				_1stValue = myPop(&sp, stack);
				myPush(&sp, stack, _1stValue - _2ndValue);
			} else if  (pol[i] == '*') {
				_2ndValue = myPop(&sp, stack);
				_1stValue = myPop(&sp, stack);
				myPush(&sp, stack, _1stValue * _2ndValue);
			} else { // if  (pol[i] == '/')
				_2ndValue = myPop(&sp, stack);
				_1stValue = myPop(&sp, stack);
				myPush(&sp, stack, _1stValue / _2ndValue);
			}
		}
	}

	return myPop(&sp, stack);
}

void myPush(int *sp, int stack[], int value)

{
	stack[(*sp)++] = value;
}

int myPop(int *sp, int stack[])
{
	return stack[--*sp];
}
