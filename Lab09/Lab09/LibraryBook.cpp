#include <iostream>
#include "LibraryBook.h"
using namespace std;

string LibraryBook::getTitle() { return title; }			//Getters and setters for LibraryBook
string LibraryBook::getAuthor() { return author; }
string LibraryBook::getISBN() { return isbn; }
void LibraryBook::checkOut() { checkedOutStatus = true; }
void LibraryBook::checkIn() { checkedOutStatus = false; }
bool LibraryBook::isCheckedOut() { return checkedOutStatus; }

LibraryBook::LibraryBook(string Title, string Author, string ISBN) {		//default overloaded constructor
	title = Title;
	author = Author;
	isbn = ISBN;
	checkedOutStatus = false;
}
LibraryBook::LibraryBook() {		//default constructor
	isbn = "";
	title = "";
	author = "";
	checkedOutStatus = false;
}

void LibraryBook::BookData(istream &in_file) {		//reads information in from books.txt, creates object for each book, and stores object in vector
	string Title, Author, ISBN;

	while (in_file.good()) {
		getline(in_file, Title);
		getline(in_file, Author);
		getline(in_file, ISBN);
		LibraryBook currBook(Title, Author, ISBN);
		book_list.push_back(currBook);
	}
}

void LibraryBook::ISBNData(istream &in_file) {		//reads in data from isbns, checks if value matches an isbn in the library, and sets the checkedoutstatus accordingly
	string ISBN;

	while (in_file.good()) {
		in_file >> ISBN;
		for (unsigned i = 0; i < book_list.size(); i++) {
			if (book_list.at(i).isbn == ISBN) {
				if (book_list.at(i).isCheckedOut() == true) {
					book_list.at(i).checkIn();
				}
				else {
					book_list.at(i).checkOut();
				}
			}
		}
	}
}

void LibraryBook::Output(ofstream &out_file) {			//Outputs books that are checked out to checkedout.txt
	out_file << "Books checked out:\n\n------------------" << endl << endl << endl << endl;
	out_file << "Title\tAuthor\tISBN" << endl << endl;
	for (unsigned i = 0; i < book_list.size(); i++) {
		if (book_list.at(i).isCheckedOut() == true) {
			out_file << book_list.at(i).title << "\t" << book_list.at(i).author << "\t" << book_list.at(i).isbn << endl << endl;
		}
	}
}