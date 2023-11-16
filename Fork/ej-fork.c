#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int g= 0;

int main() {
  int v= 0;
  pid_t child= fork();
  if (child==0) {
    g= v= 1;
    printf("Hijo g=%d &v=%p v=%d\n", g, &v, v);
    exit(1234); // termina el hijo entregando un código de retorno
  }
  else {
    int status;
    waitpid(child, &status, 0);  // espera hasta que el hijo termine
    int rc= WEXITSTATUS(status); // código de retorno del hijo
    printf("Padre g=%d &v=%p v=%d rc=%d child=%d\n", g, &v, v, rc, child);
  }
  return 0;
}
