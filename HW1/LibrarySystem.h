#include "string"
#include "iostream"
#include "Student.h"
#include "Book.h"
using namespace std;
class LibrarySystem
{
public:
    int bookId;
    string title;
    string name;
    string authors;
    int year;
    int studentId;
    Book* bookArr;
    Student* studentArr;
    int bookSize;
    int studentSize;


    LibrarySystem();
    ~ LibrarySystem ();

    void addBook( int bookId,  string title,  string authors,  int year);
    void deleteBook( int bookId);
    void addBooktoStudent(int BookId, int StudentId);
    void addStudent( int StudentId,  string name);
    void deleteStudent( int StudentId);

    void checkoutBook( int BookId,  int StudentId);
    void returnBook( int BookId);

    void showAllBooks();
    void showBook( int BookId);
    void showStudent( int StudentId);

};