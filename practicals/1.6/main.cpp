/**
* Done by:
 * Student Name: Stanislav Buket
 * Student Group: 121
 * Practice 1.6
 */

#include <iostream>
#include <vector>

using namespace std;

bool areEqual(int a, int b) {
  int bitSize = sizeof(int) * 8; // Number of bits in an integer

  // Compare bit-by-bit
  for (int i = 0; i < bitSize; i++) {
    if ((a & (1 << i)) != (b & (1 << i))) {
      return false; // Return false if bits differ
    }
  }
  return true; // Numbers are equal
}

bool isMultipleOf8(int a) {
  // 7 in binary is 00000111
  // If a & 7 == 0, then a is a multiple of 8
  int mask_binary = 0b00000111; // 7 in binary
  return (a & mask_binary) == 0;
}

void printVector(const std::vector<int>& vec) {
  for (int i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << " "; // Print each element of the vector
  }
  std::cout << std::endl;
}

// Task 1: Count the number of 1s and 0s in the binary representation of a number
int countOnes(int a) {
  int onesCount = 0;
  int bitSize = sizeof(int) * 8; // Number of bits in an integer

  for (int i = 0; i < bitSize; i++) {
    if (a & (1 << i)) {
      onesCount++; // Increment if the bit is 1
    }
  }

  return onesCount;
}

void compareBits(int a) {
  int onesCount = countOnes(a);
  int bitSize = sizeof(int) * 8; // Number of bits in an integer
  int zerosCount = bitSize - onesCount; // Calculate the number of 0s

  std::cout << "Number of 1s: " << onesCount << std::endl;
  std::cout << "Number of 0s: " << zerosCount << std::endl;

  if (onesCount > zerosCount) {
    std::cout << "There are more 1s than 0s in the binary representation." << std::endl;
  } else if (onesCount < zerosCount) {
    std::cout << "There are more 0s than 1s in the binary representation." << std::endl;
  } else {
    std::cout << "There is an equal number of 1s and 0s in the binary representation." << std::endl;
  }
}

// Task 2: Simulate XOR operation for two sequences
void xorOperation(const std::vector<int>& a, const std::vector<int>& b, std::vector<int>& r_xor) {
  int n = a.size(); // Length of sequences
  for (int i = 0; i < n; i++) {
    r_xor[i] = a[i] ^ b[i]; // Perform XOR on each pair of bits
  }
}

int main() {
  // Task 1: Compare two integers bit by bit
  {
    int a, b;
    std::cout << "Enter two integers: ";
    std::cin >> a >> b;

    if (areEqual(a, b)) {
      std::cout << "The numbers are equal." << std::endl;
    } else {
      std::cout << "The numbers are not equal." << std::endl;
    }
  }

  // Task 2: Check if a number is a multiple of 8
  {
    int a;
    std::cout << "Enter an integer: ";
    std::cin >> a;

    if (isMultipleOf8(a)) {
      std::cout << "The number is a multiple of 8." << std::endl;
    } else {
      std::cout << "The number is not a multiple of 8." << std::endl;
    }
  }

  // Task 3: Determine if a number has more 1s or 0s in its binary representation
  {
    int a;
    std::cout << "Enter an integer to compare bits: ";
    std::cin >> a;
    compareBits(a);
  }

  // Task 4: Simulate XOR operation for two binary sequences
  {
    int n = 10; // Length of sequences
    std::vector<int> a(n), b(n), r_xor(n);

    // Generate random binary sequences
    for (int i = 0; i < n; i++) {
      a[i] = rand() % 2;
      b[i] = rand() % 2;
    }

    // Perform XOR operation
    xorOperation(a, b, r_xor);

    // Print the results
    std::cout << "A  : ";
    printVector(a);
    std::cout << "B  : ";
    printVector(b);
    std::cout << "XOR: ";
    printVector(r_xor);
  }

  return 0;
}
