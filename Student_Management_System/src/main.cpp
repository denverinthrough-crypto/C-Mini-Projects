#include <iostream>
#include <vector>
#include "../include/Student.h"

using namespace std;

//////////////////////
// Student class methods
//////////////////////

// Constructor
Student::Student(int id, string name, float gpa) {
    this->id = id;
    this->name = name;
    this->gpa = gpa;
}

// Getters
int Student::getId() const { return id; }
string Student::getName() const { return name; }
float Student::getGpa() const { return gpa; }

// Display
void Student::display() const {
    cout << "ID: " << id << ", Name: " << name << ", GPA: " << gpa << endl;
}

//////////////////////
// Main program
//////////////////////

int main() {
    vector<Student> students;  // Container for all students
    int choice;

    do {
        // Menu
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name;
            float gpa;

            // Input student info
            cout << "Enter ID: "; cin >> id; cin.ignore();
            cout << "Enter Name: "; getline(cin, name);
            cout << "Enter GPA: "; cin >> gpa;

            // Add student to vector
            students.push_back(Student(id, name, gpa));
            cout << "Student added successfully!\n";
        }
        else if (choice == 2) {
            if (students.empty())
                cout << "No students available.\n";
            else
                for (const auto& s : students)
                    s.display();
        }
        else if (choice == 3) {
            int searchId; 
            cout << "Enter ID to search: "; cin >> searchId;
            bool found = false;

            // Search by ID
            for (const auto& s : students) {
                if (s.getId() == searchId) {
                    s.display();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Student not found.\n";
        }

    } while (choice != 4); // Repeat until exit

    cout << "Exiting program...\n";
    return 0;
}
