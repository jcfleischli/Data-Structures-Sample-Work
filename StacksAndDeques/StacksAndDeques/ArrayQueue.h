/**********************************************************
* AUTHOR     : John Fleischli
* STUDENT ID : 1020047
* LAB#       : 1
* CLASS      : CS 1D
* SECTION    : MW: 3p - 6p
* DUE DATE   : 02/06/17
**********************************************************/
#ifndef ArrayQueue_H
#define ArrayQueue_H

#include <iostream>
using namespace std;

template<class Type>
class ArrayQueue
{
public:
  // Overload = operator
  const ArrayQueue<Type>& operator=(const ArrayQueue<Type>&);
  void initializeQueue();
  void destroyQueue();
  int isEmptyQueue();
  int isFullQueue();
  void addQueue(Type queueElement);
  void deQueue(Type& deqElement);

  ArrayQueue(int queueSize = 100);
  // copy constructor
  ArrayQueue(const ArrayQueue<Type>& otherQueue);

  ~ArrayQueue();
  //destructor

private:
  int maxQueueSize;
  int count;
  int front;
  int rear;
  Type *list;  //pointer to the array that holds the queue elements
};

template<class Type>
void ArrayQueue<Type>::initializeQueue()
{
  front = 0;
  rear = maxQueueSize - 1;
  count = 0;
}

template<class Type>
void ArrayQueue<Type>::destroyQueue()
{
  front = 0;
  rear = maxQueueSize - 1;
  count = 0;
}

template<class Type>
int ArrayQueue<Type>::isEmptyQueue()
{
  return(count == 0);
}

template<class Type>
int ArrayQueue<Type>::isFullQueue()
{
  return(count == maxQueueSize);
}

template<class Type>
void ArrayQueue<Type>::addQueue(Type newElement)
{
  rear = (rear + 1) % maxQueueSize; // use mod operator to advance rear
                                    //because array is circular
  count++;
  list[rear] = newElement;
}

template<class Type>
void ArrayQueue<Type>::deQueue(Type& deqElement)
{
  deqElement = list[front];

  count--;
  front = (front + 1) % maxQueueSize; // use mod operator to advance 									   // rear because the array is circular

}


template<class Type>
ArrayQueue<Type>::ArrayQueue(int queueSize)   //constructor
{
  if (queueSize <= 0)
  {
    cout << "Size of the array to hold the queue must "
      << "be positive." << endl;
    cout << "Creating an array of size 100." << endl;

    maxQueueSize = 100;
  }
  else
    maxQueueSize = queueSize;  //set maxQueueSize to queueSize

  front = 0; 	   //initialize front
  rear = maxQueueSize - 1; 	   //initiaize rear
  count = 0;
  list = new Type[maxQueueSize];  //create the array to
                                  //hold queue elements
}

template<class Type>
ArrayQueue<Type>::~ArrayQueue()   //destructor
{
  delete[] list;
}

template<class Type>
const ArrayQueue<Type>& ArrayQueue<Type>::operator=
(const ArrayQueue<Type>& otherQueue)
{
 
  if (this != &otherQueue) //avoid self-copy
  {
    if (front != NULL)  //if the stack is not empty, destroy it
      destroyQueue();

    if (otherQueue.front == NULL)
      front = NULL;
    else
    {
      while (otherQueue.front != NULL)
      {
        rear = (rear + 1) % maxQueueSize;
        count++;
        list[rear] = otherQueue.front;
        otherQueue.front;
      }// end while 
    }//end else
  }//end if

  return *this;
}


#endif

