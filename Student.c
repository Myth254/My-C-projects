#include <stdio.h>
#include <string.h>

int main()
{
   char name[5][50];
   int marks[10];
   int total=0,i,j;
   float average;

   for(i=0;i<5;i++)
   {
       printf("Enter your name of student %d: ",i+1);
       fgets(name[i],50,stdin);
       name[i][strcspn(name[i],"\n")]='\0';

       printf("Enter marks for student %d: ",i+1);
       scanf("%d",&marks[i]);
       getchar();

       total += marks[i];
   }
   average = (float)total/10;
   printf("\nStudents name and marks\n\n");
   for(i=0;i<5;i++)
   {
       printf("%s:  %d\n",name[i],marks[i]);
   }
   printf("\nThe total is %d\n",total);
   printf("The average is %.2f\n",average);

   printf("\n\tThe names in reverse\t");
  for(j=5;j>=0;j--)
  {
  	printf("%s\n",name[j]);
  }
   
    return 0;
}
