#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Program starting...\n");

    // Method 1: Direct obvious null dereference
    int *p1 = NULL;
    printf("p1 points to: %p\n", (void *)p1);
    // printf("Trying to read *p1...\n"); // Uncomment later
    // int value1 = *p1; // This should crash
    // printf("Read: %d\n", value1); // We'll never get here

    // Method 2: Indirect via a function (harder to optimize away)
    int *p2 = NULL;
    printf("p2 points to: %p\n", (void *)p2);
    printf("Now attempting to dereference p2...\n");

    // Let's try to write to NULL, which is also invalid
    *p2 = 42;
    printf("If you see this, the crash didn't happen as expected.\n");

    return 0;
}