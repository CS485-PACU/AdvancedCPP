//***************************************************************************
// File name:  ExampleClassWithoutMove.h
// Author:     Chadd Williams
// Date:       3/28/2017
// Class:      CS485
// Assignment: Constexpr Examples
// Purpose:    Demonstrate how to use constexpr with objects
//***************************************************************************
#pragma once
#include <iostream>


void runnew ();

class ExampleClassWithoutMove
{
public:

  ExampleClassWithoutMove (int x, int y) :mX (x), mY (y)
  {
    std::cout << "ctor2\n";
  };

  ExampleClassWithoutMove (int x, int y, int z) :mX (x), mY (y)
  {
    std::cout << "ctor3\n";
    pInt = new int;
    runnew ();
    *pInt = z;
    
  };

  ExampleClassWithoutMove (const ExampleClassWithoutMove &rcObj);
  
  ~ExampleClassWithoutMove () { std::cout << "dtor\n"; delete pInt; };

//  ExampleClassWithoutMove & operator=(const ExampleClassWithoutMove &rcObj);

  // CopyAndSwap
  ExampleClassWithoutMove & operator=(ExampleClassWithoutMove cObj);

  ExampleClassWithoutMove operator+(const ExampleClassWithoutMove &rcObj);

  void printAll (std::ostream &rcOut) const;

private:

  int mX, mY;

  int *pInt = nullptr;

};

