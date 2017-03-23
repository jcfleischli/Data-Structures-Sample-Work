#ifndef DLINKEDDEQUE_H
#define DLINKEDDEQUE_H

#include "Header.h"

template <class Type>
struct Node
{
  Type info;
  Node<Type> * link;
};


template<class Type>
class DLinkedDeque
{
public:
  DLinkedDeque();
  ~DLinkedDeque();
  void insertFront(const Type& newItem);
  void eraseFront(Type& erasedElement);
  void insertBack(const Type& inputItem);
  void eraseBack(Type& erasedElement);
  bool isEmpty();
  void print();
  int size();



protected:
  Node<Type> * head;
  Node<Type> * tail;
  int count;

};

template <class Type>
DLinkedDeque<Type>::DLinkedDeque()
{
  head = NULL;
  tail = NULL;
  count = 0;

}

template <class Type>
DLinkedDeque<Type>::~DLinkedDeque()
{

}



template <class Type>
int DLinkedDeque<Type>::size()
{
  count = 0;

  Node<Type> *perPtr;

  for (perPtr = head; perPtr != NULL; perPtr = perPtr->link)
  {
    count++;
  }
  return count;
}

template<class Type>
void DLinkedDeque<Type>::print()
{


  Node<Type> *current;

  current = head;

  if (head != NULL)
  {
    cout << "Your list is\n";
  }
  do
  {
    cout << current->info << endl;

    if (current->link != NULL)
    {
      current = current->link;
    }
  } while (current->link != NULL);

  cout << current->info << endl << endl;

}
template<class Type>
void DLinkedDeque<Type>::insertFront(const Type& newElement)
{
  Node<Type> *newNode; //pointer to create the new node

  newNode = new Node<Type>; //create the node
  newNode->info = newElement;   //store newElement in the node
  newNode->link = head;          //insert newNode before top
  head = newNode;            //set top to point to the top node
  count++;
} //end push


template<class Type>
void DLinkedDeque<Type>::eraseFront(Type& erasedElement)
{
  Node<Type> *temp;		//pointer to deallocate memory
  erasedElement = head->info;
  temp = head;
  //copy the top element into
  //for (int i = 0; i < count; i++)
  //{
   // temp = temp->link;
  //}

  //cout << "Popped item is " << temp->info << endl;
  //poppedElement
  //cout << "Popped item is " << head->info << endl;
  temp = head;					//set temp to point to the top node
  head = head->link;				//advance top to the next node
  delete temp;					//delete the top node
  count--;
}//end pop


template <class Type>
void DLinkedDeque<Type>::insertBack(const Type& inputItem)
{
  Node <Type> *itemsPtr;
  itemsPtr = new Node <Type>;

  itemsPtr->info = inputItem;
  itemsPtr->link = NULL;

  if (isEmpty())
  {
    head = itemsPtr;

  }
  else
  {
    tail->link = itemsPtr;
  }
  tail = itemsPtr;
  count++;

}

template <class Type>
void DLinkedDeque<Type>::eraseBack(Type& erasedElement)
{
  Node<Type> *newFront;
  erasedElement = tail ->info;
  newFront = NULL;

  if (head != NULL)
  {
    newFront = tail->link;
    delete tail;
    tail = newFront;

    if (head == NULL)
    {
      tail = NULL;
    }
  }
  count--;
}


template <class Type>
bool DLinkedDeque<Type>::isEmpty()
{

  return(count == 0);
}

#endif /* DLINKEDDEQUE_H_ */
