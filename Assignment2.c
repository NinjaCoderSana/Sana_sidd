#include<stdio.h>
#include<string.h>
int main() {

 FILE *fptr;
 char code[1000];
    int i,j,opercount[20]={0};
    char operators[20][3]={
        "++","--","==","!=",">=",
        "<=","&&","||","+=","-=",
        "*=","/=","%=","&=","|=","^="
    };
 fptr=fopen("text.c","r");
 if(fptr==NULL) {
  printf("File can not open\n");
  return 0;
 }
 fread(code,1000,1,fptr);
    fclose(fptr);
    for(i=0;i<strlen(code);i++){
        for(j=0;j<20;j++){
            if(code[i]==operators[i][j] && code[i+1]==operators[j][1]){
                opercount[j]++;
            }
        }
    }
    
        for(i=0;i<20;i++){
            if(opercount[i]>0){
                printf("operation: %s, occurs : %d \n",operators[i],opercount[i]);
            }
        }
    return 0;
    }