#include <stdio.h>


typdef struct queue Queue;

Queue *makeQueue();
void destroyQueue(Queue *q);
void put(Queue *q, void *ptr);
void *get(Queue *q);
void *peek(Queue *q);
int emptyQueue(Queue *q);
int queueLength(Queue *q);


void modificar(char *nom_dic, char *palabra, char *def, int n lin, int ancho);

void quicksort(Queue *q, int (*cmp)(void *ptr1, void *ptr2));

int main(){
    modificar("","","","");
    return 0;
}

void modificar(char *nom_dic, char *palabra, char *def, int n lin, int ancho){
    char buff[ancho+1];
    FILE *f = fopen(nom_dic, "r+");

    /*  Si no puede leer ancho de 1 elemento entonces llego al final; */
    while(fread(buff, 1, ancho, f) > 0){
        char *c = buff;
        whle(*c != ':')
            c++;
        *c = 0;

        if (strcmp(buff, palabra) == 0){
            fseek(f, -ancho + strlen(palabra) + 1, SEEK_CUR);
            fputs(def, f);

            while(fgetc(f) != ':'){
                /* Las funciones siempre mueven el cursor */
                fseek(f, -1, SEEK_CUR);
                fputc(' ', f);
            }
        }

    }
    fclose(f);
}


void quicksort(Queue *q, int (*cmp)(void *ptr1, void *ptr2)){
    /*
    primero en salir es pivote 
    hacer dos colas que sean el resultado de particionar la cola
    llamada recursiva con las 2 colas
    agregar a la colar original elementos en orden
    */
    if( !emptyQueue(q) ){

        void *pivote = get(q);

        Queue *min = makeQueue();
        Queue *max = makeQueue();

        while(!emptyQueue(q)){
            void *s = get(q);            
            if( (*cmp)(s, pivote) < 0 ) put(min, s);
            else put(max, s);
        }

        quicksort(min, cmp);        
        quicksort(max, cmp);        

        while(!emptyQueue(min)){
            void *elem = get(min);
            put(q, elem);
        }

        put(pivote, q);

        while(!emptyQueue(max)){
            void *elem = get(max);
            put(q, elem);
        }
        destroyQueue(min);
        destroyQueue(max);
    }
}