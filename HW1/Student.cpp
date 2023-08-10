#include "Student.h"
#include "Book.h"

Student::Student(string name, int studentId) {
    this->name = name;
    this->studentId = studentId;
    numOfBooks = 0;
    bookToStudent = new Book[10];
}

Student::Student(const Student &s) {
    name = s.name;
    studentId = s.studentId;
    numOfBooks = s.numOfBooks;
    bookToStudent = s.bookToStudent;
}

Student::~Student() {
}

Student::Student() {
    name = "";
    studentId = 0;
    numOfBooks = 0;
    bookToStudent = new Book[10];
}
