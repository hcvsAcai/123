#include<stdio.h>
#include<ctype.h>
#include<string.h>
char* mystrtarns(char *s){
    char *re = s;
    while(*s != '\0'){
        if(isalpha(*s) > 0){
            if(islower(*s) > 0){
                (*s) = toupper(*s);
            }else if(isupper(*s) > 0){
                (*s) = tolower(*s);
            }
        }
        s++;
    }
    return re;
}
char* mystrrev(char *s){
    int i = 0;
    int size = strlen(s) - 1;
    for(i = 0; i < strlen(s) / 2; i++,size--){
        char ch = s[size]; s[size] = s[i]; s[i] = ch;
    }
    return s;
}
int countwords(char *s){
    char *str2 = " ",*ptr[100];
    char *p = strtok(s,str2);
    ptr[0] = p;
    int i,count = 1,n = 0;
    short ok = 1;
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
    return count;
}
int main(){
    char s[] = "sad FFF FFF1";
    //char *g = mystrrev(s);
    printf("%d",countwords(s));
}
