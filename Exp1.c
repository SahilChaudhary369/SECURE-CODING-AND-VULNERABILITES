#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int a = 70000;
    int neg = -10;
    float f = 12.99;
    char str[] = "123abc";

    printf("=== Unsafe Conversions ===\n");

    printf("int -> short: %d -> %hd\n", a, (short)a);
    printf("signed -> unsigned: %d -> %u\n", neg, (unsigned int)neg);
    printf("float -> int: %.2f -> %d\n", f, (int)f);
    printf("string -> int: %s -> %d\n", str, atoi(str));

    printf("\n=== Safe Conversions ===\n");

    if (a < SHRT_MIN || a > SHRT_MAX)
        printf("Rejected: int out of short range\n");
    else
        printf("%hd\n", (short)a);

    if (neg < 0)
        printf("Rejected: negative to unsigned conversion\n");
    else
        printf("%u\n", (unsigned int)neg);

    printf("float -> int: %.2f -> %d\n", f, (int)f);

    char *end;
    long num = strtol(str, &end, 10);

    if (*end != '\0')
        printf("Rejected: invalid numeric string\n");
    else
        printf("%ld\n", num);

    return 0;
}
