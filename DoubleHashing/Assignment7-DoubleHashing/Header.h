/**********************************************************
* AUTHOR     : John Fleischli
* STUDENT ID : 1020047
* ASSIGNMENT#: 6
* CLASS      : CS1D
* SECTION    : MW: 3p - 6p
* DUE DATE   : 3/8/17
**********************************************************/
#ifndef HEADER_H_
#define HEADER_H_

#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <vector>
#include <list>
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
