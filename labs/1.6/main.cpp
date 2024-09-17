/**
 * Done by:
 * Student Name: Stanislav Buket
 * Variant: 4
 * Student Group: 121
 * Lab 1.6
 */

#include <iostream>

void main() {
    // Part 1: Study of character types
    // Declaration of character type variables
    char symb1, symb2, symb3;

    // Declaration of character type constants
    const char CONST_SYMB1 = 'S';
    const char CONST_SYMB2 = '6';
    const char CONST_SYMB3 = '?';

    char ch1 = 'S';
    char ch2 = '6';
    char ch3 = '?';

    symb1 = 0x11; // 'S'
    symb2 = 0x4f; // '6'
    symb3 = 0x2c; // '?'

    // Part 2: Study of type casting mechanism

    int nA;
    float fltB;
    unsigned short wC;

    nA = 9742;
    fltB = -3.54e3;
    wC = 34033;

    double dblD;
    int nE;
    char chF;

    // Initializing variables using implicit type casting
    dblD = nA;
    nE = fltB;
    chF = wC;

    // Initializing variables using explicit type casting
    dblD = (double)nA;
    nE = (int)fltB;
    chF = (char)wC;

    // Initializing variables using strict typecasting bypass mechanism
    double* pdblD;
    void* pV;

    pV = &nA;
    pdblD = (double*)pV;
    dblD = *pdblD;

    int* pnE;
    pV = &fltB;
    pnE = (int*)pV;
    nE = *pnE;

    char* pchF;
    pV = &wC;
    pchF = (char*)pV;
    chF = *pchF;
}
