#include "../LongNumber.hpp"

#define LONG_MAX_SQRT static_cast<unsigned long long> (std::sqrt(std::numeric_limits<unsigned long long>::max()));


LongNumber LongNumber::karatsuba(LongNumber first, LongNumber second) {
    // base case numbers are small enough to be handled with primitive-types operations
    // If both factors are below the square root of the maximum value representable
    // by unsigned long long, perform multiplication using primitive types to optimize performance.
    // This is because in this way the largest result i can get does still fit in long long type.
    // Otherwise, switch to Kartsuba algorithms to handle larger numbers.
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

}
LongNumber LongNumber::operator*(int other) const{

}
LongNumber LongNumber::operator*(long other) const{

}
LongNumber LongNumber::operator*(long long other) const{

}   
LongNumber LongNumber::operator*(unsigned short other) const{

}
LongNumber LongNumber::operator*(unsigned int other) const{

}
LongNumber LongNumber::operator*(unsigned long other) const{

}
LongNumber LongNumber::operator*(unsigned long long other) const{

}




LongNumber& LongNumber::operator*=(LongNumber const &other){

}
LongNumber& LongNumber::operator*=(short other){

}
LongNumber& LongNumber::operator*=(int other){

}
LongNumber& LongNumber::operator*=(long other){

}
LongNumber& LongNumber::operator*=(long long other){

}
LongNumber& LongNumber::operator*=(unsigned short other){

}
LongNumber& LongNumber::operator*=(unsigned int other){

}
LongNumber& LongNumber::operator*=(unsigned long other){

}
LongNumber& LongNumber::operator*=(unsigned long long other){

}



LongNumber LongNumber::operator/(LongNumber const &other) const{

}
LongNumber LongNumber::operator/(short other) const{

}
LongNumber LongNumber::operator/(int other) const{

}
LongNumber LongNumber::operator/(long other) const{

}
LongNumber LongNumber::operator/(long long other) const{

}
LongNumber LongNumber::operator/(unsigned short other) const{

}
LongNumber LongNumber::operator/(unsigned int other) const{

}
LongNumber LongNumber::operator/(unsigned long other) const{

}
LongNumber LongNumber::operator/(unsigned long long other) const{

}




LongNumber& LongNumber::operator/=(LongNumber const &other){

}
LongNumber& LongNumber::operator/=(short other){

}
LongNumber& LongNumber::operator/=(int other){

}
LongNumber& LongNumber::operator/=(long other){

}
LongNumber& LongNumber::operator/=(long long other){

}
LongNumber& LongNumber::operator/=(unsigned short other){

}
LongNumber& LongNumber::operator/=(unsigned int other){

}
LongNumber& LongNumber::operator/=(unsigned long other){

}
LongNumber& LongNumber::operator/=(unsigned long long other){

}




LongNumber LongNumber::operator^(short exponent) const{

}
LongNumber LongNumber::operator^(int exponent) const{

}
LongNumber LongNumber::operator^(long exponent) const{

}
LongNumber LongNumber::operator^(long long exponent) const{

}
LongNumber LongNumber::operator^(unsigned short exponent) const{

}
LongNumber LongNumber::operator^(unsigned int exponent) const{

}
LongNumber LongNumber::operator^(unsigned long exponent) const{

}
LongNumber LongNumber::operator^(unsigned long long exponent) const{

}