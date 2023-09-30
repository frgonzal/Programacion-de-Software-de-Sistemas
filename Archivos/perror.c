#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  char buf[80];
  FILE *in= fopen(argv[1], "r");
  if (in==NULL) {
    perror(argv[1]);
    exit(1);
  }
  for (;;) {
    if (fgets(buf, 80, in)==NULL)
      break;
    printf("%s", buf);
  }
  return 0;
}
