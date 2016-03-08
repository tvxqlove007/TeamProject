#include "stdafx.h"
#include <string>
#include <iostream>
#include "Book.h"
#include "Utils.h"

using namespace std;

// Converts book object into csv (comma separated value) entry
string Utils::toCsv(Book &b) {
	time_t dateAdded = b.getDateAdded();
	string dateStr = toString(dateAdded);
	return b.getIsbn() + "," + 
		   b.getTitle() + "," + 
		   b.getAuthor() + "," + 
		   b.getPublisher() + "," + 
		   dateStr + "," +
		   to_string(b.getQuantityOnHand()) + "," + 
		   to_string(b.getWholesaleCost()) + "," + to_string(b.getRetailPrice());
}

// Parse csv (comma separated value) entry into Book object
Book Utils::fromCsv(string line) {
	istringstream tokens(line);

	// isbn
	string isbn = "";
	getline(tokens, isbn, ',');

	// title
	string title = "";
	getline(tokens, title, ',');

	// author
	string author = "";
	getline(tokens, author, ',');

	// publisher
	string publisher = "";
	getline(tokens, publisher, ',');

	// dateAdded
	string dateStr = "";
	getline(tokens, dateStr, ',');
	time_t dateAdded = fromString(dateStr);

	// quantityOnHand
	string quantityOnHandStr = "";
	getline(tokens, quantityOnHandStr, ',');
	int quantityOnHand = stoi(quantityOnHandStr);

	// wholesaleCost
	string wholesaleCostStr = "";
	getline(tokens, wholesaleCostStr, ',');
	double wholesaleCost = stod(wholesaleCostStr);

	// retailPrice
	string retailPriceStr = "";
	getline(tokens, retailPriceStr, ',');
	double retailPrice = stod(retailPriceStr);

	return Book (isbn, title, author, publisher, dateAdded, quantityOnHand, wholesaleCost, retailPrice);
} 

void Utils::swap(Book  * a, Book * b) {
	Book c = *a;
	*a = *b;
	*b = c;
}

void Utils::sortByISBN(int left, int right, Book book[]) {
	if (left <= right) {
		int x = left;
		int y = right;
		int median = x + (y - x) / 2;
		do {
			while (book[x].getIsbn() < book[median].getIsbn())
				x++;
			while (book[y].getIsbn() > book[median].getIsbn())
				y--;
			if (x <= y) {
				if (x < y) swap(&book[x], &book[y]);
				x++; y--;
			}
		} while (x <= y);
		Utils::sortByISBN(left, y, book);
		Utils::sortByISBN(x, right, book);
	}
}

void Utils::sortByTitle(int left, int right, Book book[]) {
	if (left <= right) {
		int x = left;
		int y = right;
		int median = x + (y - x) / 2;
		do {
			while (book[x].getTitle() < book[median].getTitle())
				x++;
			while (book[y].getTitle() > book[median].getTitle())
				y--;
			if (x <= y) {
				if (x < y) swap(&book[x], &book[y]);
				x++; y--;
			}
		} while (x <= y);
		Utils::sortByTitle(left, y, book);
		Utils::sortByTitle(x, right, book);
	}
}

void Utils::sortByAuthor(int left, int right, Book book[]) {
	if (left <= right) {
		int x = left;
		int y = right;
		int median = x + (y - x) / 2;
		do {
			while (book[x].getAuthor() < book[median].getAuthor())
				x++;
			while (book[y].getAuthor() > book[median].getAuthor())
				y--;
			if (x <= y) {
				if (x < y) swap(&book[x], &book[y]);
				x++; y--;
			}
		} while (x <= y);
		Utils::sortByAuthor(left, y, book);
		Utils::sortByAuthor(x, right, book);
	}
}

void Utils::sortByPublisher(int left, int right, Book book[]) {
	if (left <= right) {
		int x = left;
		int y = right;
		int median = x + (y - x) / 2;
		do {
			while (book[x].getPublisher() < book[median].getPublisher())
				x++;
			while (book[y].getPublisher() > book[median].getPublisher())
				y--;
			if (x <= y) {
				if (x < y) swap(&book[x], &book[y]);
				x++; y--;
			}
		} while (x <= y);
		Utils::sortByPublisher(left, y, book);
		Utils::sortByPublisher(x, right, book);
	}
}

void Utils::sortByQuantity(int left, int right, Book book[]) {
	if (left <= right) {
		int x = left;
		int y = right;
		int median = x + (y - x) / 2;
		do {
			while (book[x].getQuantityOnHand() < book[median].getQuantityOnHand())
				x++;
			while (book[y].getQuantityOnHand() > book[median].getQuantityOnHand())
				y--;
			if (x <= y) {
				if (x < y) swap(&book[x], &book[y]);
				x++; y--;
			}
		} while (x <= y);
		Utils::sortByQuantity(left, y, book);
		Utils::sortByQuantity(x, right, book);
	}
}

void Utils::sortByWholesaleCost(int left, int right, Book book[]) {
	if (left <= right) {
		int x = left;
		int y = right;
		int median = x + (y - x) / 2;
		do {
			while (book[x].getWholesaleCost() < book[median].getWholesaleCost())
				x++;
			while (book[y].getWholesaleCost() > book[median].getWholesaleCost())
				y--;
			if (x <= y) {
				if (x < y) swap(&book[x], &book[y]);
				x++; y--;
			}
		} while (x <= y);
		Utils::sortByWholesaleCost(left, y, book);
		Utils::sortByWholesaleCost(x, right, book);
	}
}

void Utils::sortByRetailPrice(int left, int right, Book book[]) {
	if (left <= right) {
		int x = left;
		int y = right;
		int median = x + (y - x) / 2;
		do {
			while (book[x].getRetailPrice() < book[median].getRetailPrice())
				x++;
			while (book[y].getRetailPrice() > book[median].getRetailPrice())
				y--;
			if (x <= y) {
				if (x < y) swap(&book[x], &book[y]);
				x++; y--;
			}
		} while (x <= y);
		Utils::sortByRetailPrice(left, y, book);
		Utils::sortByRetailPrice(x, right, book);
	}
}


