/**********************************************************
* AUTHOR     : John Fleischli
* STUDENT ID : 1020047
* LAB#       : 1
* CLASS      : CS 1D
* SECTION    : MW: 3p - 6p
* DUE DATE   : 02/06/17
**********************************************************/
#include "Header.h"
#include "DLinkedDeque.h"
#include "ArrayQueue.h"
#include "LinkedStack.h"

/**************************************************************
* Stacks and Deques:
* -------------------------------------------------------------
*  This program will create multiple string and double stacks,
* queues, and deques. In order it will create a STL stack,
* singly linked list stack, array queue, and a linked list
* dequeue. It will also use an Parentheses Algorithm to test
* if the functions inputed are formatted properly.
***************************************************************/

void ParenthesesMatch(char array[][19], int size);

int main()
{
  stack<string> stringStack;
  stack<double> doubleStack;
  stack<string> stringStackCopy;
  stack<double> doubleStackCopy;
  LinkedStack<string> linkedStringStack;
  LinkedStack<string> linkedStringStackCopy;
  LinkedStack<double> linkedDoubleStack;
  LinkedStack<double> linkedDoubleStackCopy;
  ArrayQueue<string> stringQueue;
  ArrayQueue<string> stringQueueCopy;
  ArrayQueue<double> doubleQueue;
  ArrayQueue<double> doubleQueueCopy;
  DLinkedDeque<string> stringDeque;
  DLinkedDeque<string> stringDequeCopy;
  DLinkedDeque<double> doubleDeque;
  DLinkedDeque<double> doubleDequeCopy;
  string myString;
  string stringTop;
  double doubleTop;
  double myDouble;
  char ParenthesesArray[7][19] = 
  {
  {'(','2','x','-','4',')','(','1','2','x','+','6',')'},
  {'{','2','x','+','5','}','(','6','x','+','4',')','}'},
  {'[','(','5','x','-','5',')','-','4','x','[','6','x','+','2',']',']'},
  {'{','{','8','x','+','5',')','-','5','x','[','9','x','+','3',']','}',')'},
  {'{','(','8','x','+','5',')','-','6','x','[','9','x','+','3',']',']'},
  {'(','2','x','-','4',')','(','1','2','x','+','6','}'},
  {'(','(','(','6','x','+','6',')','-','x','[','9','x','+','3',']',')',')',')'}
  };

  PrintHeader(cout, "John Fleischli", "Stacks and Deques", "2");

  cout << "Stacks and Queues:\n"
    << "-----------------------------------------------------------\n"
    << "| This program will create multiple string and double stacks,\n"
    << "| queues, and deques. In order it will create a STL stack,  \n"
    << "| singly linked list stack, array queue, and a linked list \n"
    << "| dequeue. It will also use an Parentheses Algorithm to test\n"
    << "| if the functions inputed are formatted properly.\n"
    << "-----------------------------------------------------------\n";
  // PART A
  cout << "--\n"
    << "A|\n"
    << "--\n"
    << "String Stack:\n";
  // Implementing stacks
  for (int i = 0; i < 6; i++)
  {
    cout << "Enter string " << i + 1 << ": ";
    getline(cin, myString);
    stringStack.push(myString);
  }

  cout << "\n\nDouble Stack:\n";

  for (int i = 0; i < 8; i++)
  {
    cout << "Enter double " << i + 1 << ": ";
    cin >> myDouble;
    doubleStack.push(myDouble);
  }
  cin.ignore(1000, '\n');

  // Displaying what the stacks contain
  cout << "\nThe string stack contains: \n";

  stringStackCopy = stringStack;

  stringTop = stringStackCopy.top();
  cout << stringTop;
  stringStackCopy.pop();

  while (!stringStackCopy.empty())
  {
    stringTop = stringStackCopy.top();
    cout << ", " << stringTop;
    stringStackCopy.pop();
  }

  cout << endl;

  cout << "\nThe double stack contains: \n";

  doubleStackCopy = doubleStack;

  doubleTop = doubleStackCopy.top();
  cout << doubleTop;
  doubleStackCopy.pop();

  while (!doubleStackCopy.empty())
  {
    doubleTop = doubleStackCopy.top();
    cout << ", " << doubleTop;
    doubleStackCopy.pop();
  }

  getchar();

  // PART B
  cout << "\n\n--\n"
    << "B|\n"
    << "--\n";

  // Removing the elements from stack
  myString = stringStack.top();
  stringStack.pop();
  cout << "Popped " << myString << " from string stack" << endl;
  myString = stringStack.top();
  stringStack.pop();
  cout << "Popped " << myString << " from string stack" << endl;

  myDouble = doubleStack.top();
  doubleStack.pop();
  cout << "\nPopped " << myDouble << " from double stack" << endl;
  myDouble = doubleStack.top();
  doubleStack.pop();
  cout << "Popped " << myDouble << " from double stack" << endl;

  // Displaying the remaining elements
  cout << "\nAfter removing " << myString << ", the string stack contains: \n";


  stringTop = stringStack.top();
  cout << stringTop;
  stringStack.pop();

  while (!stringStack.empty())
  {
    stringTop = stringStack.top();
    cout << ", " << stringTop;
    stringStack.pop();
  }

  cout << "\n\nAfter removing " << myDouble << ", the double stack contains: \n";

  doubleTop = doubleStack.top();
  cout << doubleTop;
  doubleStack.pop();

  while (!doubleStack.empty())
  {
    doubleTop = doubleStack.top();
    cout << ", " << doubleTop;
    doubleStack.pop();
  }

  getchar();

  // PART C
  cout << "\n\n--\n"
    << "C|\n"
    << "--\n"
    << "Singly Linked List String Stack:\n";
  // Implementing stacks
  for (int i = 0; i < 6; i++)
  {
    cout << "Enter string " << i + 1 << ": ";
    getline(cin, myString);
    linkedStringStack.push(myString);
    linkedStringStackCopy.push(myString);
  }

  cout << "\n\nSingly Linked List Double Stack:\n";

  for (int i = 0; i < 8; i++)
  {
    cout << "Enter double " << i + 1 << ": ";
    cin >> myDouble;
    linkedDoubleStack.push(myDouble);
    linkedDoubleStackCopy.push(myDouble);
  }

  cin.ignore(1000, '\n');

  // Displaying what the stacks contain
  cout << "\nThe Singly Linked List String Stack contains: \n";

  linkedStringStackCopy.pop(stringTop);
  cout << stringTop;

  while (!linkedStringStackCopy.isEmptyStack())
  {
    linkedStringStackCopy.pop(stringTop);
    cout << ", " << stringTop;
  }

  cout << endl;

  cout << "\nThe Singly Linked List Double Stack contains: \n";

  linkedDoubleStackCopy.pop(doubleTop);
  cout << doubleTop;

  while (!linkedDoubleStackCopy.isEmptyStack())
  {
    linkedDoubleStackCopy.pop(doubleTop);
    cout << ", " << doubleTop;
  }

  getchar();

  // PART D
  cout << "\n\n--\n"
    << "D|\n"
    << "--\n";

  // Removing elements from stack
  linkedStringStack.pop(myString);
  cout << "Popped " << myString << " from string stack" << endl;
  linkedStringStack.pop(myString);
  cout << "Popped " << myString << " from string stack" << endl;

  linkedDoubleStack.pop(myDouble);
  cout << "\nPopped " << myDouble << " from double stack" << endl;
  linkedDoubleStack.pop(myDouble);
  cout << "Popped " << myDouble << " from double stack" << endl;

  // Displaying the remaining elements in stack
  cout << "\nAfter removing " << myString << ", the singly linked list string stack contains: \n";

  linkedStringStack.pop(stringTop);
  cout << stringTop;

  while (!linkedStringStack.isEmptyStack())
  {
    linkedStringStack.pop(stringTop);
    cout << ", " << stringTop;
  }

  cout << "\n\nAfter removing " << myDouble << ", the singly linked list double stack contains: \n";

  linkedDoubleStack.pop(doubleTop);
  cout << doubleTop;

  while (!linkedDoubleStack.isEmptyStack())
  {
    linkedDoubleStack.pop(doubleTop);
    cout << ", " << doubleTop;
  }

  getchar();

  // PART E
  cout << "\n\n--\n"
    << "E|\n"
    << "--\n"
    << "Array String Queue:\n";

  // Implementing the queues
  stringQueue.initializeQueue();
  stringQueueCopy.initializeQueue();

  for (int i = 0; i < 6; i++)
  {
    cout << "Enter string " << i + 1 << ": ";
    getline(cin, myString);
    stringQueue.addQueue(myString);
    stringQueueCopy.addQueue(myString);
  }

  cout << "\n\nArray Double Queue:\n";

  doubleQueue.initializeQueue();
  doubleQueueCopy.initializeQueue();

  for (int i = 0; i < 8; i++)
  {
    cout << "Enter double " << i + 1 << ": ";
    cin >> myDouble;
    doubleQueue.addQueue(myDouble);
    doubleQueueCopy.addQueue(myDouble);
  }

  cin.ignore(1000, '\n');
  cout << "\nThe Array String Queue contains: \n";

  // Displaying the queues
  stringQueueCopy.deQueue(stringTop);
  cout << stringTop;

  while (!stringQueueCopy.isEmptyQueue())
  {
    stringQueueCopy.deQueue(stringTop);
    cout << ", " << stringTop;
  }

  cout << endl;

  cout << "\nThe Array Double Queue contains: \n";

  doubleQueueCopy.deQueue(doubleTop);
  cout << doubleTop;

  while (!doubleQueueCopy.isEmptyQueue())
  {
    doubleQueueCopy.deQueue(doubleTop);
    cout << ", " << doubleTop;
  }

  getchar();

  // PART F
  cout << "\n\n--\n"
    << "F|\n"
    << "--\n";

  // Removing elements from the queues
  for (int i = 0; i < 5; i++)
  {
    stringQueue.deQueue(myString);
    cout << "Removed " << myString << " from string queue" << endl;
  }

  cout << endl;

  for (int i = 0; i < 7; i++)
  {
    doubleQueue.deQueue(myDouble);
    cout << "Removed " << myDouble << " from double queue" << endl;
  }

  // Displaing the remaining elements in the queues
  cout << "\nAfter removing " << myString << ", the string queue contains: \n";

  stringQueue.deQueue(stringTop);
  cout << stringTop;

  while (!stringQueue.isEmptyQueue())
  {
    stringQueue.deQueue(stringTop);
    cout << ", " << stringTop;
  }

  cout << "\n\nAfter removing " << myDouble << ", the double queue contains: \n";

  doubleQueue.deQueue(doubleTop);
  cout << doubleTop;

  while (!doubleQueue.isEmptyQueue())
  {
    doubleQueue.deQueue(doubleTop);
    cout << ", " << doubleTop;
  }

  getchar();

  // PART G
  cout << "\n\n--\n"
    << "G|\n"
    << "--\n"
    << "String Deque:\n";

  // Implementing the deques

  for (int i = 0; i < 6; i++)
  {
    cout << "Enter string " << i + 1 << ": ";
    getline(cin, myString);
    stringDeque.insertBack(myString);
    stringDequeCopy.insertBack(myString);
  }

  cout << "\nDouble Deque:\n";

  for (int i = 0; i < 8; i++)
  {
    cout << "Enter double " << i + 1 << ": ";
    cin >> myDouble;
    doubleDeque.insertBack(myDouble);
    doubleDequeCopy.insertBack(myDouble);
  }

  cin.ignore(1000, '\n');
  cout << "\nThe String Deque contains: \n";

  // Displaying the deques
  stringDequeCopy.eraseFront(stringTop);
  cout << stringTop;

  while (!stringDequeCopy.isEmpty())
  {
    stringDequeCopy.eraseFront(stringTop);
    cout << ", " << stringTop;
  }

  cout << endl;

  cout << "\nThe Double Deque contains: \n";

  doubleDequeCopy.eraseFront(doubleTop);
  cout << doubleTop;

  while (!doubleDequeCopy.isEmpty())
  {
    doubleDequeCopy.eraseFront(doubleTop);
    cout << ", " << doubleTop;
  }

  getchar();

  // PART H
  cout << "\n\n--\n"
    << "H|\n"
    << "--\n";

  //Removing elements from the deques
  for (int i = 0; i < 2; i++)
  {
    stringDeque.eraseBack(myString);
    cout << "Removed " << myString << " from string deque" << endl;
  }

  cout << endl;

 for (int i = 0; i < 6; i++)
  {
   doubleDeque.eraseFront(myDouble);
    cout << "Removed " << myDouble << " from double deque" << endl;
  }

  //Displaing the remaining elements in the deque
  cout << "\nAfter removing " << myString << ", the string deque contains: \n";

  stringDeque.eraseFront(stringTop);
  cout << stringTop;

  while (!stringDeque.isEmpty())
  {
    stringDeque.eraseFront(stringTop);
    cout << ", " << stringTop;
  }

  cout << "\n\nAfter removing " << myDouble << ", the double deque contains: \n";

  doubleDeque.eraseFront(doubleTop);
  cout << doubleTop;

  while (!doubleDeque.isEmpty())
  {
    doubleDeque.eraseFront(doubleTop);
    cout << ", " << doubleTop;
  }

  getchar();

  ParenthesesMatch(ParenthesesArray, 19);


  return 0;
}

void ParenthesesMatch(char array[][19], int size)
{
  LinkedStack<char> testStack;
  char poppedVal;

  for (int row = 0; row < 7; row++)
  {
    for (int col = 0; col < size; col++)
    {
      if (array[row][col] == '(' ||
        array[row][col] == '{' ||
        array[row][col] == '[')
      {
        testStack.push(array[row][col]);
      }
      else if (array[row][col] == ')' ||
        array[row][col] == '}' ||
        array[row][col] == ']')
      {
        if (testStack.isEmptyStack())
        {
          cout << "\nExpression " << row  << " is incorrect\n";
        }

        testStack.pop(poppedVal);
        if (poppedVal != array[row][col])
        {
          cout << "\nExpression " << row << " is incorrect\n";
        }
      }

      if (testStack.isEmptyStack())
      {
        cout << "\nExpression " << row << " is correct!\n";
      }
      else
      {
        cout << "\nExpression " << row << " is incorrect\n";
      }
    }
  }
}