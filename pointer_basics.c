#include <stdio.h>

int main()
{
    int treasure = 777;   // An integer variable.
    int *map = &treasure; // A pointer variable. Holds the ADDRESS of 'treasure'.

    printf("1. The treasure itself: %d\n", treasure);
    printf("2. Location of the treasure (its address): %p\n", (void *)&treasure);
    printf("3. What's written on our 'map' (the pointer's value): %p\n", (void *)map);
    printf("4. Does the map's value equal treasure's address? %s\n",
           (map == &treasure) ? "YES" : "NO");

    // THE KEY OPERATION: DEREFERENCING
    printf("5. Following the map to the treasure (dereferencing): %d\n", *map);

    // We can use the map to CHANGE the treasure.
    *map = 999;                                      // Go to the address in 'map' and put 999 there.
    printf("6. New treasure value: %d\n", treasure); // It changed!

    // Pointer arithmetic: Navigating the array of memory.
    int numbers[] = {10, 20, 30, 40, 50};
    int *ptr = numbers; // Point to the first element. Equivalent to &numbers[0]

    printf("\n7. Array traversal via pointer:\n");
    for (int i = 0; i < 5; i++)
    {
        // Two ways to get the same value:
        printf("  numbers[%d] = %d | *(ptr + %d) = %d\n",
               i, numbers[i], i, *(ptr + i));
        // (ptr + i) calculates: address_of_ptr + (i * sizeof(int))
    }

    char letters[] = {'A', 'B', 'C', 'D', 'E'};
    char *char_ptr = letters; // Point to the first element.

    printf("\n8. Character array traversal via pointer:\n");
    for (int i = 0; i < 5; i++) 
    {
        printf("  letters[%d] = %c | *(char_ptr + %d) = %c\n",
               i, letters[i], i, *(char_ptr + i));
    }

    printf("Size of treasure variable: %zu bytes\n", sizeof(treasure));
    printf("Size of map pointer: %zu bytes\n", sizeof(map));

    return 0;
}