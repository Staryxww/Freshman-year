#include<stdio.h>
int main()
{
	int charsize = sizeof(char);
	int intsize = sizeof(int);
	int longintsize = sizeof(long);
	int floatsize = sizeof(float);
	int doublesize = sizeof(double);
	int longdoublesize = sizeof(long double);
	printf("The size of int is %d bytes\n",intsize);
	printf("The size of char is %d bytes\n",charsize);
	printf("The size of longint is %d bytes\n",longintsize);
	printf("The size of float is %d bytes\n",floatsize);
	printf("The size of double is %d bytes\n",doublesize);
	printf("The size of long double is %d bytes\n",longdoublesize);
	return 0;
}

	
