//***************************************************************************
// File name:  driver.cpp
// Author:     Chadd Williams
// Date:       3/28/2017
// Class:      CS485
// Assignment: Constexpr Examples
// Purpose:    Demonstrate how and why to use constexpr
//***************************************************************************

#include "../include/ExampleClass.h"
#include "../include/ExampleClassWithoutMove.h"

#include <vector>

#include <iostream>
//#include "vld.h"

void test() ;
void test2();

ExampleClass copyBackExampleClass()
{
  ExampleClass cRetVal(1,2,3) ;

  return cRetVal;
}

ExampleClassWithoutMove copyBackExampleClassWithoutMove()
{
  ExampleClassWithoutMove cRetVal(1,2,3);

  return cRetVal;  
}

void callFunctions()
{
  ExampleClass cOriginalExampleClass(4,5,6);
  ExampleClassWithoutMove cOriginalExampleClassWOMove(4,5,6);

  std::cout << "\n\ncopyBackStart\n";

  std::cout << "cOriginalExampleClass = copyBackExampleClass();\n";

  cOriginalExampleClass = copyBackExampleClass();

  std::cout << "cOriginalExampleClassWOMove = copyBackExampleClassWithoutMove();\n";
  cOriginalExampleClassWOMove = copyBackExampleClassWithoutMove();

  std::cout << "\ncopyBackDone\n\n";

  // clang --version
  // Apple LLVM version 10.0.0 (clang-1000.10.44.4)
  // RESULTS WITHOUT COPY AND SWAP in cOriginalExampleClassWOMove
  // copyBackStart
  // cOriginalExampleClass = copyBackExampleClass();
  // ctor3
  // NEW!
  // mop=
  // cOriginalExampleClassWOMove = copyBackExampleClassWithoutMove();
  // ctor3
  // NEW!
  // op=
  // NEW!
  // copyBackDone

  // RESULTS WITH COPY AND SWAP in cOriginalExampleClassWOMove
  // copyBackStart
  // cOriginalExampleClass = copyBackExampleClass();
  // ctor3
  // NEW!
  // mop=
  // cOriginalExampleClassWOMove = copyBackExampleClassWithoutMove();
  // ctor3
  // NEW!
  // op=
  // copyBackDone


  // Visual Studio 2017
  // RESULTS WITHOUT COPY AND SWAP in cOriginalExampleClassWOMove
  // copyBackStart
  // cOriginalExampleClass = copyBackExampleClass();
  // ctor3
  // NEW!
  // mctor
  // mop=
  // cOriginalExampleClassWOMove = copyBackExampleClassWithoutMove();
  // ctor3
  // NEW!
  // cctor
  // NEW!
  // op=
  // NEW!
  // copyBackDone

  // RESULTS WITH COPY AND SWAP in cOriginalExampleClassWOMove
  // copyBackStart
  // cOriginalExampleClass = copyBackExampleClass();
  // ctor3
  // NEW!
  // mctor
  // mop=
  // cOriginalExampleClassWOMove = copyBackExampleClassWithoutMove();
  // ctor3
  // NEW!
  // cctor
  // NEW!
  // op=
  // copyBackDone
}
int main ()
{

  ExampleClass cExClass (1, 2, 3);
  ExampleClass cExClass2 (4, 5, 6);
  ExampleClass cExClass3 (7, 8, 9);

  ExampleClassWithoutMove cExClassWO (1, 2, 3);
  ExampleClassWithoutMove cExClassWO2 (4, 5, 6);
  ExampleClassWithoutMove cExClassWO3 (7, 8, 9);

  std::vector<ExampleClass> cVecExClass;
  std::vector<ExampleClassWithoutMove> cVecExClassWO;


  cExClass.printAll (std::cout);
  std::cout << std::endl;
  cExClass2.printAll (std::cout);
  std::cout << std::endl;

  cExClass = cExClass2;

  cExClass.printAll (std::cout);
  std::cout << std::endl;
  cExClass2.printAll (std::cout);
  std::cout << std::endl;

  
  cExClass.printAll (std::cout);
  std::cout << std::endl;
  cExClass3.printAll (std::cout);
  std::cout << std::endl;

  cExClass = std::move (cExClass3);

  cExClass.printAll (std::cout);
  std::cout << std::endl;
  cExClass3.printAll (std::cout);
  std::cout << std::endl;

  
  std::cout << "\n do not invoke move\n";

  cExClassWO = cExClassWO2 + cExClassWO3;

  cExClassWO.printAll (std::cout);
  std::cout << std::endl;
  cExClassWO2.printAll (std::cout);
  std::cout << std::endl;
  cExClassWO3.printAll (std::cout);
  std::cout << std::endl;
  std::cout << std::endl;
  //do not invoke move
  //  op +
  //  ctor2
  //  NEW!
  //  cctor
  //  NEW!
  //  op =
  //  NEW!
  //  X: 11 Y : 13 Z : 15
  //  X : 4 Y : 5 Z : 6
  //  X : 7 Y : 8 Z : 9



  std::cout << "invoke move\n";

  cExClass = cExClass2 + cExClass3;

  cExClass.printAll (std::cout);
  std::cout << std::endl;
  cExClass2.printAll (std::cout);
  std::cout << std::endl;
  cExClass3.printAll (std::cout);
  std::cout << std::endl;

  //invoke move
  //  op +
  //  ctor2
  //  NEW!
  //  mctor
  //  mop =
  //  X: 11 Y : 13 Z : 15
  //  X : 4 Y : 5 Z : 6
  //  X : 7 Y : 8 Z : 9

  std::cout << std::endl;
  std::cout << "\nVector emplace vs insert\n";

  std::cout << "Insert Without Move\n";
  cVecExClassWO.push_back (ExampleClassWithoutMove(1,2,3));

  std::cout << "Insert With Move\n";
  cVecExClass.push_back (ExampleClass(1, 2, 3));

  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "Emplace Without Move\n";
  cVecExClassWO.emplace_back (ExampleClassWithoutMove(4, 5, 6));
  std::cout << "\tNo explicit ctor call\n";
  cVecExClassWO.emplace_back (4, 5, 6);

  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "Emplace With Move\n";
  cVecExClass.emplace_back (ExampleClass(4, 5, 6));
  std::cout << "\tNo explicit ctor call\n";
  cVecExClass.emplace_back (4, 5, 6);

  std::cout << std::endl;
  std::cout << std::endl;

  callFunctions();

	std::cerr << " TEST\n";
	test();
	std::cerr<< "  TEST DONE\n";

	std::cerr << " TEST2\n";
	test2();
	std::cerr<< "  TEST2 DONE\n";

  return EXIT_SUCCESS;
}

