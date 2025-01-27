#include <iostream>
#include <cstring>

using namespace std;

bool UserInput(string input) {
    if (input.empty()) return false;
    try {
        int number = stoi(input);
        return true;
    }
    catch (...) {
        return false;
    }
}

int calcRemainder(int a, int b, int c) {
    return (a + b) % c;
}

int calcDivision(int a, int b, int c) {
    return (a + b) / c;
}
