#include "Book.h"
Book::Book(const int bookId, const string title, const string authors, const int year) {
    this-> title = title;
    this-> bookId = bookId;
    this-> authors = authors;
    this-> year = year;
    this-> checkedOut = "Not Checked Out";
}

Book::Book(const Book &b) {
    title = b.title;
    bookId = b.bookId;
    authors = b.authors;
    year = b.year;
    checkedOut = b.checkedOut;
}

Book::Book() {
    title = "";
    bookId = 0;
    authors = "";
    year = 0;
    checkedOut = "Not Checked Out";
}

