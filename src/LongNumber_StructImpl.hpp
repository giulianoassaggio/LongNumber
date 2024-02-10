#include "LongNumber.hpp"
#include <iostream>
#pragma once

// private pimpl implementation
struct LongNumber::impl {
    bool sign;  // true if positive, false if negative
    int base;   // beetween 2 and 16

    // numbers are stored in a doubly linked list, in reverse order (little endian)
    // start=nullptr => Number=0. not viceversa. (number 0 can also be explicity written)
    // hex letters are stored uppercase
    struct cella {
        char value;
        cella* prev;
        cella* next;
    };
    typedef cella* pcella;
    pcella start;
    pcella end;  

    void push_back(char x){
        if (end == nullptr){
            start = end = new cella{x, nullptr, nullptr};
        }
        else {
            pcella aux = new cella{x, end, nullptr};
            end = end->next = aux;
        }
    }
    void push_front(char x){
        if (start == nullptr){
            start = end = new cella{x, nullptr, nullptr};
        }
        else {
            pcella aux = new cella{x, nullptr, start};
            start = start->prev = aux;
        }
    }
    void pop_front(){
        if (start != nullptr){
            if (start->next == nullptr){
                delete start;
                start = end = nullptr;
            }
            else {
                pcella aux = start->next;
                delete start;
                aux->prev = nullptr;
                start = aux;
            }
        }
    }
    void pop_back(){
        if (end != nullptr){
            if (end->prev == nullptr){
                delete end;
                start = end = nullptr;
            }
            else {
                pcella aux = end->prev;
                delete end;
                aux->next = nullptr;
                end = aux;
            }
        }
    }
    impl(){
        start = end = nullptr;
        sign = true;
        base = 10;
    }
    ~impl(){
        while(start) pop_front();
        start = end = nullptr;
    }

    enum comparison_result{THIS_GREATER_OTHER, THIS_LESS_OTHER, THIS_EQUALS_OTHER};
    comparison_result comparison(LongNumber const & secondo) const;
    void pulisci(){
        while (end->value == '0') pop_back();
    }
    void add(LongNumber const other);
    void sub(LongNumber const other);
    static bool controllo_input(char c, int base, int pos);
    static char int_to_char(int x){
        if (x<10) return x+'0';
        else return x+'A'-10;
    }
    static int char_to_int(char x){
        if (x <= '9') return x-'0';
        else return x-'A'+10;
    }
};
