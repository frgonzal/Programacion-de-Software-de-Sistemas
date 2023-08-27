#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elim.h"

void eliminar(char *str, char *pat) {
    long long ns = strlen(str);
    long long np = strlen(pat);
    if(ns < np || !np)//casos en los que no tiene sentido seguir
        return;

    char *end = str+np;
    char *end_str = str+ns+1;
    char tmp;

    while(end < end_str){
        tmp = *end;
        *end = 0;
        if(!strcmp(str, pat)){
            *end = tmp;
            strcpy(str, end);
            end_str -= np;
        }else{
            *end = tmp;
            str++;
            end++;
        }
    }
}

char *eliminados(char *str, char *pat) {
    long long ns = strlen(str);
    long long np = strlen(pat);

    if(ns<np || !np){
        char* p = malloc(ns+1);
        strcpy(p, str);
        return p;
    }

    char str2[ns+1];
    char *aux = str2;

    char *ini = str;
    char *end = str+np;
    char *end_str = str+ns+1;
    char tmp;

    while(end<end_str){
        tmp = *end;
        *end = 0;

        if(!strcmp(ini, pat)){//son iguales
            *end = tmp;

            ini += np; //avanzar np
            end += np;
        }else{
            *end = tmp;

            *aux = *ini; // copiar y continuar;
            aux++;
            ini++;
            end++;
        }
    }

    if(strcmp(ini, pat))//revisar lo que falta
        strcpy(aux, ini);
    else
        *aux = 0;

    char *p = malloc(strlen(str2)+1);
    strcpy(p, str2);
    return p;
}
