#include <stdio.h>


//P1
typedef struct nodo {
    int x;
    struct nodo *izq, *der;
} Nodo;

void podar(Nodo **pa, int y){
    if(*pa == NULL)
        return;
    Nodo *nodo_a = *pa;
    if(nodo_a->x <= y)
        podar(&nodo_a -> der, y);
    else{
        podar(&nodo_a->izq, y);
        *pa = nodo_a -> izq;
    }
}


//P2
typedef struct nodo2 {
    char c;
    struct nodo *izq, *der;
} Nodo2;

int reemplazarNodoK(Nodo2 **pa, int k, Nodo2 *b){
    //retorna min(k, tamaño arbol)
    if (*pa == NULL)
        return 0;    
    Nodo *nodo_actual = *pa;
    int tam_izq = reemplazarNodoK(&nodo_actual->izq, k, b);
    if (tam_izq == k)
        return k;
    else if(tam_izq < k){
        if(tam_izq == k - 1){
            *pa = b;
            return k;
        }else{
            int tam_der = reemplazarNodoK(&nodo_actual->der, k - tam_izq - 1, b);
            return tam_izq + tam_der + 1; //
        }
    }else
        return -1;
}


int main(){
    return 0;
}