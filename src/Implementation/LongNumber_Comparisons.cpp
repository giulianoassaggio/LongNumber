#include "../LongNumber_StructImpl.hpp"

/**
 * @brief Compares two LongNumber objects with the same sign and base.
 * @return An enum indicating whether *this is greater than, equal to, or less than 'other'.
 * @warning This function requires both the sign and base to be the same between *this and 'other'.
 */
LongNumber::impl::comparison_result LongNumber::impl::comparison(LongNumber const& other) const {
    pcella aux1 = end;
    pcella aux2 = other.pimpl->end;
    while (aux1->value == '0') aux1 = aux1->prev;
    while (aux2->value == '0') aux2 = aux2->prev;

    pcella aux3 = aux1;
    int len1 = 1;
    while(aux3) {
        aux3 = aux3->prev;
        len1++;
    }
    aux3 = aux2;
    int len2 = 1;
    while(aux3) {
        aux3 = aux3->prev;
        len2++;
    }

    if (len1 > len2) return sign ? THIS_GREATER_OTHER : THIS_LESS_OTHER;
    if (len2 > len1) return sign ? THIS_LESS_OTHER : THIS_GREATER_OTHER;

    while(aux1 && aux2){
        if(aux1->value < aux2->value) return sign ? THIS_LESS_OTHER : THIS_GREATER_OTHER;
        if(aux1->value > aux2->value) return sign ? THIS_GREATER_OTHER : THIS_LESS_OTHER;
        aux1 = aux1->prev;
        aux2 = aux2->prev;
    }

    return THIS_EQUALS_OTHER;
}
bool LongNumber::operator==(LongNumber const &other) const {
    if (pimpl->sign != other.pimpl->sign) return false;
    if (pimpl->base != other.pimpl->base) {
        LongNumber different_base;

        // mi conviene prima guardare se una delle due è base 10
        // in quanto passare da base x a base 10 ha complessità minore
        // che non passare da base x a base y
        if (pimpl->base == 10) {
            different_base = other.changeBase(10);
            return pimpl->comparison(different_base) == impl::comparison_result::THIS_EQUALS_OTHER;
        }
        else if (other.pimpl->base == 10) {
            different_base = changeBase(10);
            return other.pimpl->comparison(different_base) == impl::comparison_result::THIS_EQUALS_OTHER;
        }
        else {
            different_base = other.changeBase(this->pimpl->base);
            return pimpl->comparison(different_base) == impl::comparison_result::THIS_EQUALS_OTHER;
        }
    }
    return pimpl->comparison(other) == impl::comparison_result::THIS_EQUALS_OTHER;
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
bool LongNumber::equals(LongNumber const &other) const{
    return (getBase() == other.getBase()) && *this==other;
}
bool LongNumber::equals(short other) const{
    LongNumber aux = LongNumber(other);
    return (getBase() == aux.getBase()) && *this==aux;
}
bool LongNumber::equals(int other) const{
    LongNumber aux = LongNumber(other);
    return (getBase() == aux.getBase()) && *this==aux;
}
bool LongNumber::equals(long other) const{
    LongNumber aux = LongNumber(other);
    return (getBase() == aux.getBase()) && *this==aux;
}
bool LongNumber::equals(long long other) const{
    LongNumber aux = LongNumber(other);
    return (getBase() == aux.getBase()) && *this==aux;
}
bool LongNumber::operator>=(LongNumber const &other) const{
    if (this->pimpl->sign != other.pimpl->sign){
        return pimpl->sign;
    }
    if (pimpl->base != other.pimpl->base) {
        LongNumber different_base;

        // mi conviene prima guardare se una delle due è base 10
        // in quanto passare da base x a base 10 ha complessità minore
        // che non passare da base x a base y
        if (pimpl->base == 10) {
            different_base = other.changeBase(10);
            impl::comparison_result res = pimpl->comparison(different_base);
            return res != impl::comparison_result::THIS_LESS_OTHER;
        }
        else if (other.pimpl->base == 10) {
            different_base = changeBase(10);
            impl::comparison_result res = different_base.pimpl->comparison(other);
            return res != impl::comparison_result::THIS_LESS_OTHER;
        }
        else {
            different_base = other.changeBase(this->pimpl->base);
            impl::comparison_result res = pimpl->comparison(different_base);
            return res != impl::comparison_result::THIS_LESS_OTHER;
        }
    }
    return pimpl->comparison(other) != impl::comparison_result::THIS_LESS_OTHER;
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
bool LongNumber::operator<=(LongNumber const &other) const{
    if (this->pimpl->sign != other.pimpl->sign){
        return !(pimpl->sign);
    }
    if (pimpl->base != other.pimpl->base) {
        LongNumber different_base;

        // mi conviene prima guardare se una delle due è base 10
        // in quanto passare da base x a base 10 ha complessità minore
        // che non passare da base x a base y
        if (pimpl->base == 10) {
            different_base = other.changeBase(10);
            impl::comparison_result res = pimpl->comparison(different_base);
            return res != impl::comparison_result::THIS_GREATER_OTHER;
        }
        else if (other.pimpl->base == 10) {
            different_base = changeBase(10);
            impl::comparison_result res = different_base.pimpl->comparison(other);
            return res != impl::comparison_result::THIS_GREATER_OTHER;
        }
        else {
            different_base = other.changeBase(this->pimpl->base);
            impl::comparison_result res = pimpl->comparison(different_base);
            return res != impl::comparison_result::THIS_GREATER_OTHER;
        }
    }
    return pimpl->comparison(other) != impl::comparison_result::THIS_GREATER_OTHER;
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
bool LongNumber::operator<(LongNumber const &other) const{
    if (this->pimpl->sign != other.pimpl->sign){
        return !(pimpl->sign);
    }
    if (pimpl->base != other.pimpl->base) {
        LongNumber different_base;

        // mi conviene prima guardare se una delle due è base 10
        // in quanto passare da base x a base 10 ha complessità minore
        // che non passare da base x a base y
        if (pimpl->base == 10) {
            different_base = other.changeBase(10);
            impl::comparison_result res = pimpl->comparison(different_base);
            return res == impl::comparison_result::THIS_LESS_OTHER;
        }
        else if (other.pimpl->base == 10) {
            different_base = changeBase(10);
            impl::comparison_result res = different_base.pimpl->comparison(other);
            return res == impl::comparison_result::THIS_LESS_OTHER;
        }
        else {
            different_base = other.changeBase(this->pimpl->base);
            impl::comparison_result res = pimpl->comparison(different_base);
            return res == impl::comparison_result::THIS_LESS_OTHER;
        }
    }
    return pimpl->comparison(other) == impl::comparison_result::THIS_LESS_OTHER;
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
bool LongNumber::operator>(LongNumber const &other) const{
    if (this->pimpl->sign != other.pimpl->sign){
        return (pimpl->sign);
    }
    if (pimpl->base != other.pimpl->base) {
        LongNumber different_base;

        // mi conviene prima guardare se una delle due è base 10
        // in quanto passare da base x a base 10 ha complessità minore
        // che non passare da base x a base y
        if (pimpl->base == 10) {
            different_base = other.changeBase(10);
            impl::comparison_result res = pimpl->comparison(different_base);
            return res == impl::comparison_result::THIS_GREATER_OTHER;
        }
        else if (other.pimpl->base == 10) {
            different_base = changeBase(10);
            impl::comparison_result res = different_base.pimpl->comparison(other);
            return res == impl::comparison_result::THIS_GREATER_OTHER;
        }
        else {
            different_base = other.changeBase(this->pimpl->base);
            impl::comparison_result res = pimpl->comparison(different_base);
            return res == impl::comparison_result::THIS_GREATER_OTHER;
        }
    }
    return pimpl->comparison(other) == impl::comparison_result::THIS_GREATER_OTHER;
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