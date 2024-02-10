#include "../LongNumber_StructImpl.hpp"
#include "LongNumber_Modulus.cpp"

int LongNumber::getBase() const {
    return this->pimpl->base;
};

/**
 * per semplicità di comprensione, converto prima in base 10,
 * @TODO: evitare il passaggio per base 10
*/
LongNumber LongNumber::changeBase(int newBase) const{
    if (newBase < 2 || newBase > 16){
        throw LongNumberException {"La base deve essere compresa tra 2 e 16"};
    }
    if (newBase == pimpl->base) return *this;

    /*per trasformare da una base a un'altra, devo raggruppare per esponente:
    10283 = 1*10^5 + 0*10^4 + 2*10^3 + 8*10^2 + 3*10^1 + 6*10^0
    siccome l'esponente può essere molto grande (2^256 in sha256, per esempio),
    devo wrappare la base e fare i calcoli coi LongNumber*/
    LongNumber wrapped_base = LongNumber(pimpl->base);
    LongNumber result_inBase10;
    
    if (pimpl->base != 10){
        typename impl::pcella aux = pimpl->start;
        size_t i = 0;
        while(aux) {
            char c = aux->value;
            int value;
            if (c >= '0'&& c <= '9'){
                value = (int)(c-'0');
            }
            else {
                value = (int)(c-'0')+10;
            }
            LongNumber base_exp = wrapped_base^(i++);
            LongNumber temp = base_exp*value;
            result_inBase10 += temp;
        }
    }

    if (newBase == 10) return result_inBase10;

    /*
    29 in base 3: 29%3 = 2; 9%3 = 0; 3%3 = 0; 1%3 = 1; è già scritto little endian
    */
    int r = 0;
    LongNumber result;
    while(result_inBase10 != 0){
        r = result_inBase10 % newBase;
        result_inBase10 /= newBase;
        char v = (r >= 10 && r <= 15) ? static_cast<char>('A' + (r - 10)) : static_cast<char>('0' + r);
        result.pimpl->push_back(v);
    } 
    return result;
}

void LongNumber::setBase(int newBase){
    *this = changeBase(newBase);
}


/**
 * @brief Get the current sign of the LongNumber.
 * @returns char '+' or '-'
 */
char LongNumber::getSignAsCharacter() const{
    return pimpl->sign ? '+' : '-';
}
/**
 * @brief Get the current sign of the LongNumber.
 * @returns true if positive or zero, false if negative. 
*/
bool LongNumber::getSignAsBoolean() const{
    return pimpl->sign;
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
        throw LongNumberException{"invalid character as new sign in function setSign"};
    if (*this == 0) {
        pimpl->sign = true;
        return;
    }
    pimpl->sign = (newSign == '+' ? true : false);
}
/**
 * @brief Change the base of the LongNumber it is called on.If *this == 0, 
 * sign will remain true, in every case
 * @details it doesn't check actual sign, it simply reassign it
 * @param newSign The new sign to set. true if positive or zero, false otherwise
 */
void LongNumber::setSign(bool newSign){
    if (*this == 0) {
        pimpl->sign = true;
        return;
    }
    pimpl->sign = newSign;
}
/**
 * @brief Inverts the sign of the LongNumber it is called on.
 * @details if sign is set to negative, it changes it to positive and viceversa.
 * If number is 0, it sets sign to positive, always
*/
void LongNumber::invertSign(){
    if (*this == 0) {
        pimpl->sign = true;
        return;
    }
    pimpl->sign = !pimpl->sign;
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
