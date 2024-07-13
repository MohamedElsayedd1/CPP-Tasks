#ifndef MYSTRING_H
#define MYSTRING_H

#pragma once

#include <iostream>
#include <cstring>

using namespace std;

class Mystring
{
private:
    char *str;
public:
    Mystring();
    Mystring(const char *s);
    Mystring(const Mystring &s);
    // move constructor
    Mystring(Mystring &&s);
    Mystring &operator=(const Mystring &s);
    // Mystring &operator=(const char *s);
    // Move assignment operator
    Mystring &operator=(Mystring &&s); // not const and &&
    void display() const;
    int get_length() const;
    const char *get_str() const;
    ~Mystring();
};

#endif