#include <iostream> // Needef for input/output (cin, cout)
#include <vector> // Needef for std::vector to store multiple students
#include "../include/Student.h" // Include the Student class definition

using namespace std; // So we don't have to write std:: before every std function

// ====================
// Implementation of Student class functions
// =====================

// Constructor: called when we create anew Student object
// Initializes the Student's id, name, and gpa

Student::Student(int id, string name, float gpa) {
    this->id = id; // *this-> refers to the member varialbe of the object
    this->name = name;
    this->gpa = gpa;
}

// Getter for ID
int Student::getId() const { return id; }

// Getter for Name
string Student::getName() const { return name; }

// Getter for GPA
float Student::getGpa() const { return gpa; }

// Dispaly function: prints student info
void Student::display() const {
    cout << "ID: " << id << ", Name: " << name << ", GPA: " << gpa << endl;

}

// ===============
// Main program starts here
// ===============

int main() {
    vector<Student> students; // Dyanmic array to store all students
    int choice; // User menu choice

    do {
        // Display menu
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        // ==============
        // OPTION 1: Add a new student
        // ==============

        if (choice == 1) {
            int id;
            string name;
            float gpa;

            // Take input from user
            cout << "Enter ID: ";
            cin >> id;
            cin.ignore(); // Ignore leftover newline from previous input
            cout << "Enter Name: ";
            getline(cin, name); //Read full line for name
            cout << "Enter GPA: ";
            cin >> gpa;

            // Creat a Student object and add it to the vector
            students.push_back(Student(id, name, gpa));
            cout << "Student added successfully!\n";

        }

        // ===============
        // OPTION 2: View all students
        // ===============

        else if (choice == 2) {
            if(students.empty()) {
                cout << "No students availble.\n";
            
            } else {
                // Loop through vector and display each student
                for (const auto& s : students) {
                    s.display(); // Calls the display() method of Student
                }
            }
        }

        // ===============
        // OPTION 3: Search student by ID
        // ===============

        else if (choice == 3) {
            int searchId;
            cout << "Enter ID to search: ";
            cin >> searchId;

            bool found = false;

            // Loop through all students
            for (const auto& s : students) {
                if (s.getId() == searchId) { //Compare entered ID with student ID
                    s.display(); // Show student info
                    found == true; // Mark as found
                    break; // Stop searching once found
                }
            }

            if (!found) {
                cout << "Student not found.\n";
            }
        }

        // =======================
        // OPTION 4: Exit
        // =======================





    }while (choice != 4); // Keep looping until user chooses 4

    cout << "Exiting program...\n";
}