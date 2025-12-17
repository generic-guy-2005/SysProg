#include <stdio.h>
#include <windows.h> // For Windows-specific functions

int main()
{
    printf("Testing NULL pointer dereference...\n");

    // Force a crash and see what happens
    int *p = NULL;

    printf("Pointer value: %p\n", (void *)p);
    printf("About to dereference...\n");
    fflush(stdout); // Make sure output appears before crash

    // This should crash
    int x = *p;

    printf("You should never see this line.\n");
    return 0;
}