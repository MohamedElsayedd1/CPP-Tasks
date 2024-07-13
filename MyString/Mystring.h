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
    Mystring &operator=(const Mystring &s);
    Mystring &operator=(const char *s);
    void display() const;
    int get_length() const;
    const char *get_str() const;
    ~Mystring();
};

#endif