#include "LibrarySystem.h"
#include "Student.h"
#include "Book.h"

LibrarySystem::LibrarySystem(){
    title = "";
    name = "";
    authors = "";
    year = 0;
    studentId = 0;
    bookId = 0;
    bookSize =0;
    studentSize = 0;
    bookArr = new Book[bookSize];
    studentArr = new Student[studentSize];
};

void LibrarySystem::addBook(const int bookId, const string title, const string authors, const int year) {
    Book* tempB = new Book[bookSize+1];

    for (int i = 0; i < bookSize; ++i) {
        if(bookArr[i].bookId == bookId){
            cout<< "Book " << bookId << " is already in the list!" << endl;
            return;
        }
    }
    for (int i = 0; i < bookSize; ++i) {
        tempB[i] = bookArr[i];
    }
    tempB[bookSize].authors = authors;
    tempB[bookSize].bookId = bookId;
    tempB[bookSize].title = title;
    tempB[bookSize].year = year;

    cout << "Book " << bookId << " is added." << endl;
    bookSize++;
    delete[] bookArr;
    bookArr = tempB;
}

void LibrarySystem::deleteBook(const int bookId) {
    Book* tempB = new Book[bookSize - 1];
    bool check = false;
    int index = 0;
    for (int i = 0; i < bookSize; i++) {
        if (bookArr[i].bookId == bookId) {
            index = i;
            check = true;
            break;
        }
    }
    if (check) {
        for (int i = 0; i < bookSize; i++) {
            if (i < index) {
                tempB[i] = bookArr[i];
            } else if (i > index) {
                tempB[i - 1] = bookArr[i];
            }
        }
        cout << "Book " << bookId << " has been deleted" << endl;
        bookSize--;
        delete[] bookArr;
        bookArr = tempB;
    }
    else{
        cout << "Book " << bookId << " does not exist" << endl;
    }
}

void LibrarySystem::addStudent(const int StudentId, const string name) {
    Student* tempS = new Student[studentSize+1];

    for (int i = 0; i < studentSize; ++i) {
        if(studentArr[i].studentId == StudentId){
            cout<< "Student " << StudentId << " is already in the list!" << endl;
            return;
        }
    }
    for (int i = 0; i < studentSize; ++i) {
        tempS[i] = studentArr[i];
    }
    tempS[studentSize].name = name;
    tempS[studentSize].studentId = StudentId;
    tempS[studentSize].numOfBooks = 0;

    cout << "Student " << StudentId << " is added." << endl;
    studentSize++;
    delete[] studentArr;
    studentArr = tempS;
}

void LibrarySystem::deleteStudent(const int StudentId) {
    Student* tempS = new Student[studentSize - 1];
    bool check = false;
    int index = 0;
    for (int i = 0; i < studentSize; i++) {
        if (studentArr[i].studentId == StudentId) {
            index = i;
            check = true;
            break;
        }
    }
    if (check) {
        for (int i = 0; i < studentSize; i++) {
            if (i < index) {
                tempS[i] = studentArr[i];
            } else if (i > index) {
                tempS[i - 1] = studentArr[i];
            }
        }
        cout << "Student " << StudentId << " has been deleted" << endl;
        studentSize--;
        delete[] studentArr;
        studentArr = tempS;
    }
    else{
        cout << "Student " << StudentId << " does not exist" << endl;
    }
}

void LibrarySystem::checkoutBook(const int BookId, const int StudentId) {
    Book tempBook;
    bool checkFlag = false;
    for (int i = 0; i < bookSize; ++i) {
        if(bookArr[i].bookId == BookId){
            bookArr[i].checkedOut = "Checked Out";
            tempBook.title = bookArr[i].title;
            tempBook.authors = bookArr[i].authors;
            tempBook.bookId = bookArr[i].bookId;
            tempBook.year = bookArr[i].year;
            tempBook.checkedOut = bookArr[i].checkedOut;
            checkFlag = true;
        }
    }
    Student tempStudent;
    bool cFlag = false;
    for (int i = 0; i < studentSize; ++i) {
        if(studentArr[i].studentId == StudentId){
            Student debug = studentArr[i];
            studentArr[i].bookToStudent[studentArr[i].numOfBooks] = tempBook;
            studentArr[i].numOfBooks++;
            cFlag = true;
        }
    }

    if(checkFlag && cFlag){
        cout << "Book " << BookId << " has been checked out by student " << StudentId << endl;
    }
    else if (!checkFlag){
        cout << "Book " << BookId << " does not exist for checkout " << endl;
    }
    else{
        cout << "Student " << StudentId << " does not exist for checkout" << endl;
    }
}

void LibrarySystem::returnBook(const int BookId) {
    for (int i = 0; i < studentSize; i++) {
        for (int j = 0; j < studentArr[i].numOfBooks; j++) {
            Book debug = studentArr[i].bookToStudent[j];
            if (studentArr[i].bookToStudent[j].bookId == BookId) {
                Book debug2 = studentArr[i].bookToStudent[j];
                studentArr[i].bookToStudent[j] = Book();
            }
        }
    }
    cout << "Book " << BookId << " has been returned." << endl;
}

void LibrarySystem::showAllBooks() {
    for (int i = 0; i < bookSize; ++i) {
        string tempTitle = bookArr[i].title;
        int tempId = bookArr[i].bookId;
        string tempAuthors = bookArr[i].authors;
        int tempYear = bookArr[i].year;
        cout << tempId << "\t" << tempTitle << "\t" << tempAuthors << "\t" << tempYear << "\t" << bookArr[i].checkedOut <<endl;
    }
}

void LibrarySystem::showBook(int BookId) {
    Book tempBook;
    bool checkFlag = false;
    for (int i = 0; i < bookSize; ++i) {
        if(bookArr[i].bookId == BookId){
            tempBook = bookArr[i];
            checkFlag = true;
        }
    }
    if(!checkFlag){
        cout << "No such book is present!" << endl;
    }
    else{
        string tempTitle = tempBook.title;
        int tempId = tempBook.bookId;
        string tempAuthors = tempBook.authors;
        int tempYear = tempBook.year;
        cout << tempId << "\t" << tempTitle << "\t" << tempAuthors << "\t" << tempYear << tempBook.checkedOut << "\t"  <<endl;
    }
}//bool

void LibrarySystem::showStudent(int StudentId) {
    Student tempStudent;
    bool cFlag = false;

    for (int i = 0; i < studentSize; ++i) {
        if(studentArr[i].studentId == StudentId){
            tempStudent = studentArr[i];
            cFlag = true;
        }
    }
    if(!cFlag){
        cout << "No such student exists!" << endl;
    }
    else{
        string tempName = tempStudent.name;
        int tempId = tempStudent.studentId;
        cout<< tempName << "\t" << tempId << endl;
    }
    if(tempStudent.numOfBooks > 0){
        for (int i = 0; i < tempStudent.numOfBooks ; ++i) {
            Book tempBook;
            tempStudent.bookToStudent[i] = tempBook;
            string tempTitle = tempBook.title;
            int tempId = tempBook.bookId;
            string tempAuthors = tempBook.authors;
            int tempYear = tempBook.year;
            cout << tempId << "\t" << tempTitle << "\t" << tempAuthors << "\t" << tempYear << "\t" << tempBook.checkedOut <<endl;
        }
    }
}

LibrarySystem::~LibrarySystem() {
    delete[] bookArr;
    delete[] studentArr;
}




