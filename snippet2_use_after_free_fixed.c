/*
 * Snippet 2 (FIXED)
 * Fix: do not touch the pointer after free(). Set it to NULL immediately
 * after freeing so any accidental later use is a detectable NULL
 * dereference instead of silent memory corruption.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *buf = (char *)malloc(32);
    if (buf == NULL) {
        fprintf(stderr, "allocation failed\n");
        return 1;
    }

    strcpy(buf, "roll_no:2026CSE001");
    printf("Before free: %s\n", buf);

    free(buf);
    buf = NULL;                  /* FIX: nullify pointer right after free */

    /* Any further use must go through a fresh, valid pointer. */
    if (buf == NULL) {
        printf("Pointer safely nullified after free; no stale access.\n");
    }

    return 0;
}
