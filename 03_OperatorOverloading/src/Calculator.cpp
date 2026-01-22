//***************************************************************************
// File name:   Calculator.cpp
// Author:      chadd williams
// Date:        1/27/25
// Class:       CS 485
// Assignment:  Unit test example
// Purpose:     Provide a class to unit test
//***************************************************************************

#include "../include/Calculator.h"
#include <stdexcept>

//***************************************************************************
// Constructor:  Calculator
//
// Description: Create object
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
Calculator::Calculator () {

}

//***************************************************************************
// Constructor: Calculator
//
// Description: Create object
//
// Parameters:  value - the value to store in the Calculator
//
// Returned:    None
//***************************************************************************
Calculator::Calculator (double value) {
	mpRunningTotal = new double;
	*mpRunningTotal = value;
}

//***************************************************************************
// Constructor: Calculator
//
// Description: Copy Constructor
//
// Parameters:  rcOther - the object to copy
//
// Returned:    None
//***************************************************************************
Calculator::Calculator (const Calculator& rcOther) {
	if (nullptr != rcOther.mpRunningTotal) {
		mpRunningTotal = new double;
		*mpRunningTotal = *rcOther.mpRunningTotal;
	}
	mcVars = rcOther.mcVars;
}

//***************************************************************************
// Constructor: operator=
//
// Description: Assignment operator
//
// Parameters:  value - the value to assign to the running total
//
// Returned:    None
//***************************************************************************
Calculator& Calculator::operator= (double value) {
	if (nullptr == mpRunningTotal) {
		mpRunningTotal = new double;
	}
	*mpRunningTotal = value;
	return *this;
}

//***************************************************************************
// Constructor: operator=
//
// Description: Copy Assignment operator (copy and swap)
//
// Parameters:  cOther - the object to copy
//
// Returned:    None
//***************************************************************************
Calculator& Calculator::operator= (Calculator cOther) {
	// copy and swap
	std::swap (mpRunningTotal, cOther.mpRunningTotal);
	std::swap (mcVars, cOther.mcVars);
	return *this;
}


//***************************************************************************
// Destructor:  Calculator
//
// Description: Destroy object & dynamic memory
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
Calculator::~Calculator () {
	if (nullptr != mpRunningTotal) {
		delete mpRunningTotal;
	}
}

//***************************************************************************
// Function:    operator+=
//
// Description: Add one double to the running total
//
// Parameters:  rhs - the right operand
//							
// Throws:			Throws exception if no running total exists
//
// Returned:    The new running total
//***************************************************************************
Calculator& Calculator::operator+= (double rhs) {
	if (nullptr == mpRunningTotal) {
		throw std::invalid_argument ("No running total");
	}
	*mpRunningTotal += rhs;
	return *this;
}

//***************************************************************************
// Function:    operator+=
//
// Description: Add one double from a variable to the running total
//
// Parameters:  rcKey - the variable to add
//							
// Throws:			Throws exception if no running total 
//							Throws exception if the variable does not exist
//
// Returned:    The new running total
//***************************************************************************
Calculator& Calculator::operator+= (const std::string& rcKey) {
	*this += (*this)[rcKey];
	return *this;
}

//***************************************************************************
// Function:    operator+=
//
// Description: Add the running total from another Calculator
//
// Parameters:  rcRHS - the other Calculator
//							
// Throws:			Throws exception if either Calculator has no running total 
//
// Returned:    The new running total
//***************************************************************************
Calculator& Calculator::operator+= (const Calculator& rcRHS) {
	if (nullptr == rcRHS.mpRunningTotal) {
		throw std::invalid_argument ("No running total in RHS");
	}
	*this += *rcRHS.mpRunningTotal;
	return *this;
}

//***************************************************************************
// Function:    operator+
//
// Description: Add the running totals of two Calculators
//
// Parameters:  cLHS - the left operand, Calculator
// 							rsRHS - the right operand, Calculator
//							
// Throws:			Throws exception if no running total exists
//
// Returned:    updated Calculator
//***************************************************************************
Calculator operator+ (Calculator cLHS, const Calculator& rcRHS) {
	cLHS += rcRHS;
	return cLHS;
}

//***************************************************************************
// Function:    operator+
//
// Description: Add a running total and a double
//
// Parameters:  cLHS - the left operand, Calculator
// 							rhs - a double
//							
// Throws:			Throws exception if no running total exists
//
// Returned:    updated Calculator
//***************************************************************************
Calculator operator+ (Calculator cLHS, double rhs) {
	cLHS += rhs;
	return cLHS;
}

//***************************************************************************
// Function:    getTotal
//
// Description: Return the current running total
//
// Parameters:  None
//							
// Throws:			Throws exception if no running total exists
//
// Returned:    The current running total
//***************************************************************************
double Calculator::operator() () const {
	if (nullptr == mpRunningTotal) {
		throw std::invalid_argument ("No running total");
	}

	return *mpRunningTotal;
}

//***************************************************************************
// Function:    clear
//
// Description: Destroy the current running total
//
// Parameters:  None
//							
// Throws:			None
//
// Returned:    None
//***************************************************************************
void Calculator::clear () {
	if (nullptr != mpRunningTotal) {
		delete mpRunningTotal;
		mpRunningTotal = nullptr;
	}
	mcVars.clear ();
}

//***************************************************************************
// Function:    operator[]
//
// Description: Return value of the variable specified as a parameter
//
// Parameters:  rcKey - the name of the variable to find
//							
// Throws:			Throws exception if variable does not exist
//
// Returned:    The current value of the variable
//***************************************************************************
const double& Calculator::operator[] (const std::string& rcKey) const {
	if (!mcVars.contains (rcKey)) {
		throw std::range_error ("Variable " + rcKey + " not found!");
	}

	return mcVars.at (rcKey);
}

//***************************************************************************
// Function:    store
//
// Description: Store the current running total as a variable
//
// Parameters:  rcKey - the name of the variable to set
//							
// Throws:			Throws exception if the running total does not exist
//
// Returned:    The current running total
//***************************************************************************
double Calculator::store (const std::string& rcKey) {
	mcVars[rcKey] = (*this)();
	return mcVars[rcKey];
}
