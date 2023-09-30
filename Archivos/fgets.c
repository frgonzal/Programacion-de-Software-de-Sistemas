#include <stdio.h>

int main() {
  char buf[82];
  FILE *in= fopen("pers.txt", "r");
  for (;;) {
    if (fgets(buf, 82, in)==NULL)
      break;
    printf("%s", buf);
  }
  return 0;
}
