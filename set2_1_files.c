/* Get ten numbers from user. Store them in an array. Using functions, find sum, average and
product of the numbers. Obtain the sum value from the child, calculate and print the average in
the parent process. Use a child process to calculate and print the sum and product of the numbers.
Using files */

#include<stdio.h>
#include<stdlib.h>
int i;
int prod(int array2[])
{
        int prod = 1;
        for(i=0;i<10;i++)
        {
                prod = prod * array2[i];
        }
        return prod;
}
int main()
{
 int array1[10] ;
 FILE *fp;
 fp = fopen("numbers.txt","w+");
 printf("entering the file ");
 printf("enter the elements of the array with 10 only ");
 for(i=0;i<10;i++)
 {
  scanf("%d",&array1[i]);
 }
 int id = fork();
 if(id == 0)
 {
        int sum =0,prod = 1;
        for(i=0;i<10;i++)
        {
                sum += array1[i];
                prod = prod * array1[i];
        }
        //printf("the sum is %d\n",sum);
        //printf("the product is %d\n",prod);
        exit(sum);
 }
 else{
        int childval = -1;
         wait(&childval);
         int avg,sum1;
         sum1 = childval/255;
         avg = sum1/10;
         //printf("the average of the elements is %d",avg);
                 fclose(fp);
				  int array3[10] ;
 fp = fopen("numbers.txt","r");
 printf("\n----reading from the file----\n");
printf("the array elements are \n");
for(i=0;i<10;i++)
{
        printf("%d\t",array1[i]);
}
 printf("the sum is %d\n",sum1);
// printf("the product is %d\n",prod);

 int prod2 = prod(array1);
 printf("the product is %d\n",prod2);
 printf("the average of the elements is %d",avg);
 fclose(fp);
 }
 return 0 ;
}