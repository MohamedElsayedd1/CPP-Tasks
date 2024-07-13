#include "Mystring.h"

void Mystring::display() const {
    cout << "str : " << str << endl;
}

int Mystring::get_length() const {
    cout << "str length : " << strlen(str) << endl;
}

const char *Mystring::get_str() const {
    return str;
}

Mystring::Mystring() {
    str = nullptr;
    str = new char;
    str[0] = '\0';
    cout << "default constructor is called for """ << str << endl;
}

Mystring::Mystring(const char *s) {
    if (s == nullptr) {
        str = nullptr;
        str = new char;
        str[0] = '\0';
    } else {
        str = new char[strlen(s) + 1];
        strcpy(this->str, s);
        *(str + strlen(s)) = '\0';
    }
    cout << "1 arg constructor is called for " << str << endl;
}

Mystring::Mystring(const Mystring &s) {
    str = new char[strlen(s.str) + 1];
    strcpy(this->str, s.str);
    *(str + strlen(s.str)) = '\0';
    cout << "Copy constructor is called for " << str << endl;
}

Mystring::~Mystring() {
    if (str == nullptr) {
        cout << "Destructor is called for nullptr" << endl;
    } else {
        cout << "Destructor is called for " << str << endl;
    }
    delete[] this->str;
}

Mystring &Mystring::operator=(const Mystring &s) {
    if (this == &s)
        return *this;

    delete[] this->str;
    str = new char[strlen(s.str) + 1];
    strcpy(str, s.str);
    *(str + strlen(s.str)) = '\0';
    cout << "Copy assignment operator is called for " << str << endl;
    return *this;
}

Mystring &Mystring::operator=(Mystring &&s) {
    if (this == &s)
        return *this;

    delete[] str;
    str = s.str;
    s.str = nullptr;
    cout << "Move assignment operator is called for " << str << endl;
    return *this;
}

Mystring::Mystring(Mystring &&s) {
    cout << "Move constructor is called for " << s.str << endl;
    str = s.str;
    s.str = nullptr;
}

