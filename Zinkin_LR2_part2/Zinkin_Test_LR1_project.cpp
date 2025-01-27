#include "../Zinkin_LR2_part1/CUTE/cute/cute.h"
#include "../Zinkin_LR2_part1/CUTE/cute/ide_listener.h"
#include "../Zinkin_LR2_part1/CUTE/cute/cute_runner.h"

#include "Zinkin_LR1_project.h"

using namespace cute;

void testCalcDivision() {
    int a = 30;
    int b = 6;
    int c = 5;

    int expected = 7;
    int actual = calcDivision(a, b, c);

    ASSERT_EQUAL(expected, actual);
}

void testUserInput_Empty() {
    string str = "";
    bool expected = false;
    bool actual = UserInput(str);
    ASSERT_EQUAL(expected, actual);
}

void testUserInput_Letter() {
    string str = "a";
    bool expected = false;
    bool actual = UserInput(str);
    ASSERT_EQUAL(expected, actual);
}

void testUserInput_ComboValue() {
    string str = "Te5st";
    bool expected = false;
    bool actual = UserInput(str);
    ASSERT_EQUAL(expected, actual);
}

int main() {
    suite s;
    s.push_back(CUTE(testCalcDivision));
    s.push_back(CUTE(testUserInput_Empty));
    s.push_back(CUTE(testUserInput_Letter));
    s.push_back(CUTE(testUserInput_ComboValue));

    ide_listener<>listener;
    makeRunner(listener)(s, "Test CalcDivision");

    return 0;
}
