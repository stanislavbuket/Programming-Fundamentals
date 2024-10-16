/**
* Done by:
 * Student Name: Stanislav Buket
 * Student Group: 121
 * RGR
 */

#include <algorithm> //for std::all_of
#include <iostream> //for input-output operations
#include <string> //for std::string
using namespace std;

//checks if the string belongs to L(V)
bool isInLanguage(const string& s) {
    if (s.empty()) return false; //empty string does not belong to L(V)
    size_t i = 0;

    if (s[0] == '_')
        return s.size() > 1 && all_of(s.begin() + 1, s.end(), ::isdigit); //all characters after '_' must be digits

    if (isupper(s[0])) { //if starts with an uppercase letter
        while (i < s.size() && isupper(s[i])) i++; //iterate through uppercase letters
        return i == s.size() || (s[i] == '_' && i + 1 == s.size()); //valid if it ends or ends with '_'
    }
    return false; //does not fit any valid pattern
}

int main() {
    string input;
    cout << "Enter a chain: "; //prompt user to input a string
    cin >> input; //read user input

    //output whether the input string belongs to L(V)
    cout << "Chain " << input
         << (isInLanguage(input) ? " belongs to L(V)" : " does not belong to L(V)")
         << endl;

    return 0; //indicate successful program termination
}