#include <stdio.h>

int main() {
  int a=10, *p=&a, c=*p*a;
  printf("%d\n", c);
  return 0;
}
