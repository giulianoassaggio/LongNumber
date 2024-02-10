#include <string>
#pragma once

#define DEBUG 0

/**
 * @brief Class representing large numbers (bigger than 64bits) with arbitrary bases. 
 * @author Giuliano Assaggio <www.github.com/giulianoassaggio>
 * @date january/february 2024
 */
class LongNumber {
    public:
        /**
         * @brief Default constructor with base 10.
         * @param base Optional. The base of the number system (default is 10).
         * @param sign Optional. true if positive, false if negative (default is true)
         */
        LongNumber(int base, bool sign);
        LongNumber();

        /**
         * @brief Destructor.
         */
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
        LongNumber(LongNumber &&other);

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
         * @param base The base of the number system (default is 10).
         */
        LongNumber(std::string &str);
        LongNumber(std::string &str, int base);
        /**
         * @brief Constructor from string with specified base.
         * @param str The string representing the number. it MUST end with terminator \0. If void, Number == 0
         * @param base The base of the number system (default is 10).
         */
        LongNumber(const char str[]);
        LongNumber(const char str[], int base);

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
         * @return Result of the addition.
         */
        LongNumber operator+=(LongNumber const &other){return LongNumber();}
        LongNumber operator+=(short other){return LongNumber();}
        LongNumber operator+=(int other){return LongNumber();}
        LongNumber operator+=(long other){return LongNumber();}
        LongNumber operator+=(long long other){return LongNumber();}
        LongNumber operator+=(unsigned short other){return LongNumber();}
        LongNumber operator+=(unsigned int other){return LongNumber();}
        LongNumber operator+=(unsigned long other){return LongNumber();}
        LongNumber operator+=(unsigned long long other){return LongNumber();}

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
        LongNumber operator-=(LongNumber const &other){return LongNumber();}
        LongNumber operator-=(short other){return LongNumber();}
        LongNumber operator-=(int other){return LongNumber();}
        LongNumber operator-=(long other){return LongNumber();}
        LongNumber operator-=(long long other){return LongNumber();}
        LongNumber operator-=(unsigned short other){return LongNumber();}
        LongNumber operator-=(unsigned int other){return LongNumber();}
        LongNumber operator-=(unsigned long other){return LongNumber();}
        LongNumber operator-=(unsigned long long other){return LongNumber();}

        /**
         * @brief Multiplication operator.
         * @param other The LongNumber to multiply.
         * @return Result of the multiplication.
         */
        LongNumber operator*(LongNumber const &other) const{return LongNumber();}
        LongNumber operator*(short other) const{return LongNumber();}
        LongNumber operator*(int other) const{return LongNumber();}
        LongNumber operator*(long other) const{return LongNumber();}
        LongNumber operator*(long long other) const{return LongNumber();}
        LongNumber operator*(unsigned short other) const{return LongNumber();}
        LongNumber operator*(unsigned int other) const{return LongNumber();}
        LongNumber operator*(unsigned long other) const{return LongNumber();}
        LongNumber operator*(unsigned long long other) const{return LongNumber();}

        /**
         * @brief Self-Multiplication operator.
         * @param other The LongNumber to multiply.
         * @return Result of the multiplication.
         */
        LongNumber operator*=(LongNumber const &other){return LongNumber();}
        LongNumber operator*=(short other){return LongNumber();}
        LongNumber operator*=(int other){return LongNumber();}
        LongNumber operator*=(long other){return LongNumber();}
        LongNumber operator*=(long long other){return LongNumber();}
        LongNumber operator*=(unsigned short other){return LongNumber();}
        LongNumber operator*=(unsigned int other){return LongNumber();}
        LongNumber operator*=(unsigned long other){return LongNumber();}
        LongNumber operator*=(unsigned long long other){return LongNumber();}

        /**
         * @brief Division operator.
         * @param other The LongNumber to divide by.
         * @return Result of the division.
         */
        LongNumber operator/(LongNumber const &other) const{return LongNumber();}
        LongNumber operator/(short other) const{return LongNumber();}
        LongNumber operator/(int other) const{return LongNumber();}
        LongNumber operator/(long other) const{return LongNumber();}
        LongNumber operator/(long long other) const{return LongNumber();}
        LongNumber operator/(unsigned short other) const{return LongNumber();}
        LongNumber operator/(unsigned int other) const{return LongNumber();}
        LongNumber operator/(unsigned long other) const{return LongNumber();}
        LongNumber operator/(unsigned long long other) const{return LongNumber();}

