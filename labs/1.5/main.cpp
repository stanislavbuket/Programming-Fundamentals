/**
 * Done by:
 * Student Name: Stanislav Buket
 * Variant: 4
 * Student Group: 121
 * Lab 1.5
 */

#include <iostream>

using namespace std;

class Lab1_5 {
public:
    // Constructor
    Lab1_5() {
        part1();
        part2();
    }

private:
    void part1() {
        // Set 1
        int A1 = 66;
        double B1 = 12.9;
        int C1 = 62;
        int D1 = 59;

        // Expression calculation for set 1
        bool result1 = !(!(A1 != B1) && (C1 < D1));
        cout << "Result for set 1: " << boolalpha << result1 << endl;

        // Set 2
        double A2 = 3.56;
        double B2 = 89.45;
        int C2 = 15;
        double D2 = 56.2;

        // Expression calculation for set 2
        bool result2 = !(!(A2 != B2) && (C2 < D2));
        cout << "Result for set 2: " << boolalpha << result2 << endl;
    }

    void part2() {
        // Variable values for variant 4
        int A = 593;
        int B = -145;
        float C = 9.23;
        int D = 43;
        int E = 891;
        short F = sizeof(short);

        // Expression using operations specified in the tables
        int L_result = (((A ^ (B >> 1)) / C) * (-D) * sizeof(E)) < F;

        cout << "Calculation result for Part 2: " << L_result << endl;
    }
};

int main() {
    // Creating an object of the class to execute both parts
    Lab1_5 lab;
    return 0;
}
