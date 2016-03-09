#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<time.h>
#include<sstream>
#include<string>
#include "Book.h"
#include "BookDAO.h"
#include "Utils.h"

using namespace std;

void BookDAO::initialize() {
	cout << "Reading file: " << filePath << endl;
	ifstream inputFile(filePath);
	string line;
	while (getline(inputFile, line)) {
		Book b = Utils::fromCsv(line);
		b.show();
		books[numBooks] = b;
		numBooks++;
	}
	cout << "Number of books read: " << numBooks << endl;
	inputFile.close();
}

void BookDAO::storeToFile() {
	ofstream outputFile(filePath);
	for (int i = 0; i < numBooks; i++)	{
		string csvRecord = Utils::toCsv(books[i]);
		outputFile << csvRecord << endl;
	}
	outputFile.close();
}

BookDAO::BookDAO(string f) {
	filePath = f;
	initialize();
}

void BookDAO::close() {
	storeToFile();
}
	
void BookDAO::insert(string isbn, string title, string author, string publisher, 
					 int quantityOnHand, double wholesaleCost, double retailPrice) {
		//  Validated  that no book exists by this isbn number.
	Book *existingBook = get_by_isbn(isbn);
		if (existingBook != nullptr){
			cout << "Book already exist by this isbn number." << endl;
			return;
		}
		
	time_t  dateAdded = time(NULL);
	Book b(isbn, title, author, publisher, dateAdded, quantityOnHand, wholesaleCost, retailPrice);
	cout << "Inserting ";
	b.show();
	books[numBooks] = b;
	numBooks++;
}

void BookDAO::void delete_by_isbn(string isbn)
	{
		int i = 0;
		for (i = 0; i < numBooks; i++)
		{
			if (books[i].getIsbn() == isbn)
			{
				break;
			}
		}
		if (i == numBooks)
		{
			cout << "Book doesn't exits" <<endl;
			return;
		}
		for (int j = i + 1; j < numBooks; j++)
		{
			books[j - 1] = books[j];
		}
		numBooks--;
	}
};

Book * BookDAO::getBooksByISBN(string keyword) {
	Book * possibleBooks = new Book[1024];
	int numberPossibleBooks = 0;

	for (int i = 0; i < numBooks; i++) {
		if (books[i].getIsbn().find(keyword) != std::string::npos)
			possibleBooks[numberPossibleBooks++] = books[i];
	}

	Utils::sortByISBN(0, numberPossibleBooks, possibleBooks);
	return possibleBooks;
}
Book * BookDAO::getBooksByTitle(string keyword) {
	Book * possibleBooks = new Book[1024];
	int numberPossibleBooks = 0;

	for (int i = 0; i < numBooks; i++) {
		if (books[i].getTitle().find(keyword) != std::string::npos)
			possibleBooks[numberPossibleBooks++] = books[i];
	}

	Utils::sortByTitle(0, numberPossibleBooks, possibleBooks);
	return possibleBooks;
}

Book * BookDAO::getBooksByAuthor(string keyword) {
	Book * possibleBooks = new Book[1024];
	int numberPossibleBooks = 0;

	for (int i = 0; i < numBooks; i++) {
		if (books[i].getAuthor().find(keyword) != std::string::npos)
			possibleBooks[numberPossibleBooks++] = books[i];
	}

	Utils::sortByAuthor(0, numberPossibleBooks, possibleBooks);
	return possibleBooks;
}

Book * BookDAO::getBooksByPublisher(string keyword) {
	Book * possibleBooks = new Book[1024];
	int numberPossibleBooks = 0;

	for (int i = 0; i < numBooks; i++) {
		if (books[i].getPublisher().find(keyword) != std::string::npos)
			possibleBooks[numberPossibleBooks++] = books[i];
	}

	Utils::sortByPublisher(0, numberPossibleBooks, possibleBooks);
	return possibleBooks;
}

Book * BookDAO::getBooksByAge(double age) {
	return NULL;
}

Book * BookDAO::getBooksByQuantity(int quantity) {
	Book * possibleBooks = new Book[1024];
	int numberPossibleBooks = 0;

	for (int i = 0; i < numBooks; i++) {
		if (books[i].getQuantityOnHand() == quantity)
			possibleBooks[numberPossibleBooks++] = books[i];
	}

	Utils::sortByQuantity(0, numberPossibleBooks, possibleBooks);
	return possibleBooks;
}

Book * BookDAO::getBooksByWholesaleCost(double wholesaleCost) {
	Book * possibleBooks = new Book[1024];
	int numberPossibleBooks = 0;

	for (int i = 0; i < numBooks; i++) {
		if (books[i].getWholesaleCost() == wholesaleCost)
			possibleBooks[numberPossibleBooks++] = books[i];
	}

	Utils::sortByWholesaleCost(0, numberPossibleBooks, possibleBooks);
	return possibleBooks;
}

Book * BookDAO::getBooksByRetailPrice(double price) {
	Book * possibleBooks = new Book[1024];
	int numberPossibleBooks = 0;

	for (int i = 0; i < numBooks; i++) {
		if (books[i].getRetailPrice() == price)
			possibleBooks[numberPossibleBooks++] = books[i];
	}

	Utils::sortByRetailPrice(0, numberPossibleBooks, possibleBooks);
	return possibleBooks;
}
