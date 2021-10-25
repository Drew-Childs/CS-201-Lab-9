#include <iostream>
#include "LibraryBook.h"
#include <fstream>
using namespace std;

int main() {
	ifstream book_file("books.txt");		//opening all files necessary
	ifstream isbn_file("isbns.txt");
	ofstream out_file("checkedout.txt");

	LibraryBook Library_of_Yeehaw;		//creating instance of LibraryBook to be able to call functions

	Library_of_Yeehaw.BookData(book_file);		//reading data from books.txt
	Library_of_Yeehaw.ISBNData(isbn_file);		//reading data from isbns.txt
	Library_of_Yeehaw.Output(out_file);			//outputing checked out books to checkedout.txt
	return 0;
}