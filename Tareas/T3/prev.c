//Franco Gonzalez
#include <stddef.h>

#include "prev.h"

void asignarPrev(Nodo *t, Nodo **pprev) {
    //Caso base
    if(t == NULL) return;

    //mirar izq
    asignarPrev(t->izq, pprev);

    //asignar nodo
    t->prev = *pprev;
    t->prox = NULL;
    //mover prev
    *pprev = t;

    //mirar der
    asignarPrev(t->der, pprev);

    //asignar prev
    if(t->prev != NULL){
        (t->prev)->prox = t;
    }
}
