#include <stdlib.h>
#include <stdio.h>
#include <caesar.h>
#include <tis_builtin.h>

void gen_test(int user_shift, int len, char *str)
{
    char *res1, *res2;

    printf("Encrypt text '%s'\n", str);
    res1 = encrypt(str, len, user_shift);
    printf("Result: %s\n", res1);

    printf("Decrypt text '%s'\n", str);
    res2 = decrypt(str, len, user_shift);
    printf("Result: %s\n", res2);

    free(res1);
    free(res2);
}

int main(void)
{
    char str[] = "People of Earth, your attention please";
    int len = sizeof(str) / sizeof(str[0]);
    int user_shift;
    tis_make_unknown((char *)&user_shift, sizeof(int));

    printf("Test 1: Shift with a negative input\n");
    gen_test(-3, len, str);
    printf("\nTest 2: Shift with a positive input\n");
    gen_test(7, len, str);
    printf("\nTest 3: Shift with all possible input\n");
    gen_test(user_shift, len, str);
    tis_make_unknown(str, len - 1);
    printf("\nTest 4: All possible input\n");
    gen_test(user_shift, len, str);

    return 0;
}
