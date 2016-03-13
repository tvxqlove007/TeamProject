// Class CashierModule Specification

#include "stdafx.h"
#include<time.h>
#include <iostream>
#include <string>
#include <stdlib.h>

#include "Module.h"
#include "CashierModule.h"

using namespace std;

CashierModule * CashierModule::cashierModule;

CashierModule::CashierModule() {
	setName("Cashier Module");
	setDescription("act as a cash register");
	_strdate_s(datePurchase);
}

char * CashierModule::getDatePurchase() {
	return datePurchase;
}

CashierModule * CashierModule::getInstance() {
	if (cashierModule == NULL) {
		cashierModule = new CashierModule();
	}
	return cashierModule;
}

void CashierModule::display() {
	system("CLS");
	cout << "Serendipity Book Sellers" << endl << endl;
	cout << "Date: " << datePurchase << endl << endl;
	cout << " Qty\tISBN\t\tTitle\t\t\tPrice\t\tTotal" << endl;
	cout << "___________________________________________________________________________" << endl << endl;
	cout << "\t\t Subtotal:    " << endl;
	cout << "\t\t Tax:         " << endl;
	cout << "\t\t Total:       " << endl;
}
