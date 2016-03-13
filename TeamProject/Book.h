#pragma once
#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <time.h>
#include "Book.h"

using namespace std;

/*
ISBN: This is the International Standard Book Number. It is a unique number assigned to each book by the publisher.
Title: The title of the book.
Author: The book’s author.
Publisher: The company that publishes the book.
Date Added: The date the book was added to the inventory.
Quantity-On-Hand: The number of copies of the book in inventory.
Wholesale Cost: The price paid by Serendipity for each copy of the book.
Retail Price: The price Serendipity is charging for each copy of the book.
*/
#ifndef BOOK_H
#define BOOK_H
class Book {
private:
	string isbn;
	string title;
	string author;
	string publisher;
	time_t dateAdded;
	int quantityOnHand;
	double wholesaleCost;
	double retailPrice;
public:
	Book();
	Book(string isbn, string title, string author, string publisher,time_t dateAdded,
			int quantity, double wholesaleCost, double retailPrice);
	
	void setIsbn(string i) { isbn = i;	}
	void setTitle(string t) { title = t; }
	void setAuthor(string a) { author = a; }
	void setPublisher(string p) { publisher = p; }
	void setDateAdded(time_t d) { dateAdded = d; }
	void setQuantityOnHand(int q) { quantityOnHand = q; }
	void setWholesaleCost(double w) { wholesaleCost = w; }
	void setRetailPrice(double r) { retailPrice = r; }
	string getIsbn() { return isbn; }
	string getTitle() { return title; }
	string getAuthor() { return author; 	}
	string getPublisher() {	return publisher; }
	time_t getDateAdded() { return dateAdded; }
	int getQuantityOnHand() { return quantityOnHand; }
	double getWholesaleCost() { return wholesaleCost; }
	double getRetailPrice() { return retailPrice; }
};

#endif