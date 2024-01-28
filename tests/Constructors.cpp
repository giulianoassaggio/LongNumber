#include "../src/LongNumber.hpp"
#include <iostream>

int main() {
    /*
        CONSTRUCTORS
    */

    // default
    std::cout<<"Default constructor with base: "<<std::endl;
    LongNumber num1;
    
    
    // default with base and sign specified
    for (int i=2; i<17; i++){
        try{
            std::cout<<"Default constructor with base: "<<i<<" and sign: "<<std::boolalpha<<false<<std::endl;
            LongNumber(i, false);
            std::cout<<"Default constructor with base: "<<i<<" and sign: "<<std::boolalpha<<true<<std::endl;
            LongNumber(i, true);
        }
        catch (LongNumberException e){
            std::cout<<e.msg<<std::endl;
            continue;
        }
    }
 
    {
        // primitive constructors
        std::cout<<"primitive constructor, signed, positive, short"<<std::endl;
        LongNumber((short) 1); 
        std::cout<<"primitive constructor, signed, positive, int"<<std::endl;
        LongNumber((int) 1);
        std::cout<<"primitive constructor, signed, positive, long"<<std::endl;
        LongNumber((long) 1);
        std::cout<<"primitive constructor, signed, positive, long long"<<std::endl;
        LongNumber((long long) 1);
        std::cout<<"primitive constructor, signed, negative, short"<<std::endl;
        LongNumber((short) -1);
        std::cout<<"primitive constructor, signed, negative, int"<<std::endl;
        LongNumber((int) -1);
        std::cout<<"primitive constructor, signed, negative, long"<<std::endl;
        LongNumber((long) -1);
        std::cout<<"primitive constructor, signed, negative, long long"<<std::endl;
        LongNumber((long long) -1);
        std::cout<<"primitive constructor, unsigned, short"<<std::endl;
        LongNumber((unsigned short) 1);
        std::cout<<"primitive constructor, unsigned, int"<<std::endl;
        LongNumber((unsigned int) 1);
        std::cout<<"primitive constructor, unsigned, long"<<std::endl;
        LongNumber((unsigned long) 1);
        std::cout<<"primitive constructor, unsigned, long long"<<std::endl;
        LongNumber((unsigned long long) 1);
    }

    // copy
    LongNumber num2;
    std::cout<<"Copy constructor"<<std::endl;
    LongNumber num3{num1};
    
    std::cout<<"Copy self-assignment"<<std::endl;
    num2 = num2;

    std::cout<<"Copy assignment"<<std::endl;
    num2 = num3;

    //move
    std::cout<<"move constructor"<<std::endl;
    LongNumber num0;
    LongNumber num4 = std::move(num0);

    LongNumber num00(1);
    std::cout<<"move constructor"<<std::endl;
    num4 = std::move(num00);  


    {   
        // string constructors
        for (int base=2; base<16; base++){
            std::cout<<"std::string void constructor with base: "<<base<<std::endl;
            std::string s("");
            LongNumber x(s, base);
        }
    }
  
    {   
        std::cout<<"std::string void constructor with base: "<<10<<std::endl;
        std::string s0("");
        LongNumber x0(s0); 
        std::cout<<x0<<std::endl;    

        std::cout<<"number 1"<<std::endl;
        std::string s1("1");
        LongNumber x1(s1);
        std::cout<<x1<<std::endl;
        
        std::cout<<"number 6"<<std::endl;
        std::string s6("6");
        LongNumber x6(s6);
        std::cout<<x6<<std::endl;

        std::cout<<"number 10"<<std::endl;
        std::string s10("10");
        LongNumber x10(s10);
        std::cout<<x10<<std::endl;
#if DEBUG
        try{
            std::cout<<"number A"<<std::endl;
            std::string s = "A";
            LongNumber A(s);
        } catch (LongNumberException e) {
            std::cout<<e.msg<<std::endl;
        }
#endif
        std::cout<<"std::string with negative numbers"<<std::endl;
        std::cout<<"std::number -1, base 2"<<std::endl;
        std::string s = "-1";
        LongNumber A(s, 2);
        std::cout<<A<<std::endl;
        std::cout<<"std::number -1, base 16"<<std::endl;
        std::string ss1 = "-1";
        LongNumber A1(ss1, 16);
        std::cout<<A1<<std::endl;
        try {
            std::cout<<"std::number -1A2F, base 16"<<std::endl;
            std::string s2 = "-1A2F";
            LongNumber A2(s2, 16);
            std::cout<<A2<<std::endl;
        }
        catch (LongNumberException e){
            std::cout<<e.msg<<std::endl;
        }
        std::cout<<"std::number -A2F, base 16"<<std::endl;
        std::string s3 = "-A2F";
        LongNumber A3(s3, 16);
        std::cout<<A3<<std::endl;
        std::cout<<"std::string with explicitly positive numbers"<<std::endl;
        std::cout<<"std::number +1, base 2"<<std::endl;
        std::string s4 = "+1";
        LongNumber A4(s4, 2);
        std::cout<<A4<<std::endl;
        std::cout<<"std::number +1, base 16"<<std::endl;
        std::string s5 = "+1";
        LongNumber A5(s5, 16);
        std::cout<<A5<<std::endl;
        std::cout<<"std::number +1A2F, base 16"<<std::endl;
        std::string ss6 = "+1A2F";
        LongNumber A6(ss6, 16);
        std::cout<<A6<<std::endl;
        std::cout<<"std::number +A2F, base 16"<<std::endl;
        std::string s7 = "+A2F";
        LongNumber A7(s7, 16);
        std::cout<<A7<<std::endl;

#if DEBUG
        for (int i=0; i<5; i++){
            try{
                std::cout<<"String with errors in parsing"<<std::endl;
                if (i==0) {
                    std::string s("-1.Z2");
                    LongNumber(s, 16);
                }
                if (i==1) {
                    std::string s("+Z-2");
                    LongNumber(s, 16);
                }
                if (i==2) {
                    std::string s("1-2");
                    LongNumber(s, 16);
                }
                if (i==3) {
                    std::string s("-.-1AA+1--2");
                    LongNumber(s, 16);
                }
                if (i==4) {
                    std::string s("A+BF");
                    LongNumber(s, 16);
                }
            } catch (LongNumberException e) {
                std::cout<<e.msg<<std::endl;
                continue;
            }
        }
#endif
    }
    {   
        // string constructors
        for (int base=2; base<17; base++){
            std::cout<<"char* void constructor with base: "<<base<<std::endl;
            std::cout<<LongNumber("", base)<<std::endl;
        }
    }
    {   
        std::cout<<"char* void constructor with base: "<<10<<std::endl;
        std::cout<<LongNumber("")<<std::endl;
        std::cout<<"number 1"<<std::endl;
        std::cout<<LongNumber("1")<<std::endl;
        std::cout<<"number 6"<<std::endl;
        std::cout<<LongNumber("6")<<std::endl;
        std::cout<<"number 10"<<std::endl;
        std::cout<<LongNumber("10")<<std::endl;
#if DEBUG
        try{
            std::cout<<"number A"<<std::endl;
            LongNumber("A");
        } catch (LongNumberException e) {
            std::cout<<e.msg<<std::endl;
        }
#endif
    }
    std::cout<<"char* with negative numbers"<<std::endl;
    std::cout<<"std::number -1, base 2"<<std::endl;
    LongNumber A0("-1", 2);
    std::cout<<A0<<std::endl;
    std::cout<<"std::number -1, base 16"<<std::endl;
    LongNumber A1("-1", 16);
    std::cout<<A1<<std::endl;
    std::cout<<"std::number -1A2f, base 16"<<std::endl;
    LongNumber A2("-1A2f", 16);
    std::cout<<A2<<std::endl;
    std::cout<<"std::number -A2F, base 16"<<std::endl;
    LongNumber A3("-A2F", 16);
    std::cout<<A3<<std::endl;
    std::cout<<"char* with explicitly positive numbers"<<std::endl;
    std::cout<<"std::number +1, base 2"<<std::endl;
    LongNumber A4("+1", 2);
    std::cout<<A4<<std::endl;
    std::cout<<"std::number +1, base 16"<<std::endl;
    LongNumber A5("+1", 16);
    std::cout<<A5<<std::endl;
    std::cout<<"std::number +1a2f, base 16"<<std::endl;
    LongNumber A6("+1a2f", 16);
    std::cout<<A6<<std::endl;
    std::cout<<"std::number +A2F, base 16"<<std::endl;
    LongNumber A7("+A2F", 16);
    std::cout<<A7<<std::endl;
#if DEBUG
    for (int i=0; i<5; i++){
        try{
            std::cout<<"String with errors in parsing"<<std::endl;
            if (i==0) std::cout<<LongNumber("-1.,2", 16)<<std::endl;
            if (i==1) std::cout<<LongNumber("+1-2", 16)<<std::endl;
            if (i==2) std::cout<<LongNumber("1-2", 16)<<std::endl;
            if (i==3) std::cout<<LongNumber("--1AA+1--2", 16)<<std::endl;
            if (i==4) std::cout<<LongNumber("A+BF", 16)<<std::endl;
        } catch (LongNumberException e) {
            std::cout<<e.msg<<std::endl;
            continue;
        }
    }
#endif
}
