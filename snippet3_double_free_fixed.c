/*
 * Snippet 3 (FIXED)
 * Fix: free exactly once. The pointer is set to NULL after the single
 * free() so that a later, mistaken free() call becomes a harmless no-op
 * (free(NULL) is well-defined and does nothing).
 */
#include <stdio.h>
#include <stdlib.h>

void cleanup(int **arr) {
    free(*arr);
    *arr = NULL;      /* FIX: nullify the caller's pointer via double ptr */
}

int main(void) {
    int *marks = (int *)malloc(5 * sizeof(int));
    if (marks == NULL) {
        fprintf(stderr, "allocation failed\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) marks[i] = i * 10;

    printf("marks[0] = %d\n", marks[0]);

    cleanup(&marks);   /* first (and only real) free; marks becomes NULL */

    /* FIX: free exactly once -- this second call is now free(NULL),
     * which the C standard guarantees is a safe no-op. */
    free(marks);

    printf("Cleanup completed safely, no double-free occurred.\n");
    return 0;
}
