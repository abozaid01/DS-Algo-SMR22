//
//  DList.hpp
//  DynamicList
//
//  Created by Ashraf AbdelRaouf on 9/22/15.
//  Copyright © 2015 Ashraf AbdelRaouf. All rights reserved.
//
/*-- DList.h --------------------------------------------------------------
 
 This header file defines the data type List for processing lists.
 Basic operations are:
 Constructor
 Destructor
 Copy constructor
 Assignment operator
 empty:    Check if list is empty
 insert:   Insert an item
 erase:    Remove an item
 display:  Output the list
 << :      Output operator
 -------------------------------------------------------------------------*/

#include <stdio.h>
#include <iostream>
using namespace std;

#ifndef DList_hpp
#define DList_hpp

typedef int ElementType;
class List
{
public:
    /******** Function Members ********/
    /***** Class constructor *****/
    List(int maxSize = 1024);   //default parameter   List l1, l2(250);
    /*----------------------------------------------------------------------
     Construct a List object.
     
     Precondition:  maxSize is a positive integer with default value 1024.
     Postcondition: An empty List object is constructed; myCapacity ==
     maxSize (default value 1024); myArray points to a dynamic
     array with myCapacity as its capacity; and mySize is 0.
     -----------------------------------------------------------------------*/
    
    /***** Class destructor *****/
    ~List(); //tilde
    /*----------------------------------------------------------------------
     Destroys a List object.
     
     Precondition:  The life of a List object is over.
     Postcondition: The memory dynamically allocated by the constructor
     for the array pointed to by myArray has been returned to the heap.
     -----------------------------------------------------------------------*/
    
    /***** Copy constructor *****/
    List(const List & origList);
    /*----------------------------------------------------------------------
     Construct a copy of a List object.
     
     Precondition:  A copy of origList is needed; origList is a const
     reference parameter.
     Postcondition: A copy of origList has been constructed.
     -----------------------------------------------------------------------*/
    
    /***** Assignment operator *****/
    const List & operator=(const List & rightHandSide);
    /*----------------------------------------------------------------------
     Assign a copy of a List object to the current object.
     
     Precondition: none
     Postcondition: A copy of rightHandSide has been assigned to this
     object. A const reference to this list is returned.
     -----------------------------------------------------------------------*/
    
    /***** empty operation *****/
    bool empty() const;
    //--- See Figure 6.1 for documentation
    
    /***** insert and erase *****/
    void insert(ElementType item, int pos);
    //--- See Figure 6.1 for documentation (replace CAPACITY with myCapacity)
    
    void erase(int pos);
    //--- See Figure 6.1 for documentation
    
    /***** output *****/
    void display(ostream & out) const;
    //--- See Figure 6.1 for documentation
    
    void eraseAll(int index);
    List operator-(const List& list2);
private:
    /******** Data Members ********/
    int mySize;                // current size of list
    int myCapacity;            // capacity of array
    ElementType * myArray;     // pointer to dynamic array 
    
}; //--- end of List class

//------ Prototype of output operator
ostream & operator<< (ostream & out, const List & aList);

#endif /* DList_hpp */