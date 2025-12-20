#include <stdio.h>
#include <stdlib.h> // For malloc() and free()
#include <string.h> // For strcpy()

int main()
{
    printf("=== STACK VARIABLE (automatic) ===\n");
    int stack_var = 100;
    printf("stack_var lives at: %p, value: %d\n", (void *)&stack_var, stack_var);
    // It will be automatically destroyed when main() ends.

    printf("\n=== HEAP ALLOCATION (manual) ===\n");

    // 1. malloc() — Memory ALLOCation.
    // Ask the OS for memory to hold 1 integer on the heap.
    int *heap_var = (int *)malloc(sizeof(int));
    if (heap_var == NULL)
    {
        printf("Memory allocation failed! Exiting.\n");
        return 1; // Always check if malloc succeeded!
    }

    // 2. Use the allocated memory via the pointer.
    *heap_var = 200;
    printf("heap_var pointer lives at (on stack): %p\n", (void *)&heap_var);
    printf("heap_var points to (on heap): %p, value there: %d\n",
           (void *)heap_var, *heap_var);

    // 3. Allocate an array on the heap.
    int array_size = 5;
    int *heap_array = (int *)malloc(array_size * sizeof(int));
    if (heap_array == NULL)
    {
        return 1;
    }

    for (int i = 0; i < array_size; i++)
    {
        heap_array[i] = i * 100; // Use just like a stack array!
    }

    printf("\nHeap array values: ");
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", heap_array[i]);
    }
    printf("\n");

    // Task 1
    char name_size = 4;
    char *name_array = (char *)malloc(name_size * sizeof(char));
    if (name_array == NULL) {
        return 1;
    }

    strcpy(name_array, "Jev");
    printf("My name is: %s\n", name_array);

    // 4. FREEING MEMORY — CRITICAL.
    // Every malloc() MUST have a corresponding free().
    free(heap_var);   // Return the single integer's memory.
    free(heap_array); // Return the array's memory.
    free(name_array); // Return the name array's memory.

    printf("\nMemory freed. Pointers still exist but are now DANGLING.\n");
    printf("heap_var still points to: %p\n", (void *)heap_var);
    printf("Accessing *heap_var now is UNDEFINED BEHAVIOR (crash or garbage).\n");

    // Good practice: Set pointer to NULL after free.
    heap_var = NULL;
    heap_array = NULL;
    name_array = NULL;

    return 0;
    // stack_var is automatically cleaned up here.
}