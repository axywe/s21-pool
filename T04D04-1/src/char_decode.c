#include <math.h>
#include <stdio.h>

int encode() {
  char sym, space;
  int count = 0, flag = 0;
  while ((scanf("%c", &sym)) && flag == 0 && sym != '\n') {
    if (sym == ' ') {
      flag = 1;
      break;
    }
    if (scanf("%c", &space) && space != '\n') {
      if (space == ' ') {
        count++;
        printf("%X ", sym);
      } else {
        flag = 1;
        break;
      }
    } else if (space == '\n') {
      count++;
      printf("%X ", sym);
      break;
    }
  }
  if (flag == 1)
    return count;
  else
    return -1;
}

int decode() {
  char space;
  int count = 0, flag = 0, sym, temp;
  while ((temp = scanf("%X", &sym)) && flag == 0) {
    if (sym > 126 || sym < 32 || temp == 0) {
      flag = 1;
      break;
    }
    if (scanf("%c", &space) && space != '\n') {
      if (space == ' ') {
        count++;
        printf("%c ", sym);
      } else {
        flag = 1;
        break;
      }
    } else if (space == '\n') {
      count++;
      printf("%c ", sym);
      break;
    }
    if (sym == 102)
      break;
  }
  if (flag == 1 || temp == 0)
    return count;
  else
    return -1;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("n/a");
    return 1;
  }
  int count = -1;
  if (argv[1][0] == '0' && !argv[1][1]) {
    count = encode();
  } else if (argv[1][0] == '1' && !argv[1][1]) {
    count = decode();
  } else {
    printf("n/a");
    return 1;
  }
  if (count != -1) {
    for (int i = 0; i <= count; i++) {
      printf("\b\b\b");
      fflush(stdout);
    }
    printf("\033[2K");
    fflush(stdout);
    printf("n/a\n");
    return 1;
  }
  fflush(stdout);
  printf("\n");
  return 0;
}
