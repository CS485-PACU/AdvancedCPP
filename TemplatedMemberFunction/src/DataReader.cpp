#include "DataReader.h"

DataReader::DataReader(const std::string &rcName)
{
  mcSource.open(rcName);
}

DataReader::~DataReader()
{
  mcSource.close();
}


