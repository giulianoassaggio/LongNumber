#include <vector>
#include <string>
#include <type_traits>
#include <limits>
#include <cmath>

#pragma once

#define DEBUG 0
#define BASE16 16


/**
 * @brief Custom exception structure for LongNumber errors.
 */
struct LongNumberException {
    std::string msg;
};

/**
 * @brief Class representing large numbers (bigger than 64bits) with arbitrary bases. 
 * @author Giuliano Assaggio <www.github.com/giulianoassaggio>
 * @date january/february 2024
 */
class LongNumber {
    public:
        LongNumber();
        ~LongNumber();

        /**
         * @brief Copy constructor.
         * @param other The LongNumber object to copy.
         */
        LongNumber(LongNumber const &other);

        /**
         * @brief Move constructor.
         * @param other The LongNumber object to move.
         */
        LongNumber(LongNumber &&other) noexcept;

        /**
         * @brief Move assignment operator.
         * @param other The LongNumber object to move.
         * @return Reference to the assigned object.
         */
        LongNumber& operator=(LongNumber &&other);

        /**
         * @brief Copy assignment operator.
         * @param other The LongNumber object to copy.
         * @return Reference to the assigned object.
         */
        LongNumber& operator=(LongNumber const &other);

        /**
         * @brief Constructor for signed integer values.
         * @param value The signed integer value.
         */
        LongNumber(short value);
        LongNumber(int value);
        LongNumber(long value);
        LongNumber(long long value);

        /**
         * @brief Constructor for unsigned integer values.
         * @param value The unsigned integer value.
         */
        LongNumber(unsigned short value);
        LongNumber(unsigned int value);
        LongNumber(unsigned long value);
        LongNumber(unsigned long long value);

        /**
         * @brief Constructor from string with specified base.
         * @param str The string representing the number. If void, Number == 0
         * @param base The base of the number system. 2<=base<=16 (default is 16).
         */
        LongNumber(std::string &str, int base);
        LongNumber(std::string &str);
        /**
         * @brief Constructor from string with specified base.
         * @param str The string representing the number. it MUST end with terminator \0. If void, Number == 0
         * @param base The base of the number system. 2<=base<=16 (default is 16).
         */
        LongNumber(const char str[], int base);
        LongNumber(const char str[]);

        /**
         * @brief Addition operator.
         * @param other The LongNumber to add.
         * @return Result of the addition.
         */
        LongNumber operator+(LongNumber const &other) const;
        LongNumber operator+(short other) const;
        LongNumber operator+(int other) const;
        LongNumber operator+(long other) const;
        LongNumber operator+(long long other) const;
        LongNumber operator+(unsigned short other) const;
        LongNumber operator+(unsigned int other) const;
        LongNumber operator+(unsigned long other) const;
        LongNumber operator+(unsigned long long other) const;

        /**
         * @brief Self-Addition operator.
         * @param other The LongNumber to add.
         * @return Result of the addition as a longNumber
         */
        LongNumber& operator+=(LongNumber const &other);
        LongNumber& operator+=(short other);
        LongNumber& operator+=(int other);
        LongNumber& operator+=(long other);
        LongNumber& operator+=(long long other);
        LongNumber& operator+=(unsigned short other);
        LongNumber& operator+=(unsigned int other);
        LongNumber& operator+=(unsigned long other);
        LongNumber& operator+=(unsigned long long other);

        /**
         * @brief Subtraction operator.
         * @param other The LongNumber to subtract.
         * @return Result of the subtraction.
         */
        LongNumber operator-(LongNumber const &other) const;
        LongNumber operator-(short other) const;
        LongNumber operator-(int other) const;
        LongNumber operator-(long other) const;
        LongNumber operator-(long long other) const;
        LongNumber operator-(unsigned short other) const;
        LongNumber operator-(unsigned int other) const;
        LongNumber operator-(unsigned long other) const;
        LongNumber operator-(unsigned long long other) const;

