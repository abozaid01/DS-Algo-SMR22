#include <iostream>
#include "List.h"
using std::cout;
using std::cin;
using std::endl;

int main(){
    
    cout << boolalpha;
    List l1;
    cout << l1.empty() << endl;
    l1.insert(1,0);
    l1.insert(12,1);
    l1.insert(12,2);
    l1.insert(23,3);
    l1.insert(15,4);
    l1.insert(60,5);
    cout << l1 <<endl;
     l1.removeDuplicates() ;
    cout << l1 << endl;

    // l1.erase(6);
    // l1.erase(5);
    // l1.erase(3);
    // l1.erase(3);
    // l1.erase(0);
    // l1.erase(0);
    // l1.erase(0);
    // l1.erase(0);
    // cout << l1 <<endl;



    // List l2 {l1};
    // //List l2 = l1;
    // cout << l2 << endl;
    // l1.erase(0);
    // l2.insert(0,0);
    // cout << l2 << endl;
    // cout << l1 << endl;

    // cout << "Enter number: ";
    // cin >>l2;
    // cout << l2 << endl;



    //cout << l1.search(6) << endl;


    //cout << l1.nodeCount() << endl;


    // l1.reverse();
    // cout << l1 << endl;


    // cout<< l1.ascendingOrder() << endl;
    // List l100;
    // l100.insert(3,0);
    // l100.insert(5,1);
    // l100.insert(1,2);
    // cout << l100.ascendingOrder() << endl;


    return 0;
}