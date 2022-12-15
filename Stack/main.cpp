#include <iostream>
#include "Stack.h"
using std::cout;
using std::cin;
using std::endl;




int main(){
    cout << boolalpha;
    Stack s1;
    cout << s1.empty() << endl;
    cout << s1.top() << endl;
    s1.push(10);
    cout << s1.empty() << endl;
    s1.pop();
    cout << s1 << endl;


    s1.push(4);
    s1.push(5);
    s1.push(6);
    cout << s1 << endl;
    cout << s1.top() << endl;


    Stack s2 {s1};
    //Stack s2 = s1;
    cout << s1 << endl;
    cout << s2 << endl;

    s1.push(4);
    s2.push(5);

    cout << s1 << endl;
    cout << s2 << endl;

    return 0;
}