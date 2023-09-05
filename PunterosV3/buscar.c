#include <stdio.h>
#include <string.h>

typedef struct nodo {
    char *str;
    struct nodo *prox;
} Nodo;


int buscar(Nodo *cabeza, char *pal) {
    while (cabeza!=NULL) {
        if (strcmp(cabeza->str, pal)==0)
            return 1;
        cabeza= cabeza->prox;
    }
    return 0;
}

int main() {
    Nodo nodo_pedro= { "pedro", NULL };
    Nodo nodo_juan= { "juan", &nodo_pedro };
    Nodo nodo_diego= { "diego", &nodo_juan };

    printf("%d\n", buscar(&nodo_diego, "juan"));
    printf("%d\n", buscar(&nodo_diego, "jorge"));
    return 0;
}
