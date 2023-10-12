#include <string.h>

int wordsn(char *s){
  int n=0;

  while(*s){
    if(*s==' '){
      s++;
      continue;
    }
    //while en palabra
    while(*s!=' ' && *s)
      s++;
    //al terminar palabra
    n++;
  }
  return n;
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
