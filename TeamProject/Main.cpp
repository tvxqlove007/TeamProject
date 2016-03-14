#include "stdafx.h"
#include <iostream>

#include "Module.h"
#include "BookDAO.h"

using namespace std;

int main()
{
	// To initialize the DAO object at start up
	BookDAO::getInstance();
	Module::showMainMenu();
	return 0;
}
