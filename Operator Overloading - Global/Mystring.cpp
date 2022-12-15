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

//overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.get_str();
    return os;
}

// // overloaded extraction operator
// std::istream &operator>>(std::istream &in, Mystring &rhs) {
//     char *buff = new char[1000];
//     in >> buff;
//     rhs = Mystring{buff};
//     delete [] buff;
//     return in;
// }

//------------------------------------

bool operator==(const Mystring &lhs, const Mystring &rhs){
    return *(lhs.get_str()) == *(rhs.get_str());
}

bool operator!=(const Mystring &lhs, const Mystring &rhs){
    return std::strcmp(lhs.get_str(), rhs.get_str()) !=0;
}

bool operator<(const Mystring &lhs, const Mystring &rhs){
    return std::strcmp(lhs.str,rhs.str) < 0;
}

bool operator>(const Mystring &lhs, const Mystring &rhs){
    return std::strcmp(lhs.get_str(),rhs.get_str()) > 0;
}


Mystring operator-(const Mystring &rhs){
    char *str_temp = new char[rhs.get_length()+1];
    std::strcpy(str_temp,rhs.get_str());
    for(int i=0; i<rhs.get_length();i++)
        str_temp[i] = std::tolower(str_temp[i]);
    Mystring temp(str_temp);
    delete [] str_temp;
    return temp;
}

Mystring operator+(const Mystring &lhs, const Mystring &rhs){
    char *str_temp = new char[lhs.get_length()+rhs.get_length()+1];
    std::strcpy(str_temp,lhs.get_str());
    std::strcat(str_temp,rhs.get_str());
    Mystring temp(str_temp);
    delete[] str_temp;
    return temp;
}

Mystring operator+=(Mystring &lhs, const Mystring &rhs){
    lhs = lhs+rhs;
    return lhs;
}


Mystring operator*(const Mystring lhs, int num){
    Mystring temp;
    for (int i=1; i<=num; i++){
        temp = temp + lhs;
    }
    return temp;
}

Mystring operator*=(Mystring &lhs,int num){
    lhs = lhs * num;
    return lhs;
}

Mystring operator++(Mystring &rhs){
    for(int i=0; i<rhs.get_length(); i++){
        rhs.str[i] = std::toupper(rhs.str[i]);
    }
    return rhs;
}


Mystring operator++(Mystring &rhs, int){
    Mystring temp {rhs};
    ++rhs;
    return temp;
}






