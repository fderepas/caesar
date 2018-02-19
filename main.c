#include <stdlib.h>
#include <stdio.h>
#include <caesar.h>
#include <tis_builtin.h>

void gen_test(int user_shift, int len, char *str) {
  char *res1, *res2;
  
  printf("Encrypt text '%s'\n", str);
  res1 = encrypt(str, len, user_shift);

  if (res1) {
    printf("Decrypt text '%s'\n", res1);
    res2 = decrypt(res1, len, user_shift);
    if (res2)
      free(res2);  
    free(res1);
  }
}

int main(void) {
  char str[] = "People of Earth, your attention please";
  int len = sizeof(str) / sizeof(str[0]);
  int user_shift;
  tis_make_unknown((char *)&user_shift, sizeof(int));
  str[len-1]=0;
  
  printf("Test 1: Shift with a negative input\n");
  gen_test(-3, len, str);
  printf("\nTest 2: Shift with a positive input\n");
  gen_test(7, len, str);
  printf("\nTest 3: Shift with all possible input\n");
  if (user_shift != INT_MIN )
    gen_test(user_shift, len, str);
  return 0;
}
