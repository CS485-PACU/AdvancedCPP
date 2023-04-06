#include "DataReader.h"

DataReader::DataReader(const std::string &rcName)
{
  mSource.open(rcName);
}

DataReader::~DataReader()
{
  mSource.close();
}


