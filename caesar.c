#include <stdlib.h>

int absolute_int(int x) {
  int abs_x;
  if (x < 0)
    abs_x = -x;
  else
    abs_x = x;
  return abs_x;
}

char *encrypt(char *str, int d) {
  int shift = absolute_int(d);
  int i = 0;
  char * buf = (char *)malloc(33);
  
  if (buf) {
    while (str[i]) {
      /* Spaces are not encrypted. */
      buf[i] = (str[i] == ' ' ? ' ' : str[i] + (char)shift);
      i++;
    }
    buf[i] = '\0';
  }
  return buf;
}

char *decrypt(char *str, int d) {
  int shift = absolute_int(d);
  int i = 0;
  char *buf = (char *)malloc(33);

  if (buf) {
    while (str[i]) {
      /* Spaces are not decrypted. */
      buf[i] = ( str[i] == ' ' ? ' ' : str[i] - (char)shift);
      i++;
    }
    buf[i] = '\0';
  }
  return buf;
}
