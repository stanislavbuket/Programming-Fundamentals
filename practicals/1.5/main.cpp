/**
 * Done by:
 * Student Name: Severyn Kotyhoroshko
 * Student Group: 123
 * Lab 1.5
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void initRandomizer() {
    // Seed the random number generator with the current time
    srand(time(0));  // srand(time(NULL)) could also be used
}

int main() {
    // A sequence of values A[n] is given. Find the minimum value in the sequence.
    {
        initRandomizer();

        int n;
        cout << "Enter the length of the sequence: ";
        cin >> n;

        std::vector<int> myVector;
        // Populate the array with random values
        for (int i = 0; i < n; i++) {
            // arr[i] = rand();
            int randomVar = (rand() % 100) - 50;
            myVector.push_back(randomVar);
        }

        // cout the array
        for (int i = 0; i < n; i++) {
            cout << myVector[i] << " ";
        }
        cout << endl;

        int min = myVector[0];
        for (int i = 1; i < n; i++) {
            if (myVector[i] < min) {
                min = myVector[i];
            }
        }

        cout << "The minimum value in the sequence is: " << min << endl;
    }

    return 0;
}
