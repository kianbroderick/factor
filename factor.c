#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int factor(unsigned long int n);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("error: please enter a single integer beween 1 and %lu\n",
           ULONG_MAX);
    exit(EXIT_FAILURE);
  };
  if (*argv[1] == '-') {
    printf("error: enter a positive integer\n");
    exit(EXIT_FAILURE);
  }
  unsigned long int n;
  char *endptr;
  n = strtoul(argv[1], &endptr, 10);
  if (n <= 0) {
    printf("please enter an integer beween 1 and %lu\n", ULONG_MAX);
  };
  factor(n);
  exit(EXIT_SUCCESS);
}

int factor(unsigned long int n) {
  unsigned long int max = sqrt(n);
  for (unsigned long int i = 1; i <= max; i++) {
    if (n % i == 0) {
      if (!(i * i == n)) {
        printf("%lu %lu ", i, n / i);
      } else {
        printf("%lu ", i);
      }
    }
  }
  printf("\n");
  return 0;
}
