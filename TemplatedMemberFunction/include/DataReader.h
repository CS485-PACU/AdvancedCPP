#pragma once

#include <iostream>
#include <fstream>
#include <string>


class DataReader
{

  public:

    DataReader(const std::string &);

    ~DataReader();

    template<class T>
    bool readData(T&);

  private:

    std::ifstream mcSource;
};

template<class T>
bool DataReader::readData(T &rcItem)
{
  bool retVal = false;

  if ( mcSource >> rcItem)  
  {
    retVal = true;
  }
  return retVal;
 
}