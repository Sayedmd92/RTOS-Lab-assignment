#include <stdio.h> 
#include <string.h> 
 
int main() 
 
{ 
  FILE *fe; 
  FILE *fo; 
  FILE *fg; 
  int i; 
  int j,l; 
  char ch; 
  char tmp[100] ; 
 
 fo = fopen("oddfile.txt","a"); 
 if (fo == NULL) 
 { 
  perror("ODDFILE"); 
 } 
 fclose(fo); 
 
 fe = fopen("evenfile.txt","a"); 
 if (fe == NULL) 
 { 
  perror("EVENFILE"); 
 } 
 fclose(fe); 
 
 fg = fopen("generalfile","r"); 
 if (fg == NULL) 
 { 
  perror("GENERALFILE"); 
 } 
 
 while((ch = fgetc(fg))!=EOF) 
 { 
    if (ch != '\n' && ch != '\t' && ch != ' ')
    { 
        tmp[i] = ch;
        i++; 
    } 
 
 
    else  
    { 
        printf("%s",tmp); 
        l =strlen(tmp); 
        j = l % 2; 
        if (j == 0) 
        { 
          fe = fopen("evenfile.txt","ab"); 
            if (fe == NULL) 
            { 
                perror("EVENFILE"); 
             }   
 
         fwrite(&tmp,sizeof(tmp),1,fe); 
         fclose(fe); 
 
        } 
 
        else 
        { 
            fo = fopen("oddfile.txt","ab"); 
            if (fo == NULL) 
             { 
                perror("ODDFILE"); 
             } 
         fwrite(&tmp,sizeof(tmp),1,fo); 
         fclose(fo); 
 
        } 
    } 
 
 } 
 fclose(fg);
 
}