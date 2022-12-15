#include "List.h"

//cosntruct
List::List()
:first{NULL},mySize{0}{
}

//copy constructor
List::List(const List& origList):first{0},mySize{origList.mySize}{ //List l2{l1};
    if(mySize == 0)
        return;
    mySize = origList.mySize;
    first = new Node(origList.first->data);
    NodePointer orgi,cpy;
    cpy = first;
    orgi = origList.first->next;
    while(orgi != nullptr){
        cpy->next = new Node(orgi->data);
        orgi = orgi->next;
        cpy = cpy->next;
    }

}

//destructor
List::~List(){
    NodePointer ptr,prev;
    ptr = prev = first;
    while(prev != NULL){
        ptr = prev->next;
        delete prev;
        prev = ptr;
    }
}

//assignment operator
const List &List::operator=(const List &rightSide){
    if(this == &rightSide)
        return *this;
    this->~List();
    mySize = rightSide.mySize;
    first = nullptr;
    NodePointer orgi,cpy;
    first = new Node(rightSide.first->data);
    cpy = first;
    orgi = rightSide.first->next;
    while(orgi != nullptr){
        cpy->next = new Node(orgi->data);
        orgi = orgi->next;
        cpy = cpy->next;
    }
    return *this;
}

//empty method
bool List::empty(){
    return mySize==0;
}

//insert method
void List::insert(ElementType dataVal,int index){
    if(index<0 || index > mySize){
        std::cerr<<"invalid position" << std::endl;
        return;
    }
    mySize++;
    NodePointer ptr = first;
    NodePointer new_ptr = new Node{dataVal};
    if(index==0){
        new_ptr->next = first;
        first = new_ptr;
    }
    else{
        for(int i=0;i<index-1;i++)
          ptr = ptr->next; 
        new_ptr->next = ptr->next;
        ptr->next = new_ptr;
    }

}


//erase
void List::erase(int index){
    if(index<0 || index >= mySize){
        std::cerr<<"invalid position" << std::endl;
        return;
    }
    NodePointer ptr = first->next;
    NodePointer prev =first;
    if(index == 0){
        first = first->next;
        delete prev;
        prev = first;
    }
    else{
        for(int i=0; i<index-1; i++){
            ptr = ptr->next;
            prev = prev->next;
        }
        prev->next = ptr->next;
        delete ptr;
    }
    mySize--;

}

//Search
int List::search(ElementType dataVal){
    if(mySize == 0)
        return -1;
    NodePointer ptr = first;
    int count = 0;
    bool found = false;
    while(ptr->next != nullptr){
        count++;
        if(ptr->data == dataVal){
            found = true;
            break;
        }
        ptr = ptr->next;   
    }
    if(found)
        return count;
    else
        return -1;
}

//display
void List::display(std::ostream& out)const{
    if(mySize == 0){
        out << "No elements found";
        return;
    }
    NodePointer ptr = first;
    out << "[";
    while(ptr->next != NULL){
        out << ptr->data << ", ";
        ptr = ptr->next;
    }
    out << ptr->data << "]";
        
}


//insertion operator
std::ostream &operator<<(std::ostream &out, const List &alist){
    alist.display(out);
    return out;
}


//extraction operator
std::istream &operator>>(std::istream &in, List &alist){
    ElementType data;
    in >> data;
    alist.insert(data, alist.mySize);
    return in;
}


//Count the elements of this list.
int List::nodeCount(){
    return mySize;

    //Another Soultion
    /*if(this->empty()){
        cout << "Empty list" << endl;
        return 0;
    }
    NodePointer ptr = first;
    int count = 1;
    while(ptr->next != NULL){
        ptr = ptr->next;
        count++;
    }
    return count;*/

}

// Reverse this list
void List::reverse(){
    NodePointer current = first;
    NodePointer next = NULL;
    NodePointer prev = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    first = prev;
}

//Check if the elements of this list are in ascending order
bool List::ascendingOrder(){
    if(this->empty()){
        cout << "Empty list" << endl;
        return false;
    }
    NodePointer ptr = first;
    while(ptr->next != NULL){
        if(ptr->data > ptr->next->data)
            return false;
        ptr = ptr->next;
    }
    return true;
}


void List::removeDuplicates (){
    NodePointer ptr = first->next;
    NodePointer prev = first;
    int index = -1;
    while(ptr != NULL){
        index++;
        if(ptr->data == prev->data)
            this->erase(index);
        prev = prev->next;
        ptr = ptr->next;        
    }
}