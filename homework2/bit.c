#include<stdio.h>
int main()
{
	char ch;
	printf("Please enter a character\n");
	scanf("%c",&ch);

	int b;
	b  = ch;

	//printf("%d\n",b);
			
	int s;
	int y;
	int c=128;
	int i=0;

	struct position
	{
		char theposition[8];

	} position[8]=
			{
				{"eighth"},
				{"seventh"},
				{"sixth"},
				{"fifth"},
				{"fourth"},
				{"third"},
				{"second"},
				{"first"}
			};

	for(s = b;s >= 1;c = c / 2)
	{	
		y = s / c;
		s = s % c;	
		printf("The %s bit is %d\n",position[i].theposition,y);	
		//printf("(%d) (%d)",i,y);
		i=i+1;
	}

	return 0;
}
