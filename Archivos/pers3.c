#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char *rut;
  int edad;
  char *nom;
}  Persona;

int main() {
  FILE *in= fopen("pers.bin", "r");
  Persona *pers2= malloc(100*sizeof(Persona));
  int cnt= fread(pers2, sizeof(Persona), 100, in);

  for (int i= 0; i<cnt; i++) {
    printf("%s %d %s\n", pers2[i].rut, pers2[i].edad, pers2[i].nom);
  }

  return 0;
}
