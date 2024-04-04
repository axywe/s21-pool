#include <math.h>
#include <stdio.h>

void v(double x) {
  double a = (pow(1, 3) / (pow(1, 2) + (pow(x, 2))));
  if (a != a)
    printf("| - ");
  else
    printf("| %.7lf ", a);
  return;
}

void b(double x) {
  double y =
      sqrt(pow(1, 4) + 4 * pow(x, 2) * pow(1, 2)) - pow(x, 2) - pow(1, 2);
  if (y <= 0)
    printf("| - ");
  else
    printf("| %.7lf ", sqrt(y));
  return;
}

void g(double x) {
  double a = (1 / pow(x, 2));
  if (a != a)
    printf("| -");
  else
    printf("| %.7lf\n", a);
  return;
}

int main(void) {
  for (double x = -M_PI; x <= M_PI; x += 2 * M_PI / 41.) {
    printf("%.7lf ", x);
    v(x);
    b(x);
    g(x);
  }
  return 0;
}
