/*
 * Snippet 1 (ORIGINAL - VULNERABLE)
 * Error type: Unchecked return value of a memory allocation function
 * A large / adversarial allocation size can make malloc() return NULL.
 * The code writes through the pointer immediately without checking,
 * causing a NULL pointer dereference.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int build_record(size_t n, const char *name) {
    char *record = (char *)malloc(n);   /* return value never checked */
    strcpy(record, name);               /* crash if malloc returned NULL */
    printf("Record created: %s\n", record);
    free(record);
    return 0;
}

int main(void) {
    /* An attacker-influenced or overflowed size can force malloc to fail */
    size_t huge_size = (size_t)-1;      /* forces malloc() to fail */
    build_record(huge_size, "student");
    return 0;
}