        /**
         * @brief Self-Substraction operator.
         * @param other The LongNumber to add.
         * @return Result of the addition.
         */
        LongNumber& operator-=(LongNumber const &other);
        LongNumber& operator-=(short other);
        LongNumber& operator-=(int other);
        LongNumber& operator-=(long other);
        LongNumber& operator-=(long long other);
        LongNumber& operator-=(unsigned short other);
        LongNumber& operator-=(unsigned int other);
        LongNumber& operator-=(unsigned long other);
        LongNumber& operator-=(unsigned long long other);

        /**
         * @brief Multiplication operator.
         * @param other The LongNumber to multiply.
         * @return Result of the multiplication.
         */
        LongNumber operator*(LongNumber const &other) const;
        LongNumber operator*(short other) const;
        LongNumber operator*(int other) const;
        LongNumber operator*(long other) const;
        LongNumber operator*(long long other) const;
        LongNumber operator*(unsigned short other) const;
        LongNumber operator*(unsigned int other) const;
        LongNumber operator*(unsigned long other) const;
        LongNumber operator*(unsigned long long other) const;

        /**
         * @brief Self-Multiplication operator.
         * @param other The LongNumber to multiply.
         * @return Result of the multiplication.
         */
        LongNumber& operator*=(LongNumber const &other);
        LongNumber& operator*=(short other);
        LongNumber& operator*=(int other);
        LongNumber& operator*=(long other);
        LongNumber& operator*=(long long other);
        LongNumber& operator*=(unsigned short other);
        LongNumber& operator*=(unsigned int other);
        LongNumber& operator*=(unsigned long other);
        LongNumber& operator*=(unsigned long long other);

        /**
         * @brief Division operator.
         * @param other The LongNumber to divide by.
         * @return Result of the division.
         * @throws LongNumberException if divisor is 0
         */
        LongNumber operator/(LongNumber const &other) const;
        LongNumber operator/(short other) const;
        LongNumber operator/(int other) const;
        LongNumber operator/(long other) const;
        LongNumber operator/(long long other) const;
        LongNumber operator/(unsigned short other) const;
        LongNumber operator/(unsigned int other) const;
        LongNumber operator/(unsigned long other) const;
        LongNumber operator/(unsigned long long other) const;

        /**
         * @brief Self-Division operator.
         * @param other The LongNumber to divide by.
         * @return Result of the division.
         * @throws LongNumberException if divisor is 0
         */
        LongNumber& operator/=(LongNumber const &other);
        LongNumber& operator/=(short other);
        LongNumber& operator/=(int other);
        LongNumber& operator/=(long other);
        LongNumber& operator/=(long long other);
        LongNumber& operator/=(unsigned short other);
        LongNumber& operator/=(unsigned int other);
        LongNumber& operator/=(unsigned long other);
        LongNumber& operator/=(unsigned long long other);


        template <typename T>
        /**
         * Calculates LongNumber modulo an integeral type.
         * types allowed (both signed and unsigned): short, int, long, long long.
         * @param mod the divisor. It must be > 1. It must be an integeral.
         * @returns the calculated modulus result, with the same type of the "mod" param
         * @throws LongNumberException if divisor is negative or <=1; or if mod type is not allowed
         * 
        */
        T operator%(T mod) const{
            if (mod <= 1) throw LongNumberException {"Modulus divisor must be greater than 1"};
            static_assert(std::is_integral_v<T>, "Modulus must be an integral type");
            
            LongNumber remainder(0); // must be LongNumber due to overflow possibility. Then casted to T.
            pcell aux = end;
            while (aux) {
                int digit = char_to_int(aux->value);
                remainder = (remainder * BASE16 + digit) % mod;
                aux = aux->prev;
            }

            /*
            if sign is positive, modulus result is just the remainder, else it is
            the inverted remainder plus the modulus.

            for example:
            5 % 3 = 2
            -5 % 3 = 1   -> (-2)+3  -> 3 - 2
            */
            T casted_remainder = (T)(remainder);
            return sign ? casted_remainder : mod - casted_remainder;
        }


