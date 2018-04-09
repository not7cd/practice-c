#include "stdio.h"

int main(int argc, char const *argv[]) {

  for (int i = 1; i <= 100; i++) {
    if (i % 3 == 0)
      printf("X\n");
    else
      printf("%i\n", i);
  }
  return 0;
}
