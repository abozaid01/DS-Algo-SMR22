/*
A good storage structure for a two-stack data type would be to use a single array for the storage
structure and let the stacks grow toward each other, as shown in the figure below:

Design a class for this two-stack data type using this implementation and a dynamic array. Just
implement the constructors, empty, full, push, pop and top operations. In your functions for the
basic stack operations, the number of the stack to be operated upon, 1 or 2, should be passed
as a parameter. Assume that the class declaration is implemented.
*/

#include <iostream>
#include <stdlib.h>

using namespace std;
typedef int ElementType; 
class twoStacks {
	ElementType *myArray;
	int mySize;
	int myTop1, myTop2;

public:
	// Constructor
	twoStacks(int maxSize)
	:mySize{0}{
		myArray = new int[maxSize];
		myTop1 = -1;
		myTop2 = maxSize;
	}

    // Method to push an element x to stack1
	void push1(ElementType x){
		if (myTop1 < mySize - 1) { //at least one element from the second stack
			myTop1++;
			myArray[myTop1] = x;
		}
		else {
			cout << "Stack Overflow" << endl;
			return;
		}
	}


	// Method to push an element x to stack2
	void push2(ElementType x){
		if (myTop2 > 0) {  //at least one element from the first stack
			myTop2--;
			myArray[myTop2] = x;
		}
		else {
			cout << "Stack Overflow" << endl;
			return;
		}
	}

    // Method to pop an element from first stack
	void pop1()
	{
		if (myTop1 >= mySize/2 + 1) {
			myTop1--;
		}
		else {
			cout << "Stack UnderFlow";
			return;
		}
	}

	// Method to pop an element from second stack
	void pop2()
	{
		if (myTop2 <= mySize / 2) {
			myTop2++;
		}
		else {
			cout << "Stack UnderFlow";
			return;
		}
	}

    //top1
    ElementType top1(){
        
        if (myTop1 >= mySize/2 + 1) {
            return myArray[myTop1];
        }
        else {
            cout << "Stack UnderFlow";
            return;
        }
    }

    //top2
    ElementType top2(){
        if (myTop2 <= mySize / 2) 
            return myArray[myTop2];
		else {
			cout << "Stack UnderFlow";
			return;
		}
    }

    bool empty1() { return myTop1 == -1;}
    bool empty2() { return myTop2 == mySize;}
    bool full() { return myTop1 == mySize/2 + 1 && myTop2 == mySize/2 ; }

};

int main(){

	twoStacks ts(5);
	ts.push1(5);
	ts.push2(10);
	ts.push2(15);
	ts.push1(11);
	ts.push2(7);
	
	return 0;
}

