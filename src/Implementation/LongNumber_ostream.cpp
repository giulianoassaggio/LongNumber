#include "../LongNumber_StructImpl.hpp"

std::string LongNumber::getNumber() const{
    typename impl::pcella aux = pimpl->end;
    std::string s;
    if (pimpl->base != 10) s += std::string("base") + std::to_string(pimpl->base) + ": ";
    if (!pimpl->sign) s += '-';
    if (!aux) s += '0';
    while(aux){
        s += aux->value;
        aux = aux->prev;
    }
    return s;
}

std::ostream& operator<<(std::ostream &os, LongNumber const &number){
    return os<<number.getNumber();
}
