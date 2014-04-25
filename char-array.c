#include <stdio.h>

#define NUM  3

int main(void)
{
  int seq[NUM];
  int aseq[NUM];
  int *tmp;
  int i;
  for (i = 0; i < NUM; i++) {
    seq[i] = i;
    aseq[i] = NUM - i;
  }
  printf("%p, sizeof: %lu\n", seq, sizeof(seq));
  /* *(aseq + 0) = *(seq + 0); */
  /* *aseq = *seq; */
  printf("%p, sizeof: %lu\n", aseq, sizeof(aseq));
  for (i = 0; i < NUM; i++) {
    tmp = seq + i;
    printf("%p, sizeof: %lu\n", tmp, sizeof(tmp));
  }
  for (i = 0; i < NUM; i++) {
    printf("seq[%d]: %d\n", i, seq[i]);
  }
  for (i = 0; i < NUM; i++) {
    printf("aseq[%d]: %d\n", i, aseq[i]);
  }
  return 0;
}
