#include <stdio.h>

int
main(void)
{
  char buf[16];
  unsigned int ip = 0xffffff01;
  unsigned int ip_frame = 255;
  unsigned int ip_1,ip_2,ip_3,ip_4;
  ip_4 = ip & ip_frame;
  ip = ip >> 8;
  ip_3 = ip & ip_frame;
  ip = ip >> 8;
  ip_2 = ip & ip_frame;
  ip = ip >> 8;
  ip_1 = ip & ip_frame;
  ip = ip >> 8;
  sprintf(buf, "%d.%d.%d.%d", ip_1, ip_2, ip_3, ip_4);
  printf("%s\n", buf);
  return 0;
}
