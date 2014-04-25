#include <stdio.h>
#include <stdlib.h>

#define TEST_SIZE (100)

typedef struct {
	int size;
	char buffer[0];
} dynamic_struct;

int main(int argc, char **argv)
{
	dynamic_struct *t;
	t = malloc(sizeof(dynamic_struct) + TEST_SIZE * sizeof(char));
	t->size = TEST_SIZE;
	int i;
	for (i = 0; i < TEST_SIZE; i++) {
		if ((i % 27) == 26) {
			t->buffer[i] = '\n';
		} else {
			t->buffer[i] = 'a' + (i % 27);
		}
	}
	printf("%s\n", t->buffer);
	return 0;
}
