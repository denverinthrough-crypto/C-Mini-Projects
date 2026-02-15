#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

// Student class declaration
class Student {
private:
    int id;         // Student ID
    string name;    // Student Name
    float gpa;      // Student GPA

public:
    // Constructor
    Student(int id, string name, float gpa);

    // Getter functions
    int getId() const;
    string getName() const;
    float getGpa() const;

    // Display student details
    void display() const;
};

#endif
