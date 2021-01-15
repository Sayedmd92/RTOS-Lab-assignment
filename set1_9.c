#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main(int argc, char *argv[]) 
{
    int op_val = atoi(argv[2]);
    int len = strlen(argv[1]);

    char string[len];
    
    strcpy(string, argv[1]);
    strCompare(string, op_val, len);
        
    return EXIT_SUCCESS;
}