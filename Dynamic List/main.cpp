#include <iostream>
#include "List.h"
using std::cout;
using std::cin;
using std::endl;

int main(){

    List l1;
    cout << l1.empty() << endl;
    l1.insert(1,0);
    l1.insert(12,1);
    l1.insert(23,2);
    l1.insert(54,3);
    l1.insert(65,4);
    l1.insert(76,5);
    cout << l1 <<endl;
    cout << l1.empty() << endl;



    // l1.erase(6);
    // l1.erase(5);
    // l1.erase(3);
    // l1.erase(3);
    // l1.erase(0);
    // l1.erase(0);
    // l1.erase(0);
    // l1.erase(0);
    // cout << l1 <<endl;



    // List l5{l1};
    // cout << l5 <<endl;
    // l5.insert(10,0);
    // l1.erase(0);
    // cout << l1 <<endl;
    // cout << l5 <<endl;



    // List l6;
    // l6.insert(6,0);
    // l6.insert(6,1);
    // l6.insert(6,2);
    // cout << l6 <<endl;
    // l6 = l1;
    // cout << l1 <<endl;
    // cout << l6 <<endl;
    // l6.insert(10,0);
    // l1.erase(0);
    // cout << l1 <<endl;
    // cout << l6 <<endl;




    // List l10(7);
    // l10.insert(1,0);
    // l10.insert(11,1);
    // l10.insert(23,2);
    // l10.insert(53,3);
    // l10.insert(65,4);
    // l10.insert(76,5);
    // l10.insert(99,6);
    // cout << l10 << endl;
    // List l20;
    // l20.insert(11,0);
    // l20.insert(32,1);
    // l20.insert(53,2);
    // l20.insert(11,3);
    // l20.insert(76,4);
    // l20.insert(96,5);
    // l20.insert(99,6);
    // cout << l20 << endl;
    // List l30 = l10-l20;
    // cout << l30 << endl;




    // List l4;
    // l4.insert(1,0);
    // l4.insert(2,1);
    // l4.insert(5,2);
    // l4.insert(7,3);
    // l4.insert(3,4);
    // l4.insert(13,5);
    // l4.insert(5,6);
    // l4.insert(15,7);
    // l4.insert(7,8);
    // l4.insert(21,9);
    // l4.insert(5,10);
    // l4.insert(9,11);
    // l4.insert(15,12);
    // l4.insert(20,13);
    // cout << l4 << endl;
    // l4.eraseAll(2);
    // cout << l4 << endl;
     

    return 0;
}