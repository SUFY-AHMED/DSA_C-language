#include<stdio.h>
//Break and continue statements in C language
int main ()
{
	int age;
	for (int i=0 ; i<=10 ; i++)
	{
		printf("%d\nEnter your age:", i);
		scanf("%d",& age);
		if(age>10)
		{
			break;
		}
	}
	return 0;
}
