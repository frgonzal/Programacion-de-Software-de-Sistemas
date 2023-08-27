#include <stdio.h>
#include <stdlib.h>

//sizeof(type) entrega numero de bytes
//

int bits1(unsigned int n){
    int contador = 0;

    //for(int i=0; i<sizeof(int)*8; i++){
        //contador += (n<<i)&1;
    //}

    while(n){
        contador += n & 1;
        n >>= 1;
    }
    return contador;
}

int posicionBits(int x, int p, unsigned int n){
    int mascara = ~((-1)<<n); // == 0^(32-n) 1^
    for(int i=0; i<sizeof(int)*8-n; i++){
        if(((x>>i)&mascara) == p) return i;
    }
    return -1;
}

unsigned int repBits(unsigned int x, int i, int k, unsigned val){
    val <<= i;
    unsigned int x1 = x & (~((-1)<<i));
    unsigned int x2 = x & (~((-1)<<(i+k)));
    return x1 | x2 | val;
}

//p1
int main(int argc, char **argv){
    if(argc == 1) return 1;

    int n = atoi(argv[1]);
    printf("%d\n", bits1(n));
    printf("%d\n", posicionBits(0b0011100, 0b11, 2));
    printf("%d\n", repBits(0b0));

    return 0;
}


