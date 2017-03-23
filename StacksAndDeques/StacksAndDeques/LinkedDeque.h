
#include <iostream>
#include <string>
using namespace std;

typedef string Elem;				
class LinkedDeque
{				
public:
  LinkedDeque();				
  int size() const;				
  bool empty() const;				
  const Elem& front() const throw(DequeEmpty); 
  const Elem& back() const throw(DequeEmpty);	
  void insertFront(const Elem& e);		
  void insertBack(const Elem& e);		
  void removeFront() throw(DequeEmpty);	
  void removeBack() throw(DequeEmpty);	
private:					
  DLinkedList D;				
  int n;					
};

// Insert into the front
void LinkedDeque::insertFront(const Elem& e)
{
  D.addFront(e);
  n++;
}

// Insert into the back
void LinkedDeque::insertBack(const Elem& e)
{
  D.addBack(e);
  n++;
}
// Remove the first element
void LinkedDeque::removeFront() throw(DequeEmpty)
{
  if (empty())
    throw DequeEmpty("removeFront of empty deque");
  D.removeFront();
  n--;
}
// Remove last element
void LinkedDeque::removeBack() throw(DequeEmpty)
{
  if (empty())
    throw DequeEmpty("removeBack of empty deque");
  D.removeBack();
  n--;
}