        /**
         * @brief Power operator.
         * @param exponent The exponent value.
         * @return Result of raising the number to the power of the exponent.
         * @details the time complexity is O(log n) * every multiplication subroutine ~O(x^1.585), where n is the exponent and 
         * x is the number of digits of the two numbers involved in multiplication.
         */
        LongNumber operator^(short exponent) const;
        LongNumber operator^(int exponent) const;
        LongNumber operator^(long exponent) const;
        LongNumber operator^(long long exponent) const;
        LongNumber operator^(unsigned short exponent) const;
        LongNumber operator^(unsigned int exponent) const;
        LongNumber operator^(unsigned long exponent) const;
        LongNumber operator^(unsigned long long exponent) const; 

        /**
         * @brief Equality comparison operator. It checks the value
         * @param other The LongNumber to compare.
         * @return True if the numbers are equal, false otherwise.
         */
        bool operator==(LongNumber const &other) const;
        bool operator==(short other) const;
        bool operator==(int other) const;
        bool operator==(long other) const;
        bool operator==(long long other) const;
        bool operator==(unsigned short other) const;
        bool operator==(unsigned int other) const;
        bool operator==(unsigned long other) const;
        bool operator==(unsigned long long other) const;

        /**
         * @brief Inequality comparison operator. It checks the value
         * @param other The LongNumber to compare.
         * @return True if the numbers are not equal, false otherwise.
         */
        bool operator!=(LongNumber const &other) const;
        bool operator!=(short other) const;
        bool operator!=(int other) const;
        bool operator!=(long other) const;
        bool operator!=(long long other) const;
        bool operator!=(unsigned short other) const;
        bool operator!=(unsigned int other) const;
        bool operator!=(unsigned long other) const;
        bool operator!=(unsigned long long other) const;

        /**
         * @brief Greater than or equal to comparison operator.
         * @param other The LongNumber to compare.
         * @return True if the calling number is greater than or equal to the provided number, false otherwise.
         */
        bool operator>=(LongNumber const &other) const;
        bool operator>=(short other) const;
        bool operator>=(int other) const;
        bool operator>=(long other) const;
        bool operator>=(long long other) const;
        bool operator>=(unsigned short other) const;
        bool operator>=(unsigned int other) const;
        bool operator>=(unsigned long other) const;
        bool operator>=(unsigned long long other) const;

        /**
         * @brief Less than or equal to comparison operator
         * @param other The LongNumber to compare.
         * @return True if the calling number is less than or equal to the provided number, false otherwise.
         */
        bool operator<=(LongNumber const &other) const;
        bool operator<=(short other) const;
        bool operator<=(int other) const;
        bool operator<=(long other) const;
        bool operator<=(long long other) const;
        bool operator<=(unsigned short other) const;
        bool operator<=(unsigned int other) const;
        bool operator<=(unsigned long other) const;
        bool operator<=(unsigned long long other) const;

        /**
         * @brief Less than comparison operator
         * @param other The LongNumber to compare.
         * @return True if the calling number is less than the provided number, false otherwise.
         */
        bool operator<(LongNumber const &other) const;
        bool operator<(short other) const;
        bool operator<(int other) const;
        bool operator<(long other) const;
        bool operator<(long long other) const;
        bool operator<(unsigned short other) const;
        bool operator<(unsigned int other) const;
        bool operator<(unsigned long other) const;
        bool operator<(unsigned long long other) const;

        /**
         * @brief Greater than comparison operator
         * @param other The LongNumber to compare.
         * @return True if the calling number is greater than the provided number, false otherwise.
         */
        bool operator>(LongNumber const &other) const;
        bool operator>(short other) const;
        bool operator>(int other) const;
        bool operator>(long other) const;
        bool operator>(long long other) const;
        bool operator>(unsigned short other) const;
        bool operator>(unsigned int other) const;
        bool operator>(unsigned long other) const;
        bool operator>(unsigned long long other) const;

