//Get ten numbers from user. Store them in an array. Using functions, find sum, average and
product of the numbers. Obtain the sum value from the child, calculate and print the average in
the parent process. Use a child process to calculate and print the sum and product of the numbers.
Using pipes..//
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
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
int sum(int array2[])
{
        int sum = 0;
        for(i=0;i<10;i++)
        {
                sum = sum + array2[i];
        }
        return sum;
}
int main()
{
    int array1[10];
    int sum1,prod1;
    int p2[2];
    printf("enter the elements of the array\n");
     for(i=0;i<10;i++)
    {
      scanf("%d",&array1[i]);
    }
    if(pipe(p2)== -1 )
    {
      return -1;
    }
    printf("now we created 1 pipe\n ");
    int pid = fork();
    if(pid <0){return -1;}
    if(pid == 0)
    {
      close(p2[0]);
     // read(p2[0],&x,sizeof(int));
      sum1 = sum(array1);
      write(p2[1],&sum1,sizeof(sum1));
	        prod1 = prod(array1);
      printf("the sum of the elements %d\n",sum1);
      printf("the product of the elements is %d\n",prod1);
    }
    else
    {
            wait();
            close(p2[1]);
            int avg,x;
            read(p2[0],&x,sizeof(x));
            avg = x/10;
            printf("the average is %d\n",avg);

    }

}