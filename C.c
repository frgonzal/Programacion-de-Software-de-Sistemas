#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void eliminar(char *str, char *pat);
char *eliminados(char *str, char *pat);

void mov_n(char *str, unsigned int n);

int main(int argc, char **argv){
    char p[] = "hola";
    //printf("%d\n",(strlen(p)+1)*sizeof(char));
    strcpy(p, "");
    //printf("%s \n",p);
    //*(p+4) = 0;
    //eliminar(p,"la");
    //printf("%d\n",strcmp("hola","hola"));//0 si son iguales
    //printf("%s, %d\n",p,strlen(p));
    //printf("%d\n",strcmp("hola","holaaaaa"));
    printf("%s\n",p);

    return 0;
}

void eliminar(char *str, char *pat) {
    unsigned int np = strlen(pat);
    if(strlen(str) < np || !np)
        return;

    char *end = str+np;
    char tmp = *end;

    while(*end){
        tmp = *end;
        *end = 0;
        if(!strcmp(str, pat)){
            *end = tmp;
            mov_n(str, np);
        }else{
            *end = tmp;
            str++;
            end++;
        }
    }
    if(!strcmp(str, pat)){
        *str = 0;
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