void test() {
	ExampleClass cExClass (1, 2, 3);
  ExampleClass cExClass2 (4, 5, 6);

	std::cerr << "cExClass3\n";
	// call normal cctor
	// cExClass2 is an LVALUE
  ExampleClass cExClass3 (cExClass2);

	std::cerr << "cExClass4\n";
	// call move op=
	// the RHS of the = is a
	// Temporary object - RVALUE
  ExampleClass cExClass4 = cExClass2 + cExClass3 + cExClass2;
	std::cerr << "cExClass4 DONE\n";

	std::cerr << "cExClass4 mop=\n";
	// call move op=
	// the RHS of the = is a
	// Temporary object - RVALUE
	cExClass4 = cExClass2 + cExClass3;
	std::cerr << "cExClass4 mop= DONE\n";

	std::cerr << "cExClass4 op=\n";
	// call regular op=
	// the RHS of the = is an LVALUE
	cExClass4 = cExClass2;
	std::cerr << "cExClass4 op= DONE\n";

}

void test2() {
	ExampleClass cExClass (1, 2, 3);
  ExampleClass cExClass2 (4, 5, 6);

	std::cerr << "cExClass3\n";
	// call normal cctor
	// cExClass2 is an LVALUE
  ExampleClass cExClass3 (cExClass2);

	std::cerr << "cExClass3 mop=\n";
	// call move op=
	// the RHS of the = is a
	// Temporary object - RVALUE
	cExClass3 = cExClass + cExClass2;
	std::cerr << "cExClass3 mop= DONE\n";

	std::cerr << "cExClass3 op=\n";
	// call regular op=
	// the RHS of the = is an LVALUE
	cExClass3 = cExClass2;
	std::cerr << "cExClass3 op= DONE\n";
}