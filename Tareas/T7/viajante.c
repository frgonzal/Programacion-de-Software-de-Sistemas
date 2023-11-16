#define _XOPEN_SOURCE 500

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "viajante.h"

int leer(int fd, void *vbuf, int n);

double viajante_par(int z[], int n, double **m, int nperm, int p) {
    // Complete esta funcion
    // Puede invocar a su version secuencial: viajante
    // Use la funcion leer para que el padre reciba la ruta del hijo.
    // Use fork() para crear p nuevos procesos.  El padre solo obtiene los
    // resultados de los procesos hijos a traves de pipes, entierra a los
    // los hijos y calcula el resultado final.
    // Despues de invocar fork() agregue: srandom(getUSecsOfDay()*getpid());
    // Esto es para que cada proceso genere secuencias de numeros aleatorios
    // diferentes.
    double min= DBL_MAX; // la menor distancia hasta el momento

    for (int i= 1; i<=nperm; i++) {

        int x[n+1];          // almacenará una ruta aleatoria
        gen_ruta_alea(x, n); // genera ruta x[0]=0, x[1], x[2], ..., x[n], x[0]=0

        // calcula la distancia al recorrer 0, x[1], ..., x[n], 0
        double d= dist(x, n, m);

        if (d<min) {      // si distancia es menor que la que se tenía hasta el momento
            min= d;       // d es la nueva menor distancia
            for (int j= 0; j<=n; j++)
            z[j]= x[j];   // guarda ruta que recorre la menor distancia en parámetro z
        }
    }
    return min;
}





int leer(int fd, void *vbuf, int n) {
    char *buf= vbuf;
    do {
        int rc= read(fd, buf, n);
        if (rc<=0)
            return 1; /* fracaso: error o fin del archivo/pipe/socket */
        n-= rc; /* descontamos los bytes leídos */
        buf+= rc; /* avanzamos el buffer para no reescribir lo leido previamente */
    } while (n>0); /* mientras no leamos todo lo que esperamos */
    return 0; /* exito */
}