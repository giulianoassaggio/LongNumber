#include "../LongNumber.hpp"

/**
 * @brief Get the current sign of the LongNumber.
 * @returns char '+' or '-'
 */
char LongNumber::getSignAsCharacter() const{
    return sign ? '+' : '-';
}

/**
 * @brief Get the current sign of the LongNumber.
 * @returns true if positive or zero, false if negative. 
*/
bool LongNumber::getSignAsBoolean() const{
    return sign;
}

/**
 * @brief Change the sign of the LongNumber it is called on. If *this == 0, 
 * sign will remain true, in every case
 * @details it doesn't check actual sign, it simply reassign it
 * @param newSign The new sign to set. must be '+' or '-'
 * @throws LongNumberException if param is invalid
 */
void LongNumber::setSign(char newSign){
    if (newSign != '+' && newSign != '-') 
        throw LongNumberException{
            "LongNumber::setSign(): invalid character as new sign"
        };
    if (*this == 0) {
        sign = true;
        return;
    }
    sign = (newSign == '+' ? true : false);
}
/**
 * @brief Change the sign of the LongNumber it is called on.If *this == 0, 
 * sign will remain true, in every case
 * @details it doesn't check actual sign, it simply reassign it
 * @param newSign The new sign to set. true if positive or zero, false otherwise
 */
void LongNumber::setSign(bool newSign){
    setSign(newSign == true ? '+' : '-');
}
/**
 * @brief Inverts the sign of the LongNumber it is called on.
 * @details if sign is set to negative, it changes it to positive and viceversa.
 * If number is 0, it sets sign to positive, always
*/
void LongNumber::invertSign(){
    if (*this == 0) {
        sign = true;
        return;
    }
    sign = !sign;
}

/**
 * @brief it returns a new LongNumber with value equal to the object it is called on, 
 * but with sign set to `newSign`. If *this == 0, sign will remain true, in every case
 * @param newSign The new sign to set. must be '+' or '-'
 * @throws LongNumberException if param is invalid
 */
LongNumber LongNumber::changeSign(char newSign) const{
    LongNumber result = *this;
    result.setSign(newSign);
    return result;
}
/**
 * @brief it returns a new LongNumber with value equal to the object it is called on, 
 * but with sign set to `newSign`. If *this == 0, sign will remain true, in every case
 * @param newSign The new base to set. true if positive or zero, false otherwise
 */
LongNumber LongNumber::changeSign(bool newSign) const{
    LongNumber result = *this;
    result.setSign(newSign);
    return result;  
}
/**
 * @brief it returns a new LongNumber with value equal to the object it is called on, 
 * but with sign inverted
 * If number is 0, it sets sign to positive, always
*/
LongNumber LongNumber::changeSign() const{
    LongNumber result = *this;
    result.invertSign();
    return result;
}

long long LongNumber::getSize() const {
    return size;
}