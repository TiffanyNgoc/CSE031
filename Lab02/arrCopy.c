#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int size; // Variable to record size of original array arr
int evenCount = 0, oddCount = 0; // Variables to record sizes of new arrays arr_even and arr_odd
int *arr; // Dynamically allocated original array with #elements = size
int *arr_even;  // Dynamically allocated array with #elements = #even elements in arr (evenCount)
int *arr_odd;   // Dynamically allocated array with #elements = #odd elements in arr (oddCount)
char *str1 = "Original array's contents: ";
char *str2 = "Contents of new array containing even elements from original: ";
char *str3 = "Contents of new array containing odd elements from original: ";

/*
 * DO NOT change the definition of the printArr function when it comes to 
 * adding/removing/modifying the function parameters, or changing its return 
 * type. 
 */
void printArr(int *a, int size, char *prompt) {

    int i; // used to go through the array

    // print the message that was passed into the function
    printf("%s", prompt);

    // if the array has no elements, print empty
    if (size == 0) {
        printf("empty\n");
    }
    else {

    // go through every element in the array
    // loop through every element in the array one at a time
    // i starts at 0 because the first array element is at position 0
    // the loop keeps running as long as i is less than size
    // after each loop, i++ increases i by 1 to move to the next element
    for (i = 0; i < size; i++) {

    // a is a pointer that points to the beginning of the array
    // (a + i) gives the memory address of the element at position i
    // the * dereferences that address, meaning it gets the actual value stored there
    // so *(a + i) gets the value of the current array element
    // this is the pointer version of a[i], since the assignment does not allow []
    // %d tells printf that the value being printed is an integer
    // the space after %d puts a space between each number in the output
    printf("%d ", *(a + i));
}

// after all of the array elements are printed,
// \n moves the output to the next line
printf("\n");
    }
}

/* 
 * DO NOT change the definition of the arrCopy function when it comes to 
 * adding/removing/modifying the function parameters, or changing its return 
 * type. 
 */
void arrCopy() {

    int i; // used to go through the original array and to keep track of position

    // tells me where to put the next even number
    int evenIndex = 0;

    // tells me where to put the next odd number
    int oddIndex = 0;


    // go through every number in the original array
    for (i = 0; i < size; i++) {

        // *(arr + i) gets the current number
        // % 2 checks the remainder after dividing by 2
        // remainder of 0 means the number is even
        if (*(arr + i) % 2 == 0) {

            // copy the current number into the even array
            *(arr_even + evenIndex) = *(arr + i);

            // move to the next spot in the even array
            evenIndex = evenIndex + 1;
        }
        else {

            // if it is not even, copy it into the odd array
            *(arr_odd + oddIndex) = *(arr + i);

            // move to the next spot in the odd array
            oddIndex = oddIndex + 1;
        }
    }
}

int main() {

    // i is my loop counter and keeps track of which array position I am on
    int i;

    // ask the user how many elements they want in the original array
    printf("Enter the size of array you wish to create: ");

    // %d means I am reading an integer
    // scanf needs the address of size so it knows where to store the input
    // & means "address of", so &size gives scanf the address of size
    scanf("%d", &size);


    // dynamically allocate enough memory to hold "size" integers
    // sizeof(int) gives the number of bytes needed for one integer
    // size * sizeof(int) calculates the total number of bytes needed
    // malloc returns the starting address of that memory
    // arr stores that address because arr is an integer pointer
    arr = malloc(size * sizeof(int));


    // go through every position in the original array
    // i starts at 0 because arrays start at position 0
    // i < size makes sure I only access valid positions
    // i++ moves to the next position after each loop
    for (i = 0; i < size; i++) {

        // ask the user for the value that will go into the current position
        // i + 1 is only used for the displayed number so the prompt says
        // #1, #2, #3 instead of #0, #1, #2
        printf("Enter array element #%d: ", i + 1);

        // arr + i gives the address of the current array position
        // scanf needs an address, so I do not need & here because
        // arr is already a pointer and arr + i is already an address
        scanf("%d", arr + i);


        // *(arr + i) gets the actual value that the user just entered
        // % 2 finds the remainder after dividing that value by 2
        // if the remainder is 0, the number is even
        if (*(arr + i) % 2 == 0) {

            // increase evenCount because I found another even number
            // I will later use evenCount to know how large arr_even needs to be
            evenCount = evenCount + 1;
        }
        else {

            // if the number is not even, it is odd
            // increase oddCount because I found another odd number
            // I will later use oddCount to know how large arr_odd needs to be
            oddCount = oddCount + 1;
        }
    }


    // create exactly enough memory for all the even numbers
    arr_even = malloc(evenCount * sizeof(int));

    // create exactly enough memory for all the odd numbers
    arr_odd = malloc(oddCount * sizeof(int));
	
/*************** YOU MUST NOT MAKE CHANGES BEYOND THIS LINE! ***********/
	
	// Print original array
    printArr(arr, size, str1);

	/// Copy even elements of arr into arr_even and odd elements into arr_odd
    arrCopy();

    // Print new array containing even elements from arr
    printArr(arr_even, evenCount, str2);

    // Print new array containing odd elements from arr
    printArr(arr_odd, oddCount, str3);

    printf("\n");

    return 0;
}