#include "../src/LongNumber.hpp"
#include <cassert>
#include <iostream>

void basic_modulus() {
    assert(LongNumber("123", 10) % 5 == 3);
    assert(LongNumber("ABC", 16) % 8 == 4);
    assert(LongNumber("1001", 2) % 3 == 0);
    assert(LongNumber("-123", 10) % 5 == 2);
    assert(LongNumber("-ABC", 16) % 8 == 4);
    assert(LongNumber("-1001", 2) % 3 == 0);
}
void edge_cases() {
    assert(LongNumber("0", 10) % 7 == 0);
    assert(LongNumber("1", 10) % 13 == 1);
    assert(LongNumber("123456789012345678901234567890", 10) % 97654321 == 45705223);
}

void test_exception_handling() {
    try {
        LongNumber("123", 10) % 1;
        assert(false && "Expected exception not thrown");
    } catch (const LongNumberException& e) {
        assert(std::string(e.msg) == "Modulus divisor must be greater than 1");
    }
    try {
        LongNumber("456", 10) % 0;
        assert(false && "Expected exception not thrown");
    } catch (const LongNumberException& e) {
        assert(std::string(e.msg) == "Modulus divisor must be greater than 1");
    }
    try {
        LongNumber("789", 10) % -2;
        assert(false && "Expected exception not thrown");
    } catch (const LongNumberException& e) {
        assert(std::string(e.msg) == "Modulus divisor must be greater than 1");
    }
}
void randomized() {
        for (int i = 0; i < 100; ++i) {
            int num1 = rand() % 1000;
            int num2 = rand() % 1000;

            std::string a = std::to_string(num1);
            LongNumber ln1(a);
            int expected = num1 % num2;
            int result = ln1 % num2;
            assert(result == expected);
        }
}
int main() {
    basic_modulus();
    edge_cases();
    test_exception_handling();
    randomized();
    std::cout<<"//////////////////////////////////"<<std::endl;
    std::cout<<std::endl;
    std::cout<<"        no assertion failed       "<<std::endl;
    std::cout<<"        all testcases passed      "<<std::endl;
    std::cout<<std::endl;
    std::cout<<"//////////////////////////////////"<<std::endl;

    return 0;
}