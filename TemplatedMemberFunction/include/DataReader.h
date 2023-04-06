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

    std::ifstream mSource;
};

template<class T>
bool DataReader::readData(T &rcItem)
{
  bool retVal = false;

  if ( mSource >> rcItem)  
  {
    retVal = true;
  }
  return retVal;
 
}