//***************************************************************************
// File name:  driver.cpp
// Author:     Chadd Williams
// Date:       3/18/2019
// Class:      CS485
// Assignment: Functor Example
// Purpose:    Demonstrate how the a functor can be used
//***************************************************************************


#include "../include/LogFunctor.h"
#include "../include/IntFunctor.h"
#include "../include/CountingLogFunctor.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

//***************************************************************************
// Function:    doWork
//
// Description: Do work and log work to appropriate location
//
// Parameters:  rcLog - log to use
//
// Returned:    none
//***************************************************************************

void doWork (LogFunctor &rcLog) {

  for (int i = 0; i < 10; ++i)
  {
    std::cout << rcLog (std::to_string (i*i));
    std::cout << std::endl;
  }
}

//***************************************************************************
// Function:    doWorkTemplate
//
// Description: Do work and log work to appropriate location
//
// Parameters:  rcLog - log to use
//
// Returned:    none
//***************************************************************************
template<class T>
void doWorkTemplate (T &rcLog) {

  for (int i = 0; i < 10; ++i)
  {
    std::cout << rcLog (std::to_string (i*i));
    std::cout << std::endl;
  }
}

//***************************************************************************
// Function:    doCountingWork
//
// Description: Do work and log work to appropriate location
//
// Parameters:  rcLog - log to use
//
// Returned:    none
//***************************************************************************

void doCountingWork (CountingLogFunctor &rcLog) {

  for (int i = 0; i < 10; ++i)
  {
    std::cout << rcLog (std::to_string (i*i));
    std::cout << std::endl;
  }
}

//***************************************************************************
// Function:    main
//
// Description: Demonstrate functors
//
// Parameters:  None
//
// Returned:    EXIT_SUCCESS
//***************************************************************************

int main () {

  LogFunctor cTestLog ("Testing");
  LogFunctor cActualLog ("Actual");

  CountingLogFunctor cCountingLog ("Count");
  
  doWork (cTestLog);
  doWork (cActualLog);


  doCountingWork (cCountingLog);
  doCountingWork (cCountingLog);

  doWorkTemplate(cTestLog);
  doWorkTemplate(cCountingLog);
  
	std::vector<std::string> cVecOfValues = {"CS", "PACU", "AUCOIN"};

	// change each entry in the vector using the functor
	std::transform (cVecOfValues.begin (), cVecOfValues.end (),
  	cVecOfValues.begin (), cTestLog);
	
	for (std::string cValue : cVecOfValues) {
		std::cout << " >> " <<  cValue << std::endl;
	}

  return EXIT_SUCCESS;
}