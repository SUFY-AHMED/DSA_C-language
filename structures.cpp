#include<stdio.h>
#include<conio.h>
#include<string.h>//mandatory when dealing with strings
//Storing user's data using structures in C 

struct stud
{
	int id;
	char name[30];
	int marks;
};

int main()
{
	typedef struct stud s1, s2, s3, s4;
	s1.name = 'Sufyan';
	s2.name = 'Misbah';
	s3.name = 'Ahmed';
	
	s1.id = 112;
	s2.id = 125;
	s3.id = 94;
	
	s1.marks = 96.54;	
	s2.marks = 96.55;
	s3.marks = 96.87;
	
	printf("Student 1 name = %s\nStudent 1 id = %d\nStudent 1 marks = %f\n");
	printf("Student 2 name = %s\nStudent 2 id = %d\nStudent 2 marks = %f\n");
	printf("Student 3 name = %s\nStudent 3 id = %d\nStudent 3 marks = %f\n");
	return 0
}
