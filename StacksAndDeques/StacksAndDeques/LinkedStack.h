/**********************************************************
* AUTHOR     : John Fleischli
* STUDENT ID : 1020047
* LAB#       : 1
* CLASS      : CS 1D
* SECTION    : MW: 3p - 6p
* DUE DATE   : 02/06/17
**********************************************************/
#ifndef LINKEDSTACK_H_
#define LINKEDSTACk_H_

#include <iostream>
using namespace std;

template <class Type>
struct nodeType
{
  Type info;
  nodeType<Type> *link;
};

template<class Type>
class LinkedStack
{
public:
  //default constructor
  LinkedStack();

  //copy constructor
  LinkedStack(const LinkedStack<Type>& otherStack);

  //destructor
  ~LinkedStack();

  //overload = operator
  const LinkedStack<Type>& operator= (const LinkedStack<Type>&);

  //Initialize the stack to an empty state.
  void initializeStack();

  //Checks if the stack is empty
  bool isEmptyStack();

  //Checks if the stack is full
  bool isFullStack();

  //Add newItem to the stack
  void push(const Type& newItem);

  //Remove top element of the stack
  void pop(Type& poppedElement);

  //Remove all elements of the stack
  void destroyStack();

private:
  nodeType<Type> *top; // pointer to the stack
};

// default constructor
template<class Type> 
LinkedStack<Type>::LinkedStack()
{
  top = NULL;
}

// Destroys the stack
template<class Type>
void LinkedStack<Type>::destroyStack()
{
  nodeType<Type> *temp; 

  while (top != NULL)  
  {
    temp = top;      
    top = top->link; 
    delete temp;     
  }
}

template<class Type>
void LinkedStack<Type>::initializeStack()
{
  destroyStack();
}

template<class Type>
bool LinkedStack<Type>::isEmptyStack()
{
  return(top == NULL);
}

template<class Type>
bool LinkedStack<Type>::isFullStack()
{
  return 0;
}

// Adds new element to the stack
template<class Type>
void LinkedStack<Type>::push(const Type& newElement)
{
  nodeType<Type> *newNode; 

  newNode = new nodeType<Type>; 
  newNode->info = newElement;   
  newNode->link = top;          
  top = newNode;            
} 

// Remove element from the stack
template<class Type>
void LinkedStack<Type>::pop(Type& poppedElement)
{
  nodeType<Type> *temp;		

  poppedElement = top->info;	
                              
    temp = top;					
  top = top->link;				
  delete temp;					
}

//copy constructor
template<class Type>   
LinkedStack<Type>::LinkedStack(const LinkedStack<Type>& otherStack)
{
  nodeType<Type> *newNode, *current, *last;

  if (otherStack.top == NULL)
    top = NULL;
  else
  {
    current = otherStack.top;	
                             
    top = new nodeType<Type>;   
    top->info = current->info;  
    top->link = NULL;     	    
    last = top;                 
    current = current->link;    

                                
    while (current != NULL)
    {
      newNode = new nodeType<Type>;
      newNode->info = current->info;
      newNode->link = NULL;
      last->link = newNode;
      last = newNode;
      current = current->link;
    }//end while
  }//end else
}


template<class Type> //destructor
LinkedStack<Type>::~LinkedStack()
{
  nodeType<Type> *temp;

  while (top != NULL)     
  {
    temp = top;        
    top = top->link;  
    delete temp;       
  }//end while
}

//overloading the assignment operator
template<class Type>   
const LinkedStack<Type>& LinkedStack<Type>::operator=
(const LinkedStack<Type>& otherStack)
{
  nodeType<Type> *newNode, *current, *last;

  if (this != &otherStack) 
  {
    if (top != NULL)  
      destroyStack();

    if (otherStack.top == NULL)
      top = NULL;
    else
    {
      current = otherStack.top;	

                                
      top = new nodeType<Type>;	
      top->info = current->info;	
      top->link = NULL;			
                            
      last = top;           		
      current = current->link;	
                                
      while (current != NULL)
      {
        newNode = new nodeType<Type>;
        newNode->info = current->info;
        newNode->link = NULL;
        last->link = newNode;
        last = newNode;
        current = current->link;
      }//end while
    }//end else
  }//end if

  return *this;
}

#endif


