#include "../LongNumber.hpp"

#define LONG_MAX_SQRT static_cast<unsigned long long> (std::sqrt(std::numeric_limits<unsigned long long>::max()));
#define LONG_MAX static_cast<unsigned long long> (std::numeric_limits<unsigned long long>::max());


LongNumber LongNumber::karatsuba(LongNumber first, LongNumber second) {
    // base case numbers are small enough to be handled with primitive-types operations
    // If both factors are below the square root of the maximum value representable
    // by unsigned long long, perform multiplication using primitive types to optimize performance.
    // This is because in this way the largest result i can get does still fit in long long type.
    // Otherwise, switch to Kartsuba algorithms to handle larger numbers.
    if (first == 16) {
        second.push_front('0');
        return second;
    }
    else if (second == 16) {
        first.push_front('0');
        return first;
    }
    static const unsigned long long limit = LONG_MAX_SQRT;
    if (first < limit && second < limit) {
        unsigned long long result = ((unsigned long long) first) * ((unsigned long long) second);
        return LongNumber(result);
    }
    else {
        /*
         karatsuba is a divide-and-conquer algorithm. 
         Given for example two number of two digits each one, standard multiplication is:
         ab * cd = (a*base + b) * (c*base + d)

         it becomes a*base*c*base + b*c*base + a*base*d + b*d.
         it requires the 4 multiplications: a*c*base^2 + b*c*base + a*d*base + b*d.

         so, we got base^2(a*c) + base(b*c + a*d) + b*d

         (b*c + a*d) can be written as (a+b)(c+d) - a*c - b*d

         but wait, we know the value of ac and bd !

         so, the entire multiplication is:

         base^2((a*c)) + base((a+b)(c+d)-a*c-b*d) + (b*d)

         now we have 3 multiplications instead of 4: ac, bd and (a+b)(c+d)
        */

        // starting point: karatsuba algorithm split the number, so the number of digits must be the same on the two halves
        if (first.getSize() % 2 != 0) first.push_back('0'); // pad with leading zero
        if (second.getSize() % 2 != 0) second.push_back('0');

        LongNumber first_Greater /*a*/, first_Smaller /*b*/, second_Greater/*c*/, second_Smaller/*d*/;

        pcell currentNode = first.end;
        for (int i=0; i<first.getSize()/2; i++) {
            first_Greater.push_front(currentNode->value);
            currentNode = currentNode->prev;
        }
        while(currentNode) {
            first_Smaller.push_front(currentNode->value);
            currentNode = currentNode->prev;
        }

        currentNode = second.end;
        for (int i=0; i<second.getSize()/2; i++) {
            second_Greater.push_front(currentNode->value);
            currentNode = currentNode->prev;
        }
        while(currentNode) {
            second_Smaller.push_front(currentNode->value);
            currentNode = currentNode->prev;
        }

        LongNumber ac = karatsuba(first_Greater, second_Greater);
        LongNumber bd = karatsuba(first_Smaller, second_Smaller);
        LongNumber abcd = karatsuba((first_Greater+first_Smaller), (second_Greater+second_Smaller)) - ac - bd;
        ac.push_front('0'); ac.push_front('0'); // ac*base^2. represents shifting the number to the left by two positions.
        abcd.push_front('0'); //same, by just one position

        return ac + bd + abcd;
    }
    /**
     * COMPLEXITY ANALISYS
     *  we first check if the numbers are small enough to be handled with primitive types. This check and the result have a constant time complexity, O(1).
     *  The recurrence relation for the time complexity can be expressed as: T(n) = 3T(n/2) + O(n),
     *  where the O(n) term comes from the addition and subtraction operations of the result, plus the copying of original LongNumbers split in half
     *  By applying the Master theorem, we find that the time complexity of the Karatsuba algorithm is O(n^log2(3)), which is approximately O(n^1.585).
     *  Therefore, the overall time complexity is ~O(n^1.585).
     * 
     *  The space complexity of the Karatsuba algorithm is O(n log n). 
     *  This is because at each recursive step, the algorithm splits the input numbers into halves, resulting in a binary tree of recursive calls. 
     *  Each level of recursion involves creating temporary LongNumber objects for intermediate results, 
     *  and since there are log n levels in the recursion tree (each level representing a halving of the input size), 
     *  the total space complexity becomes O(n log n).
    */
}
/**
 * @brief multiplication between LongNumber or LongNumber and primitive integrals
 * @details it uses primitive unsigned multiplication if values are small enough, otherwise it uses Karatsuba algorithm
*/
LongNumber LongNumber::operator*(LongNumber const &other) const{
    // one factor is zero -> result is zero
    if (*this == 0 || other == 0) return LongNumber(0);

    // computation of the sign and multiplication of the absolute values.
    bool res_sign = this->getSignAsBoolean() == other.getSignAsBoolean() ? true : false;
    LongNumber result = karatsuba(this->changeSign(true), other.changeSign(true));

    result.setSign(res_sign);
    return result;
}
LongNumber LongNumber::operator*(short other) const{
    return *this * LongNumber(other);
}
LongNumber LongNumber::operator*(int other) const{
    return *this * LongNumber(other);
}
LongNumber LongNumber::operator*(long other) const{
    return *this * LongNumber(other);
}
LongNumber LongNumber::operator*(long long other) const{
    return *this * LongNumber(other);
}   
LongNumber LongNumber::operator*(unsigned short other) const{
    return *this * LongNumber(other);
}
LongNumber LongNumber::operator*(unsigned int other) const{
    return *this * LongNumber(other);
}
LongNumber LongNumber::operator*(unsigned long other) const{
    return *this * LongNumber(other);
}
LongNumber LongNumber::operator*(unsigned long long other) const{
    return *this * LongNumber(other);
}


