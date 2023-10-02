// Franco Gonzalez
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "pss.h"


int main(int argc, char *argv[]) {
    if(argc != 4){
        fprintf(stderr, "Uso: ./definir <diccionario> <llave> <definicion>\n");
        return 1;
    }

    char *fileName   = argv[1];
    char *key        = argv[2];
    char *definition = argv[3];

    FILE *fp = fopen(fileName, "r+");
    if(fp == NULL){
        perror(fileName);
        return 1;
    } 

    int lineSize = 81;
    char buf[lineSize+1];
    buf[lineSize] = 0;
    char *buf_r;

    /* numero de lineas */
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp)/lineSize;

    int line = hash_string(key)%fileSize;
    int initial_line = line;

    fseek(fp, line*lineSize, SEEK_SET);

    for(;;){

        buf_r = buf;
        if(fread(buf, sizeof(char), lineSize, fp) > 0){

            if(*buf_r == ' '){//si el primer valor es un espacio
                /*
                 volver puntero al inicio de la linea y copiar
                 <llave>:<def>...\n
                */
                fseek(fp, -lineSize, SEEK_CUR);
                fwrite(key, sizeof(char), strlen(key), fp);
                fputc(':', fp);
                fwrite(definition, sizeof(char), strlen(definition), fp);
                break;

            }else{//no es vacio
                while(*buf_r != ':' && *buf_r != 0)
                    buf_r++;
                *buf_r = 0;

                if( !strcmp(buf, key) ){//ya esta
                    fprintf(stderr, "La llave %s ya se encuentra en el diccionario\n", key);
                    fclose(fp);
                    return 1;
                }
            }
        }

        line = (line+1)%fileSize;  //avanzar
        if(line == initial_line){  // si es igual al primer valor entonces dio la vuelta
            fprintf(stderr,"%s: el diccionario esta lleno\n", fileName);
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
