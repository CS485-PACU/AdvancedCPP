//***************************************************************************
// File name:  driver.cpp
// Author:     Chadd Williams
// Date:       3/18/2017
// Class:      CS485
// Assignment: Visitor Pattern Example
// Purpose:    Demonstrate how the Visitor Pattern is implemented
//***************************************************************************
#include "../include/Worker.h"
#include "../include/Manager.h"
#include "../include/PrintVisitor.h"
#include "../include/GiveBonusVisitor.h"
#include <iostream>
#include "../include/SimpleContainer.h"
#include "../include/SalarySumVisitor.h"

// for demonstration of function call writeup
void bar(int value) {
	std::cout << value << ": Visitor!\n";
}

void foo(int value) {
	bar(value);
}

void foo(int left, int right) {
	bar(left + right);
}
// END for demonstration of function call writeup

//***************************************************************************
// Function:    main
//
// Description: Add Employees to a container and use visitors to display and
//              update those employees
//
// Parameters:  None
//
// Returned:    EXIT_SUCCESS
//***************************************************************************

int main ()
{

  SimpleContainer cTheContainer;
  PrintVisitor cPrintVisitor(std::cout);
  GiveBonusVisitor cGiveBonusVisitor;
  SalarySumVisitor cSalarySumVisitor;

  cTheContainer.addEmployee (new Worker ("Bob", "Bib", 1000000));
  cTheContainer.addEmployee (new Worker ("Sally", "Silly", 1500000));
  cTheContainer.addEmployee (new Manager ("Jim", "Jam", 2500000));
  cTheContainer.addEmployee (new Manager ("Mable", "Table", 3500000));

  std::cout << std::endl;
  
	// non-member, non-friend function
  applyVisitorNMNF (cTheContainer, &cPrintVisitor);
  std::cout << std::endl;
  std::cout << std::endl;

	// member function
  cTheContainer.applyVisitor (&cGiveBonusVisitor);
  std::cout << std::endl;
  std::cout << std::endl;

  cTheContainer.applyVisitor (&cPrintVisitor);
  std::cout << std::endl;
  std::cout << std::endl;

  cTheContainer.applyVisitor (&cSalarySumVisitor);
  cSalarySumVisitor.displaySums (std::cout);

  std::cout << std::endl;
  std::cout << std::endl;

	foo(480, 5);

	return EXIT_SUCCESS;
}