LongNumber& LongNumber::operator*=(LongNumber const &other){
    *this = LongNumber(other);
    return *this;
}
LongNumber& LongNumber::operator*=(short other){
    *this = LongNumber(other);
    return *this;
}
LongNumber& LongNumber::operator*=(int other){
    *this = LongNumber(other);
    return *this;
}
LongNumber& LongNumber::operator*=(long other){
    *this = LongNumber(other);
    return *this;
}
LongNumber& LongNumber::operator*=(long long other){
    *this = LongNumber(other);
    return *this;
}
LongNumber& LongNumber::operator*=(unsigned short other){
    *this = LongNumber(other);
    return *this;
}
LongNumber& LongNumber::operator*=(unsigned int other){
    *this = LongNumber(other);
    return *this;
}
LongNumber& LongNumber::operator*=(unsigned long other){
    *this = LongNumber(other);
    return *this;
}
LongNumber& LongNumber::operator*=(unsigned long long other){
    *this = LongNumber(other);
    return *this;
}


LongNumber LongNumber::long_division_algorithm(LongNumber dividend, LongNumber divisor) {
    if (divisor == 0)
        throw LongNumberException{"LongNumber:operator/(): Cannot divide by zero"};

    if (dividend < divisor)
        return LongNumber("0"); // If dividend < divisor, result is 0

    
}

LongNumber LongNumber::long_division_algorithm(LongNumber dividend, LongNumber divisor) {
    if (divisor == 16) 
        return char_to_int(dividend.end->value);

    if (divisor == 0)
        throw LongNumberException{"LongNumber:operator/(): Cannot divide by zero"};

    if (dividend < divisor)
        return 0; // If dividend < divisor, result is 0

    static constexpr unsigned long long limit = LONG_MAX;
    if (dividend < limit && divisor < limit) {
        unsigned long long result = (unsigned long long) dividend / (unsigned long long) divisor;
        return result;
    }
/*
IN THE FIRST TIME, i implemented the exact algortithm i use when I compute division with pen and paper:
- you take the first N digits of the dividend that form a number greater than the divisor
- you substract X times the divisor from the temporary number just created, and X is the current digit of quotient
- you reattach remaining digits of temp to original dividend. 
- If dividend is still greater than divisor, you add a digit to the quotient and repeat, else you can return quotient directly.


    LongNumber result;
    LongNumber temp;
    while (dividend >= divisor) {
        while(temp < divisor){
            temp.push_front(dividend.end->value);
            dividend.pop_back();
        }
        while(temp > divisor){
            temp -= divisor;
            result += 1;
        }
        while(temp.start) {
            dividend.push_back(temp.start->value);
            temp.pop_front();
        }
        if (dividend > divisor){
            result.push_front('0');
        }
    }
    return result;

THEN, i opted for this modified version. Please note that dividend is passed by copy, so it can be modified in the function.
In this algorithm:
- you compute the order of magnitude of the quotient, left-shifting the divisor enough to make it the closest possible to the dividend
- then you compute how many times you have to substract divisor from divident, to compute the current digit of the quotient.
- then you right-shift the number and repeat the algorithm to compute every remaining digit od the quotient
*/
    LongNumber quotient;
    LongNumber temp;
    
    while (dividend >= divisor) {
        temp = divisor;
        LongNumber multiple(1);

        // Find the multiple of divisor closest to dividend
        while (temp.push_front('0') <= dividend) {
            temp.push_front('0');
            multiple.push_front('0');
        }

        // Subtract multiples of divisor from dividend until it's less than divisor
        while (dividend >= divisor) {
            if (dividend >= temp) {
                dividend -= temp;
                quotient += multiple;
            }
            temp.pop_front();
            multiple.pop_front();
        }
    }

    return quotient;
}
 
