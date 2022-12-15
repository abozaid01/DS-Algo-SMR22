#include <iostream>

int main(){

    unsigned int x = 1; //00000000 00000000 00000000 0000001 

    char *c =(char*) &x; //whicg 1 byte of the 4 bytes integer?
    if(*c)
        std::cout << "Little endian" << std::endl; //00000001 00000000 00000000 00000000   *c =1
    else
        std::cout << "Big endian" << std::endl;  //00000000 00000000 00000000 00000001    *c =0

    return 0;
}