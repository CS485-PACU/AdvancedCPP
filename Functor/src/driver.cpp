//***************************************************************************
// File name:  driver.cpp
// Author:     Chadd Williams
// Date:       3/18/2019
// Class:      CS485
// Assignment: Functor Example
// Purpose:    Demonstrate how the a functor can be used
//***************************************************************************


#include "LogFunctor.h"
#include "StreamFunctor.h"
#include "IntFunctor.h"
#include "FilterFunctor.h"
#include "CountingLogFunctor.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

//***************************************************************************
// Function:    isPrefix
//
// Description: Determine if the second parameter is a prefix of the first
//
// Parameters:  msg - string to check
//              prefix - string to use for prefix
//
// Returned:    true if prefix is a prefix of msg, false otherwise
//***************************************************************************

bool isPrefix (std::string msg, std::string prefix) {
  return 0 == msg.find (prefix);
}

//***************************************************************************
// Function:    isSuffix
//
// Description: Determine if the second parameter is a suffix of the first
//
// Parameters:  msg - string to check
//              suffix - string to use for suffix
//
// Returned:    true if suffix is a suffix of msg, false otherwise
//***************************************************************************

bool isSuffix (std::string msg, std::string suffix) {
  return (msg.length() - suffix.length()) == msg.find (suffix);
}

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
  

  ////
  std::vector<std::string> cVecOfValues;
  
  StreamFunctor cScreenWriter (std::cout, cActualLog);

  for (int i = 0; i < 10; ++i)
  {
    cVecOfValues.push_back (std::to_string (i*i + i));
  }

  // for_each only knows about operator()
  std::for_each (cVecOfValues.begin (), cVecOfValues.end (), cScreenWriter);

  // change each entry in the vector using the functor
  std::transform (cVecOfValues.begin (), cVecOfValues.end (),
    cVecOfValues.begin (), cTestLog);

  // show actual values in the vector
  for (int i = 0; i < 10; ++i)
  {
    std::cout << "Vector values: "<< cVecOfValues[i] << std::endl;
  }


  ///
  IntFunctor cIntFunctor (100);

  // for_each only knows about operator()
  // COMPILE ERROR!
  //std::for_each (cVecOfValues.begin (), cVecOfValues.end (), cIntFunctor);


  FilterFunctor cFindPrefix ("Test", isPrefix);
  FilterFunctor cFindSuffix ("0", isSuffix);

  // show actual values in the vector
  for (int i = 0; i < 10; ++i)
  {
    if (cFindPrefix (cVecOfValues[i]))
    {
      std::cout << "PREFIX: Vector values: " << cVecOfValues[i] << std::endl;
    }
   }

  // show actual values in the vector
  for (int i = 0; i < 10; ++i)
  {
    if (cFindSuffix (cVecOfValues[i]))
    {
      std::cout << "SUFFIX: Vector values: " << cVecOfValues[i] << std::endl;
    }
  }

  int state = 0;

  auto lambdaWithState = [&state](auto &rStr) mutable
    {
      std::cout << "Lambda: " << state++ << " " << rStr << std::endl;
    };

  // simulate functor with lambda
  std::for_each (cVecOfValues.begin (), cVecOfValues.end (),
    lambdaWithState
  );

  // simulate functor with lambda
  std::for_each (cVecOfValues.begin (), cVecOfValues.end (),
    lambdaWithState
  );

  return EXIT_SUCCESS;
}