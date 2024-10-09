/**
* Done by:
 * Student Name: Stanislav Buket
 * Student Group: 121
 * Lab: 2.2
 */

#include <iostream>

using namespace std;

enum Names { David, Tom, Andrew, Kate, Mary, Olga };

//struct representing a student
struct Student {
    Names name;
    int yearOfStudy;
    bool army;
};

//function to convert enum Names to string
string getName(Names name) {
    switch (name) {
        case David: return "David";
        case Tom: return "Tom";
        case Andrew: return "Andrew";
        case Kate: return "Kate";
        case Mary: return "Mary";
        case Olga: return "Olga";
        default: return "Unknown";
    }
}

int main() {
    //array of students
    Student students[7] = {
        { Tom, 2, true },
        { David, 1, false },
        { Kate, 2, false },
        { Andrew, 3, true },
        { Olga, 2, false },
        { Mary, 1, true },
        { Andrew, 2, false }
    };

    //count of students on the 2nd year who haven't served in the army
    int count = 0;

    //iterating through the array to find students who meet the condition
    for (auto & student : students) {
        if (student.yearOfStudy == 2 && !student.army) {
            count++;
        }
    }

    //calculating the percentage of such students
    float percent = (float)count * 100 / 7;
    cout << "percentage of 2nd-year students who haven't served in the army: " << percent << "%" << endl;

    return 0;
}
