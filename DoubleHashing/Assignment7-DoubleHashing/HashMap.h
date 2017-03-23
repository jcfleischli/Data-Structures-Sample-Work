/**********************************************************
* AUTHOR     : John Fleischli
* STUDENT ID : 1020047
* ASSIGNMENT#: 6
* CLASS      : CS1D
* SECTION    : MW: 3p - 6p
* DUE DATE   : 3/8/17
**********************************************************/
#ifndef DOUBLEHASHING_H_
#define DOUBLEHASHING_H_
#include "Header.h"

template <typename K, typename V>
class HashMap
{
public:
  HashMap(); //Constructor
  void insert(K key, V value); //Inserts a key and value into the data structure
  void remove(K key, V value); //Remove a key and value from the data structure
  void print(); //Prints all the keys and values from the data structure
  static const int sizeOfArray = 31; //Holds the size of the array
private:

  //Node to hold keys and cities
  struct Node
  {
    K num;
    V city;

    Node() {num = 0, city = V();}

    Node(K key, V value){num = key, city = value;}
  };
  Node hashAr[sizeOfArray];

  //Checks data structure to see if another node is at the key.
  int hashKey(K key, int i)
  {
    int hashkey;
    hashkey = ((key % sizeOfArray) + i * (17 - key % 17)) % sizeOfArray;

    // Uses recursion to check through every position
    if (hashAr[hashkey].city == V() || hashAr[hashkey].num == key)    
      return hashkey;   
    else    
      return hashKey(key, i + 1);    
  }
};

// Constructor
template <typename K, typename V>
HashMap<K, V>::HashMap()
{
  for (int i = 0; i < sizeOfArray; i++)
  {
    hashAr[i] = Node();
  }
}

//Inserts a key and value into the data structure
template <typename K, typename V>
void HashMap<K, V>::insert(K key, V value)
{
  hashAr[hashKey(key, 0)] = Node(key, value);
  cout << " " << value << " has been added.\n";
}

//Remove a key and value from the data structure
template <typename K, typename V>
void HashMap<K, V>::remove(K key, V value)
{
  hashAr[hashKey(key, 0)] = Node();
  cout << endl;
  if (value == "")
  {
    cout << " No value at location! Can not remove.\n\n";
  }
  else
  {
    cout << " " << value << " has been removed.\n\n";
  }
}

// Prints the keys and values of the entire data structure
template <typename K, typename V>
void HashMap<K, V>::print()
{
  cout << "\n Printing Entire List:\n\n";

  cout << "Cell  Key      Value\n";
  cout << "----  ----  -------------\n";

  for (int i = 0; i < sizeOfArray; i++)
  {
    cout << " ";
    if (i < 10)
      cout << 0;
    cout << i << "    ";
    if (hashAr[i].num == 0)
      cout << 0;
    cout << hashAr[i].num;
    
    if (hashAr[i].num < 100)
      cout << " ";

    if (hashAr[i].city == V())
      cout << "   EMPTY" << endl;
    else
      cout << "   " << hashAr[i].city << endl;
  }
  cout << endl << endl;
}
#endif 
