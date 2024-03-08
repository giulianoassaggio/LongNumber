#include "../LongNumber.hpp"

/**
 * @brief Compares two LongNumber objects with the same sign and base.
 * @return An enum indicating whether *this is greater than, equal to, or less than 'other'.
 * @warning This function requires both the sign and base to be the same between *this and 'other'.
 */
LongNumber::comparison_result LongNumber::comparison(LongNumber const& other) const {
    pcell aux_this = end;
    pcell aux_other = other.end;
    while (aux_this && aux_this->value == '0') aux_this = aux_this->prev;
    while (aux_other && aux_other->value == '0') aux_other = aux_other->prev;

    pcell aux3 = aux_this;
    int len1 = 1;
    while(aux3) {
        aux3 = aux3->prev;
        len1++;
    }
    aux3 = aux_other;
    int len2 = 1;
    while(aux3) {
        aux3 = aux3->prev;
        len2++;
    }

    if (len1 > len2) return sign ? THIS_GREATER_OTHER : THIS_LESS_OTHER;
    if (len2 > len1) return sign ? THIS_LESS_OTHER : THIS_GREATER_OTHER;

    while(aux_this && aux_other){
        if(aux_this->value < aux_other->value) return sign ? THIS_LESS_OTHER : THIS_GREATER_OTHER;
        if(aux_this->value > aux_other->value) return sign ? THIS_GREATER_OTHER : THIS_LESS_OTHER;
        aux_this = aux_this->prev;
        aux_other = aux_other->prev;
    }

    return THIS_EQUALS_OTHER;
}
bool LongNumber::operator==(LongNumber const &other) const {
    if (sign != other.sign) return false;
    return comparison(other) == comparison_result::THIS_EQUALS_OTHER;
}
bool LongNumber::operator==(short other) const{
    return *this == LongNumber(other);
}
bool LongNumber::operator==(int other) const{
    return *this == LongNumber(other);
}
bool LongNumber::operator==(long other) const{
    return *this == LongNumber(other);
}
bool LongNumber::operator==(long long other) const{
    return *this == LongNumber(other);
}
bool LongNumber::operator==(unsigned short other) const{
    return *this == LongNumber(other);
}
bool LongNumber::operator==(unsigned int other) const{
    return *this == LongNumber(other);
}
bool LongNumber::operator==(unsigned long other) const{
    return *this == LongNumber(other);
}
bool LongNumber::operator==(unsigned long long other) const{
    return *this == LongNumber(other);
}
bool LongNumber::operator!=(LongNumber const &other) const{
    return !(*this == other);
}
bool LongNumber::operator!=(short other) const{
    return !(*this == LongNumber(other));
}
bool LongNumber::operator!=(int other) const{
    return !(*this == LongNumber(other));
}
bool LongNumber::operator!=(long other) const{
    return !(*this == LongNumber(other));
}
bool LongNumber::operator!=(long long other) const{
    return !(*this == LongNumber(other));
}
bool LongNumber::operator!=(unsigned short other) const{
    return !(*this == LongNumber(other));
}
bool LongNumber::operator!=(unsigned int other) const{
    return !(*this == LongNumber(other));
}
bool LongNumber::operator!=(unsigned long other) const{
    return !(*this == LongNumber(other));
}
bool LongNumber::operator!=(unsigned long long other) const{
    return !(*this == LongNumber(other));
}
bool LongNumber::operator>=(LongNumber const &other) const{
    if (this->sign != other.sign){
        return sign;
    }
    return comparison(other) != comparison_result::THIS_LESS_OTHER;
}
bool LongNumber::operator>=(short other) const{
    return *this >= LongNumber(other);
}
bool LongNumber::operator>=(int other) const{
    return *this >= LongNumber(other);
}
bool LongNumber::operator>=(long other) const{
    return *this >= LongNumber(other);
}
bool LongNumber::operator>=(long long other) const{
    return *this >= LongNumber(other);
}
bool LongNumber::operator>=(unsigned short other) const{
    return *this >= LongNumber(other);
}
bool LongNumber::operator>=(unsigned int other) const{
    return *this >= LongNumber(other);
}
bool LongNumber::operator>=(unsigned long other) const{
    return *this >= LongNumber(other);
}
bool LongNumber::operator>=(unsigned long long other) const{
    return *this >= LongNumber(other);
}
bool LongNumber::operator<=(LongNumber const &other) const{
    if (this->sign != other.sign){
        return !sign;
    }
    return comparison(other) != comparison_result::THIS_GREATER_OTHER;
}
bool LongNumber::operator<=(short other) const{
    return *this<=LongNumber(other);
}
bool LongNumber::operator<=(int other) const{
    return *this<=LongNumber(other);
}
bool LongNumber::operator<=(long other) const{
    return *this<=LongNumber(other);
}
bool LongNumber::operator<=(long long other) const{
    return *this<=LongNumber(other);
}
bool LongNumber::operator<=(unsigned short other) const{
    return *this<=LongNumber(other);
}
bool LongNumber::operator<=(unsigned int other) const{
    return *this<=LongNumber(other);
}
bool LongNumber::operator<=(unsigned long other) const{
    return *this<=LongNumber(other);
}
bool LongNumber::operator<=(unsigned long long other) const{
    return *this<=LongNumber(other);
}
bool LongNumber::operator<(LongNumber const &other) const{
    if (this->sign != other.sign){
        return !sign;
    }
    return comparison(other) == comparison_result::THIS_LESS_OTHER;
}
bool LongNumber::operator<(short other) const{
    return *this < LongNumber(other);
}
bool LongNumber::operator<(int other) const{
    return *this < LongNumber(other);
}
bool LongNumber::operator<(long other) const{
    return *this < LongNumber(other);
}
bool LongNumber::operator<(long long other) const{
    return *this < LongNumber(other);
}
bool LongNumber::operator<(unsigned short other) const{
    return *this < LongNumber(other);
}
bool LongNumber::operator<(unsigned int other) const{
    return *this < LongNumber(other);
}
bool LongNumber::operator<(unsigned long other) const{
    return *this < LongNumber(other);
}
bool LongNumber::operator<(unsigned long long other) const{
    return *this < LongNumber(other);
}
bool LongNumber::operator>(LongNumber const &other) const{
    if (this->sign != other.sign){
        return sign;
    }
    return comparison(other) == comparison_result::THIS_GREATER_OTHER;
}
bool LongNumber::operator>(short other) const{
    return *this > LongNumber(other);
}
bool LongNumber::operator>(int other) const{
    return *this > LongNumber(other);
}
bool LongNumber::operator>(long other) const{
    return *this > LongNumber(other);
}
bool LongNumber::operator>(long long other) const{
    return *this > LongNumber(other);
}
bool LongNumber::operator>(unsigned short other) const{
    return *this > LongNumber(other);
}
bool LongNumber::operator>(unsigned int other) const{
    return *this > LongNumber(other);
}
bool LongNumber::operator>(unsigned long other) const{
    return *this > LongNumber(other);
}
bool LongNumber::operator>(unsigned long long other) const{
    return *this > LongNumber(other);
}