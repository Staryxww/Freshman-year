#include<stdio.h>
int main()
{

	typedef struct {
		int _char=1;
		int _int=2;
		int _longint=3;
		int _float=4;
		int _double=5;
		int _longdoube=6;
	           	}type;

	printf("please type in whose you want like the example:_int");
	scanf("%s",&type);
	switch(type)
	{
		case 1:
			printf("The size of char is %d bytes\n",sizeof(char));
			break;
		case 2:
		        printf("The size of int is %d bytes\n",sizeof(int));
                        break;
		case 3:
			printf("The size of long int  is %d bytes\n",sizeof(long int ));
                        break;
		case 4:
			printf("The size of float  is %d bytes\n",sizeof(float));
                        break;
		case 5:
			printf("The size of double is %d bytes\n",sizeof(double));
                        break;
		case 6:
			printf("The size of long double is %d bytes\n",sizeof(long double));
                        break;
	}
	return 0;
}



