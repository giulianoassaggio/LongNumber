#include "../LongNumber.hpp"
#include <algorithm>

void LongNumber::convert_to_BASE16(std::string & str, int base){
    LongNumber buffer (0);
    LongNumber base_L (base);
    for (int i=0; i<str.length(); i++){
        buffer = buffer * base_L + char_to_int(str[i]); 
    }
    str = buffer.getNumber();
}
void LongNumber::convert_from_BASE16(std::string & str, int base){
    LongNumber buffer (str);
    str = "";
    while(buffer > 0){
        str += int_to_char(buffer % base);
        buffer /= base;
    }
    std::reverse(str.begin(), str.end());
}