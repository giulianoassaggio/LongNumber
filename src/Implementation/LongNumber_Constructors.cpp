#include "../LongNumber.hpp"
#include <iostream>


LongNumber::LongNumber(){
    sign = true;
    size = 0;
    end = start = nullptr;
}

// destructor
LongNumber::~LongNumber(){
    while(start) pop_front();
};

// Copy Constructor
LongNumber::LongNumber(LongNumber const &other) {
        size = 0;
        sign = other.sign;
        pcell aux = other.start;
        while(aux) {
            push_back(aux->value);
            aux=aux->next;
        }
}

// Move Constructor
LongNumber::LongNumber(LongNumber &&other) noexcept {
    size = other.size;
    sign = other.sign;
    start = other.start;
    end = other.end;
    other.start = other.end = nullptr;
}

// Copy Assignment Operator
LongNumber& LongNumber::operator=(LongNumber const &other) {
    if (this != &other) {  // Verifica se non stai assegnando a te stesso
        while(start) pop_front();
        sign = other.sign;
        pcell aux = other.start;
        while(aux) {
            push_back(aux->value);
            aux=aux->next;
        }
    }
    return *this;
}

// Move Assignment Operator
LongNumber& LongNumber::operator=(LongNumber &&other) {
    if (this != &other) {
        while(start) pop_front();
        size = other.size;
        start = other.start;
        end = other.end;
        sign = other.sign;
        other.start = other.end = nullptr;
    }
    return *this;
}

// Wraps primitive types to LongNumber Objects
LongNumber::LongNumber(unsigned short value){
    *this = LongNumber(static_cast<long long>(value));
}
// Wraps primitive types to LongNumber Objects
LongNumber::LongNumber(unsigned int value){
    *this = LongNumber(static_cast<long long>(value));
}
// Wraps primitive types to LongNumber Objects
LongNumber::LongNumber(unsigned long value){
    *this = LongNumber(static_cast<long long>(value));
}
// Wraps primitive types to LongNumber Objects
LongNumber::LongNumber(unsigned long long  value){
    *this = LongNumber(static_cast<long long>(value));
}
// Wraps primitive types to LongNumber Objects
LongNumber::LongNumber(short value){
    *this = LongNumber(static_cast<long long>(value));
}
// Wraps primitive types to LongNumber Objects
LongNumber::LongNumber(int value){
    *this = LongNumber(static_cast<long long>(value));
}
// Wraps primitive types to LongNumber Objects
LongNumber::LongNumber(long value){
    *this = LongNumber(static_cast<long long>(value));
}
// Wraps primitive types to LongNumber Objects
LongNumber::LongNumber(long long value){
    *this = LongNumber();

    if (value == 0) return;
    if (value < 0) sign = false;
    
    bool finito = false;
    while(!finito){
        if (value / BASE16 == 0){
            finito = true;
        }
        push_back(int_to_char(value % BASE16));
        value = value / BASE16;
    }
}
bool LongNumber::input_check(char c, int base, int pos){
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
LongNumber::LongNumber(const char str[]){
    std::string s = str;
    *this = LongNumber(s, 16);
}
LongNumber::LongNumber(std::string& str){
    *this = LongNumber(str, 16);
}
LongNumber::LongNumber(const char str[], int base){
    std::string s = str;
    *this = LongNumber(s, base);
}
LongNumber::LongNumber(std::string& str, int base){
    if (base<2 || base>16) 
    throw LongNumberException {
        "LongNumber::Constructor from string: base must be beetween 2 and 16"
    };

    sign = true;
    size = 0;

    for(size_t i = 0; i<str.length(); i++){
        if (!input_check(str[i], base, i))
            throw LongNumberException{
                "LongNumber::Constructor from string: str contains unexpected characters"
            };
    }

    if (base != BASE16) 
        convert_to_BASE16(str, base);
    
    for (int i = 0; i<str.length(); i++){
        if (i == 0 && str[i] == '+')
            sign = true;
        else if (i == 0 && str[i] == '-')
            sign = false;
        else push_front(str[i]);
    }

    clean_up();
    if (*this == 0) sign = true;
}
