// Class CashierModule Specification

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdlib.h>

#include "Module.h"
#include "InventoryModule.h"
#include "Book.h"
#include "BookDAO.h"
#include "Utils.h"

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
		case 2:
			displayAdd();
			break;
		case 3:

			break;
		case 4:

			break;
		case 5:
			Module::showMainMenu();
	}
}

void InventoryModule::displayLookUpMenu() {
	system("CLS");
	cout << "\t\t  Serendipity Booksellers" << endl;
	cout << "\t\t    Look Up A Book" << endl << endl;
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
			showBooksByISBN();
			break;
		case 2:
			showBooksByTitle();
			break;
		case 3:
			showBooksByAuthor();
			break;
		case 4:
			showBooksByPublisher();
			break;
		case 5:
			showBooksByDate();
			break;
		case 6:
			showBooksByQuantity();
			break;
		case 7:
			showBooksByWholesale();
			break;
		case 8:
			showBooksByRetailPrice();
			displayLookUpMenu();
			break;
		case 9:
			display();
	}
}

void InventoryModule::displayAdd() {
	system("CLS");
	cout << "\t\t  Serendipity Booksellers" << endl;
	cout << "\t\t    Add A Book" << endl << endl;

	string isbn = "", title = "", author = "", publisher = "";
	int quantity = 0;
	double wholesaleCost = 0, retailPrice = 0;
	
	cin.ignore();
	do {
		cout << "\tEnter ISBN            \t";
		getline(cin, isbn);
		if (isbn.length() != 10 && isbn.length() != 13)
			cout << "Invalid ISBN! There Has To Be Exactly 10  or 13 Digits!" << endl;
	} while (isbn.length() != 10 && isbn.length() != 13);

	cout << "\tEnter Title           \t";
	getline(cin, title);
	cout << "\tEnter Author          \t";
	getline(cin, author);
	cout << "\tEnter Publisher       \t";
	getline(cin, publisher);
	cout << "\tEnter Quantity-On-Hand\t";
	cin >> quantity;
	cout << "\tEnter Wholesale Cost  \t";
	cin >> wholesaleCost;
	cout << "\tEnter Retail Price    \t";
	cin >> retailPrice;
	
	int choice = 0;
	do {
		cout << "\n\t\t Do You Want To Add This Book?" << endl;
		cout << "\t\t1. Yes, I Want To Add This Book" << endl;
		cout << "\t\t2. No, I Want To Go Back To Inventory Menu" << endl << endl;
		cout << "\t\t Enter Your Choice: ";
		cin >> choice;
		if (choice != 1 && choice != 2)
			cout << "\t\t Invalid Option! Please Enter Your Choice Again!!!" << endl << endl;	
	} while (choice != 1 && choice != 2);

	if (choice == 1) {
		BookDAO::getInstance()->insert(isbn, title, author,
			publisher, quantity, wholesaleCost, retailPrice);
		system("pause");
	}
	display();
}

void InventoryModule::showBooksByISBN() {
	system("CLS");
	cout << "\t\t  Serendipity Booksellers" << endl;
	cout << "\t\t    Look Up By ISBN" << endl << endl;
	cout << "\t\t     Enter ISBN: ";
	string keyword = "";
	cin.ignore();
	getline(cin, keyword);
	Book * possibleBooks = BookDAO::getInstance()->getBooksByISBN(keyword);

	int choice = 0;
	if (BookDAO::numPossibleBooks != 0) {
		for (int i = 0; i < BookDAO::numPossibleBooks; i++) {
			cout << i + 1 << endl;
			cout << "ISBN:\t" << possibleBooks[i].getIsbn() << endl;
			cout << "Title:\t" << possibleBooks[i].getTitle() << endl;
			cout << "Author:\t" << possibleBooks[i].getAuthor() << endl << endl;
		}
		do {
			cout << "\t\t Enter Your Choice: ";
			cin >> choice;
			if (choice < 1 || choice > BookDAO::numPossibleBooks)
				cout << "\t\t Invalid Option! Please Enter Again!" << endl << endl;
		} while (choice < 1 || choice > BookDAO::numPossibleBooks);
		system("CLS");
		cout << "\t\t  Serendipity Booksellers" << endl;
		cout << "\t\t      Book Information" << endl << endl;
		Utils::displayBookInformation(possibleBooks[choice - 1]);
		BookDAO::numPossibleBooks = 0;
	}
	else cout << "\t\t Sorry! Your ISBN Cannot Be Found!" << endl << endl;
	
	cout << "\t\t 1. Look Up Another Book" << endl;
	cout << "\t\t 2. Back To Look Up Menu" << endl << endl;
	do {
		cout << "\t\t Enter Your Choice: ";
		cin >> choice;
		if (choice != 1 && choice != 2)
			cout << "\t\t Invalid Option! Please Enter Again!" << endl << endl;
	} while (choice != 1 && choice != 2);
	switch (choice) {
	case 1:
		showBooksByISBN();
		break;
	case 2:
		displayLookUpMenu();
		break;
	}
}

