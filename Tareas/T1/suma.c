//Franco Gonzalez
#include <stdio.h>

#include "suma.h"

Bcd sumaBcd(Bcd x, Bcd y) {
    int mask  = 0xf; // == 0b1111, para obtener los ultimos 4 bits
    int carry = 0;    // para guardar lo que sobra en cada suma
    int suma;
    Bcd ans = 0;

    for(int i=0; i<64; i+=4){//moverse 4 bits en cada iteracion

        //mover los bits a sumar a las primeras 4 posiciones y aplicar mascara
        suma  = ((int)(x>>i) & mask) + ((int)(y>>i) & mask) + carry;
        carry = 0;

        //si el numero es mayor a 9, se le resta 10 y guardamos lo que sobra
        if(suma > 9){
            suma -= 10;
            carry = 1;
        }

        //sumar en la posicion correspondiente
        ans |= (Bcd)suma<<i;
    }

    if(!carry)//si el carry no es 0 ==> desborde
        return ans;
    else
        return 0xffffffffffffffff;
}