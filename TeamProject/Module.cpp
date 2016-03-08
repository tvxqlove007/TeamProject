// Class Module Specification

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>

#include "Module.h"
#include "CashierModule.h"
#include "InventoryModule.h"
#include "ReportModule.h"

string Module::getName() {
	return name;
}

string Module::getDescription() {
	return description;
}

void Module::setName(string name) {
	this->name = name;
}

void Module::setDescription(string description) {
	this->description = description;
}

void Module::showMainMenu() {
	system("CLS");
	cout << "\t\t  Serendipity Booksellers" << endl;
	cout << "\t\t\t Main Menu" << endl << endl;
	cout << "\t\t 1. Cashier Module" << endl;
	cout << "\t\t 2. Inventory Database Module" << endl;
	cout << "\t\t 3. Report Module" << endl;
	cout << "\t\t 4. Exit" << endl << endl;

	int choice = 0;
	do {
		cout << "\t\t Enter Your Choice: ";
		cin >> choice;
		if (choice != 1 && choice != 2 && choice != 3 && choice != 4)
			cout << "\t\t Invalid Command. Please Enter Your Choice Again!!!" << endl << endl;
	} while (choice != 1 && choice != 2 && choice != 3 && choice != 4);

	switch (choice) {
	case 1:
		CashierModule::getInstance()->display();
		break;
	case 2:
		InventoryModule::getInstance()->display();
		break;
	case 3:
		ReportModule::getInstance()->display();
	case 4:
		cout << "Thank You For Using Serendipity Booksellers!" << endl << endl;
	}
}