void InventoryModule::showBooksByTitle() {
	system("CLS");
	cout << "\t\t  Serendipity Booksellers" << endl;
	cout << "\t\t    Look Up By Title" << endl << endl;
	cout << "\t\t     Enter Title: ";
	string keyword = "";
	cin.ignore();
	getline(cin, keyword);
	Book * possibleBooks = BookDAO::getInstance()->getBooksByTitle(keyword);

	int choice = 0;
	if (BookDAO::numPossibleBooks != 0) {
		for (int i = 0; i < BookDAO::numPossibleBooks; i++) {
			cout << i + 1 << endl;
			cout << "ISBN:\t" << possibleBooks[i].getIsbn() << endl;
			cout << "Title:\t" << possibleBooks[i].getTitle() << endl;
			cout << "Author:\t" << possibleBooks[i].getAuthor() << endl << endl;
		}
		do {
			cout << "\t\t Enter Your Choice: ";
			cin >> choice;
			if (choice < 1 || choice > BookDAO::numPossibleBooks)
				cout << "\t\t Invalid Option! Please Enter Again!" << endl << endl;
		} while (choice < 1 || choice > BookDAO::numPossibleBooks);
		system("CLS");
		cout << "\t\t  Serendipity Booksellers" << endl;
		cout << "\t\t      Book Information" << endl << endl;
		Utils::displayBookInformation(possibleBooks[choice - 1]);
		BookDAO::numPossibleBooks = 0;
	}
	else cout << "\t\t Sorry! Your Title Cannot Be Found!" << endl << endl;

	cout << "\t\t 1. Look Up Another Book" << endl;
	cout << "\t\t 2. Back To Look Up Menu" << endl << endl;
	do {
		cout << "\t\t Enter Your Choice: ";
		cin >> choice;
		if (choice != 1 && choice != 2)
			cout << "\t\t Invalid Option! Please Enter Again!" << endl << endl;
	} while (choice != 1 && choice != 2);
	switch (choice) {
	case 1:
		showBooksByTitle();
		break;
	case 2:
		displayLookUpMenu();
		break;
	}
}

void InventoryModule::showBooksByAuthor() {
	system("CLS");
	cout << "\t\t  Serendipity Booksellers" << endl;
	cout << "\t\t    Look Up By Author" << endl << endl;
	cout << "\t\t     Enter Author: ";
	string keyword = "";
	cin.ignore();
	getline(cin, keyword);
	Book * possibleBooks = BookDAO::getInstance()->getBooksByAuthor(keyword);

	int choice = 0;
	if (BookDAO::numPossibleBooks != 0) {
		for (int i = 0; i < BookDAO::numPossibleBooks; i++) {
			cout << i + 1 << endl;
			cout << "ISBN:\t" << possibleBooks[i].getIsbn() << endl;
			cout << "Title:\t" << possibleBooks[i].getTitle() << endl;
			cout << "Author:\t" << possibleBooks[i].getAuthor() << endl << endl;
		}
		do {
			cout << "\t\t Enter Your Choice: ";
			cin >> choice;
			if (choice < 1 || choice > BookDAO::numPossibleBooks)
				cout << "\t\t Invalid Option! Please Enter Again!" << endl << endl;
		} while (choice < 1 || choice > BookDAO::numPossibleBooks);
		system("CLS");
		cout << "\t\t  Serendipity Booksellers" << endl;
		cout << "\t\t      Book Information" << endl << endl;
		Utils::displayBookInformation(possibleBooks[choice - 1]);
		BookDAO::numPossibleBooks = 0;
	}
	else cout << "\t\t Sorry! Your Author Cannot Be Found!" << endl << endl;

	cout << "\t\t 1. Look Up Another Book" << endl;
	cout << "\t\t 2. Back To Look Up Menu" << endl << endl;
	do {
		cout << "\t\t Enter Your Choice: ";
		cin >> choice;
		if (choice != 1 && choice != 2)
			cout << "\t\t Invalid Option! Please Enter Again!" << endl << endl;
	} while (choice != 1 && choice != 2);
	switch (choice) {
	case 1:
		showBooksByAuthor();
		break;
	case 2:
		displayLookUpMenu();
		break;
	}
}

