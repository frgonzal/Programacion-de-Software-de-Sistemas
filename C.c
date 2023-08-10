#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char *argv[]) {
  int n= atoi(argv[1]);
  int prev= 0;
  printf("f0= 0\n");
  int curr= 1;
  int next;
  printf("f1= 1\n");

  for (int i= 2; i<n; i++) {
    next= prev+curr;
    printf("f%d= %d\n", i, next);
    prev= curr;
    curr= next;
  }

  return 0;
}