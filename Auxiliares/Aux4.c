#include <stdio.h>

typedef struct nodo {
    int *info;
    struct nodo *sgte;
} Nodo;

typedef struct cola {
    typedef Nodo *first;
    typedef Nodo *last;
} Cola;

//void append(Nodo **pa, Nodo *b);


Cola *creaCola();
void put(Cola *q, int *n);
int *get(Cola *q);
void freeCola(Cola *q);


int main(){
    return 0;
}

//P1
void append(Nodo **pa, Nodo *b){//si 
    Nodo *a = *pa;

    if(a == NULL)
        a = b;
        // para esto necesitamos el puntero original (con **pa)
        // en caso contrario estariamos modificando la
        // copia y seguiria vacio el original
        // (solo necesario por ese caso)
    else
        append(&(a->sgte), b);
}



//P2
Cola *creaCola(){
    Cola *C = malloc(sizeof(Cola));
    C->first = NULL;
    C->last = NULL;
    return C;
}
void put(Cola *q, int *x){
    Nodo *n = malloc(sizeof(Nodo));
    n->info = x;
    n->sgte = NULL;
    if(q->first == NULL){//lista vacia
        q->first = n;
        q->last = n;
        return;
    }
    Nodo *pu = q->last //puntero al ultimo
    pu->sgte = n;      //modificamos lo siguiente del ultimo
    q->last = n;       //modificamos el ultimo puntero
}
int *get(Cola *q){
    if(q->first == NULL)//lista vacia
        return NULL;

    Nodo *p = q->first;
    int *resultado = p->info;  //guardar result
    q->first = p->sgte;        //primero apunta al sig

    if(p-sgte==NULL)//lista con solo un elemento
        q->last=NULL;

    free(p);
    return resultado;
}

void freeCola(Cola *q){
    if(q->primero==NULL){
        free(q);
        return;
    }   
    Nodo *n = q->first;
    q->first = n->sgte; //primero apunta al sig
    free(n);            //liberar primer elemento
    freeCola(q);
}