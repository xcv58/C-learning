/*
 * Test fork(), pipe(), etc.
 * Author: xcv58
 * Date: 2/2/2014
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define DEFAULTBUFFERSIZE 10

/* #define PIPE */

char *getLine(void)
{
  int maxlength = DEFAULTBUFFERSIZE;
  int i = 0;

  char *str = (char*) malloc (maxlength * sizeof(char));
  if (str == NULL) {
    printf("malloc error!!");
    return NULL;
  }

  while ((str[i++] = getchar()) != '\n') {
    if (i == maxlength) {
      maxlength = maxlength * 2;
      printf("Double the capable of stringBuffer\n");
      char *tmp = (char*) malloc (maxlength * sizeof(char));

      if (tmp == NULL) {
        printf("malloc error!!");
        free(str);
        str = NULL;
        return NULL;
      }

      strcpy( tmp, str );
      free(str);
      str = tmp;
    }
  }
  str[i] = '\0';
  return str;
}

void printPinfo(int return_code_fork, int origin_pid)
{
  printf("My pid is %d\n", getpid());
  if (return_code_fork == 0) {
    printf("I am child.\nMy parent pid is: %d\n", origin_pid);
  } else {
    printf("I am parent.\nMy child's pid is: %d\n", return_code_fork);
  }
  printf("\n");
  return;
}

#ifdef PIPE
void printPipe(int return_code_fork, int *fd)
{
  if (return_code_fork == 0) {
    char readbuffer[80];
    close(fd[1]);
    int nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
    printf("Received string: %s\n", readbuffer);
    /* printf("nbtyes = %d\n", nbytes); */
  } else {
    /* printf("Please key in a line:\n"); */
    close(fd[0]);
    char *str = getLine();
    /* printf("string length: %d\n", strlen(str)); */
    write(fd[1], str, (strlen(str)+1));
    free(str);
    str = NULL;
  }
  return;
}
#endif

void testCloseFiletable(int return_code_fork)
{
  if (return_code_fork == 0) {
  }
  return;
}

void testAlwaysFork(int i) {
  if (i <= 0)
    return;
  while (i-- > 0) {
    fork();
    printf("i: %d, My pid is: %d\n", i, getpid());
  }
  return;
}

int main()
{
  /* char *test = "HELLO"; */
  /* test[0] = (char *) "a"; */
  /* *test[2] = (char *) "bc"; */
  /* char **t; */
  /* printf("%d\n", sizeof(t)); */
  /* printf("%d\n", sizeof(char*)); */
  /* printf("%d\n", sizeof(char *)); */


  /* for (i = 0; i < 10; i++) { */
  /*   if (test[i] == NULL) */
  /*     printf("%d\n", i); */
  /* } */
#ifdef PIPE
  printf("%s\n",__FILE__);
  int filedes[2];
  int return_code_pipe = pipe(filedes);
  if (!return_code_pipe) {
    printf("Successfully create pipe.\n");
  }
  int nbytes;
#endif

  int origin_pid = getpid();
  int return_code_fork = fork();
  printPinfo(return_code_fork, origin_pid);

  testCloseFiletable(return_code_fork);
  /* testAlwaysFork(1000); */


#ifdef PIPE
  if (!return_code_pipe)
    printPipe(return_code_fork, filedes);
#endif
  return 0;
}
