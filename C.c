#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mystrcmp(char *str1, char *str2);
void eliminar(char *str, char *pat);
char *eliminados(char *str, char *pat);
void mystrcpy(char *str1, char *str2);


void mov_n(char *str, unsigned int n);

int main(int argc, char **argv){
    char *p = "ho";
    char *q = "holaaa";
    printf("%d \n", strncmp(p, q, strlen(q)));

    return 0;
    //printf("%d\n",(strlen(p)+1)*sizeof(char));
    //eliminar(p,"1");
    //printf("%s \n",p);
    //*(p+4) = 0;
    //eliminar(p,"la");
    //printf("%d\n",strcmp("hola","hola"));//0 si son iguales
    //printf("%s, %d\n",p,strlen(p));
    //printf("%d\n",strcmp("hola","holaaaaa"));
}

void eliminar(char *str, char *pat) {
    unsigned int ns = strlen(str);
    unsigned int np = strlen(pat);
    if(ns < np || !np || !ns)//casos en los que no tiene sentido seguir
        return;

    char *end     = str+np;
    char *end_str = str+ns;

    while(end <= end_str){
        if(mystrcmp(str, pat)){
            printf("%s\n",str);
            printf("%s\n",end);
            strcpy(str, end);
            end_str -= np;
        }else{
            str++;
            end++;
        }
    }
}

char *eliminados(char *str, char *pat) {
    unsigned int ns = strlen(str);
    unsigned int np = strlen(pat);

    if(ns < np || !np){
        char* p = malloc((ns+1)*sizeof(char));
        return strcpy(p, str);
    }

    char str2[ns+1];
    strcpy(str2, str);

    char *aux = str2;
    char *end = str2+np;
    char tmp = *end;

    while(*end && *aux){
        tmp = *end;
        *end = 0;

        if(!strcmp(aux, pat)){
            *end = tmp;
            mov_n(aux, np);
        }else if(strcmp(aux, pat) < 0){
            break;
        }else{
            *end = tmp;
            aux++;
            end++;
        }
    }
    if(!strcmp(aux, pat)){
        *aux = 0;
    }

    char *p = malloc((strlen(str2)+1)*sizeof(char));
    return strcpy(p, str2);
}

void mov_n(char* str, unsigned int n){
    char *end = str+n;
    while(*end){
        *str = *end;
        str++;
        end++;
    }
    *str = *end = 0;
}

int mystrcmp(char *str1, char *str2){
    while(*str2){
        if(*str1!=*str2)
            return 0;
        str1++;
        str2++;
    }
    return 1;
}

void mystrcpy(char *str1, char *str2){
    while(*str2){
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = 0;
}