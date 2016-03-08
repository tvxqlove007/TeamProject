#pragma once
#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include "Book.h"

using namespace std;

#ifndef BOOK_DAO_H
#define BOOK_DAO_H

class BookDAO {
private:
	string filePath;
	// FIXME use map instead of array
	Book books[1024];
	int numBooks = 0;

	void initialize();
	void storeToFile();

public:
	BookDAO(string f);
	void close();
	
	//CREATE
	void insert(string isbn, string title, string author, string publisher, 
				int quantityOnHand, double wholesaleCost, double retailPrice);

	//READ
	Book * getBooks() { return books; };
	Book * getBooksByISBN(string keyword);
	Book * getBooksByTitle(string keyword);
	Book * getBooksByAuthor(string keyword);
	Book * getBooksByPublisher(string keyword);
	Book * getBooksByAge(double age);	///
	Book * getBooksByQuantity(int quantity);
	Book * getBooksByWholesaleCost(double wholesaleCost);
	Book * getBooksByRetailPrice(double price);

};

#endif 