        /**
         * @brief cast to primitive integral type 
         * @details truncates the value, if too big. Casting negative numbers to unsigned types return absolute value
        */

        explicit operator short() const{
            return cast_value<short>();
        }
        explicit operator int() const{
            return cast_value<int>();
        }
        explicit operator long() const{
            return cast_value<long>();
        }
        explicit operator long long() const{
            return cast_value<long long>();
        }
        explicit operator unsigned short() const{
            return cast_value<unsigned short>();
        }
        explicit operator unsigned int() const{
            return cast_value<unsigned int>();
        }
        explicit operator unsigned long() const{
            return cast_value<unsigned long>();
        }
        explicit operator unsigned long long() const{
            return cast_value<unsigned long long>();
        }
        explicit operator bool() const{
            return *this == 0 ? false : true;
        }

        /**
         * @brief Get the current sign of the LongNumber.
         * @returns char '+' or '-'
         */
        char getSignAsCharacter() const;
        /**
         * @brief Get the current sign of the LongNumber.
         * @returns true if positive or zero, false if negative. 
        */
        bool getSignAsBoolean() const;

        /**
         * @brief Change the sign of the LongNumber it is called on. If *this == 0, 
         * sign will remain true, in every case
         * @details it doesn't check actual sign, it simply reassign it
         * @param newSign The new sign to set. must be '+' or '-'
         * @throws LongNumberException if param is invalid
         */
        void setSign(char newSign);
        /**
         * @brief Change the base of the LongNumber it is called on.If *this == 0, 
         * sign will remain true, in every case
         * @details it doesn't check actual sign, it simply reassign it
         * @param newSign The new sign to set. true if positive or zero, false otherwise
         */
        void setSign(bool newSign);
        /**
         * @brief Inverts the sign of the LongNumber it is called on.
         * @details if sign is set to negative, it changes it to positive and viceversa.
         * If number is 0, it sets sign to positive, always
        */
        void invertSign();

        /**
         * @brief it returns a new LongNumber with value equal to the object it is called on, 
         * but with sign set to `newSign`. If *this == 0, sign will remain true, in every case
         * @param newSign The new sign to set. must be '+' or '-'
         * @throws LongNumberException if param is invalid
         */
        LongNumber changeSign(char newSign) const;
        /**
         * @brief it returns a new LongNumber with value equal to the object it is called on, 
         * but with sign set to `newSign`. If *this == 0, sign will remain true, in every case
         * @param newSign The new base to set. true if positive or zero, false otherwise
         */
        LongNumber changeSign(bool newSign) const;
        /**
         * @brief it returns a new LongNumber with value equal to the object it is called on, 
         * but with sign inverted
         * If number is 0, it sets sign to positive, always
        */
        LongNumber changeSign() const;

        /**
         * @brief default getter
         * @details hexadecimal value of LongNumber as string. letters are uppercase. explicit sign only if negative.
        */
        std::string getNumber() const;
        /**
         * @brief custom-based getter
         * @details return LongNumber as string, in the base choosen. letters are uppercase. explicit sign only if negative.
         * @param base custom base
         * @warning allowed bases: 2<=base<=16.
         * @throws LongNumberException if base not allowed
        */
        std::string getNumber(int base) const;

        /**
         * @brief returns number of digits (assuming hex representation)
        */
        long long getSize() const;
         
    private:
        long long size;
        bool sign;  // true if positive or 0, false if negative
        /* 
        * numbers are stored as hexadecimal in a doubly linked list, in reverse order (little endian)
        * start=nullptr => Number=0. not viceversa. (number 0 can also be explicity written)
        * hex letters are stored uppercase
        */
        struct cell {
            char value;
            cell* prev;
            cell* next;
        };
        typedef cell* pcell;
        pcell start;
        pcell end;  

