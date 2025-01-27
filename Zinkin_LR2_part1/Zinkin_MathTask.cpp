#include <iostream>
#include "Zinkin_MathTask.h"

using namespace std;

int main() {
    string str_input;
    cout << "input height A" << endl;
    getline(cin, str_input);
    while (!UserInput(str_input)) {
        cout << "input height A" << endl;
        getline(cin, str_input);
    }

    int NumberA = stoi(str_input);

    cout << "input weight B" << endl;
    getline (cin, str_input) ;

    while (!UserInput (str_input)) {
        cout << "input weight B" << endl;
        getline(cin, str_input);
    }

    int NumberB = stoi(str_input);
    int RectangleArea = CalcRectangleArea(NumberA, NumberB) ;
    cout << "Area of Rectangle is " << RectangleArea << endl;
}
