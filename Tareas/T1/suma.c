//Franco Gonzalez
#include <stdio.h>

#include "suma.h"

Bcd sumaBcd(Bcd x, Bcd y) {
    unsigned int mascara = 15; // == 0b1111
    unsigned int resto = 0;

    Bcd m;
    Bcd z = 0;

    for(int i=0; i<16; i++){

        //mover los bits a sumar a las primeras 4 posiciones y aplicar mascara
        m = ((x>>i*4) & mascara) + ((y>>i*4) & mascara) + resto;
        resto = 0;

        //si el numero es mayor a 9, se le resta 10 y guardamos lo que sobra
        if (m > 9){
            m -= 10;
            resto = 1;
        }

        //sumar en la posicion correspondiente
        z += m<<i*4;
    }

    if(!resto)//si el resto no es 0 ==> desborde
        return z;
    else
        return 0xffffffffffffffff;
}