#ifndef HW1_STUDENT_H
#define HW1_STUDENT_H
#include "iostream"
#include "string"
#include "Book.h"
using namespace std;

class Student {
public:
    string name;
    int studentId;
    int numOfBooks;
    Book* bookToStudent;
    Student();
    Student(string name, int studentId);
    Student(const Student& s);
    ~Student();
};
#endif //HW1_STUDENT_H
