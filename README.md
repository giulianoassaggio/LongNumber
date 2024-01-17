 
# LongNumber Class

A C++ class for handling large numbers (greater than 64 bits) with arbitrary bases.

## Overview

The `LongNumber` class is designed to represent large numbers with arbitrary bases (between 2 and 16, included), providing a set of operations like addition, subtraction, multiplication, and division. It supports signed and unsigned integers and can be initialized from various data types, from standard integers to string.

## Dependecies

It does not rely on anthing but standard library (in particular, it includes `string`).

## General features (below: feature yet implemented)

- Handles large numbers with arbitrary bases.
- Implements base conversion tools
- Arithmetic operations implemented: comparisons, addition, subtraction, multiplication, division, modulo and power, everything both signed and unsigned
- Supports operations between LongNumbers with different bases
- Supports operations between LongNumbers and primitive types
- Constructor overloads for different numeric types and string representations.
- Custom exceptions for error handling.
- Designed with ease of use and flexibility in mind.

## Usage

Here's a basic example demonstrating the usage of the `LongNumber` class:

```cpp
#include "LongNumber.hpp"
#include <iostream>

int main() {
    LongNumber num1("123456789012345678901234567890"); // default base is 10
    LongNumber num2("9171AF3bc", 16); // base can be specified
    LongNumber num3(12);
    LongNumber num4("-1001010", 2);
    LongNumber num5(std::string("345678aae88cd"), 15);
    num4 += 15;
    num3 += num1;
    num3.invertSign();
    num5 = (num2.changeSign('+')).changeBase(num3.getBase());
    bool compare = num1 >= num2;

    std::cout << "operation allowed: " << num1 + num2 << std::endl;
    std::cout << "operation allowed: " << num1 - num3 << std::endl;
    std::cout << "operation allowed: " << num4.changeBase(10) << std::endl;
    std::cout << "operation allowed: " << num3 % 100 << std::endl;
    std::cout << "operation allowed: " << num1 ^ 10 << std::endl;
    std::cout << "operation allowed: " << num3 * 15 << std::endl;
    std::cout << "operation allowed: " << num3 / num1 << std::endl;

    /*
        AND SO ON
    */

    return 0;
}
```

# Features implemented

- constructors
- comparisons
- additions
- substractions
- base changes

# Documentation
~~Refer to the doxygen-generated documentation in the `docs` folder.~~
see comments on the code

# Contributions
Feel free to contribute, submit PRs, open Issues - every improvement proposal is welcome!

# Licence
I think MIT licence is the most suitable one... Anyway, do whatever you want with this code. I don't care

