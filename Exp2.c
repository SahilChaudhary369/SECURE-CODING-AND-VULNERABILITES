#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    printf("=== Type Conversion Tests ===\n");

    int a = 70000;
    printf("int -> short: %d -> %hd\n", a, (short)a);

    int neg = -10;
    printf("signed -> unsigned: %d -> %u\n", neg, (unsigned int)neg);

    float f = 12.99f;
    printf("float -> int: %.2f -> %d\n", f, (int)f);

    char str[] = "123abc";
    printf("string -> int: %s -> %d\n", str, atoi(str));

    printf("\n=== UBSan Test ===\n");

    int x = INT_MAX;
    int y = x + 1;
    printf("Overflow result: %d\n", y);

    printf("\n=== ASan Test ===\n");

    char arr[5] = "test";
    arr[10] = 'A';

    printf("Program Finished\n");

    return 0;
}
