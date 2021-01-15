#include<stdio.h>
#include<string.h>

#define SIZE 30

int main()
{
	char str[SIZE],b[SIZE];
	int i,n=0;
	printf("enter the string\n");
	fgets(str,sizeof(str),stdin);
	for(i=1;str[i]!='\0';i++)
		{
		n++;
		}
	printf("the number of character in the string is %d\n",n);
		return 0;
}		
	
	

