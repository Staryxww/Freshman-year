#include<stdio.h>
int main()
{
        int number;
        printf("please enter a number\n");
        scanf("%d",&number);
	if(number>1)
	{
		int m;
		for(m = number;m>=2;m--)

 		{	
			int x;
       			int n;
		 	int judgenumber=0;
			for(n = 2; n<= m-1;n++)
        	{
                	x  = m % n;
                	if(x==0) judgenumber=1;

        	}

        	if(judgenumber!=1) printf("%d ",m);

		}
	}
	else
	printf(" \n");
        return 0;
}

