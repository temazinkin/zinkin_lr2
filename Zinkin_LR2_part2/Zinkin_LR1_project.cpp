// Вариант № 10
// - ввести целое число A
// - ввести целое число B
// - ввести целое число C
// - найти остаток от деления суммы целых чисел А и В на число С
// - найти целую часть от деления суммы целых чисел А и В на число С

#include <iostream>
#include <cstring>
#include <map>
#include <functional>

using namespace std;

int A, B, C;

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

int calcDevision(int a, int b, int c) {
    return (a + b) / c;
}

function<void()> EnterNumber(int& varLink, string label) {
    return [&varLink, label]() {
        string raw_input;

        getline(cin, raw_input);

        while (!UserInput(raw_input)) {
            cout << label << " = ";
            getline(cin, raw_input);
        }

        varLink = stoi(raw_input);
    };
}

void Remainder() {
    if (C == 0) {
        cout << "Ошибка вычисления, C = 0.";
    } else {
        cout << "(" << A << " + " << B;
        cout << ") mod " << C << " = ";
        cout << calcRemainder(A, B, C);
    }
}

void Division() {
    if (C == 0) {
        cout << "Ошибка вычисления, C = 0.";
    } else {
        cout << "⎣(" << A << " + " << B;
        cout << ") / " << C << "⎦ = ";
        cout << calcDevision(A, B, C);
    }
}

int main() {
    struct MenuItem {
        string title;
        function<void()> action;
    };

    map<int, MenuItem> menu = {
        {1, {"Ввод целого числа A", EnterNumber(A, "A")}},
        {2, {"Ввод целого числа B", EnterNumber(B, "B")}},
        {3, {"Ввод целого числа C", EnterNumber(C, "C")}},
        {4, {"(A + B) mod C", Remainder}},
        {5, {"⎣(A + B) / C⎦", Division}},
    };

    int choice = 0;

    while (true) {
        cout << "Меню:" << endl;

        for (const auto& item : menu) {
            cout << "Task " << item.first << ". " << item.second.title << endl;
        }

        cout << "0. Выход" << endl;
        cout << "Введите номер пункта: ";
        cin >> choice;

        if (choice == 0) {
            cout << "© 2025 Artem Zinkin" << endl;
            break;
        }

        cout << endl;

        if (menu.find(choice) != menu.end()) {
            menu[choice].action();
        } else {
            cout << "Некорректный ввод.";
        }

        cout << endl << endl;
    }

    return 0;
}
