//***************************************************************************
// File name:  Employee.h
// Author:     Chadd Williams
// Date:       3/18/2017
// Class:      CS485
// Assignment: Visitor Pattern Example
// Purpose:    Demonstrate how the Visitor Pattern is implemented
//***************************************************************************
#pragma once
#include "Employee.h"

class SimpleContainer {

	public:
		SimpleContainer ();

		virtual ~SimpleContainer ();

		SimpleContainer (const SimpleContainer&) = delete;
		SimpleContainer& operator=(const SimpleContainer&) = delete;

		virtual void addEmployee (Employee* pcAcct);

		virtual bool isFull () const;

		virtual std::size_t count () const;

		virtual Employee*& operator[](std::size_t index);
		virtual Employee* const& operator[](std::size_t index) const;

		void applyVisitor (IEmployeeVisitor* pcVisitor);

	private:
		static const int MAX_PPL = 100;
		Employee* mcEmployees[MAX_PPL];
		int mCurrentEmployees = 0;

};

// convenience function!
void applyVisitorNMNF (SimpleContainer& rcCon, IEmployeeVisitor* pcVisitor);