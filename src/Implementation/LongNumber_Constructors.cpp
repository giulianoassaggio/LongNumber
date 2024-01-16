#include "../LongNumber_StructImpl.hpp"

LongNumber::LongNumber(){
    *this = LongNumber(10, true);
}
LongNumber::LongNumber(int base, bool sign){
    if (base < 2 || base > 16){
        throw new LongNumberException{"La base deve essere compresa tra 2 e 16"};
    }
    this->pimpl = new impl;
    pimpl->sign = sign;
    pimpl->base = base;
    pimpl->start = pimpl->end = nullptr;
}

// destructor
LongNumber::~LongNumber(){
    if (pimpl) delete pimpl;
    pimpl = nullptr;
};

// Copy Constructor
LongNumber::LongNumber(LongNumber const &other) {
    if (this != &other) {  // Verifica se non stai assegnando a te stesso
        if (pimpl) delete pimpl;  // Dealloca la struttura di implementazione corrente
        pimpl = new impl;
        pimpl->sign = other.pimpl->sign;
        pimpl->base = other.pimpl->base;
        typename impl::pcella aux = other.pimpl->start;
        if (aux==nullptr) {
            pimpl->start = pimpl->end = nullptr;
        }
        else {
            while(aux) {
                pimpl->push_back(aux->value);
                aux = aux->next;
            }
        }
    }
}

// Move Constructor
LongNumber::LongNumber(LongNumber &&other) {
    pimpl = other.pimpl;  // Sposta il puntatore alla struttura di implementazione
    other.pimpl = nullptr;  // Invalida il puntatore nell'oggetto sorgente
}

// Copy Assignment Operator
LongNumber& LongNumber::operator=(LongNumber const &other) {
    if (this != &other) {  // Verifica se non stai assegnando a te stesso
        if (pimpl) delete pimpl;  // Dealloca la struttura di implementazione corrente
        pimpl = new impl;
        pimpl->sign = other.pimpl->sign;
        pimpl->base = other.pimpl->base;
        typename impl::pcella aux = other.pimpl->start;
        if (aux==nullptr) {
            pimpl->start = pimpl->end = nullptr;
        }
        else {
            while(aux) {
                pimpl->push_back(aux->value);
                aux = aux->next;
            }
        }
    }
    return *this;
}

// Move Assignment Operator
LongNumber& LongNumber::operator=(LongNumber &&other) {
    if (this != &other) {  // Verifica se non stai assegnando a te stesso
        delete pimpl;  // Dealloca la struttura di implementazione corrente
        pimpl = other.pimpl;  // Sposta il puntatore alla struttura di implementazione
        other.pimpl = nullptr;  // Invalida il puntatore nell'oggetto sorgente
    }
    return *this;
}

// Wraps primitive types to LongNumber Objects
LongNumber::LongNumber(unsigned short value){
    *this = LongNumber(static_cast<long long>(value));
}
LongNumber::LongNumber(unsigned int value){
    *this = LongNumber(static_cast<long long>(value));
}
LongNumber::LongNumber(unsigned long value){
    *this = LongNumber(static_cast<long long>(value));
}
LongNumber::LongNumber(unsigned long long  value){
    *this = LongNumber(static_cast<long long>(value));
}
LongNumber::LongNumber(short value){
    *this = LongNumber(static_cast<long long>(value));
}
LongNumber::LongNumber(int value){
    *this = LongNumber(static_cast<long long>(value));
}
LongNumber::LongNumber(long value){
    *this = LongNumber(static_cast<long long>(value));
}
LongNumber::LongNumber(long long value){
    if (value < 0){
        *this = LongNumber(10, false);
        value *= -1;
    }
    else *this = LongNumber();
    
    bool finito = false;
    if (value == 0) pimpl->push_back('0');
    while(!finito){
        if (value / 10 == 0){
            finito = true;
        }
        pimpl->push_back((value % 10 + '0'));
        value = value / 10;
    }
}
bool LongNumber::impl::controllo_input(char c, int base, int pos){
    if (pos == 0){
        if (c == '-' || c == '+') return true;
    }
    if (
        (c-'0'>= 0 && c-'0'<base) ||
        (c-'A'>=10 && c-'A'<base) ||
        (c-'a'>=10 && c-'a'<base)
    )
        return true;
    return false;
}
LongNumber::LongNumber(char* str, int base = 10){
    std::string s;
    while (str!='\0') s += *str++;
    *this = LongNumber(s, base);
}
LongNumber::LongNumber(std::string str, int base = 10){
    if (base<2 || base>16) throw LongNumberException{"base must be beetween 2 and 16"};

    if (str.length() == 0) 
        *this = LongNumber();
    for(size_t i = 0; i<str.length(); i++){
        if (!impl::controllo_input(str[i], base, i)) throw LongNumberException{"str contains unexpected characters"};
        if (i == 0 && str[i]== '-') 
            pimpl->sign = false;
        else if (i == 0 && str[i] == '+') 
            pimpl->sign = true;
        else
            pimpl->push_front(std::toupper(str[i]));
    }
}