        LongNumber push_back(char x){
            if (end == nullptr){
                start = end = new cell{x, nullptr, nullptr};
            }
            else {
                pcell aux = new cell{x, end, nullptr};
                end = end->next = aux;
            }
            size++;
            return *this;
        }
        LongNumber push_front(char x){
            if (start == nullptr){
                start = end = new cell{x, nullptr, nullptr};
            }
            else {
                pcell aux = new cell{x, nullptr, start};
                start = start->prev = aux;
            }
            size++;
            return *this;
        }
        LongNumber pop_front(){
            if (start != nullptr){
                if (start->next == nullptr){
                    delete start;
                    start = end = nullptr;
                }
                else {
                    pcell aux = start->next;
                    delete start;
                    aux->prev = nullptr;
                    start = aux;
                }
            }
            size--;
            return *this;
        }
        LongNumber pop_back(){
            if (end != nullptr){
                if (end->prev == nullptr){
                    delete end;
                    start = end = nullptr;
                }
                else {
                    pcell aux = end->prev;
                    delete end;
                    aux->next = nullptr;
                    end = aux;
                }
            }
            size--;
            return *this;
        }

        /* * * * * * * * * * * 
        *  UTILITY FUNCTIONS *
        * * * * * * * * * * */

        // Used in comparison operators 
        enum comparison_result{THIS_GREATER_OTHER, THIS_LESS_OTHER, THIS_EQUALS_OTHER};
        comparison_result comparison(LongNumber const & secondo) const;

        // removes all unnecessary zeros in the most significant positions
        void clean_up(){
            while (end && end->value == '0') pop_back();
        }

        // digit by digit sum and sub, used in operators + and -
        void add(LongNumber const &other);
        void sub(LongNumber const &other);

        // input validation
        static bool input_check(char c, int base, int pos);

        // custom casts to handle base16 alphabet
        static char int_to_char(int x){
            if (x<10) return x+'0';
            else return x+'A'-10;
        }
        static int char_to_int(char x){
            if (x <= '9') return x-'0';
            else return x-'A';
        }

        // base conversion, used in constructors and output with different bases.
        static void convert_to_BASE16(std::string & str, int base);
        static void convert_from_BASE16(std::string & str, int base);

        // template to cast LongNumber to integral primitive types
        template <typename T>
        T cast_value() const {
            
            if (std::is_unsigned<T>::value && !sign)
                return (T) this->changeSign(true);

            T limit = std::numeric_limits<T>::max();
            if (*this >= LongNumber(limit)) return limit;

            limit = std::numeric_limits<T>::min();
            if (*this <= LongNumber(limit)) return limit;

            limit = 0;
            pcell aux = start;
            T i = 0;
            while (aux) {
                limit += static_cast<T>(aux->value) * static_cast<T>(std::pow(BASE16, i));
                aux = aux->next;
                ++i;
            }
            return limit;
        }

        // karatsuba algorithm implementation
        static LongNumber karatsuba(LongNumber first, LongNumber second);

        /**
         * @brief division algorithm
         * @details Implements a long division algorithm similar to how it's performed manually. If numbers are small enough, it uses built-in operations.
         * @throws LongNumberException if divisor is 0
        */
        static LongNumber long_division_algorithm(LongNumber dividend, LongNumber divisor);


        /**
         * @brief it uses squaring method 
         * @warning it handles only positive exponents
        */
        template <typename T>
        static LongNumber squared_power(LongNumber base, T exponent) {
            if (exponent == 0) {
                return LongNumber(1);
            }

            if (exponent % 2 == 0) {
                LongNumber halfPower = squared_power(base, exponent / 2);
                LongNumber result =  halfPower * halfPower;
                return result;
            } else {
                return base * squared_power(base, exponent - 1);
            }
        }
};

/**
* @brief Output stream operator for LongNumber.
* @param os The output stream.
* @param number The LongNumber to output, in base16.
* @return Reference to the output stream.
*/
std::ostream& operator<<(std::ostream &os, LongNumber const &number);

/**
* @brief Input stream operator for LongNumber.
* @param is The input stream.
* @param number The LongNumber to input. can be signed, it will be interpreted as base16
* @return Reference to the input stream.
*/
std::istream& operator>>(std::istream &is, LongNumber & Number);
