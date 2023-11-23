/* Franco González */

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
    double min = DBL_MAX;
    // Complete esta funcion
    // Puede invocar a su version secuencial: viajante
    // Use la funcion leer para que el padre reciba la ruta del hijo.
    // Use fork() para crear p nuevos procesos.  El padre solo obtiene los
    // resultados de los procesos hijos a traves de pipes, entierra a los
    // los hijos y calcula el resultado final.
    // Despues de invocar fork() agregue: srandom(getUSecsOfDay()*getpid());
    // Esto es para que cada proceso genere secuencias de numeros aleatorios
    // diferentes.

    pid_t pids[p];
    int fds[p][2]; 

    /* Poner a trabajar a los hijos */
    for(int i=0; i<p; i++){
        pipe(fds[i]);
        pids[i] = fork();
        srandom(getUSecsOfDay()*getpid());

        /* calcular valor para los hijos */
        if (pids[i] == 0){  //hijo
            close(fds[i][0]);
            int x[n+1];

            double d = viajante(x, n, m, nperm/p);

            write(fds[i][1], &d, sizeof(double));    //distancia
            write(fds[i][1], &x, (n+1)*sizeof(int)); //camino
            exit(0);
        }else{  //padre
            close(fds[i][1]);//padre no escribe
        }
    }

    /* Juntar todo en el padre */
    for(int i=0; i<p; i++){
        double d;
        int x[n+1];

        leer(fds[i][0], &d, sizeof(double));    //distancia
        leer(fds[i][0], &x, (n+1)*sizeof(int)); // camino
        close(fds[i][0]);
        waitpid(pids[i], NULL, 0);

        if(d < min){
            min = d;
            for(int j=0; j<=n; j++)
                z[j] = x[j];
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
        n-= rc;       /* descontamos los bytes leídos */
        buf+= rc;     /* avanzamos el buffer para no reescribir lo leido previamente */
    } while (n>0);    /* mientras no leamos todo lo que esperamos */
    return 0;         /* exito */
}