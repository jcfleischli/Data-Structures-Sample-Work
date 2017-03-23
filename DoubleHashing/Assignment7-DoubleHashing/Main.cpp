/**********************************************************
* AUTHOR     : John Fleischli
* STUDENT ID : 1020047
* ASSIGNMENT#: 6
* CLASS      : CS1D
* SECTION    : MW: 3p - 6p
* DUE DATE   : 3/8/17
**********************************************************/
#include "HashMap.h"

/********************************************************************************
* Double Hashing:
* -------------------------------------------------------------------------------
* This program will create a map that holds integer keys and string values.
* Nodes containing keys and values will be inserted and removed throughout
* the runtime. The program will use a double hashing algorithm to place the
* nodes into the correct cell. If the cell is already taken the 2nd hash 
* function will be used. If a matching key is passed in with a different value,
* the cell in which that key is located will have its value overwritten.
* When all the keys and values have been stored, the map will print in an 
* organized table by column.
*******************************************************************************/
int main()
{
  PrintHeader(cout, "John Fleischli", "Double Hashing", "7");

  cout << "Double Hashing:\n";
  cout << "------------------------------------------------------------------------------\n"
    << "| This program will create a map that holds integer keys and string values.\n"
    << "| Nodes containing keys and values will be inserted and removed throughout\n"
    << "| the runtime. The program will use a double hashing algorithm to place the\n"
    << "| nodes into the correct cell. If the cell is already taken the 2nd hash\n"
    << "| function will be used. If a matching key is passed in with a different value,\n"
    << "| the cell in which that key is located will have its value overwritten.\n"
    << "| When all the keys and values have been stored, the map will print in an \n"
    << "| organized table by column.\n"
    << "-------------------------------------------------------------------------------\n\n";

  cout << "*******************************************\n"
    << "NOTE: The data structure used was an Array.\n"
    << "*******************************************\n\n";

  // Initialize map with key of type int and value of type string
  HashMap<int, string> myMap;
  cout << " Map has been Initialized\n\n";

  // Inserting values
  myMap.insert(18, "Laguna Niguel");
  myMap.insert(41, "Mission Viejo");
  myMap.insert(22, "San Clemente");
  myMap.insert(44, "Irvine");

  // Removing value
  myMap.remove(41, "Mission Viejo");

  // Inserting values
  myMap.insert(58, "Lake Forest");
  myMap.insert(32, "San Diego");
  myMap.insert(49, "Anahiem");

  // Removing Value
  myMap.remove(58, "Lake Forest");
  
  // Inserting values
  myMap.insert(31, "Los Angeles");
  myMap.insert(17, "Orange");
  myMap.insert(72, "Palms Springs");
  myMap.insert(41, "Riverside"); 

  // Removing Value
  myMap.remove(73, "");	
  
  //Inserting values
  myMap.insert(19, "Brea");
  myMap.insert(60, "Santa Ana");
  myMap.insert(35, "Tustin");
  myMap.insert(103, "Oceanside");
  myMap.insert(11, "La Jolla");
  myMap.insert(18, "Del Mar");
  myMap.insert(22, "Aliso Viejo");
  myMap.insert(49, "Laguna Beach");

  // Removing value
  myMap.remove(41, "Riverside");
  
  // Inserting values
  myMap.insert(42, "Vista");
  myMap.insert(49, "San Diego");
  myMap.insert(99, "San Juan");
  myMap.insert(29, "Dana Point");
  myMap.insert(88, "El Segundo");
  myMap.insert(41, "San Clemente");
  myMap.insert(62, "Laguna Hills");

  // Print the entire map
  myMap.print();

  getchar();
  return 0;
}
