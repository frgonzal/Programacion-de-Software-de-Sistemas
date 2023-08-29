#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elim.h"

unsigned int contar_espacio(char *str, unsigned int ns, char *pat, unsigned int np);

void eliminar(char *str, char *pat) {
    unsigned int ns = strlen(str);
    unsigned int np = strlen(pat);
    if(ns < np || !np)//casos en los que no tiene sentido seguir
        return;
    char *end     = str+np;
    char *end_str = str+ns;

    while(end <= end_str){
        if(!strncmp(str, pat, np)){
            memmove(str, str+np, strlen(str));
            end_str = str+strlen(str);
        }else{
            str++;
            end++;
        }
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
        if(!strncmp(ini, pat, np)){
            ini += np;
            end += np;
        }else{
            *aux = *ini;
            aux++;
            ini++;
            end++;
        }
    }
    if(ini<=end_str)
        strcpy(aux, ini);
    return str2;
}

unsigned int contar_espacio(char *str, unsigned int ns, char *pat, unsigned int np){
    unsigned int contador = 0;
    char *end     = str+np;
    char *end_str = str+ns;
    while(end<=end_str){
        if(!strncmp(str, pat, np)){
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