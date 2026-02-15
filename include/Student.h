#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
    private:
        int id;
        string name;
        float gpa;

    public:
        Student(int id, string name, float gpa);

        int getId() const;
        string getName() const;
        float getGpa() const;

        void display() const;


};

#endif