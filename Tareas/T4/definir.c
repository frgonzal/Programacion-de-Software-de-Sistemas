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

    char *file = argv[1];
    char *key  = argv[2];
    char *def  = argv[3];
    FILE *f = fopen(file, "r+");
    if(f == NULL){
        perror(file);
        return 1;
    } 

    int lineSize = 81;

    char buf[lineSize+1];
    char *buf_r;

    fseek(f, 0, SEEK_END);

    int fileSize = ftell(f);
    if(fileSize%(81*sizeof(char)) != 0){
        fprintf(stderr, "%s: linea 4 de tamaño incorrecto\n", file);
        return 1;
    }
    fileSize = fileSize/(81*sizeof(char));

    int pos = hash_string(key)%fileSize;
    int pos_cpy = pos;

    for(;;){
        buf_r = buf;

        fseek(f, pos*lineSize, SEEK_SET);
        fread(buf, sizeof(char), lineSize, f);
        buf[lineSize] = 0;
        fseek(f, -lineSize, SEEK_CUR);

        if( *buf_r == ' ' ){//vacio
            fwrite(key, sizeof(char), strlen(key), f); //copiar llave
            fwrite(":", sizeof(char), 1, f);
            fwrite(def, sizeof(char), strlen(def), f); //copiar definicion
            break;

        }else{//no es vacio
            while(*buf_r != ':')
                buf_r++;
            *buf_r = 0;   

            if( !strcmp(buf, key) ){//ya esta
                fprintf(stderr, "La llave %s ya se encuentra en el diccionario\n", key);
                return 1;
            }

            pos = (pos+1)%fileSize;
            if(pos == pos_cpy){ // si es igual al primer valor entonces dio la vuelta
                fprintf(stderr,"%s: el diccionario esta lleno\n", file);
                return 1;
            }
        }
    }
    fclose(f);
    return 0;
}
