#include<stdio.h>
int main()
{
	int number;
        printf("please enter a number\n");
	scanf("%d",&number);

	int x;
	int n;
	int judgenumber=0;
	if(number>1)
	{
       		 for(n = 2; n<= number-1;n++)
        	{
        	        x  = number % n;
			if(x==0) judgenumber=1;
	
		}

		if(judgenumber==1)
		{
			printf("no\n");
		}
		else
		{
			printf("yes\n");
		}
	}
	else
		printf("no\n");

	return 0;
}

