/*
 * Snippet 1 (FIXED)
 * Fix: check the return value of malloc() before use. On failure,
 * handle the error gracefully instead of dereferencing NULL.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int build_record(size_t n, const char *name) {
    char *record = (char *)malloc(n);
    if (record == NULL) {                 /* FIX: check return value */
        fprintf(stderr, "Error: allocation of %zu bytes failed\n", n);
        return -1;
    }

    strncpy(record, name, n - 1);
    record[n - 1] = '\0';
    printf("Record created: %s\n", record);

    free(record);
    record = NULL;                        /* FIX: avoid dangling pointer */
    return 0;
}

int main(void) {
    size_t huge_size = (size_t)-1;        /* still an unreasonable size */
    if (build_record(huge_size, "student") != 0) {
        fprintf(stderr, "build_record failed safely, no crash occurred\n");
    }

    /* demonstrate the normal, successful path as well */
    build_record(64, "student");
    return 0;
}
