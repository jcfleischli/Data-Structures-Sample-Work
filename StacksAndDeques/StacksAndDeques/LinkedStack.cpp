#include "LinkedStack.h"

template<class Type> //default constructor
LinkedStack<Type>::LinkedStack()
{
  top = NULL;
}

template<class Type>
void LinkedStack<Type>::destroyStack()
{
  nodeType<Type> *temp; //pointer to delete the node

  while (top != NULL)  //while there are elements in the stack
  {
    temp = top;      //set temp to point to the current node
    top = top->link; //advance top to the next node
    delete temp;     //deallocate memory occupied by temp
  }
}// end destroyStack



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

template<class Type>
void LinkedStack<Type>::push(const Type& newElement)
{
  nodeType<Type> *newNode; //pointer to create the new node

  newNode = new nodeType<Type>; //create the node
  newNode->info = newElement;   //store newElement in the node
  newNode->link = top;          //insert newNode before top
  top = newNode;            //set top to point to the top node
} //end push


template<class Type>
void LinkedStack<Type>::pop(Type& poppedElement)
{
  nodeType<Type> *temp;		//pointer to deallocate memory

  poppedElement = top->info;	//copy the top element into
                              //poppedElement
  cout << "Popped item is " << poppedElement << endl;
  temp = top;					//set temp to point to the top node
  top = top->link;				//advance top to the next node
  delete temp;					//delete the top node
}//end pop



template<class Type>   //copy constructor
LinkedStack<Type>::LinkedStack(const LinkedStack<Type>& otherStack)
{
  nodeType<Type> *newNode, *current, *last;

  if (otherStack.top == NULL)
    top = NULL;
  else
  {
    current = otherStack.top;	//set current to point to the
                              //stack to be copied

                              //copy the top element of the stack
    top = new nodeType<Type>;   //create the node
    top->info = current->info;  //copy the info
    top->link = NULL;     	    //set the link field of the
                                //node to null
    last = top;                 //set last to point to the node
    current = current->link;    //set current to point to the
                                //next node

                                //copy the remaining stack
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
}//end copy constructor


template<class Type> //destructor
LinkedStack<Type>::~LinkedStack()
{
  nodeType<Type> *temp;

  while (top != NULL)     //while there are elements in the stack
  {
    temp = top;        //set temp to point to the current node
    top = top->link;  //advance first to the next node
    delete temp;       //deallocate the memory occupied by temp
  }//end while
}//end destructor

template<class Type>   //overloading the assignment operator
const LinkedStack<Type>& LinkedStack<Type>::operator=
(const LinkedStack<Type>& otherStack)
{
  nodeType<Type> *newNode, *current, *last;

  if (this != &otherStack) //avoid self-copy
  {
    if (top != NULL)  //if the stack is not empty, destroy it
      destroyStack();

    if (otherStack.top == NULL)
      top = NULL;
    else
    {
      current = otherStack.top;	//set current to point to
                                //the stack to be copied

                                //copy the top element of otherStack
      top = new nodeType<Type>;	//create the node
      top->info = current->info;	//copy the info
      top->link = NULL;			//set the link field of the
                            //node to null
      last = top;           		//make last point to the node
      current = current->link;	//make current point to
                                //the next node

                                //copy the remaining elements of the stack
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
}//end operator=

