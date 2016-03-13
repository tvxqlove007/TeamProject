// Class Utils Declaration
#pragma once
#include "stdafx.h"
#include <string>
#include<time.h>
#include "Book.h"

using namespace std;

#ifndef UTILS_H
#define UTILS_H

class Utils {

public:
	static string toString(time_t const &time);
	static time_t fromString(string str);
	
	static string toCsv(Book &b);
	static Book fromCsv(string line);

	static string toLowerCase(string givenString);
	static void displayBookInformation(Book book);
};

#endif // UTILS_H
