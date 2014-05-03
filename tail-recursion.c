#include <stdio.h>

int
factorial_tail(int n, int num1, int num2)
{
  if (n < 2) {
    return num1;
  } else {
    return factorial_tail(n-1, num2, num1 + num2);
  }
}

int
main(void)
{
  int n = 20;
  int i;
  for (i = 0; i < n; i++) {
    printf("%2d: %d\n", i, factorial_tail(i, 1, 1));
  }
  return 0;
}
