#include <stdio.h>
struct str{
    int len;
    char s[0];
};

struct foo {
    struct str *a;
};

int main(int argc, char** argv) {
  /* struct foo *f = NULL; */
  /* if (f->a->s) { */
  /*   printf("x\n"); */
  /*   printf(f->a->s); */
  /* } */
    struct foo f={0};
    if (f.a->s) {
    printf("x\n");
        printf( f.a->s);
    }
    return 0;
}
