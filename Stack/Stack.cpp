#include "Stack.h"

//Construct a Stack object
Stack::Stack()
:myTop {NULL}{
}


//copy constructor
Stack::Stack(const Stack &original){
    if(original.myTop == NULL)
        return;
    myTop = new Node(original.myTop->data);
    NodePointer orgi,cpy;
    cpy = myTop;
    orgi = original.myTop->next;
    while(orgi != nullptr){
        cpy->next = new Node(orgi->data);
        orgi = orgi->next;
        cpy = cpy->next;
    }
}

//destructor
Stack::~Stack(){
    NodePointer ptr = myTop;
    NodePointer prev = myTop;
    while(ptr != NULL){
        ptr = ptr->next;
        delete prev;
        prev = ptr;
    }
}

//Assignment operator
const Stack& Stack::operator=(const Stack & rightHandSide) {
    if(this == &rightHandSide)
        return *this;
    this->~Stack();
    myTop = nullptr;
    NodePointer orgi,cpy;
    myTop = new Node(rightHandSide.myTop->data);
    cpy = myTop;
    orgi = rightHandSide.myTop->next;
    while(orgi != nullptr){
        cpy->next = new Node(orgi->data);
        orgi = orgi->next;
        cpy = cpy->next;
    }
    return *this;
}

// Check if stack is empty
bool Stack::empty()const{
    return myTop == NULL;
}

//Add a value to a stack
void Stack::push(const StackElement & value){
    if(myTop == NULL){
        NodePointer newPtr = new Node(value);
        myTop = newPtr;
        newPtr->next = NULL;
    }
    else{
        NodePointer newPtr = new Node(value);
        newPtr->next = myTop;
        myTop = newPtr;
    }
}

//Retrieve value at top of stack (if any)
StackElement Stack::top()const{
    if(!this->empty())
        return myTop->data;
    else{
        cout << "Top of stack is empty" << endl;
        return -1;
    }
}

void Stack::pop(){
    if(myTop == NULL){
        cout << "Top of stack is empty" << endl;
        return;
    }
    NodePointer ptr = myTop;
    myTop = myTop->next;
    delete ptr;

}

//Display vlaues in the stack
void Stack::display(ostream & out) const{
    if(this->empty()){
        cout << "Empty Stack" << endl;
        return;
    }
    NodePointer ptr = myTop;
    out << "[";
    while(ptr->next !=NULL){
        out << ptr->data << ", ";
        ptr = ptr->next;
    }
    out << ptr->data <<"]";
    
}

//output operator
std::ostream &operator<<(std::ostream &out, const Stack &aStack){
    aStack.display(out);
    return out;
}