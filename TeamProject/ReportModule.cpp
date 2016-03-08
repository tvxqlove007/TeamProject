// Class CashierModule Specification

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>

#include "Module.h"
#include "ReportModule.h"

ReportModule * ReportModule::reportModule;

ReportModule::ReportModule() {
	setName("Report Module");
	setDescription("analyze information in inventory database module");
}

ReportModule * ReportModule::getInstance() {
	if (reportModule == NULL) {
		reportModule = new ReportModule();
	}
	return reportModule;
}

void ReportModule::display() {
	system("CLS");
	cout << "\t\t  Serendipity Booksellers" << endl;
	cout << "\t\t\t Reports" << endl << endl;
	cout << "\t\t 1. Inventory Listing" << endl;
	cout << "\t\t 2. Inventory Wholesale Value" << endl;
	cout << "\t\t 3. Inventory Retail Value" << endl;
	cout << "\t\t 4. Inventory by Quantity" << endl;
	cout << "\t\t 5. Inventory by Cost" << endl;
	cout << "\t\t 6. Inventory by Age" << endl;
	cout << "\t\t 7. Return to Main Menu" << endl << endl;

	int choice = 0;
	do {
		cout << "\t\t Enter Your Choice: ";
		cin >> choice;
		if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7)
			cout << "\t\t Invalid Command. Please Enter Your Choice Again!!!" << endl << endl;
	} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7);

	switch (choice) {

	case 7:
		Module::showMainMenu();
	}
}
