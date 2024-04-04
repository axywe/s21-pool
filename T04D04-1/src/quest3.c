#include <stdio.h>

int fiv(int a) {
  if (a == 0)
    return 0;
  if (a == 1 || a == 2) {
    return 1;
  }
  return fiv(a - 1) + fiv(a - 2);
}

int main(void) {
  int count;
  char c;
  if (scanf("%d%c", &count, &c) && (c == '\n')) {
    if (count > -1) {
      printf("%d\n", fiv(count));
    } else {
      if (count % 2 == 0)
        printf("-%d\n", fiv(count * -1));
      else
        printf("%d\n", fiv(count * -1));
    }

  } else {
    printf("n/a\n");
  }
}