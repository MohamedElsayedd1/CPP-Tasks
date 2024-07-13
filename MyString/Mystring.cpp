#include "Mystring.h"

void Mystring::display() const{
    cout << "str : " << str << endl;
}
int Mystring::get_length() const{
    cout << "str length : " << strlen(str) << endl;
}
const char *Mystring::get_str() const{
    return str;
}

Mystring::Mystring()
{
    str = nullptr;
    str = new char;
    str[0] = '\0';
}
Mystring::Mystring(const char *s)
{
    if(s == nullptr){
        str = nullptr;
        str = new char;
        *str = '\0';
    }
    else{
        str = new char[strlen(s) + 1];
        strcpy(str, s);
        *(str + strlen(s)) = '\0';
    }
    
}

Mystring::Mystring(const Mystring &s)
{
    str = new char[strlen(s.str) + 1];
    strcpy(this->str, s.str);
    *(str + strlen(s.str)) = '\0';
}


Mystring::~Mystring(){
    delete[] this->str;
}

Mystring &Mystring::operator=(const Mystring &s){
    if(this == &s)
        return *this;

    delete[] this->str;
    str = new char[strlen(s.str) + 1];
    strcpy(str, s.str);
    *(str + strlen(s.str)) = '\0';
    return *this;
}

Mystring &Mystring::operator=(char const *s){
    delete[] str;
    str = new char[strlen(s) + 1];
    strcpy(str, s);
    *(str + strlen(s)) = '\0';
    return *this;
}
