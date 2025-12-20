#include <stdio.h>
#include <stddef.h> // For offsetof()

struct Memory
{
    char b; // 1 byte
    char d[3]; // 3 bytes
    int a; // 4 bytes
    double c; // 8 bytes
};

int main(){
    printf("The size of Memory struct: %zu bytes\n", sizeof(struct Memory));
}
