#include <stdio.h>
#include <string.h>

typedef double (*Fun)(void *ptr, double x);

double integral(Fun pf, void *ptr, double xi, double xf, int n) {
    double h= (xf-xi)/n;
    double sum= ( (*pf)(ptr, xi) + (*pf)(ptr, xf) ) / 2;
    for (int k= 1; k<n; k++)
        sum += (*pf)(ptr, xi + k*h);
    return sum * h;
}

typedef struct { double a, b, c; } Abc;

double poli2(void *ptr, double x) {
    Abc *pabc= (Abc*)ptr;
    return pabc->a*x*x+pabc->b*x+pabc->c;
}

double h(double a, double b, double c,
                  double xi, double xf, int n) {
    Abc abc= { a, b, c };
    return integral(poli2, &abc, xi, xf, n);
}

int main() {
  double area= h(2.0, -3.0, 20.0, 0.0, 10.0, 100);
  printf("%f\n", area);

  return 0;
}
