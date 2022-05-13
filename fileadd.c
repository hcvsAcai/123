#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *in;
    if ((in = fopen("filehw1.txt","rb")) == NULL)
        exit(0);
    char buffer[5];
    fread(&buffer, 5, 1, in);
    int col, raw;char aa;
    sscanf(buffer, "%d %c %d ", &raw, &aa, &col);
    double **data;
    data = (double**)malloc(sizeof(double*)*raw);
    int i = 0,j = 0;
    while (i < raw)
        data[i++] = (double*)malloc(sizeof(double)*col);
    double temp = -1;
    double ans = 0;
    char coldata[256];
    char *str;
    i = 0; j = 0;
    while (!feof(in)){
        fgets(coldata, 256, in);
        while ((temp = strtod(coldata, &str))){
            data[i][j] = temp;
            ans += data[i][j++];
            sscanf(str, "%c %s",&aa ,coldata);
            if (j >= col) break;
        }
        i++;j = 0;
        if (i >= raw) break;
    }
    printf("%f" ,ans);
    fclose(in);
}
