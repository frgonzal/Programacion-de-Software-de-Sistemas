//Franco González Leiva
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elim.h"

unsigned int contar_espacio(char *str, unsigned int ns, char *pat, unsigned int np);
int mystrcmp(char *str1, char *str2);

void eliminar(char *str, char *pat) {
    unsigned int ns = strlen(str);
    unsigned int np = strlen(pat);
    if(ns < np || !np)//casos en los que no tiene sentido seguir
        return;

    char *ini = str;
    char *end = str+np;
    char *end_str = str+ns;

    while(end <= end_str){
        if(*ini==*pat && mystrcmp(ini+1, pat+1)){
            ini+=np;
            end+=np;
        }else{
            *str = *ini;
            str++;
            ini++;
            end++;
        }
    }
    while(ini<=end_str){
        *str=*ini;
        str++;
        ini++;
    }
}

char *eliminados(char *str, char *pat) {
    unsigned int ns = strlen(str);
    unsigned int np = strlen(pat);
    char *str2;
    if(ns<np || !np ){
        str2 = (char*)malloc(ns+1);
        strcpy(str2, str);
        return str2;
    }
    str2 = (char*)malloc(contar_espacio(str, ns, pat, np)*sizeof(char));
    char *aux = str2;

    char *ini = str;
    char *end = str+np;
    char *end_str = str+ns;

    while(end<=end_str){
        if(*ini==*pat && mystrcmp(ini+1, pat+1)){
            ini += np;
            end += np;
        }else{
            *aux = *ini;
            aux++;
            ini++;
            end++;
        }
    }
    while(ini<end_str){
        *aux=*ini;
        aux++;
        ini++;
    }
    *aux=0;
    return str2;
}

unsigned int contar_espacio(char *str, unsigned int ns, char *pat, unsigned int np){
    unsigned int contador = 0;
    char *end     = str+np;
    char *end_str = str+ns;
    while(end<=end_str){
        if(*str==*pat && mystrcmp(str+1, pat+1)){
            str+=np;
            end+=np;
        }else{
            contador++;
            str++;
            end++;
        }
    }
    return contador + np;
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