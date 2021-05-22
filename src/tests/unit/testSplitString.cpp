#include <cassert>
#include <iostream>
#include <vector>

#include "../../utils/splitString.h"

int main() {
    std::vector<std::string> testVector = {"hello", "hello", "hello"};
    assert(splitString("hello,hello,hello", ",") == testVector);

    testVector = {"1", "2", "3"};
    assert(splitString("1t2t3", "t") == testVector);

    testVector = {"58"};
    assert(splitString("58", "w") == testVector);

    testVector = {};
    assert(splitString("", "") == testVector);

    testVector = {};
    assert(splitString("", "s") == testVector);
};