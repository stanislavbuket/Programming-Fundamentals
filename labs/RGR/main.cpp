/**
 * Done by:
 * Student Name: Stanislav Buket
 * Student Group: 121
 * RGR
 */

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

bool isInLanguage(const string& s) {
    if (s.empty()) return false;

    size_t i = 0;
    if (s[0] == '_') {
        //return true if all remaining characters are digits
        return s.size() > 1 && all_of(s.begin() + 1, s.end(), ::isdigit);
    }

    //check if the string starts with an uppercase letter
    if (isupper(s[0])) {
        //move i to the first non-uppercase character
        while (i < s.size() && isupper(s[i])) i++;
        //return true if the string ends or contains '_' at the end
        return i == s.size() || (s[i] == '_' && i + 1 == s.size());
    }

    return false;
}

int main() {
    string input;
    cout << "Enter a chain: ";
    cin >> input;

    cout << "Chain " << input
         << (isInLanguage(input) ? " belongs to L(V)" : " does not belong to L(V)")
         << endl;

    return 0;
}