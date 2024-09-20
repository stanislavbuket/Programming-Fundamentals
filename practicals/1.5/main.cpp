/**
 * Done by:
 * Student Name: Stanislav Buket
 * Student Group: 121
 * Lab 1.5
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

void initRandomizer() {
    // Seed the random number generator with the current time
    srand(time(0));  // srand(time(NULL)) could also be used
}

// Function to find the index of the first occurrence of P in the sequence
int findFirstOccurrence(const vector<int>& myVector, int P) {
    for (int i = 0; i < myVector.size(); i++) {
        if (myVector[i] == P) {
            return i; // Returns the index of the first occurrence
        }
    }
    return -1; // If P is not found
}

// Function to find the smallest positive element in the sequence
int findMinPositive(const vector<int>& myVector) {
    int minPositive = -1;
    for (int i = 0; i < myVector.size(); i++) {
        if (myVector[i] > 0 && (minPositive == -1 || myVector[i] < minPositive)) {
            minPositive = myVector[i];
        }
    }
    return minPositive;
}

// Function to swap the largest and smallest elements in the sequence
void swapMinMax(vector<int>& myVector) {
    int minIndex = 0, maxIndex = 0;
    for (int i = 1; i < myVector.size(); i++) {
        if (myVector[i] < myVector[minIndex]) {
            minIndex = i;
        }
        if (myVector[i] > myVector[maxIndex]) {
            maxIndex = i;
        }
    }
    swap(myVector[minIndex], myVector[maxIndex]);
}

int main() {
    initRandomizer();

    int n, P;
    cout << "Enter the length of the sequence: ";
    cin >> n;

    vector<int> myVector;
    // Populate the array with random values
    for (int i = 0; i < n; i++) {
        int randomVar = (rand() % 100) - 50;
        myVector.push_back(randomVar);
    }

    // Output the array
    for (int i = 0; i < n; i++) {
        cout << myVector[i] << " ";
    }
    cout << endl;

    // Task 1: Find the index of the first occurrence of P
    cout << "Enter the value to find (P): ";
    cin >> P;

    int index = findFirstOccurrence(myVector, P);
    if (index != -1) {
        cout << "First occurrence of " << P << " is at index: " << index << endl;
    }
    else {
        cout << P << " not found in the sequence." << endl;
    }

    // Task 2: Find the smallest positive element
    int minPositive = findMinPositive(myVector);
    if (minPositive != -1) {
        cout << "The minimum positive value is: " << minPositive << endl;
    }
    else {
        cout << "No positive values in the sequence." << endl;
    }

    // Task 3: Swap the largest and smallest elements
    swapMinMax(myVector);
    cout << "Sequence after swapping the min and max values: ";
    for (int i = 0; i < n; i++) {
        cout << myVector[i] << " ";
    }
    cout << endl;

    return 0;
}
