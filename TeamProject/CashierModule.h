// Class CashierModule Declaration
#pragma once
#include "stdafx.h"
#include<time.h>
#include <string>

#include "Module.h"

using namespace std;

#ifndef CASHIER_MODULE_H
#define CASHIER_MODULE_H

class CashierModule : public Module {

private:

	char datePurchase[11];
	static CashierModule * cashierModule;
	CashierModule();

public:

	char * getDatePurchase();
	static CashierModule * getInstance();

	void display();
};

#endif // CASHIER_MODULE_H
