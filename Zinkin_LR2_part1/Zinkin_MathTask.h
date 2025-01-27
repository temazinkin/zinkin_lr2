#ifndef _SURNAME_MATHTASK_H_
#define _SURNAME_MATHTASK_H_

#include <cstring>
using namespace std;

bool UserInput (string input) {
    if (input.empty()) return false;
    try {
        int number = stoi(input);
    }
    catch (...) {
        return false;
    }
    return true;
}

int CalcRectangleArea(int NumberA, int NumberB) {
    return NumberA * NumberB;
}

#endif
