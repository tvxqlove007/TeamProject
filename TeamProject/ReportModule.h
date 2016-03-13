// Class ReportModule Declaration
#pragma once
#include "stdafx.h"
#include<time.h>
#include <string>

#include "Module.h"
#include "Book.h"

using namespace std;

#ifndef REPORT_MODULE_H
#define REPORT_MODULE_H

class ReportModule : public Module {

private:
	static ReportModule * reportModule;
	ReportModule();

public:
	static ReportModule * getInstance();

	void display();

	void displayInventoryListing();
	void displayInventoryWholesaleValue();
	void displayInventoryRetailValue();
	void displayListingByQuantity();
	void displayListingByCost();
	void displayListingByAge();

	template<class Type> void printOut(Type value);
	template<> void printOut(string value);
	void printBook(Book book);

};

#endif // REPORT_MODULE_H
