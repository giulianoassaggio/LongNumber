# include "../LongNumber_StructImpl.hpp"

/**
 * @brief Adds another LongNumber to the current instance.
 * It assumes that both numbers have the same sign and base.
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
 * @throws LongNumberException if called on generic LongNumber with differents sign and/or
 * different bases 
*/
void LongNumber::impl::add(LongNumber const other){
    if (sign != other.pimpl->sign || base != other.pimpl->base)
        throw LongNumberException{"invalid arguments for `LongNumber::impl::add`"};
    pcella aux1 = start;
    pcella aux2 = other.pimpl->start;
    int carry = 0;
    while (aux1 && aux2) {
        int sum_aux = (int((aux1->value-'0') + (aux2->value-'0')) + carry);
        int sum = sum_aux % base;
        carry = sum_aux / base;
        aux1->value = int_to_char(sum);
        aux1 = aux1->next;
        aux2 = aux2->next;
    }
    while (aux1){
        int sum_aux = int((aux1->value-'0') + carry);
        int sum = sum_aux % base;
        carry = sum_aux / base;
        aux1->value = int_to_char(sum);
        aux1 = aux1->next;
    }
    while (aux2){
        int sum_aux = int((aux2->value-'0') + carry);
        int sum = sum_aux % base;
        carry = sum_aux / base;
        push_back(int_to_char(sum));
    }
    if (carry) push_back(int_to_char(carry));
}
/**
 * @brief Addition operator for LongNumber class. Performs addition of two 
 * signed LongNumber objects. If the base of the two numbers is different, 
 * `changeBase` method is used to convert the base of the current instance 
 * to match that of `other`, so the final result will have other's base
 * @param other The LongNumber to be added to the current instance.
 * @return A new LongNumber representing the sum of the current instance and `other`.
 *
 * @details
 * If the signs of the two numbers are different, the subtraction operation is used to
 * calculate the sum. The sign of the result is determined by the sign of the operand
 * with the larger absolute value.
 *
 * If the signs are the same, the addition is performed directly. If the base of the
 * two numbers is different, the `changeBase` method is used to convert the base of
 * the current instance to match that of `other`.
 *
 * @note
 * This operator does not modify the current instance or `other`. It returns a new
 * LongNumber object representing the result of the addition operation.
 */
LongNumber LongNumber::operator+(LongNumber const &other) const{
    if (pimpl->sign != other.pimpl->sign) {
        if (pimpl->sign == false) {
            LongNumber aux = *this;
            aux.pimpl->sign = true;
            return aux - *this;
        }
        else {
            LongNumber aux = other;
            aux.pimpl->sign = true;
            return *this - aux;
        }
    }
    // else
    LongNumber result = changeBase(other.pimpl->base);
    result.pimpl->add(other);
    result.pimpl->pulisci();
    if (result == 0) result.pimpl->sign = true;
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
void LongNumber::impl::sub(LongNumber const other){
    if (sign != other.pimpl->sign || base != other.pimpl->base)
        throw LongNumberException{"invalid arguments for function sub"};

    // function `pulisci` deletes most significant digits, if equals to 0.
    this->pulisci();
    other.pimpl->pulisci();

    int borrow = 0;
    pcella aux1 = start;
    pcella aux2 = other.pimpl->start;

    while(aux1 && aux2){
        int check = char_to_int(aux1->value) - borrow >= char_to_int(aux2->value);
        if (check){
            aux1->value = int_to_char(char_to_int(aux1->value) - borrow - char_to_int(aux2->value));
            borrow = 0;
            aux1 = aux1->next;
            aux2 = aux2->next;
        }
        else {
            borrow = 1;
            aux1->value = int_to_char(char_to_int(aux1->value) + base - char_to_int(aux2->value));
            aux1 = aux1->next;
            aux2 = aux2->next;
        }
    }
    if (aux2 && !aux1)
        throw LongNumberException{"aux2 should be less than aux1, so it is impossible that aux2 is still alive"};
    while(aux1 && borrow){
        int check = char_to_int(aux1->value) - borrow >= 0;
        if (check){
            aux1->value = int_to_char(char_to_int(aux1->value) - 1);
            borrow = 0;
            aux1 = aux1->next;
        }
        else {
            borrow = 1;
            aux1->value = int_to_char(char_to_int(aux1->value) + base);
            aux1 = aux1->next;
        }
    }
    pulisci();
}
/**
 * @brief Subtraction operator for LongNumber class. Performs subtraction of two 
 * signed LongNumber objects. If the base of the two numbers is different, 
 * `changeBase` method is used to convert the base of the current instance 
 * to match that of `other`, so the final result will have other's base
 * @param other The LongNumber to be subtracted from the current instance.
 * @return A new LongNumber representing the result of the subtraction operation.
 * @details
 * If the signs of the two numbers are different, substraction is handled
 * as a sum, and result sign is calculated separately.
 * otherwise, it is performed directly. If the bases of the
 * two numbers are different, the `changeBase` method is used to convert the base of
 * the current instance to match that of `other`.
 * @note
 * This operator does not modify the current instance or `other`. It returns a new
 * LongNumber object representing the result of the addition operation.
 */
LongNumber LongNumber::operator-(LongNumber const &other) const{
    if (pimpl->sign != other.pimpl->sign) {
        LongNumber result(this->changeBase(other.getBase()));
        result.invertSign(); // this is because function `add` requires numbers to have same sign
        result.pimpl->add(other);
        if (result == 0) result.pimpl->sign = true;
        else result.invertSign(); // the first sign (same of *this)
        return result;
    }
    // else
    LongNumber this_withBaseChanged = this->changeBase(other.pimpl->base);
    impl::comparison_result comparison = this_withBaseChanged.pimpl->comparison(other);
    if (comparison == impl::THIS_GREATER_OTHER){
        this_withBaseChanged.pimpl->sub(other);
        this_withBaseChanged.pimpl->pulisci();
        return this_withBaseChanged;
    }
    else if (comparison == impl::THIS_EQUALS_OTHER){
        return LongNumber{0};
    }
    else {
        LongNumber aux(other);
        aux.pimpl->sub(this_withBaseChanged);
        aux.invertSign();
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
