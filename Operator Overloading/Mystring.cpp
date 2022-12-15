#include <iostream>
#include <cstring>
#include "Mystring.h"

 // No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[strlen(s)+1];
            strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[strlen(source.str)+ 1];
        strcpy(str, source.str);
 //       std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
Mystring::Mystring( Mystring &&source) 
    :str(source.str) {
        source.str = nullptr;
//        std::cout << "Move constructor used" << std::endl;
}

 // Destructor
Mystring::~Mystring() {
    delete [] str;
}

 // Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
//    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=( Mystring &&rhs) {
 //   std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}


// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

 // getters
 int Mystring::get_length() const { return strlen(str); }
 const char *Mystring::get_str() const { return str; }

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}

//---------------------------------------------------------

//==
bool Mystring::operator==(const Mystring &rhs) const {
    return *str == *(rhs.str);
    // if(std::strcmp(str,rhs.str)==0)
    //     return true;
    // else
    //     return false;
}

//!=
bool Mystring::operator!=(const Mystring &rhs) const {
    //return *str != *(rhs.str);
    if(std::strcmp(str,rhs.str)==0)
        return false;
    else
        return true;
}

//<
bool Mystring::operator<(const Mystring &rhs) const{ 
    if(std::strcmp(str,rhs.str) == -1)
        return true;
    else
        return false;
    
}

//>
bool Mystring::operator>(const Mystring &rhs) const{ 
    if(std::strcmp(str,rhs.str) == 1)
        return true;
    else
        return false;
    
}

//-
Mystring Mystring::operator-()const{
    char *str_temp = new char[get_length()+1];
    std::strcpy(str_temp,this->str);
    for(int i=0; i<get_length();i++)
        str_temp[i] = std::tolower(str_temp[i]);
    Mystring temp(str_temp);
    delete[] str_temp;
    return temp;
}

//+
Mystring Mystring::operator+(const Mystring &rhs)const{
    char *str_temp = new char[get_length()+strlen(rhs.str)+1];
    std::strcpy(str_temp,this->str);
    std::strcat(str_temp,rhs.str);
    Mystring temp(str_temp);
    delete[] str_temp;
    return temp;
}

//+=
Mystring &Mystring::operator+=(const Mystring &rhs){
    //void: std::strcat(this->str,rhs.str);
    *this = *this + rhs;
    return *this;
}

//*
Mystring Mystring::operator*(int num)const{
    char *str_temp = new char[this->get_length()*num+1];
    std::strcpy(str_temp,this->str);
    
    for(int i=1; i< num; i++)
        std::strcat(str_temp,str);

    Mystring temp{str_temp};
    delete[] str_temp;
    return temp;
}

//*=
Mystring & Mystring::operator*=(int num) {
    *this = *this * num;
    return *this;

}

Mystring &Mystring::operator++(){
    for(int i=0; i<get_length();i++)
        str[i] = std::toupper(str[i]);
    return *this;
}


Mystring Mystring::operator++(int){
    Mystring temp;
    temp = *this;
    operator++();
    return temp;
}