#include <stdio.h>
#define SIZE 3
struct student_type
{   char name[10];
     int num;
     int age;
     char addr[15];
}stud[SIZE];
main()
{   int i;
     for(i=0;i<SIZE;i++)
	scanf("%s%d%d%s",stud[i].name,&stud[i].num,
			 &stud[i].age,stud[i].addr);
     save();
     display();
}
