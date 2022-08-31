#include<stdio.h>

int func(int a, int b)
{
	if(b==0)
		return 0;
	if(b==1)
		return a;
	return a + func(a,b-1);
}
int main ()
{
	int out;
	out = func(3,8);
	printf("%d",out);
	return 0;
}
