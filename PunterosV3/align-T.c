#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n;
    char c;
} T;

int main() {
    T *t= malloc(sizeof(T));
    printf("%p\n", t);
    printf("%ld\n", sizeof(T));
    printf("desplazamiento de c=%ld\n", (char*)&t->c-(char*)t);
    printf("desplazamiento de n=%ld\n", (char*)&t->n-(char*)t);
}

