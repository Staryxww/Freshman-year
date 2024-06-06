#include<stdio.h>
int main()
{	
	char engcharacter;
	printf("Please enter a character,you can choose from:e,t,c\n");
	scanf("%c",&engcharacter);
	switch(engcharacter)
	{
		case 'e':
		printf("\x1b[31m*******\n*\n*\n*\n******\n*\n*\n*\n*******\x1b[0m\n");
		break;
		case 't':
		printf("\x1b[31m*******\n   *   \n   *   \n   *   \n   *   \n   *   \n   *   \x1b[0m\n");
		break;
		case 'c':
		printf("\x1b[31m*******\n*\n*\n*\n*\n*\n*\n*******\x1b[0m\n");
		break;
	}
	return 0;
 	
}
