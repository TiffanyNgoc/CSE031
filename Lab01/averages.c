#include <stdio.h> // lets me use printf and scanf

int main() {

    // stores the number the user enters
    int number;

    // keeps track of which value the user is entering
    int counter = 1;

    // keeps track of the total and amount of numbers
    // whose digits add up to an even number
    int even_sum = 0;
    int even_count = 0;

    // same thing but for numbers whose digits add up to an odd number
    int odd_sum = 0;
    int odd_count = 0;

    // temp is a copy of the number so I don't change the original
    // digit stores one digit at a time
    // digit_sum keeps track of all the digits added together
    int temp;
    int digit;
    int digit_sum;

    // doubles because averages can have decimals
    double even_average;
    double odd_average;


    // keeps asking for numbers until I break out of the loop
    while (1) {

        // counter tells me which input I am currently on
        // I need separate ones for 1st, 2nd, and 3rd
        if (counter == 1) {
            printf("Enter the 1st value: ");
        }
        else if (counter == 2) {
            printf("Enter the 2nd value: ");
        }
        else if (counter == 3) {
            printf("Enter the 3rd value: ");
        }
        else {
            // %d puts the counter number into the sentence
            printf("Enter the %dth value: ", counter);
        }

        // gets an integer from the user and stores it in number
        // &number gives scanf the location of the variable
        scanf("%d", &number);


        // 0 means the user is done entering numbers
        if (number == 0) {
            break;
        }


        // make a copy because I am going to change temp
        // but I still need the original number later
        temp = number;


        // if the number is negative, make the copy positive
        // I only care about the digits when finding digit_sum
        if (temp < 0) {
            temp = -temp;
        }


        // reset this to 0 for every new number
        digit_sum = 0;


        // go through every digit in the number
        while (temp > 0) {

            // % 10 gets the last digit
            // example: 123 % 10 gives me 3
            digit = temp % 10;

            // add that digit to my running digit total
            digit_sum = digit_sum + digit;

            // divide by 10 to remove the last digit
            // example: 123 / 10 becomes 12 since temp is an int
            temp = temp / 10;
        }


        // % 2 checks if the digit sum is even
        // if the remainder is 0, it is even
        if (digit_sum % 2 == 0) {

            // add the ORIGINAL number to the even total
            even_sum = even_sum + number;

            // keep track of how many numbers are in the even group
            even_count = even_count + 1;
        }
        else {

            // if the digit sum wasn't even, it is odd
            // add the original number to the odd total
            odd_sum = odd_sum + number;

            // keep track of how many numbers are in the odd group
            odd_count = odd_count + 1;
        }


        // move on to the next input number
        counter = counter + 1;
    }


    // prints a blank line before showing the averages
    printf("\n");


    // only calculate this if I actually have numbers in the even group
    // this also prevents me from dividing by 0
    if (even_count > 0) {

        // average = total / amount
        // (double) makes sure I get a decimal answer
        even_average = (double) even_sum / even_count;

        // %.2f prints the average to 2 decimal places
        printf("Average of input values whose digits sum up to an even number: %.2f\n",
               even_average);
    }


    // same thing for the odd group
    if (odd_count > 0) {

        // cast to double so I get decimal division
        odd_average = (double) odd_sum / odd_count;

        // print the odd average to 2 decimal places
        printf("Average of input values whose digits sum up to an odd number: %.2f\n",
               odd_average);
    }


    // if both counts are still 0, the user entered 0 right away
    // so there aren't any numbers to average
    if (even_count == 0 && odd_count == 0) {
        printf("There is no average to compute.\n");
    }


    // 0 means the program finished successfully
    return 0; 
}