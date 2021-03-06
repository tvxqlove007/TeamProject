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
	static const int DEFAULT;
	static const int INCREASING;
	static const int DECREASING;

	static int showChoices(int lowerBound, int upperBound);
	static string convertBookToString(int itemNumber, string isbn, string title, string author, 
		string publisher, time_t dateAdded,int quantity, double retailPrice);

	static string toString(time_t const &time);
	static time_t fromString(string str);

	static string toCsv(Book &b);
	static Book fromCsv(string line);

	static string toLowerCase(string givenString);
	static void displayBookInformation(Book book);

	static void swap(Book * a, Book * b);

	static void sortByAge(int left, int right, Book book[], int sortMode);
	static void sortByQuantity(int left, int right, Book book[], int sortMode);
	static void sortByWholesaleCost(int left, int right, Book book[], int sortMode);
	static void sortByRetailPrice(int left, int right, Book book[], int sortMode);
};

#endif // UTILS_H