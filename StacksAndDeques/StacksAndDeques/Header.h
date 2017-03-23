/**********************************************************
* AUTHOR     : John Fleischli
* STUDENT ID : 1020047
* LAB#       : 1
* CLASS      : CS 1D
* SECTION    : MW: 3p - 6p
* DUE DATE   : 02/06/17
**********************************************************/
#ifndef HEADER_H_
#define HEADER_H_

#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

// FUNCTIONS
/**************************************************************************
* PrintHeader
* ------------------------------------------------------------------------
* This function receives an user name, assignment name, type, and number
* then outputs the appropriate header. This function returns nothing.
*************************************************************************/
void PrintHeader(ostream &out,    	   //IN - stream to output too
  string name,  		     //IN - user name(s)
  string assignName,	   //IN - assignment Name
  string	assignNum)	   //IN - assignment number
{
  out << left;
  out << "**************************************************\n";
  out << "*  PROGRAMMED BY : " << name;
  out << "\n*  " << setw(14) << "CLASS" << ": CS1D";
  out << "\n*  " << setw(14) << "SECTION" << ": MW: 3p - 6p";
  out << "\n*  ";
  out << "ASSIGNMENT #" << setw(2);
  out << assignNum << ": " << assignName;
  out << "\n**************************************************\n\n";
  out << right;
}



#endif /* HEADER_H_ */
