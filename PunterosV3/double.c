#include <stdio.h>
#include <string.h>

int main() {
  double pi= 3.14159;
  double *ptr_double= &pi;
  int *ptr_int= (int*)ptr_double;
  printf("%d\n", *ptr_int);
  printf("%d %d %d %d\n", ptr_int[-1], ptr_int[0], ptr_int[1], ptr_int[2]);

  return 0;
}
