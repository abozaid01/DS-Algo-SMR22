#include "List.h"

//class constructor
List::List()
:mySize{0}{
    std::cout << "constructor has been called!" << std::endl;
}

//empy operation
bool List::empty() const{
    return mySize == 0;
}

//insert
void List::insert(ElementType item, int pos){
    if(mySize == CAPACITY){
        std::cerr<<"No Enough Size!"<<std::endl;
        return;
    }
    if(pos<0 || pos>=CAPACITY){
        std::cerr<<"invalid pos" <<std::endl;
        return;
    }
    for(int i=mySize; i>pos; i--){
        myArray[i] = myArray[i-1];
    }
    myArray[pos] = item;
    mySize++;
}

//display
void List::display(std::ostream & out) const{
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

//insertion opereator
std::ostream & operator<< (std::ostream & out, const List & aList){
    aList.display(out);
    return out;
}

//erase
void List::erase(int pos) {
    if(pos<0 || pos>=mySize){
        std::cout<<"invalid pos" <<std::endl;
        return;
    }
    for(int i=pos; i<mySize; i++)
        myArray[i+1]=myArray[i];
    mySize--;
}                                       
                                        //l1{1,12,23,54,65,76}
//MergeSorted                           //l2{11,32,53,64,75,96,99}
List List::MergeSorted(const List &l2){ //MList{1,11,12,23,32,53,54,64,65,75,76,96,99}
    /*Precondition: the two lists MUST be sorted before merging them*/
    List MList {l2}; //Member wise copy
    for(int i=0; i<this->mySize; i++){
        for(int j=0; j<MList.mySize; j++){
            if(myArray[i]<MList.myArray[j]){
                MList.insert(myArray[i],j);
                break;
            }
        }
        std::cout << MList << std::endl;
    }
                                        
    return MList;
}