LongNumber LongNumber::operator/(LongNumber const &other) const{
    //Handle the sign of the result
    LongNumber result {0};
    result = long_division_algorithm(this->changeSign(true), other.changeSign(true));
    result.setSign(this->getSignAsBoolean() == other.getSignAsBoolean() ? true : false);
    return result;
}
LongNumber LongNumber::operator/(short other) const{
    return *this / LongNumber(other);
}
LongNumber LongNumber::operator/(int other) const{
    return *this / LongNumber(other);
}
LongNumber LongNumber::operator/(long other) const{
    return *this / LongNumber(other);
}
LongNumber LongNumber::operator/(long long other) const{
    return *this / LongNumber(other);
}
LongNumber LongNumber::operator/(unsigned short other) const{
    return *this / LongNumber(other);
}
LongNumber LongNumber::operator/(unsigned int other) const{
    return *this / LongNumber(other);
}
LongNumber LongNumber::operator/(unsigned long other) const{
    return *this / LongNumber(other);
}
LongNumber LongNumber::operator/(unsigned long long other) const{
    return *this / LongNumber(other);
}




LongNumber& LongNumber::operator/=(LongNumber const &other){
    *this = *this / other;
    return *this;
}
LongNumber& LongNumber::operator/=(short other){
    *this = *this / other;
    return *this;
}
LongNumber& LongNumber::operator/=(int other){
    *this = *this / other;
    return *this;
}
LongNumber& LongNumber::operator/=(long other){
    *this = *this / other;
    return *this;
}
LongNumber& LongNumber::operator/=(long long other){
    *this = *this / other;
    return *this;
}
LongNumber& LongNumber::operator/=(unsigned short other){
    *this = *this / other;
    return *this;
}
LongNumber& LongNumber::operator/=(unsigned int other){
    *this = *this / other;
    return *this;
}
LongNumber& LongNumber::operator/=(unsigned long other){
    *this = *this / other;
    return *this;
}
LongNumber& LongNumber::operator/=(unsigned long long other){
    *this = *this / other;
    return *this;
}


LongNumber LongNumber::operator^(short exponent) const{
    if (exponent < 0) 
        throw LongNumberException{
            "LongNumber::operator^(): exponent must be a positive value"
        };
    return squared_power(*this, exponent);
}
LongNumber LongNumber::operator^(int exponent) const{
    if (exponent < 0) 
        throw LongNumberException{
            "LongNumber::operator^(): exponent must be a positive value"
        };
    return squared_power(*this, exponent);
}
LongNumber LongNumber::operator^(long exponent) const{
    if (exponent < 0) 
        throw LongNumberException{
            "LongNumber::operator^(): exponent must be a positive value"
        };
    return squared_power(*this, exponent);
}
LongNumber LongNumber::operator^(long long exponent) const{
    if (exponent < 0) 
        throw LongNumberException{
            "LongNumber::operator^(): exponent must be a positive value"
        };
    return squared_power(*this, exponent);
}
LongNumber LongNumber::operator^(unsigned short exponent) const{
    if (exponent < 0) 
        throw LongNumberException{
            "LongNumber::operator^(): exponent must be a positive value"
        };
    return squared_power(*this, exponent);
}
LongNumber LongNumber::operator^(unsigned int exponent) const{
    if (exponent < 0) 
        throw LongNumberException{
            "LongNumber::operator^(): exponent must be a positive value"
        };
    return squared_power(*this, exponent);
}
LongNumber LongNumber::operator^(unsigned long exponent) const{
    if (exponent < 0) 
        throw LongNumberException{
            "LongNumber::operator^(): exponent must be a positive value"
        };
    return squared_power(*this, exponent);
}
LongNumber LongNumber::operator^(unsigned long long exponent) const{
    if (exponent < 0) 
        throw LongNumberException{
            "LongNumber::operator^(): exponent must be a positive value"
        };
    return squared_power(*this, exponent);
}