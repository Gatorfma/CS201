#ifndef HW1_BOOK_H
#define HW1_BOOK_H
#include "iostream"
#include "string"
using namespace std;

class Book {
public:
    string title;
    string authors;
    int bookId;
    int year;
    string checkedOut;

    Book();
    Book( int bookId,  string title,  string authors,  int year);
    Book(const Book& b);
};


#endif //HW1_BOOK_H
