#include <stdio.h>

int main() {
    int x, y, *px, *py; // Declare two integers and two pointers to integers
    int arr[10]; // Declare an array of 10 integers

    printf("x = %d, y = %d, px = %p, py = %p, arr = %p\n", x, y, (void*)px, (void*)py, (void*)arr); // Print the values of x, y, px, py, and arr (uninitialized values)

    return 0;
}