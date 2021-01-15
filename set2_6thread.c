#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define LIMIT 10

struct for_FFF 
{
    char string[LIMIT];
    int option;
    int length;
}; typedef struct for_FFF FFF_t;

int strCompare(char buffer[], int option, int str_length)
{    
    int ret_val = 0;
    char str1[5] = "msis";
    char str2[5] = "sois";
    char end[4] = "FFF";

    switch (option) {
    case 0:
        for(int i = 0; i < str_length-3; i++) {
            if(str1[i] == buffer[i]){
                ret_val++;
            }  
        }
        if(ret_val == 4)  
            printf("Match found for 'MSIS'\n");
        else {
            printf("Match false for option '0'\n");
        }
        ret_val = 0;
        break;
    
    case 1:
        for(int j = 0; j < str_length-3; j++) {
            if(str2[j] == buffer[j]){
                ret_val++;
            }  
        }
        if(ret_val == 4)  
            printf("Match found for 'SOIS'\n");
        else { 
            printf("Match false for option '1'\n");
        }
        ret_val = 0;
        break;

    default:
        printf("Something went wrong\n");
        break;
    }
    printf("Length of string = %d\n", str_length-3);
}

void *routine(FFF_t *argt)
{
    strCompare(argt->string, argt->option, argt->length);
}

int main(int argc, char *argv[]) 
{
    FFF_t args;                 //struct to pass multiple arguments to a single thread 
    int op_val = atoi(argv[2]); //Converting the option value from int_string to actual int
    int len = strlen(argv[1]);  //Finding out the length of string
    
    //Putting it into argument passing struct
    args.option = op_val;       
    args.length = len;          
    strcpy(args.string, argv[1]);  
    
    //creating a thread to compare string wrt the option value
    pthread_t thread;
    pthread_create(&thread, NULL, routine, &args);
    pthread_join(thread, NULL);
        
    return EXIT_SUCCESS;
}