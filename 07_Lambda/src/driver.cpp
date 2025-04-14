//***************************************************************************
// File name:  driver.cpp
// Author:     Chadd Williams
// Date:       3/28/2017
// Class:      CS485
// Assignment: Lambda Examples
// Purpose:    Demonstrate how to use lambda, focus on variable capture 
//***************************************************************************

#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <typeinfo>

//***************************************************************************
// Function:    takeOperator
//
// Description: Takes a function as a parameter and invokes that function
//              the return value of the passed in function is returned
//
// Parameters:  func - function with prototype int(int,int)
//
// Returned:    the return value of func(1,100)
//***************************************************************************
int takeOperator (std::function<int (int, int)> func)
{
  return func (1, 100);
}

//***************************************************************************
// Function:    createOperator - CONTAINS ERROR
//
// Description: Creates and returns a new lambda
//
// Parameters:  value - the value used in the lambda!
//
// Returned:    function with prototype int(int)
//***************************************************************************
std::function<int (int)> createOperator (int value)
{
  auto func = [&value] (int param) -> int
  {
		std::cout << "\nfunc: " << param  << " + " << value << std::endl;
    return param + value; 
		// ERROR! value will be popped off stack!
  };
  return func;
}

//***************************************************************************
// Function:    main
//
// Description: Create and invoke various lambda functions for demonstration
// 
// Parameters:  None
//
// Returned:    EXIT_SUCCESS
//***************************************************************************
int main ()
{
  std::vector<int> cLocalVector;

  auto cList = { 1,2,3,4,5 };

	std::for_each (cList.begin (), cList.end (),
    [](auto cItem) {
		std::cout << cItem << ", ";
	 }
  );

  // capture the cLocalVector by reference
  std::for_each(cList.begin(), cList.end(),
    [&](auto cItem)
  {
    cLocalVector.push_back (cItem);
  });

  // print the vector
  // no capture necessary
  std::for_each (cLocalVector.begin (), cLocalVector.end (),
    [](auto cItem)
  {
    std::cout << cItem << std::endl;
  });


  // store a function into a variable
  auto func = 
  [](int param1, int param2) -> int
  { 
    return param1 + param2;
  };

  // invoke the function
  std::cout << func (1, 2) << std::endl;

  /// explicitly type the variable as an std::function
  std::function<int(int,int)> add =
    [](int param1, int param2) -> int
  {
    return param1 + param2;
  };

  // invoke the function
  std::cout << add (1, 2) << std::endl;

  // create an array of functions
  std::function<int (int, int)> aMathOps[2] =
  {
    [] (int param1, int param2) -> int
    {
      return param1 + param2;
    },
    [](int param1, int param2) -> int
    {
      return param1 - param2;
    }
  };

  std::cout << std::endl;

  // invoke each function in the array
  std::cout << "aMathOps[0] " << aMathOps[0] (1, 2) << std::endl;
  std::cout << "aMathOps[1] " << aMathOps[1] (1, 2) << std::endl;

  // pass the function to a function
  std::cout << std::endl;
  std::cout << "aMathOps[0] " << takeOperator (aMathOps[0]) << std::endl;
  
  return EXIT_SUCCESS;
}
