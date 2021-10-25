#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class LibraryBook {
public:
	LibraryBook (string Title, string Author, string ISBN);		//creating constructors and other functions
	LibraryBook ();
	void BookData(istream &in_file);
	void ISBNData(istream &in_file);
	void Output(ofstream &out_file);

	string getTitle();		//creating getters and setters
	string getAuthor();
	string getISBN();
	void checkOut();
	void checkIn();
	bool isCheckedOut();

private:
	string title, author, isbn;		//creating variables and vector to store book objects in
	bool checkedOutStatus;
	vector<LibraryBook> book_list;
};