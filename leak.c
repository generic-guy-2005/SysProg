#include <stdio.h>
#include <stdlib.h> // For malloc() and free()

int main() {
    // Simulate a memory leak by allocating memory and not freeing it.
    int *leak = (int *)malloc(10 * sizeof(int));
    if (leak == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Use the allocated memory
    for (int i = 0; i < 10; i++) {
        leak[i] = i * 10;
    }

    printf("Allocated memory for 10 integers on the heap.\n");

    // Intentionally not freeing the allocated memory to simulate a leak.
    // free(leak); // This line is commented out to create a memory leak.

    return 0;
}