void InventoryModule::showBooksByPublisher() {
	system("CLS");
	cout << "\t\t  Serendipity Booksellers" << endl;
	cout << "\t\t    Look Up By Publisher" << endl << endl;
	cout << "\t\t     Enter Publisher: ";
	string keyword = "";
	cin.ignore();
	getline(cin, keyword);
	Book * possibleBooks = BookDAO::getInstance()->getBooksByPublisher(keyword);

	int choice = 0;
	if (BookDAO::numPossibleBooks != 0) {
		for (int i = 0; i < BookDAO::numPossibleBooks; i++) {
			cout << i + 1 << endl;
			cout << "ISBN:     \t" << possibleBooks[i].getIsbn() << endl;
			cout << "Title:    \t" << possibleBooks[i].getTitle() << endl;
			cout << "Author:   \t" << possibleBooks[i].getAuthor() << endl;
			cout << "Publisher:\t" << possibleBooks[i].getPublisher() << endl << endl;
		}
		do {
			cout << "\t\t Enter Your Choice: ";
			cin >> choice;
			if (choice < 1 || choice > BookDAO::numPossibleBooks)
				cout << "\t\t Invalid Option! Please Enter Again!" << endl << endl;
		} while (choice < 1 || choice > BookDAO::numPossibleBooks);
		system("CLS");
		cout << "\t\t  Serendipity Booksellers" << endl;
		cout << "\t\t      Book Information" << endl << endl;
		Utils::displayBookInformation(possibleBooks[choice - 1]);
		BookDAO::numPossibleBooks = 0;
	}
	else cout << "\t\t Sorry! Your Publisher Cannot Be Found!" << endl << endl;

	cout << "\t\t 1. Look Up Another Book" << endl;
	cout << "\t\t 2. Back To Look Up Menu" << endl << endl;
	do {
		cout << "\t\t Enter Your Choice: ";
		cin >> choice;
		if (choice != 1 && choice != 2)
			cout << "\t\t Invalid Option! Please Enter Again!" << endl << endl;
	} while (choice != 1 && choice != 2);
	switch (choice) {
	case 1:
		showBooksByPublisher();
		break;
	case 2:
		displayLookUpMenu();
		break;
	}
}

void InventoryModule::showBooksByDate() {
	
}

void InventoryModule::showBooksByQuantity() {
	system("CLS");
	cout << "\t\t  Serendipity Booksellers" << endl;
	cout << "\t\t    Look Up By Quantity" << endl << endl;
	cout << "\t\t     Enter Quantity: ";
	int quantity = 0;
	cin >> quantity;
	Book * possibleBooks = BookDAO::getInstance()->getBooksByQuantity(quantity);

	int choice = 0;
	if (BookDAO::numPossibleBooks != 0) {
		for (int i = 0; i < BookDAO::numPossibleBooks; i++) {
			cout << i + 1 << endl;
			cout << "ISBN:\t" << possibleBooks[i].getIsbn() << endl;
			cout << "Title:\t" << possibleBooks[i].getTitle() << endl;
			cout << "Author:\t" << possibleBooks[i].getAuthor() << endl;
		}
		do {
			cout << "\t\t Enter Your Choice: ";
			cin >> choice;
			if (choice < 1 || choice > BookDAO::numPossibleBooks)
				cout << "\t\t Invalid Option! Please Enter Again!" << endl << endl;
		} while (choice < 1 || choice > BookDAO::numPossibleBooks);
		system("CLS");
		cout << "\t\t  Serendipity Booksellers" << endl;
		cout << "\t\t      Book Information" << endl << endl;
		Utils::displayBookInformation(possibleBooks[choice - 1]);
		BookDAO::numPossibleBooks = 0;
	}
	else cout << "\t\t Sorry! Your Quantity Cannot Be Found!" << endl << endl;

	cout << "\t\t 1. Look Up Another Book" << endl;
	cout << "\t\t 2. Back To Look Up Menu" << endl << endl;
	do {
		cout << "\t\t Enter Your Choice: ";
		cin >> choice;
		if (choice != 1 && choice != 2)
			cout << "\t\t Invalid Option! Please Enter Again!" << endl << endl;
	} while (choice != 1 && choice != 2);
	switch (choice) {
	case 1:
		showBooksByQuantity();
		break;
	case 2:
		displayLookUpMenu();
		break;
	}
}

