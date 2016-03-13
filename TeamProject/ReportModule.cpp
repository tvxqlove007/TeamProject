// Class CashierModule Specification

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>

#include "Module.h"
#include "ReportModule.h"
#include "Book.h"
#include "BookDAO.h"
#include "Utils.h"

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

template<class Type> void ReportModule::printOut(Type value) {
	cout << left << setw(10) << setfill(' ') << value;
}

template<> void ReportModule::printOut(string value) {
	cout << left << setw(10) << setfill(' ') << value;
}

void ReportModule::printBook(Book book) {
	printOut(book.getIsbn());
	printOut(book.getTitle());
	printOut(book.getAuthor());
	printOut(book.getPublisher());
	printOut(Utils::toString(book.getDateAdded()));
	printOut(book.getQuantityOnHand());
	printOut(book.getWholesaleCost());
	printOut(book.getRetailPrice());
	cout << endl;
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
	case 1:
		displayInventoryListing();
		break;
	case 2:
		displayInventoryWholesaleValue();
		break;
	case 3:
		displayInventoryRetailValue();
		break;
	case 4:
		displayListingByQuantity();
		break;
	case 5:
		displayListingByCost();
		break;
	case 6:
		displayListingByAge();
		break;
	case 7:
		Module::showMainMenu();
	}
}

void ReportModule::displayInventoryListing() {
	system("CLS");
	Book * books = BookDAO::getInstance()->getBooks();
	printOut("ISBN");
	printOut("Title");
	printOut("Author");
	printOut("Publisher");
	printOut("Date Added");
	printOut("Quantity On Hand");
	printOut("Wholesale Cost");
	printOut("Retail Price");
	cout << endl;
	for (int i = 0; i < BookDAO::getInstance()->getNumBooks(); i++)
		printBook(books[i]);
}

void ReportModule::displayInventoryWholesaleValue() {

}

void ReportModule::displayInventoryRetailValue() {

}

void ReportModule::displayListingByQuantity() {

}

void ReportModule::displayListingByCost() {

}

void ReportModule::displayListingByAge() {

}
