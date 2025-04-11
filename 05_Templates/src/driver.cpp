//***************************************************************************
// File name:  driver.cpp
// Author:     Chadd Williams
// Date:       3/13/2017
// Class:      CS485
// Assignment: STL Example
// Purpose:    Demonstrate how to use STL and template programming
//***************************************************************************

#include <iostream>

//***************************************************************************
// Function:    sumThem 
//
// Description: Template function to sum two objects with + and 
//              return the result
//
// Parameters:  rLhs - the left object
//              rRhs - the right object
//              
// Returned:    the sum of rLhs and rRhs
//***************************************************************************
template<class T>
T sumThem (const T &rLhs, const T &rRhs)
{
  return rLhs + rRhs;
}


//***************************************************************************
// Function:    CompareThem 
//
// Description: Template function to compare using < two objects and
//              return the result
//
// Parameters:  rLhs - the left object
//              rRhs - the right object
//              
// Returned:    rLhs < rRhs
//***************************************************************************
template<class T>
bool CompareThem(const T &rLhs, const T &rRhs)
{
  return rLhs < rRhs;
}

//***************************************************************************
// Function:    main
//
// Description: Demonstrate template functions and invoke the functions 
//              that demonstrate STL containers
//
// Parameters:  None
//
// Returned:    EXIT_SUCCESS
//***************************************************************************
int main ()
{
  
  auto value = sumThem (1, 2);

  std::cout << value << std::endl;

  std::cout << sumThem (1, 2) << std::endl;
  std::cout << sumThem (1.1, 2.2) << std::endl;
  //std::cout << sumThem (1.1, 2) << std::endl; // type mismatch
  //std::cout << sumThem ('a', 1) << std::endl; // type mismatch
  //std::cout << sumThem ("test", "test") << std::endl; // const char * 
  std::cout << sumThem (std::string ("CS"), std::string ("485")) << std::endl;
  

	const int INT_ARRAY_SIZE = 8;
	const int STR_ARRAY_SIZE = 3;
	int aIntArray[INT_ARRAY_SIZE] = {0,1,2,3,4,5,6,7};
	std::string aStrArray[STR_ARRAY_SIZE] = {"CS1", "CS2", "CS3"};

	// printThem(aIntArray, INT_ARRAY_SIZE);
	// printThem(aStrArray, STR_ARRAY_SIZE);

  return EXIT_SUCCESS;
}