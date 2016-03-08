// Class Utils Declaration
#pragma once
#include "stdafx.h"
#include <string>
#include "Book.h"

using namespace std;

#ifndef UTILS_H
#define UTILS_H

class Utils {

public:
	
	static string toCsv(Book &b);
	static Book fromCsv(string line);
	static void swap(Book * a, Book * b);
	static void sortByISBN(int left, int right, Book book[]);
	static void sortByTitle(int left, int right, Book book[]);
	static void sortByAuthor(int left, int right, Book book[]);
	static void sortByPublisher(int left, int right, Book book[]);
	static void sortByAge(int left, int right, Book book[]);	///
	static void sortByQuantity(int left, int right, Book book[]);
	static void sortByWholesaleCost(int left, int right, Book book[]);
	static void sortByRetailPrice(int left, int right, Book book[]);
};

#endif // UTILS_H

