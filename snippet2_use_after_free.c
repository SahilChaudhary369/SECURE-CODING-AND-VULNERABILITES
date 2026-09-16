/*
 * Snippet 2 (ORIGINAL - VULNERABLE)
 * Error type: Use-After-Free (UAF)
 * The pointer 'buf' is used to read/write memory after it has already
 * been freed. The freed block may be reused by the allocator for an
 * unrelated object, so the read/write corrupts or leaks that object's data.
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

    free(buf);              /* memory returned to the allocator */

    /* BUG: buf still points at the freed block and is used afterwards */
    printf("After free : %s\n", buf);   /* use-after-free read  */
    strcpy(buf, "tampered!");           /* use-after-free write */

    return 0;
}
