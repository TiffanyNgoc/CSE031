#include <stdio.h>
#include <stdlib.h>

 int main() {
	int num;
	int *ptr;
	int **handle;

	num = 14;
	ptr = (int *) malloc(2 * sizeof(int));
	*ptr = num;
	handle = (int **) malloc(1 * sizeof(int *));
	*handle = ptr;

	// Insert code here
	
	// print the addresses of my 3 local variables
	// & gives me the memory address of a variable
	// %p prints a memory address
	printf("Address of num: %p\n", (void *)&num);
	printf("Address of ptr: %p\n", (void *)&ptr);
	printf("Address of handle: %p\n", (void *)&handle);

	// print the actual value stored in num
	printf("Value of num: %d\n", num);

	// ptr stores the address of the allocated memory on the heap
	printf("Value of ptr: %p\n", (void *)ptr);

	// *ptr gets the integer stored at the address ptr points to
	printf("Value pointed to by ptr: %d\n", *ptr);

	// handle stores the address of another heap allocation
	printf("Value of handle: %p\n", (void *)handle);

	// *handle gets the pointer stored in that heap allocation
	printf("Value pointed to by handle: %p\n", (void *)*handle);

	// **handle follows both pointers to get the integer value
	printf("Value pointed to by *handle: %d\n", **handle);

	return 0;
} 

