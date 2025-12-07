#include <stdio.h>

int main() {
    float my_float = 3.14;
    printf("Value of my_float is: %.2f\n", my_float);
    printf("Address of my_float is: %p\n", (void*)&my_float);
    printf("Size of my_float is: %zu bytes\n", sizeof(my_float));
    
    char *my_string = "Hello";
    printf("Address of my_string is: %p\n", (void*)&my_string);
    printf("Size of my_string pointer is: %zu bytes\n", sizeof(my_string));
	return 0;
}