#include <stdio.h>
#include <stdlib.h>
  
typedef struct {
    char c; /* Observe que primero viene el caracter */
    int n;
} U;
  
int main() {
    U *u= malloc(sizeof(U));
    printf("%p\n", u);
    printf("%ld\n", sizeof(U));
    printf("desplazamiento de c=%ld\n", (char*)&u->c-(char*)u);
    printf("desplazamiento de n=%ld\n", (char*)&u->n-(char*)u);
}
