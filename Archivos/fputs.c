#include <stdio.h>
#include <string.h>

int main() {
  char buf[82];
  FILE *in= fopen("pers.txt", "r");
  FILE *out= fopen("datos.txt", "w");
  for (;;) {
    if (fgets(buf, 82, in)==NULL)
      break;
    int len= strlen(buf);
    buf[len-1]= ' '; // Cambia '\n' por ' '
    fputs(buf, out);
  }
  return 0;
}
