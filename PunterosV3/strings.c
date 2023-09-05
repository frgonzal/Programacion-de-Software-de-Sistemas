#include <stdio.h>
#include <string.h>

int mistrlen(char *s) {
  char *r= s;
  while (*r++)
    ;
  return r-s-1;
}

char *mistrcpy(char *d, char *s) {
  char *t= d;
  while (*t++ = *s++)
    ;
  return d;
}

int main() {
  double z[10];
  printf("%p\n", z);
  double *p = z, *top= z+10; // &z[0] y &z[10]
  while ( p < top ) {
    *p++ = 0;
    printf("%p\n", p);
  }

  char str[ ] = {'H', 'o', 'l', 'a', 0};
  printf("%s\n", str);
  char *r = str;
  int cnt = 0;
  while (*r != 0) {
    if ('A' <= *r && *r <= 'Z') {
      cnt++;
    }
    r++;
  }
  printf("Mayusculas: %d\n", cnt);

  char *str2= "Hello";
  // *str2= 'h';
  printf("%s\n", str2);

  char str3[] = "Salut";
  *str3= 's';
  printf("%s\n", str3);

  printf("%ld\n", sizeof(str3));
  printf("%ld\n", strlen(str3));
  r = str3;
  printf("%ld\n", sizeof(r));

  // Ejercicio: ejecutar paso a paso
  // las funciones strlen y strcpy
  printf("%d\n", mistrlen(str3));
  char str4[10];
  mistrcpy(str4, str3);

  return 0;
}


