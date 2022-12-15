#include "List.h"

//Class constructor
List::List(int maxSize)
:mySize{0}, myCapacity{maxSize}{
    myArray = new ElementType[maxSize];
}

//Class destructor
List::~List(){
    delete[] myArray;
}

//Copy constructor
List::List(const List &origList){ //List l2 {l1};
    this->mySize = origList.mySize;
    this->myCapacity = origList.myCapacity;
    this->myArray = new ElementType[myCapacity]; //Deep copy
    for(int i = 0; i < mySize; i++){
        this->myArray[i] = origList.myArray[i];
    }
    cout << "copy constructor" << endl;

}

//Assignment operator
const List &List::operator=(const List &rightHandSide){  //l1 = l2
    if(this == &rightHandSide)
        return *this;
    delete[] this->myArray;
    this->myCapacity=rightHandSide.myCapacity;
    this->mySize = rightHandSide.mySize;
    myArray = new ElementType[rightHandSide.myCapacity];
    for(int i=0; i<mySize; i++)
        myArray[i] = rightHandSide.myArray[i];
    return *this;

}

//empty operation
bool List::empty() const{
    return mySize == 0;
}

//insert
void List::insert(const ElementType item, int pos){
    if(mySize == myCapacity){
        std::cerr<<"No Enough Size!"<<std::endl;
        return;
    }
    if(pos<0 || pos>=myCapacity){
        std::cerr<<"invalid pos" <<std::endl;
        return;
    }
    for(int i=mySize; i>pos; i--){
        myArray[i] = myArray[i-1];
    }
    myArray[pos] = item;
    mySize++;
}

//erase
void List::erase(int pos){
    if(pos<0 || pos>=myCapacity){
        std::cerr<<"invalid pos" <<std::endl;
        return;
    }
    for(int i=pos;i<mySize;i++){
        myArray[i] = myArray[i+1];

    }
    mySize --;
}

//erase all
// list = (1, 2, 5, 7, 3, 13, 5, 15, 7, 21, 5, 9, 15, 20)
//list.eraseAll(2);
// The list will be = (1, 2, 7, 3, 13, 15, 7, 21, 9, 15, 20)
void List::eraseAll(int index) {
    if(index<0 || index>=mySize)
        cerr<<"Error, the index is not correct"<<endl;

    ElementType del = myArray[index];
    for(int i = index; i < mySize; i++)
        if(myArray[i] == del)
            erase(i);
}

//display
void List::display(ostream & out) const{
    if(mySize == 0){
        out << "Empty\n";
        return;
    }
    out <<"[";
    for(int i=0; i<mySize-1; i++){
        out << myArray[i] << ", ";
    }
    out <<myArray[mySize-1] <<  "]";
}

//insertion operator
ostream & operator<< (ostream & out, const List & aList){
    aList.display(out);
    return out;
}

// - operator 
// list1 = (1, 11, 23, 53, 65, 76, 99);
// list2 = (11, 32, 53, 64, 76, 96, 99);
// list3=list1-list2;
// list3 (11, 53, 76, 99)
List List::operator-(const List & aList){
    List temp;
    int pos =-1;
    for(int i=0; i<mySize; i++){
        for(int j=0; j<aList.mySize; j++){
            if(myArray[i]==aList.myArray[j]){
                pos++;
                temp.insert(myArray[i],pos);
                break;
            }
        }
        
    }
    return temp;
}

/*
A good storage structure for a two-stack data type would be to use a single array for the storage
structure and let the stacks grow toward each other, as shown in the figure below:

Design a class for this two-stack data type using this implementation and a dynamic array. Just
implement the constructors, empty, full, push, pop and top operations. In your functions for the
basic stack operations, the number of the stack to be operated upon, 1 or 2, should be passed
as a parameter. Assume that the class declaration is implemented.
*/

class MyStack
{
private:
    int myCapacity;
    int mySize;
    ElementType *myArray;
public:
    MyStack(/* args */);
    ~MyStack();
};

MyStack::MyStack(/* args */)
{
}

MyStack::~MyStack()
{
}