#include <stdlib.h>
#include <stdio.h>
#include <caesar.h>
#include <tis_builtin.h>

void gen_test(int user_shift, int len, char *str) {
  char *res1, *res2;
  
  printf("Encrypt text '%s'\n", str);
  res1 = encrypt(str, len, user_shift);
  
  printf("Decrypt text '%s'\n", str);
  res2 = decrypt(str, len, user_shift);

  free(res1);
  free(res2);
}

int main(void) {
  int len = 1000;
  char str[1000];
  int user_shift;
  // get any integer for user shift
  tis_make_unknown((char *)&user_shift, sizeof(int));
  // get any content for the string pointed to by str
  tis_make_unknown(str, sizeof(char)*(len-1));
  str[len-1]=0;
  
  if (user_shift!=INT_MIN) {
    gen_test(user_shift, len, str);
  }
  return 0;
}
