#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>
#include<time.h>
#include "Book.h"
#include "Utils.h"

using namespace std;

// Converts time_t into string of format YY-MM-DD HH:MM:SS
string Utils::toString(time_t const &time) {
	tm * timeinfo = localtime(&time);
	int year = timeinfo->tm_year + 1900;
	int month = timeinfo->tm_mon + 1;
	int day = timeinfo->tm_mday;
	int hour = timeinfo->tm_hour;
	int min = timeinfo->tm_min;
	int sec = timeinfo->tm_sec;

	string dateStr = to_string(year) + "-" + to_string(month) + "-" + to_string(day);
	string timeStr = to_string(hour) + ":" + to_string(min) + ":" + to_string(sec);

	return dateStr + " " + timeStr;
}

// Parse string of format YY-MM-DD HH:MM:SS into time_t
time_t Utils::fromString(string str) {
	// separate date and time
	istringstream dateTimeStream(str);
	string date;
	getline(dateTimeStream, date, ' ');
	string time;
	getline(dateTimeStream, time, ' ');

	// parse date
	istringstream dateStream(date);
	string yearStr;
	getline(dateStream, yearStr, '-');
	int year = stoi(yearStr);
	string monthStr;
	getline(dateStream, monthStr, '-');
	int month = stoi(monthStr);
	string dayStr;
	getline(dateStream, dayStr, '-');
	int day = stoi(dayStr);

	// parse time
	istringstream timeStream(time);
	string hourStr;
	getline(timeStream, hourStr, ':');
	int hour = stoi(hourStr);
	string minStr;
	getline(timeStream, minStr, ':');
	int min = stoi(minStr);
	string secStr;
	getline(timeStream, secStr, ':');
	int sec = stoi(secStr);

	struct tm timeinfo = { 0 };

	timeinfo.tm_year = year - 1900;
	timeinfo.tm_mon = month - 1;
	timeinfo.tm_mday = day;
	timeinfo.tm_hour = hour;
	timeinfo.tm_min = min;
	timeinfo.tm_sec = sec;

	return mktime(&timeinfo);
}

// Converts book object into csv (comma separated value) entry
string Utils::toCsv(Book &b) {
	time_t dateAdded = b.getDateAdded();
	string dateStr = Utils::toString(dateAdded);
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

	return Book(isbn, title, author, publisher, dateAdded, quantityOnHand, wholesaleCost, retailPrice);
}

string Utils::toLowerCase(string givenString) {
	for (int i = 0; i < givenString.length(); i++)
		if (givenString[i] >= 'A' && givenString[i] <= 'Z')
			givenString[i] = givenString[i] + 32;
	return givenString;
}

void Utils::displayBookInformation(Book book) {
	cout << "\tISBN            \t" << book.getIsbn() << endl;
	cout << "\tTitle           \t" << book.getTitle() << endl;
	cout << "\tAuthor          \t" << book.getAuthor() << endl;
	cout << "\tPublisher       \t" << book.getPublisher() << endl;
	cout << "\tDate Added      \t" << toString(book.getDateAdded()) << endl;
	cout << "\tQuantity-On-Hand\t" << book.getQuantityOnHand() << endl;
	cout << "\tWholesale Cost  \t" << book.getWholesaleCost() << endl;
	cout << "\tRetail Price    \t" << book.getRetailPrice() << endl << endl;
}



