#include <stdio.h>
#include <string.h>

typedef double (*Fun)(double x);

double integral(Fun pf, double xi, double xf, int n) {
    double h= (xf-xi)/n;
    double sum= ( (*pf)(xi) + (*pf)(xf) ) / 2;
    for (int k= 1; k<n; k++)
        sum += (*pf)(xi + k*h);
    return sum * h;
}

double g_a, g_b, g_c;		// variables globales

double poli2(double x) {
    return g_a*x*x+g_b*x+g_c;  // ✔
}

double h(double a, double b, double c,
                  double xi, double xf, int n) {
    g_a= a; g_b= b; g_c= c;
    return integral(poli2, xi, xf, n);
}

int main() {
  double area= h(2.0, -3.0, 20.0, 0.0, 10.0, 100);
  printf("%f\n", area);

  return 0;
}
