#include <stdio.h>

int main() {
    int count; // Variable to store the repetition count
    int mistake; // Variable to store the line number where the typo will be inserted

    // 1. Get and validate 'count'
    printf("Enter the repetition count for the punishment phrase: "); // Prompt the user for the repetition count
    while (scanf("%d", &count) != 1 || count < 1) { // Validate the repetition count input
        printf("Invalid repetition count. Please enter a positive number: "); // Prompt the user again if the input is invalid
    }

    // 2. Get and validate 'mistake' second (now that we know 'count' is valid)
    printf("Enter the line where you want to insert the typo: "); // Prompt the user for the line number where the typo will be inserted
    while (scanf("%d", &mistake) != 1 || mistake < 1 || mistake > count) { // Validate the line number input
        printf("Invalid line number. Please enter a number between 1 and %d: ", count); // Prompt the user again if the input is invalid
    }

    // 3. Print the punishment phrase with the intentional typo on the specified line
    for (int i = 0; i < count; i++) { // Loop to print the punishment phrase 'count' times
        if (i == mistake - 1) { // Check if the current line is the one where the typo should be inserted
            printf("Coding with C is awsome!.\n"); // Intentional typo
        } else { // If it's not the line with the typo, print the correct phrase
            printf("Coding with C is awesome!.\n"); // Correct phrase
        }
    }
    return 0;
}
