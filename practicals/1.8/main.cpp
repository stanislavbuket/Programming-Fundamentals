/**
* Done by:
 * Student Name: Stanislav Buket
 * Student Group: 121
 * Practice 1.8
 */

#include <iostream>

// Function to check if a number is even
int isEven(int number) {
    return (number & 1) == 0;
}

// Function to count the number of 1 bits in a number
int countOnes(int number) {
    int count = 0;
    while (number) {
        count += number & 1;
        number >>= 1;
    }
    return count;
}

// Function to check if a bit is set at a specific position
int checkBit(int number, int position) {
    return (number & (1 << position)) != 0;
}

int main() {
    int num = 15;  // Example number
    int pos = 3;   // Example bit position

    // Use the functions without any print statements
    int even = isEven(num);
    int onesCount = countOnes(num);
    int bitCheck = checkBit(num, pos);

    return 0;
}
