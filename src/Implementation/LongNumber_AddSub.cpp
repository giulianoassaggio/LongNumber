# include "../LongNumber.hpp"

/**
 * @brief Utility function. Adds another LongNumber to the current instance.
 * It assumes that both numbers have the same sign
 *
 * @param other The LongNumber to be added to the current instance.
 *
 * @details
 * The addition is performed digit by digit
 *
 * @warning
 * This is an auxiliary function designed for controlled contexts. Don't use it
 * for generic LongNumber additions. use `operator+` function instead.
 * 
 * @throws LongNumberException if called on generic LongNumber with differents sign
*/
void LongNumber::add(LongNumber const & other) {
    if (sign != other.sign)
        throw LongNumberException{
            "LongNumber::add(): invalid argument"
        };
    
    pcell aux_this = start;
    pcell aux_other = other.start;

    int carry = 0;
    while (aux_this && aux_other) {
        int sum_aux = (int((aux_this->value-'0') + (aux_other->value-'0')) + carry);
        int sum = sum_aux % BASE16;
        carry = sum_aux / BASE16;
        aux_this->value = int_to_char(sum);
        aux_this = aux_this->next;
        aux_other = aux_other->next;
    }
    while (aux_this){
        int sum_aux = int((aux_this->value-'0') + carry);
        int sum = sum_aux % BASE16;
        carry = sum_aux / BASE16;
        aux_this->value = int_to_char(sum);
        aux_this = aux_this->next;
    }
    while (aux_other){
        int sum_aux = int((aux_other->value-'0') + carry);
        int sum = sum_aux % BASE16;
        carry = sum_aux / BASE16;
        push_back(int_to_char(sum));
    }
    if (carry) push_back(int_to_char(carry));
}
/**
 * @brief Addition operator for LongNumber class. Performs addition of two 
 * signed LongNumber objects.
 * 
 * @param other The LongNumber to be added to the current instance.
 * @return A new LongNumber representing the sum of the current instance and `other`.
 *
 * @details
 * If the signs of the two numbers are different, the subtraction operation is used to
 * calculate the sum. The sign of the result is determined by the sign of the operand
 * with the larger absolute value.
 *
 * If the signs are the same, the addition is performed directly.
 *
 * @note
 * This operator does not modify the current instance or `other`. It returns a new
 * LongNumber object representing the result of the addition operation.
 */
LongNumber LongNumber::operator+(LongNumber const &other) const {
    if (this->sign != other.sign) {
        if (this->sign == false) {
            LongNumber aux = *this;
            aux.sign = true;
            return aux - *this;
        }
        else {
            LongNumber aux = other;
            aux.sign = true;
            return *this - aux;
        }
    }
    // else
    LongNumber result = *this;
    result.add(other);
    result.clean_up();
    if (result == 0) result.sign = true;
    return result;
}
LongNumber LongNumber::operator+(short other) const{
    return *this+LongNumber(other);
}
LongNumber LongNumber::operator+(int other) const{
    return *this+LongNumber(other);
}
LongNumber LongNumber::operator+(long other) const{
    return *this+LongNumber(other);
}
LongNumber LongNumber::operator+(long long other) const{
    return *this+LongNumber(other);
}
LongNumber LongNumber::operator+(unsigned short other) const{
    return *this+LongNumber(other);
}
LongNumber LongNumber::operator+(unsigned int other) const{
    return *this+LongNumber(other);
}
LongNumber LongNumber::operator+(unsigned long other) const{
    return *this+LongNumber(other);
}
LongNumber LongNumber::operator+(unsigned long long other) const{
    return *this+LongNumber(other);
}

/**
 * @brief Subs another LongNumber to the current instance.
 * It assumes that both numbers have the same sign and base.
 * @param other The LongNumber to be added to the current instance.
 *
 * @details
 * The substraction is performed digit by digit
 *
 * @warning
 * This is an auxiliary function designed for controlled contexts. Don't use it
 * for generic LongNumber additions. use `operator+` function instead.
 * 
 * @throws LongNumberException if called on generic LongNumber with differents sign and/or
 * different bases 
*/
void LongNumber::sub(LongNumber const &other){
    if (sign != other.sign)
        throw LongNumberException{
            "LongNumber::sub(): invalid argument"
        };

    int borrow = 0;
    pcell aux_this = start;
    pcell aux_other = other.start;

    while(aux_this && aux_other){
        int check = char_to_int(aux_this->value) - borrow >= char_to_int(aux_other->value);
        if (check){
            aux_this->value = int_to_char(char_to_int(aux_this->value) - borrow - char_to_int(aux_other->value));
            borrow = 0;
            aux_this = aux_this->next;
            aux_other = aux_other->next;
        }
        else {
            borrow = 1;
            aux_this->value = int_to_char(char_to_int(aux_this->value) + BASE16 - char_to_int(aux_other->value));
            aux_this = aux_this->next;
            aux_other = aux_other->next;
        }
    }
    if (aux_other && !aux_this)
        throw LongNumberException{
            "LongNumber::sub(): aux_other should be less than aux_this, so it is impossible that aux_other is still alive"
        };
    while(aux_this && borrow){
        int check = char_to_int(aux_this->value) - borrow >= 0;
        if (check){
            aux_this->value = int_to_char(char_to_int(aux_this->value) - 1);
            borrow = 0;
            aux_this = aux_this->next;
        }
        else {
            borrow = 1;
            aux_this->value = int_to_char(char_to_int(aux_this->value) + BASE16);
            aux_this = aux_this->next;
        }
    }
    clean_up();
}

