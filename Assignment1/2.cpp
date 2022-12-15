/*
Implement Queue using Stacks

Implement a first in first out (FIFO) queue using only two stacks. The implemented
queue should support all the functions of a normal queue (push, peek, pop, and empty).
Implement the MyQueue class:
    ● void push(int x) Pushes element x to the back of the queue.
    ● int pop() Removes the element from the front of the queue and returns it.
    ● int peek() Returns the element at the front of the queue.
    ● boolean empty() Returns true if the queue is empty, false otherwise.
*/
#include <iostream>
#include "Stack.h"
using namespace std;

class MyQueue
{
private:
    Stack s1, s2;
public:
    MyQueue();
    void push(int x);
    int pop();
    bool empty();
    int peek();
};

MyQueue::MyQueue()
{
}
	

// push an item to the queue
void MyQueue::push(int x){
    // Push item into the first stack
    s1.push(x);
}

// pop an item from the queue
int MyQueue::pop(){
    // if both stacks are empty
    if (s1.empty() && s2.empty()) {
        cout << "Q is empty";
        exit(0);
    }
    // if s2 is empty, move elements from s1
    if (s2.empty()) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    // return the top item from s2
    int x = s2.top();
    s2.pop();
    return x;
}

bool MyQueue::empty(){
    return s1.empty() && s2.empty();
}

int MyQueue::peek(){
    if(this->empty()) return -1;
    if(s2.empty()){
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        return s2.top();
    }
    return s2.top();
}

int main(){


    MyQueue myQueue;
    myQueue.push(1); // queue is: [1]
    myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
    cout << myQueue.peek() << endl; // return 1
    cout << myQueue.pop() << endl; // return 1, queue is [2]
    cout << myQueue.peek() << endl; // return 2
    cout << myQueue.empty(); // return false

    return 0;
}