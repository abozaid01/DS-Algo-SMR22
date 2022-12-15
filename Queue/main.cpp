#include <iostream>
#include <vector>
#include <algorithm>
#include "Queue.h"
using namespace std;

int main(){
    cout << boolalpha;

    Queue q1;

    q1.enqueue(3);
    q1.enqueue(2);
    q1.enqueue(6);
    q1.enqueue(7);
    q1.enqueue(1);
    q1.enqueue(8);

    cout << q1 << endl;


    // vector<int> vec;
	// for(int i = 0; i<q. ;i++)
	// 	vec.at(i) = i << " ";

	// cout << endl;

	// sort(vec.begin(), vec.end());
	// for(auto i:vec)
	// 	cout << i << " ";

    // q1.enqueue(vec[0]); 
    
    // Queue q2;
    // q2.enqueue(5);
    // q2.enqueue(5);
    // q2.enqueue(5);
    // q2= q1; 
    // cout << q2 << endl;
    // q1.enqueue(30);
    // q2.enqueue(20);
    // cout << q1 << endl;
    // cout << q2 << endl;

    // Queue q3{q1};
    // cout << q3 << endl;



    return 0;
}