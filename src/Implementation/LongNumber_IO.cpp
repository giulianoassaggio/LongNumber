#include "../LongNumber.hpp"

std::string LongNumber::getNumber() const{
    std::string s;
    pcell aux = end;
    
    if (!sign) s += '-';
    if (!aux) s += '0';
    while(aux){
        s += aux->value;
        aux = aux->prev;
    }
    return s;
}

std::string LongNumber::getNumber(int base) const {
    if (base<2 || base>16) 
        throw LongNumberException {
            "LongNumber::getNumber(): base must be beetween 2 and 16"
        };

    std::string s = getNumber();
    convert_from_BASE16(s, base); 
    return s;
}

std::ostream& operator<<(std::ostream &os, LongNumber const &number){
    return os<<number.getNumber();
}

std::istream& operator>>(std::istream& is, LongNumber& Number) {
    std::string str;
    is >> str;
    Number = LongNumber(str);
    return is;
}