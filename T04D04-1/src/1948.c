#include <stdio.h>

int simple(int a);
int div(int a, int b);

int main() {
  int x;
  char c;
  int max = 0;
  if (scanf("%d%c", &x, &c) && c == '\n' && x != 0) {
    for (int i = 2; x > 0 ? i < x : i < x * -1; i++) {
      if (div(x, i) == 0) {
        if (simple(i) == 0)
          max = i;
      }
    }

  } else {
    printf("n/a\n");
    return 1;
  }
  printf("%d\n", max == 0 ? max = x : max);
  return 0;
}

int simple(int a) {
  for (int i = 2; i < a; i++) {
    if (div(a, i) != 1) {
      return 1;
    }
  }
  return 0;
}

int div(int a, int b) {
  int c = 0;
  if (b == 0)
    return 1;
  if (a > 0) {
    while (a >= b) {
      a = a - b;
      c++;
    }
  } else {
    while (a <= b * -1) {
      a = a + b;
      c++;
    }
  }
  if (a == 0)
    return 0;
  else
    return 1;
}