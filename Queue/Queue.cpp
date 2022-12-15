#include "Queue.h"

//constructor
Queue::Queue()
:myFront{NULL}, myBack{NULL}{
}

//copy constructor
Queue::Queue(const Queue & original){
    if(original.myFront == NULL && original.myBack == NULL)
        return;
    myFront = new Node(original.myFront->data);
    myBack = myFront;
    NodePointer orgi;
    orgi = original.myFront->next;
    while(orgi != nullptr){
        myBack->next = new Node(orgi->data);
        orgi = orgi->next;
        myBack = myBack->next;
    }
}

//destructor
Queue::~Queue(){
    NodePointer ptr = myFront;
    NodePointer prev = myFront;
    while(ptr != NULL){
        ptr = ptr->next;
        delete prev;
        prev = ptr;
    }
}

//assignment operator
const Queue & Queue::operator=(const Queue & rightHandSide){
    if(this == &rightHandSide)
        return *this;
    this->~Queue();
    myFront = new Node(rightHandSide.myFront->data);
    myBack = myFront;
    NodePointer orgi;
    orgi = rightHandSide.myFront->next;
    while(orgi != nullptr){
        myBack->next = new Node(orgi->data);
        orgi = orgi->next;
        myBack = myBack->next;
    }
    return *this;
}

//Check if queue is empty
bool Queue::empty() const{
    return myFront == nullptr && myBack == nullptr;
}

//Add a value to a queue
void Queue::enqueue(const QueueElement & value){
    NodePointer newPtr = new Node(value);
    newPtr->next = NULL;
    if(myFront == nullptr && myBack == nullptr){
        myFront = newPtr;
        myBack = newPtr;
    }
    else{
        myBack->next = newPtr;
        myBack = newPtr;        
    }

}

//Retrieve value at front of queue (if any)
QueueElement Queue::front()const{
    if(!this->empty()){
        return myFront->data;
    }
    else{
        cout << "Queue is empty" << endl;
        return -1;
    }
}

//Remove value at front of queue (if any)
void Queue::dequeue(){
    if(this->empty()){
        cout << "Queue is empty" << endl;
        return;
    }
    if(myFront == myBack){
        myFront = NULL;
        myBack = NULL;
        return;
    }
    NodePointer ptr = myFront;
    myFront = myFront->next;
    delete ptr;
}

//Display values stored in the queue
void Queue::display(ostream & out) const{
    if(this->empty()){
        cout << "Empty Queue" << endl;
        return;
    }
    NodePointer ptr = myFront;
    out << "[";
    while(ptr->next !=NULL){
        out << ptr->data << ", ";
        ptr = ptr->next;
    }
    out << ptr->data <<"]";
}

//output operator
ostream & operator<< (ostream & out, const Queue & aList){
    aList.display(out);
    return out;
}