#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elim.h"

int contar_espacio(char *str, int ns, char *pat, int np);

int mystrcmp(char *str, char *str2);
void mystrcpy(char *str1, char *str2);

void eliminar(char *str, char *pat) {
    unsigned int ns = strlen(str);
    unsigned int np = strlen(pat);
    if(ns < np || !np || !ns)//casos en los que no tiene sentido seguir
        return;

    char *end     = str+np;
    char *end_str = str+ns;

    while(end <= end_str){
        if(mystrcmp(str, pat)){
            memmove(str, str+np, strlen(str));// ilegal??
            end_str = str+strlen(str);
        }else{
            str++;
            end++;
        }
    }
}

char *eliminados(char *str, char *pat) {
    int ns = strlen(str);
    int np = strlen(pat);
    char *str2;

    if(ns<np || !np ){
        str2 = (char*)malloc(ns+1);
        strcpy(str2, str);
        return str2;
    }

    str2 = (char*)malloc(ns+1);
    char *aux = str2;

    char *ini = str;
    char *end = str+np;
    char *end_str = str+ns;

    while(end<=end_str){
        if(mystrcmp(ini, pat)){//son iguales
            ini += np; //avanzar np
            end += np;
        }else{
            *aux = *ini; // copiar y continuar;
            aux++;
            ini++;
            end++;
        }
    }
    while(ini<=end_str){
        *aux = *ini;
        ini++;
        aux++;
    }
    return str2;

}

int contar_espacio(char *str, int ns, char *pat, int np){
    int contador = 1;

    char *end = str+np;
    char *end_str = str+ns;
    char tmp;

    while(end<=end_str){
        tmp = *end;
        *end = 0;
        if(!strcmp(str, pat)){
            *end = tmp;
            str+=np;
            end+=np;
        }else{
            contador++;
            *end = tmp;
            str++;
            end++;
        }
    }
    return contador;
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