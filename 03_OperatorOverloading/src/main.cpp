//***************************************************************************
// File name:  main.cpp
// Author:     Chadd Williams
// Date:       2/3/2017
// Class:      CS485
// Assignment: Operator Overloading Examples
// Purpose:    Demonstrate operator overloading
//***************************************************************************


#include <iostream>
#include <memory>
#include "../include/Calculator.h"
#include <stdexcept>

//***************************************************************************
// Function: 		main
//
// Description: demonstrate smart pointers
//
// Parameters:  None
//
// Returned:    EXIT_SUCCESS
//***************************************************************************
int main () {
	Calculator* pcCalc;
	Calculator cCalc (485);
	cCalc.store ("Z");

	pcCalc = new Calculator (cCalc);
	*pcCalc = 100;
	std::cout << (*pcCalc)["Z"] << std::endl;

	cCalc = cCalc + 3;
	cCalc += 3.0;

	std::cout << cCalc () << std::endl;

	cCalc.clear ();

	cCalc = 100.0;
	cCalc.store ("X"); 	// 100
	cCalc += 10.1;
	cCalc += "X"; 			// X is 100
	cCalc = cCalc () + cCalc["X"];

	std::cout << "EXPECTING: 310.1 -> \n";
	std::cout << cCalc () << std::endl;

	cCalc += *pcCalc;
	std::cout << "EXPECTING: 410.1 -> \n";
	std::cout << cCalc () << std::endl;

	cCalc = cCalc + 42.0;
	cCalc = 0.42 + cCalc; // 0.42 gets implicitly converted
	// to a Calculator via the ctor(double)
	// otherwise, the code would need:
	// friend Calculator operator+(double, Calculator)
	std::cout << "EXPECTING: 452.52 -> \n";
	std::cout << cCalc () << std::endl;

	cCalc.clear ();
	cCalc = 1;

	cCalc = cCalc + 1.1 + cCalc + 1.1 + 4.0 + cCalc;

	std::cout << "EXPECTING: 9.2 -> \n";
	std::cout << cCalc () << std::endl;

	try {
		std::cout << "X = " << cCalc["X"];

	}
	catch (const std::exception& rcErr) {
		std::cerr << "Oh no! : " << rcErr.what () << std::endl;
	}

	cCalc = 1;
	try {
		cCalc += "Y";
		std::cout << cCalc () << std::endl;

	}
	catch (const std::exception& rcErr) {
		std::cerr << "Oh no! : " << rcErr.what () << std::endl;
	}

	delete pcCalc;
	pcCalc = nullptr;

	return EXIT_SUCCESS;
}