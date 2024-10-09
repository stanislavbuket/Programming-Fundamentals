/**
* Done by:
 * Student Name: Stanislav Buket
 * Student Group: 121
 * Lab: 2.1
 */

#include <iostream>

using namespace std;

//function for bubble sort
void bubbleSort(int arr[], int n, bool ascending = true) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ascending) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            } else {
                if (arr[j] < arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
}

//function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    //task 1
    int arr1[11];

    //initializing the array according to the formulas
    for (int i = 0; i < 11; i++) {
        if (i % 2 == 0) {
            arr1[i] = 6 * i - 9;
        } else {
            arr1[i] = -9 + 2 * i;
        }
    }

    cout << "task 1:\n";
    cout << "array before sorting: ";
    printArray(arr1, 11);

    //sorting the array in ascending order
    bubbleSort(arr1, 11);
    cout << "array after sorting in ascending order: ";
    printArray(arr1, 11);

    //sorting the array in descending order
    bubbleSort(arr1, 11, false);
    cout << "array after sorting in descending order: ";
    printArray(arr1, 11);

    //task 2
    int arr2[10], arr3[10], arr4[10];
    int k = 0;

    //initializing two arrays
    for (int i = 0; i < 10; i++) {
        arr2[i] = 43 - i;
        arr3[i] = 37 + i;
    }

    //finding common elements
    for (int i : arr2) {
        for (int j : arr3) {
            if (i == j) {
                arr4[k] = i;
                k++;
                break;
            }
        }
    }

    //printing the common elements
    cout << "\ntask 2:\n";
    cout << "common elements: ";
    printArray(arr4, k);

    //finding the product of elements greater than 40
    int mult = 1;
    for (int i = 0; i < k; i++) {
        if (arr4[i] > 40) {
            mult *= arr4[i];
        }
    }
    cout << "product of elements greater than 40: " << mult << endl;

    return 0;
}