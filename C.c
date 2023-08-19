#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long Bcd;
Bcd sumaBcd(Bcd x, Bcd y);

unsigned long long Binario_a_decimal(unsigned long long binario){
    unsigned long long decimal = 0;
    unsigned long long potencia = 1;
    unsigned long long mascara = 1;

    while(binario){
        decimal += ( binario&mascara ) * potencia;
        potencia <<= 1;
        binario >>= 1;
    }

    return decimal;
}
unsigned long long Decimal_a_Binario(unsigned long long decimal){
    unsigned long long binario = 0;
    unsigned long long mascara = 1;
    unsigned long long potencia = 1;

    while(decimal){
        binario += (decimal&mascara)*potencia;
        potencia *= 10;
        decimal >>= 1;
    }
    return binario;
}

int main(int argc, char **argv){
    printf("\n");
}