/**
 * @brief Subtraction operator for LongNumber class. Performs subtraction of two 
 * signed LongNumber objects. 
 * @param other The LongNumber to be subtracted from the current instance.
 * @return A new LongNumber representing the result of the subtraction operation.
 * @details
 * If the signs of the two numbers are different, substraction is handled
 * as a sum, and result sign is calculated separately.
 * otherwise, it is performed directly. 
 * @note
 * This operator does not modify the current instance or `other`. It returns a new
 * LongNumber object representing the result of the addition operation.
 */
LongNumber LongNumber::operator-(LongNumber const &other) const{
    LongNumber result(*this);
    if (sign != other.sign) {
        result.invertSign(); // this is because function `add` requires numbers to have same sign
        result.add(other);
        if (result == 0) result.sign = true;
        else result.invertSign(); // the first sign (same of *this)
        return result;
    }
    // else
    

    comparison_result comparison = result.comparison(other);
    if (comparison == THIS_GREATER_OTHER){
        result.sub(other);
        result.clean_up();
        return result;
    }
    else if (comparison == THIS_EQUALS_OTHER){
        return LongNumber{0};
    }
    else {
        LongNumber aux(other);
        aux.sub(result);
        aux.invertSign();
        aux.clean_up();
        return aux;
    }
}
LongNumber LongNumber::operator-(short other) const{
    return *this-LongNumber(other);
}
LongNumber LongNumber::operator-(int other) const{
    return *this-LongNumber(other);
}
LongNumber LongNumber::operator-(long other) const{
    return *this-LongNumber(other);
}
LongNumber LongNumber::operator-(long long other) const{
    return *this-LongNumber(other);
}
LongNumber LongNumber::operator-(unsigned short other) const{
    return *this-LongNumber(other);
}
LongNumber LongNumber::operator-(unsigned int other) const{
    return *this-LongNumber(other);
}
LongNumber LongNumber::operator-(unsigned long other) const{
    return *this-LongNumber(other);
}
LongNumber LongNumber::operator-(unsigned long long other) const{
    return *this-LongNumber(other);
}

LongNumber& LongNumber::operator+=(LongNumber const &other){
    *this = *this + other;
    return *this;
}
LongNumber& LongNumber::operator+=(short other){
    *this = *this + other;
    return *this;
}
LongNumber& LongNumber::operator+=(int other){
    *this = *this + other;
    return *this;
}
LongNumber& LongNumber::operator+=(long other){
    *this = *this + other;
    return *this;
}
LongNumber& LongNumber::operator+=(long long other){
    *this = *this + other;
    return *this;
}
LongNumber& LongNumber::operator+=(unsigned short other){
    *this = *this + other;
    return *this;
}
LongNumber& LongNumber::operator+=(unsigned int other){
    *this = *this + other;
    return *this;
}
LongNumber& LongNumber::operator+=(unsigned long other){
    *this = *this + other;
    return *this;
}
LongNumber& LongNumber::operator+=(unsigned long long other){
    *this = *this + other;
    return *this;
}

LongNumber& LongNumber::operator-=(LongNumber const &other){
    *this = *this + other;
    return *this;
}
LongNumber& LongNumber::operator-=(short other){
    *this = *this + other;
    return *this;
}
LongNumber& LongNumber::operator-=(int other){
    *this = *this + other;
    return *this;
}
LongNumber& LongNumber::operator-=(long other){
    *this = *this + other;
    return *this;
}
LongNumber& LongNumber::operator-=(long long other){
    *this = *this + other;
    return *this;
}
LongNumber& LongNumber::operator-=(unsigned short other){
    *this = *this + other;
    return *this;
}
LongNumber& LongNumber::operator-=(unsigned int other){
    *this = *this + other;
    return *this;
}
LongNumber& LongNumber::operator-=(unsigned long other){
    *this = *this + other;
    return *this;
}
LongNumber& LongNumber::operator-=(unsigned long long other){
    *this = *this + other;
    return *this;
}