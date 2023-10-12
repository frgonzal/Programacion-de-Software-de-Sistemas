#include <string.h>

int wordsn(char *s){
  int c = *s;
  int len = 0;
  int espacio = ' ';

  for(;;){

    if(c == 0)
      break;

    if(c == espacio){
      s++;
      c=*s;
      continue;
    }

    for(;;){//    para entrar al ciclo no puede ser igual a 0 ni a ' '
      if(c == espacio){
        break;
      }
      if(c==0){
        break;
      }
      s++;
      c=*s;
    }// al terminar aumentar contador
    len++;
  }
  return len;
}

int strCmp(char *s1, char *s2) {
    return wordsn(s1) - wordsn(s2);
}

void sort(char **a, int n) {
  char **ult= &a[n-1];
  char **p= a;
  while (p<ult) {

    int t1= strCmp(p[0], p[1]);

    if (t1 <= 0)
      p++;
    else {
      char *tmp= p[0];
      p[0]= p[1];
      p[1]= tmp;
      p= a;
    }
  }
}
