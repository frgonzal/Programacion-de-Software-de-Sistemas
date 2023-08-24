#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long Bcd;
Bcd sumaBcd(Bcd x, Bcd y);

void Decimal_a_Binario(unsigned long long decimal){
    unsigned long long mask = 0x1;
    printf("Decimal a Binario: ");
    int i = sizeof(unsigned long long)*8-1;
    while(i--)
        if((decimal>>i)&mask) break; // lee algo distinto de 1
    i++;
    while(i--){
        printf("%d", (decimal>>i)&mask);
    }
    printf("\n");
}

int main(int argc, char **argv){
    printf("Binario a decimal: %d \n", 0x40);
    Decimal_a_Binario(725);
}
