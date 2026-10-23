#include <stdio.h>
#include <stdlib.h>

int* bubbleSort(int arr[], int n) {
    int temp, i = 0, j = 0;
    int *s_arr = (int *) malloc(n * sizeof(int));

    // Copy arr to s_arr
    for(i = 0; i < n; i++)
        s_arr[i] = arr[i];

    // Sorting using array notations
	// Comment this when implementing pointer version.
    // for (i = 0; i < n - 1; i++) {
    //     for(j = 0; j < n - 1; j++) {
    //         if(s_arr[j] > s_arr[j + 1]) {
    //             temp = s_arr[j + 1];
    //             s_arr[j + 1] = s_arr[j];
    //             s_arr[j] = temp;
    //         }
    //     }
    // }

    // Sorting using pointer notations. i.e. you cannot use "[]"!
    // Your code goes here...

    // Go through the array multiple times to sort the numbers
    for (i = 0; i < n - 1; i++) {

        // Compare each number with the number next to it
        for (j = 0; j < n - 1; j++) {

            // Get the current number and the next number using pointers
            // If the current number is bigger, swap them
            if (*(s_arr + j) > *(s_arr + j + 1)) {

                // Save the next number so we don't lose it
                temp = *(s_arr + j + 1);

                // Move the bigger number to the next position
                *(s_arr + j + 1) = *(s_arr + j);

                // Put the saved smaller number in the current position
                *(s_arr + j) = temp;
            }
        }
    }


    return s_arr;

}

void printArray(int arr[], int n) {
    int i = 0;
    printf("[");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("]\n");
}

int bSearch(int *arr, int a, int b, int key) {
    // Binary search function. arr is the array, key is the value to search for, a and b are the boundaries of arr to be searched within.
    // You must use pointer notations. i.e. no "[]"
    // Your code goes here:

    int middle; // Store the middle index of the array

    // If the starting index is bigger than the ending index,
    // there are no more numbers to search, so return -1
    if (a > b) {
        return -1;
    }

    // Find the middle index between a and b
    middle = a + (b - a) / 2;

    // Check if the middle number is the number we want
    // *(arr + middle) gets the value at the middle index
    if (*(arr + middle) == key) {

        // If we found the number, return its index
        return middle;
    }

    // If the number we want is smaller than the middle number,
    // search only the left half of the array
    else if (key < *(arr + middle)) {

        // Call the same function again with a smaller ending index
        return bSearch(arr, a, middle - 1, key);
    }

    // Otherwise, the number must be bigger than the middle number
    else {

        // Call the same function again to search the right half
        return bSearch(arr, middle + 1, b, key);
    }
}

int main() {

    int i = 0, size = 0, key = 0, result = 0;
    int *array, *sorted;

    printf("How big is your array? ");
    scanf("%d", &size);
    array = (int *) malloc(size * sizeof(int));

    for(i = 0; i < size; i++) {
        printf("Please enter array[%d]: ", i);
        scanf("%d", &array[i]);
    }

    printf("Please wait while I sort your numbers...\n");
    sorted = bubbleSort(array, size);
    printf("Here is your original array:\n");
    printArray(array, size);
    printf("Here is your SORTED array: \n");
    printArray(sorted, size);
    printf("What number are you looking for? ");
    scanf("%d", &key);
    printf("OK, let me see if I can find a \"%d\" in the array...\n", key);
    result = bSearch(sorted, 0, size-1, key);
    if(result != -1)
        printf("Got it! A \"%d\" is at index %d.\n", key, result);
    else
        printf("I'm sorry, \"%d\" cannot be found in the array.\n", key);

	return 0;


}


