/**
 * Done by:
 * Student Name: Stanislav Buket
 * Student Group: 121
 * Variant: 4
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
        //if the first character is '_', all following characters must be digits
        return s.size() > 1 && all_of(s.begin() + 1, s.end(), ::isdigit);

    if (isupper(s[0])) { //if the string starts with an uppercase letter
        //iterate through all consecutive uppercase letters
        while (i < s.size() && isupper(s[i])) i++;

        //valid if:
        //1) string ends right after uppercase letters, or
        //2) string ends with a single '_'
        return i == s.size() || (s[i] == '_' && i + 1 == s.size());
    }

    //if it does not meet the required structure, return false
    return false;
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

/**
* Explanation:
* 1. This program checks if a given string conforms to the syntax rules of L(V).
* 2. The function `isInLanguage` follows two primary rules:
*  - If the string starts with an underscore `_`, all following characters must be digits (e.g., `_03348` is valid).
*  - If the string starts with uppercase letters, it can contain only uppercase letters and may optionally end with a single underscore (e.g., `SPT_` is valid, but `SPT4398` is not).
* 3. If the input string matches one of these patterns, the function returns `true`. If not, it returns `false`.
*/
