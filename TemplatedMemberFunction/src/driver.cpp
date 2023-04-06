//***************************************************************************
// File name:   main.cpp
// Author:      
// Date:        
// Class:       
// Assignment:  
// Purpose:     
//***************************************************************************

#include <iostream>
#include <vector> 
#include <string>
#include <sstream>
#include "DataReader.h"

//***************************************************************************
// Function:    main
//
// Description: Print hi!
//
// Parameters:  none
//
// Returned:    EXIT_SUCCESS
//***************************************************************************
int main()
{
  DataReader cReader("data/values.txt");

  int intValue;
  float floatValue;
  std::string strValue;

  cReader.readData(intValue);
  std::cout << intValue << " " ;
  cReader.readData(strValue);
  std::cout << strValue << " " ;

  cReader.readData(floatValue);
  std::cout << floatValue << " " ;

  if (cReader.readData(intValue))
  {
    std::cout << intValue;
  }

  std::cout << std::endl;

}
