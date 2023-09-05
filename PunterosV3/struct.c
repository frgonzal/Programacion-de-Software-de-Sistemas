#include <stdio.h>
#include <string.h>

typedef struct {
  double r, im;
} Complejo;

void sumar(Complejo zx, Complejo zy) {
  zx.r += zy.r;
  zx.im += zy.im;
}

void sumar2(Complejo *pz, Complejo zy) {
  (*pz).r += zy.r;
  (*pz).im += zy.im;
}

void sumar3(Complejo *pz, Complejo zy) {
  pz->r += zy.r;
  pz->im += zy.im;
}

int main() {
  Complejo a = { 1.3, -10 },  b = { -0.03, 1 };
  Complejo c = a;
  sumar(a, b);     // ¡a sigue siendo { 1.3, -10 }!
  printf("%f %f\n", a.r, a.im);
  sumar2(&a, b);   // a es { 1.27, -9 }
  printf("%f %f\n", a.r, a.im);
  a = c;
  sumar3(&a, b);   // a es { 1.27, -9 }
  printf("%f %f\n", a.r, a.im);

  return 0;
}
