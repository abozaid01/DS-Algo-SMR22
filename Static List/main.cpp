#include <iostream>
#include "List.h"
using namespace std;

int main(){
    
    cout << boolalpha;
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


    cout << "\n\n================================\n";


    List l2;
    l2.insert(11,0);
    l2.insert(32,1);
    l2.insert(53,2);
    l2.insert(64,3);
    l2.insert(75,4);
    l2.insert(96,5);
    l2.insert(99,6);
    cout << l2 <<endl;

    List l3 = l1.MergeSorted(l2);
    cout << l3 <<endl;
}
