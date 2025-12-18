#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Starting memory leak simulation...\n");

    // Loop 100,000 times to see noticeable effect
    for (int i = 0; i < 100000; i++)
    {
        int *leak = (int *)malloc(1000 * sizeof(int)); // 4KB each iteration

        if (leak == NULL)
        {
            printf("Allocation failed at iteration %d\n", i);
            break;
        }

        // Use the memory a bit
        leak[0] = i;

        // INTENTIONALLY DON'T FREE!
        // free(leak);  // <-- This line is commented out to create the leak

        if (i % 10000 == 0)
        {
            printf("Iteration %d - allocated %d KB so far\n",
                   i, (i + 1) * 1000 * sizeof(int) / 1024);
        }
    }

    printf("Loop finished. Press Enter to exit (memory will leak until then).\n");
    getchar(); // Wait, so you can observe memory usage
    return 0;
}