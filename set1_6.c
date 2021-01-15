#include<stdio.h>
#include<stdlib.h>
 struct date
 {
  int day;
  int month;
  int year;
 };
typedef struct date Date1;

int main(int argv,char *argc[])
{
 Date1 date_1;
 Date1 date_2;
// printf("Enter the number of the args");
// scanf("%d",&argv);
 if(argv>=8)
 {
  printf("enter the correct format of ./prog a0 a1 a2 a3 a4 a5");
 }
else
{
 date_1.day = atoi(argc[1]);
 date_1.month = atoi(argc[2]);
 date_1.year = atoi(argc[3]);
 date_2.day = atoi(argc[4]);
 date_2.month = atoi(argc[5]);
 date_2.year = atoi(argc[6]);
 printf("the latter date is %d/%d/%d ",date_2.day,date_2.month,date_2.year);
}
}