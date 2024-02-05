#include "../LongNumber_StructImpl.hpp"
#include <iostream>


LongNumber::LongNumber(){
    pimpl = new impl;
}
LongNumber::LongNumber(int base){
    if (base < 2 || base > 16){
        throw LongNumberException{"La base deve essere compresa tra 2 e 16"};
    }
    this->pimpl = new impl;
    pimpl->base = base;
    pimpl->sign = true;
}

// destructor
LongNumber::~LongNumber(){
    if (pimpl) delete pimpl;
    pimpl = nullptr;
};

// Copy Constructor
LongNumber::LongNumber(LongNumber const &other) {
        pimpl = new impl;
        pimpl->sign = other.pimpl->sign;
        pimpl->base = other.pimpl->base;
        impl::pcella aux = other.pimpl->start;
        while(aux) {
            pimpl->push_back(aux->value);
            aux=aux->next;
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
        delete pimpl;  // Dealloca la struttura di implementazione corrente
        pimpl = new impl;
        pimpl->base = other.pimpl->base;
        pimpl->sign = other.pimpl->sign;
        impl::pcella aux = other.pimpl->start;
        while(aux) {
            pimpl->push_back(aux->value);
            aux=aux->next;
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
    pimpl = new impl;
    *this = LongNumber(static_cast<long long>(value));
}
// Wraps primitive types to LongNumber Objects
LongNumber::LongNumber(unsigned int value){
    pimpl = new impl;
    *this = LongNumber(static_cast<long long>(value));
}
// Wraps primitive types to LongNumber Objects
LongNumber::LongNumber(unsigned long value){
    pimpl = new impl;
    *this = LongNumber(static_cast<long long>(value));
}
// Wraps primitive types to LongNumber Objects
LongNumber::LongNumber(unsigned long long  value){
    pimpl = new impl;
    *this = LongNumber(static_cast<long long>(value));
}
// Wraps primitive types to LongNumber Objects
LongNumber::LongNumber(short value){
    pimpl = new impl;
    *this = LongNumber(static_cast<long long>(value));
}
// Wraps primitive types to LongNumber Objects
LongNumber::LongNumber(int value){
    pimpl = new impl;
    *this = LongNumber(static_cast<long long>(value));
}
// Wraps primitive types to LongNumber Objects
LongNumber::LongNumber(long value){
    pimpl = new impl;
    *this = LongNumber(static_cast<long long>(value));
}
// Wraps primitive types to LongNumber Objects
LongNumber::LongNumber(long long value){
    pimpl = new impl;
    *this = LongNumber();

    if (value == 0) return;
    if (value < 0) pimpl->sign = false;
    
    bool finito = false;
    while(!finito){
        if (value / 10 == 0){
            finito = true;
        }
        pimpl->push_back((value % 10 + '0'));
        value = value / 10;
    }
}
bool LongNumber::impl::controllo_input(char c, int base, int pos){
#if DEBUG
    std::cout<<"c: "<<c<<", base: "<<base<<", pos: "<<pos;
#endif
    if (pos == 0){
        if (c == '-' || c == '+') {
#if DEBUG
            std::cout<<" true"<<std::endl;
#endif
            return true;
        }
    }
    if (
        (c-'0'>= 0 && c-'0'<base) ||
        (c-'A'>= 0 && c-'A'<base-10) ||
        (c-'a'>= 0 && c-'a'<base-10)
    ){
#if DEBUG
        std::cout<<" true"<<std::endl;
#endif
        return true;
    }
#if DEBUG
    std::cout<<" true"<<std::endl;
#endif
    return false;
}
LongNumber::LongNumber(const char str[], int base){
    pimpl = new impl;
    pimpl->base = base;
    std::string s;
    while (*str!='\0') s += *str++;
    *this = LongNumber(s, base);
    pimpl->pulisci();
    if (*this == 0) pimpl->sign = true;
}
LongNumber::LongNumber(const char str[]){
    pimpl = new impl;
    pimpl->base = 10;
    std::string s;
    while (*str!='\0') s += *str++;
    *this = LongNumber(s, 10);
    pimpl->pulisci();
    if (*this == 0) pimpl->sign = true;
}
LongNumber::LongNumber(std::string& str){
    pimpl = new impl;
    *this = LongNumber(str, 10);
}
LongNumber::LongNumber(std::string& str, int base){
    if (base<2 || base>16) throw LongNumberException{"base must be beetween 2 and 16"};
    pimpl = new impl;
    pimpl->base = base;
    pimpl->sign = true;

    for(size_t i = 0; i<str.length(); i++){
        if (!impl::controllo_input(str[i], base, i)) {
#if DEBUG
            std::cout<<"i: "<<i<<" str[i]: "<<str[i]<<std::endl;
#endif
            throw LongNumberException{"str contains unexpected characters"};
        }
        if (i == 0 && str[i] == '-') 
            pimpl->sign = false;
        else if (i == 0 && str[i] == '+') 
            pimpl->sign = true;
        else
            pimpl->push_front(std::toupper(str[i]));
    }
    pimpl->pulisci();
    if (*this == 0) pimpl->sign = true;
}
