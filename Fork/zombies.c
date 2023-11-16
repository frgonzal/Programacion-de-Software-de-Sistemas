#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
 
int vars[10];
int main() {
  int pids[10];
  for(int i=0; i < 10; i++) {
    pids[i] = fork();
    if (pids[i] == 0) {  // proceso hijo de corta duracion
      vars[i] = 1;      // getpid() retorna mi pid
      printf("hijo %d, pid=%d,var_i=%d\n", i, getpid(), vars[i]);
      exit(0);  // que pasa si no pongo este exit? (prueben!)
    }
  }
  sleep(20); // pueden mirar los zombies durante un rato
  for(int i=0; i < 10; i++)  // ahora los entierro para que descansen en paz
    waitpid(pids[i], NULL, 0);
 
  for(int i= 0; i<10; i++) {
    // Esto muestra que mis hijos heredan mis variables pero no me
    // las pueden modificar a mi
    printf("%d  ", vars[i]);
  }
  printf("\n");
  sleep(20);
  return 0;
}
