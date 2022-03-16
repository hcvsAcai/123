#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
int countword();
int countwordtestversion();
int main(){
    char s[] = "A B C D A AB";
    char *ptr[100];
    int i,size;
    printf("%d",countword(s));
}
int countword(char *s){
    char *str2 = " ",*p;
    int count =  0;
    if(s != "\0"){
        count++;
        char *ptr[100];
        char *p = strtok(s,str2);
        ptr[0] = p;
        int i,ok = 1;
        int n = 0;
        for(i = 1; p != NULL; i++){
            p = strtok(NULL,str2);
            ptr[i] = p;
            n = 0;
            if(p == NULL) continue;
            while(n < i && ok){
                if(strcmp(ptr[i],ptr[n++]) == 0)
                    ok = 0;
            }
            if(ok) count++;
        }
    }
    return count;
}
int countwordstestversion(char *s){
    char *str2 = " ",*p;
    char *data = (char*)calloc(strlen(s),sizeof(char));
    sprintf(data,"%s%c",p,'/');
    int count = 1;
    while(p != NULL){
        p = strtok(NULL,str2);
        if(p == NULL) break;
        char *cg = (char*)calloc(strlen(p),sizeof(char));
        sprintf(cg,"%s%c",p,'/');
        if(strstr(data,cg) == NULL) {    
            sprintf(data,"%s%s",data,p);
            count++;
        }
    }
    return count;
}
