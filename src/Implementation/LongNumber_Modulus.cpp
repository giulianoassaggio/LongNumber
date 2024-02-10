#include "../LongNumber_StructImpl.hpp"

template <typename T>
/**
 * Calculates LongNumber modulo an integral type.
 * types allowed (both signed and unsigned): short, int, long, long long.
 * @param mod the divisor. It must be > 1. It must be an integral.
 * @returns the calculated modulus result, with the same type of the "mod" param
 * @throws LongNumberException if divisor is negative or <=1; or if mod type is not allowed
 * 
*/
T LongNumber::operator%(T mod) const {
    if (mod <= 1) throw LongNumberException {"Modulus divisor must be greater than 1"};
    static_assert(std::is_integral_v<T>, "Modulus must be an integral type");
    T remainder = 0;
    typename impl::pcella aux = pimpl->end;
    #if DEBUG
    std::cout<<"il numero è "<<this->getNumber()<<std::endl;
    #endif 
    while (aux) {
        int digit = impl::char_to_int(aux->value);
        remainder = (remainder * pimpl->base + digit) % mod;
        aux = aux->prev;
    }

    /*
    if sign is positive, modulus result is just the remainder, else it is
    the inverted remainder plus the modulus.

    for example:
    5 % 3 = 2
    -5 % 3 = 1   -> (-2)+3  -> 3 - 2
    */
    return pimpl->sign ? remainder : (mod - remainder) % mod;
}
