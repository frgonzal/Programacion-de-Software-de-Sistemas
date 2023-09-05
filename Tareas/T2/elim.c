//Franco González Leiva
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elim.h"
unsigned int contar_espacio(char *str, char *pat, unsigned int np);

void eliminar(char *str, char *pat){
    unsigned int np = strlen(pat);
    if(!np)//caso en el que no tiene sentido seguir
        return;
    char *ini = str;
    while(*ini){
        if(*ini==*pat && !strncmp(ini+1, pat+1, np-1))
            ini+=np;
        else
            *str++ = *ini++;
    }
    *str = 0;
}

char *eliminados(char *str, char *pat){
    unsigned int np = strlen(pat);
    char *str2;
    if(!np ){
        str2 = (char*)malloc(strlen(str)+1);
        strcpy(str2, str);
        return str2;
    }
    str2 = (char*)malloc(contar_espacio(str, pat, np)*sizeof(char));
    char *aux = str2;
    while(*str){
        if(*str==*pat && !strncmp(str+1, pat+1, np-1))
            str += np;
        else
            *aux++ = *str++;
    }
    *aux=0;//final de str2
    return str2;
}

unsigned int contar_espacio(char *str, char *pat, unsigned int np){
    unsigned int contador = 1;
    while(*str){
        if(*str==*pat && !strncmp(str+1, pat+1, np-1))
            str+=np;
        else{
            contador++;
            str++;
        }
    }
    return contador;
}