#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count = 0;
int j,i;
int count_char(char str2[])
{
        int i;
        for(i=0;i<=strlen(str2);i++)
        {
                if(str2[i]!=' ' && str2[i]!='\0')
                {
                count++;
            }
        }
        return count;
}
int main()
{
        FILE *ptr,*ptr1;
        //char *strlwr(char str[50]);
        //int count =0;
        //ptr = fopen("main.txt","r+");
        //fgets(str,50,ptr);
        int pid = fork();
        if(pid == 0)
                {
                        char str[50];
                        ptr = fopen("second.txt","r+");
                        fgets(str,50,ptr);
                        for(j=0;j!='\0';j++)
                        {
                                if(str[j]=='a'||str[j]=='e'||str[j]=='o'||str[j]=='i'||str[j]=='u'||str[j]=='A'||str[j]=='E'||str[j]=='O'||str[j]=='I'||str[j]=='U')
                                {
                                count++;
                                }
                        }
                        printf("the number of the vowels is %d\n",count);
                   fclose(ptr);
                }



                else
                {
					                wait();
                int x;
                char str1[50];
                ptr1 = fopen("second.txt","r+");
                fgets(str1,50,ptr1);
                x = count_char(str1);
                printf("the number of the characters are %d\n",x-1);
                fclose(ptr1);

        }
}
