/*
 * Snippet 3 (ORIGINAL - VULNERABLE)
 * Error type: Double-Free
 * free() is called twice on the same pointer. This corrupts the heap
 * allocator's internal free-list metadata.
 */
#include <stdio.h>
#include <stdlib.h>

void cleanup(int *arr) {
    free(arr);
}

int main(void) {
    int *marks = (int *)malloc(5 * sizeof(int));
    if (marks == NULL) {
        fprintf(stderr, "allocation failed\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) marks[i] = i * 10;

    printf("marks[0] = %d\n", marks[0]);

    cleanup(marks);   /* first free */
    /* ... later in the function, the same pointer is freed again ... */
    free(marks);       /* BUG: second free on the same pointer */

    return 0;
}
