/***************************************************************************
File name:  tiger.h
Author:     chadd
Date:       April 27, 2017
Class:      CS 485
Purpose:		Demonstrate VS's C++ name mangling and virtual function table

cl.exe /c /d1reportSingleClassLayoutcat cat.cpp > cat_single.out

cl.exe /c /d1reportSingleClassLayoutanimal animal.cpp > animal_single.out

***************************************************************************/


#pragma once

#include "cat.h"

class tiger : public cat
{
public:
  tiger (int w);
  virtual ~tiger() {};

  virtual int getWeight2 ();
  virtual void hi ();

  int nonVirtualFunction ();

  int getStripes () { return mStripes; }

private:
  int mStripes;
};