        /**
         * @brief Self-Division operator.
         * @param other The LongNumber to divide by.
         * @return Result of the division.
         */
        LongNumber operator/=(LongNumber const &other){return LongNumber();}
        LongNumber operator/=(short other){return LongNumber();}
        LongNumber operator/=(int other){return LongNumber();}
        LongNumber operator/=(long other){return LongNumber();}
        LongNumber operator/=(long long other){return LongNumber();}
        LongNumber operator/=(unsigned short other){return LongNumber();}
        LongNumber operator/=(unsigned int other){return LongNumber();}
        LongNumber operator/=(unsigned long other){return LongNumber();}
        LongNumber operator/=(unsigned long long other){return LongNumber();}

        template <typename T>
        /**
         * Calculates LongNumber modulo an integeral type.
         * types allowed (both signed and unsigned): short, int, long, long long.
         * @param mod the divisor. It must be > 1. It must be an integeral.
         * @returns the calculated modulus result, with the same type of the "mod" param
         * @throws LongNumberException if divisor is negative or <=1; or if mod type is not allowed
         * 
        */
        T operator%(T mod) const;


        /**
         * @brief Power operator.
         * @param exponent The exponent value.
         * @return Result of raising the number to the power of the exponent.
         */
        LongNumber operator^(short exponent) const{return LongNumber();}
        LongNumber operator^(int exponent) const{return LongNumber();}
        LongNumber operator^(long exponent) const{return LongNumber();}
        LongNumber operator^(long long exponent) const{return LongNumber();}
        LongNumber operator^(unsigned short exponent) const{return LongNumber();}
        LongNumber operator^(unsigned int exponent) const{return LongNumber();}
        LongNumber operator^(unsigned long exponent) const{return LongNumber();}
        LongNumber operator^(unsigned long long exponent) const{return LongNumber();}

        /**
         * @brief Equality comparison operator. It checks the value, not the base
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
         * @brief Inequality comparison operator. It checks the value, not the base
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
         * @brief Clone comparison. It checks both value and base
         * @param other The LongNumber to compare.
         * @return True if the value of the numbers are equal and base is equal too, false otherwise.
         */
        bool equals(LongNumber const &other) const;
        bool equals(short other) const;
        bool equals(int other) const;
        bool equals(long other) const;
        bool equals(long long other) const;
        bool equals(unsigned short other) const;
        bool equals(unsigned int other) const;
        bool equals(unsigned long other) const;
        bool equals(unsigned long long other) const;

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
         * @brief Get the current base of the LongNumber.
         */
        int getBase() const;

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
         * @brief Change the base of the LongNumber it is called on.
         * @param newBase The new base to set.
         * @note NewBase must be between 2 and 16 (included)
         * @throws LongNumberException if param is invalid
         */
        void setBase(int newBase);

        /**
         * @brief Change the sign of the LongNumber it is called on.
         * @details it doesn't check actual sign, it simply reassign it
         * @param newSign The new sign to set. must be '+' or '-'
         * @throws LongNumberException if param is invalid
         */
        void setSign(char newSign);
        /**
         * @brief Change the base of the LongNumber it is called on.
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
         * @brief it returns a new LongNumber semantically equal to this, but with base changed
         * @param newBase The new base to set.
         * @note NewBase must be between 2 and 16 (included)
         * @throws LongNumberException if param is invalid
         */
        LongNumber changeBase(int newBase) const;

        /**
         * @brief it returns a new LongNumber with value equal to the object it is called on, 
         * but with sign set to `newSign`
         * @param newSign The new sign to set. must be '+' or '-'
         * @throws LongNumberException if param is invalid
         */
        LongNumber changeSign(char newSign) const;
        /**
         * @brief it returns a new LongNumber with value equal to the object it is called on, 
         * but with sign set to `newSign`
         * @param newSign The new base to set. true if positive or zero, false otherwise
         */
        LongNumber changeSign(bool newSign) const;
        /**
         * @brief it returns a new LongNumber with value equal to the object it is called on, 
         * but with sign inverted
         * If number is 0, it sets sign to positive, always
        */
        LongNumber changeSign() const;

        std::string getNumber() const;
        
    private:
        struct impl;
        impl* pimpl;
};

/**
 * @brief Custom exception structure for LongNumber errors.
 */
struct LongNumberException {
    std::string msg;
};

/**
* @brief Output stream operator for LongNumber.
* @param os The output stream.
* @param number The LongNumber to output.
* @return Reference to the output stream.
*/
std::ostream& operator<<(std::ostream &os, LongNumber const &number);

/**
* @brief Input stream operator for LongNumber.
* @param is The input stream.
* @param number The LongNumber to input.
* @return Reference to the input stream.
*/
std::istream& operator>>(std::istream &is, LongNumber const & Number);
