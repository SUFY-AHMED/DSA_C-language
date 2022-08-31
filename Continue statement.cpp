#include<stdio.h>

int main()
{
	int i, age;
	for (i=0 ; i<=10 ; i++)
	{
		printf("Enter your age : ");
		scanf("%d", &age);
		if(age>10)
		{
			continue;
		}
		printf("Okay, Good Morning Toddler!\n");
		printf("What do you want to have in your lunch ?\n");
	}
	return 0;
}
