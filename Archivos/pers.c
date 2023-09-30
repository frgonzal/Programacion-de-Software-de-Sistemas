#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char rut[12];
  int edad;
  char nom[30];
}  Persona;

Persona pers[] = { { "14475267-1", 20, "pedro" },
                   { "14847282-4", 22, "juan" },
                   { "14844738-9", 24, "diego" },
};

int main() {
  FILE *out= fopen("pers.bin", "w");
  fwrite(pers, sizeof(Persona), 3, out);
  fclose(out); // Importante!

  FILE *in= fopen("pers.bin", "r");
  Persona *pers2= malloc(100*sizeof(Persona));
  int cnt= fread(pers2, sizeof(Persona), 100, in);

  for (int i= 0; i<cnt; i++) {
    printf("%s %d %s\n", pers2[i].rut, pers2[i].edad, pers2[i].nom);
  }

  return 0;
}
