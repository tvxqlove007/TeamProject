// Class InventorModule Declaration
#pragma once
#include "stdafx.h"
#include <string>

#include "Module.h"

using namespace std;

#ifndef INVENTORY_MODULE_H
#define INVENTORY_MODULE_H

class InventoryModule : public Module {

private:
	char datePurchase[11];
	static InventoryModule * inventoryModule;

	InventoryModule();

public:
	static InventoryModule * getInstance();

	void display();
	void displayLookUpMenu();
	void displayAdd();

	void showBooksByISBN();
	void showBooksByTitle();
	void showBooksByAuthor();
	void showBooksByPublisher();
	void showBooksByDate();
	void showBooksByQuantity();
	void showBooksByWholesale();
	void showBooksByRetailPrice();
};

#endif // INVENTORY_MODULE_H