void InventoryModule::showBooksByWholesale() {
	system("CLS");
	cout << "\t\t  Serendipity Booksellers" << endl;
	cout << "\t\t    Look Up By Wholesale Cost" << endl << endl;
	cout << "\t\t   Enter Wholesale Cost: ";
	double wholesaleCost = 0;
	cin >> wholesaleCost;
	Book * possibleBooks = BookDAO::getInstance()->getBooksByWholesaleCost(wholesaleCost);

	int choice = 0;
	if (BookDAO::numPossibleBooks != 0) {
		for (int i = 0; i < BookDAO::numPossibleBooks; i++) {
			cout << i + 1 << endl;
			cout << "ISBN:\t" << possibleBooks[i].getIsbn() << endl;
			cout << "Title:\t" << possibleBooks[i].getTitle() << endl;
			cout << "Author:\t" << possibleBooks[i].getAuthor() << endl;
		}
		do {
			cout << "\t\t Enter Your Choice: ";
			cin >> choice;
			if (choice < 1 || choice > BookDAO::numPossibleBooks)
				cout << "\t\t Invalid Option! Please Enter Again!" << endl << endl;
		} while (choice < 1 || choice > BookDAO::numPossibleBooks);
		system("CLS");
		cout << "\t\t  Serendipity Booksellers" << endl;
		cout << "\t\t      Book Information" << endl << endl;
		Utils::displayBookInformation(possibleBooks[choice - 1]);
		BookDAO::numPossibleBooks = 0;
	}
	else cout << "\t\t Sorry! Your Wholesale Cost Cannot Be Found!" << endl << endl;

	cout << "\t\t 1. Look Up Another Book" << endl;
	cout << "\t\t 2. Back To Look Up Menu" << endl << endl;
	do {
		cout << "\t\t Enter Your Choice: ";
		cin >> choice;
		if (choice != 1 && choice != 2)
			cout << "\t\t Invalid Option! Please Enter Again!" << endl << endl;
	} while (choice != 1 && choice != 2);
	switch (choice) {
	case 1:
		showBooksByWholesale();
		break;
	case 2:
		displayLookUpMenu();
		break;
	}
}

void InventoryModule::showBooksByRetailPrice() {
	system("CLS");
	cout << "\t\t  Serendipity Booksellers" << endl;
	cout << "\t\t    Look Up By Retail Price" << endl << endl;
	cout << "\t\t   Enter Retail Price: ";
	double retailPrice = 0;
	cin >> retailPrice;
	Book * possibleBooks = BookDAO::getInstance()->getBooksByRetailPrice(retailPrice);

	int choice = 0;
	if (BookDAO::numPossibleBooks != 0) {
		for (int i = 0; i < BookDAO::numPossibleBooks; i++) {
			cout << i + 1 << endl;
			cout << "ISBN:\t" << possibleBooks[i].getIsbn() << endl;
			cout << "Title:\t" << possibleBooks[i].getTitle() << endl;
			cout << "Author:\t" << possibleBooks[i].getAuthor() << endl;
		}
		do {
			cout << "\t\t Enter Your Choice: ";
			cin >> choice;
			if (choice < 1 || choice > BookDAO::numPossibleBooks)
				cout << "\t\t Invalid Option! Please Enter Again!" << endl << endl;
		} while (choice < 1 || choice > BookDAO::numPossibleBooks);
		system("CLS");
		cout << "\t\t  Serendipity Booksellers" << endl;
		cout << "\t\t      Book Information" << endl << endl;
		Utils::displayBookInformation(possibleBooks[choice - 1]);
		BookDAO::numPossibleBooks = 0;
	}
	else cout << "\t\t Sorry! Your Retail Price Cannot Be Found!" << endl << endl;

	cout << "\t\t 1. Look Up Another Book" << endl;
	cout << "\t\t 2. Back To Look Up Menu" << endl << endl;
	do {
		cout << "\t\t Enter Your Choice: ";
		cin >> choice;
		if (choice != 1 && choice != 2)
			cout << "\t\t Invalid Option! Please Enter Again!" << endl << endl;
	} while (choice != 1 && choice != 2);
	switch (choice) {
	case 1:
		showBooksByRetailPrice();
		break;
	case 2:
		displayLookUpMenu();
		break;
	}
}