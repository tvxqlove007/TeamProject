// Class CashierModule Specification

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>

#include "Module.h"
#include "InventoryModule.h"

InventoryModule * InventoryModule::inventoryModule;

InventoryModule::InventoryModule() {
	setName("Inventory Database Module Module");
	setDescription("perform query on a file containing list of books");
}

InventoryModule * InventoryModule::getInstance() {
	if (inventoryModule == NULL) {
		inventoryModule = new InventoryModule();
	}
	return inventoryModule;
}

void InventoryModule::display() {
	system("CLS");
	cout << "\t\t  Serendipity Booksellers" << endl;
	cout << "\t\t     Inventory Database" << endl << endl;
	cout << "\t\t 1. Look Up a Book" << endl;
	cout << "\t\t 2. Add a Book" << endl;
	cout << "\t\t 3. Edit a Book's Record" << endl;
	cout << "\t\t 4. Delete a Book" << endl;
	cout << "\t\t 5. Return to the Main Menu" << endl << endl;

	int choice = 0;
	do {
		cout << "\t\t Enter Your Choice: ";
		cin >> choice;
		if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5)
			cout << "\t\t Invalid Command. Please Enter Your Choice Again!!!" << endl << endl;
	} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);

	switch (choice) {
		case 1:
			displayLookUpMenu();
			break;
		case 5:
			Module::showMainMenu();
	}
}

void InventoryModule::displayLookUpMenu() {
	system("CLS");
	cout << "\t\t  Serendipity Booksellers" << endl;
	cout << "\t\t    Look Up A Book" << endl;
	cout << "\t\t 1. Look Up By ISBN" << endl;
	cout << "\t\t 2. Look Up By Title" << endl;
	cout << "\t\t 3. Look Up By Author" << endl;
	cout << "\t\t 4. Look Up By Publisher" << endl;
	cout << "\t\t 5. Look Up By Age (Date Added)" << endl;
	cout << "\t\t 6. Look Up By Quantity On Hand" << endl;
	cout << "\t\t 7. Look Up By Wholesale Cost" << endl;
	cout << "\t\t 8. Look Up By Retail Price" << endl;
	cout << "\t\t 9. Return to the Inventory Module" << endl << endl;

	int choice = 0;
	do {
		cout << "\t\t Enter Your Choice: ";
		cin >> choice;
		if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 &&
			choice != 6 && choice != 7 && choice != 8 && choice != 9)
			cout << "\t\t Invalid Command. Please Enter Your Choice Again!!!" << endl << endl;
	} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 &&
			 choice != 6 && choice != 7 && choice != 8 && choice != 9);

	switch (choice) {
		case 1:
			
			break;
		case 2:
			
			break;
		case 3:

			break;
		case 4:
			
			break;
		case 5:

			break;
		case 6:
			
			break;
		case 7:

			break;
		case 8:
			
			break;
		case 9:
			display();
	}
}
