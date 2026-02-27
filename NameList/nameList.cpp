#include <string>      // for string type
#include <vector>      // for vector type
#include <iostream>    // for cout, cin
#include <cctype>      // for toupper()
#include <algorithm>   // for transform()
#include <limits>      // for numeric_limits
using namespace std;   // avoid writing std:: everywhere


// =====================
//   CLASS DEFINITION
// =====================
class Namelist {
    private:
        vector<string> names;  // dynamic array that stores all names

        // converts any string to uppercase letters
        // const = this method does not modify any member variables
        string toUpper(string text) const {
            transform(text.begin(), text.end(), text.begin(),  // loop from start to end of text
                [](unsigned char c) { return toupper(c); });   // lambda: convert each character to uppercase
            return text;                                        // return the converted string
        }

    public:

        // returns how many names are currently in the list
        // const = read only, does not modify anything
        int getSize() const {
            return names.size();  // size() returns the number of elements in the vector
        }

        // receives name by const reference (efficient, no copy, cannot modify original)
        // converts to uppercase then appends to the vector
        void addName(const string& name) {
            string upperName = toUpper(name);   // convert name to uppercase
            names.push_back(upperName);         // append to end of vector
            cout << "Added: " << upperName << endl;  // confirm to user
        }

        // loops through all names and prints them with 1-based index
        // const = display only, does not modify anything
        void showNames() const {
            if (names.empty()) {                     // check if vector has no elements
                cout << "No names in the list.\n";   // inform user
                return;                              // exit early, nothing to show
            }
            for (size_t i = 0; i < names.size(); i++) {       // size_t = unsigned int, matches size() return type
                cout << i + 1 << ". " << names[i] << endl;    // i+1 so display starts at 1 not 0
            }
        }

        // searches for a name in the list by comparing uppercase versions
        // const = read only, does not modify anything
        void searchName(const string& name) const {
            string upperName = toUpper(name);              // convert search input to uppercase for fair comparison
            for (size_t i = 0; i < names.size(); i++) {   // loop through every name
                if (names[i] == upperName) {               // compare current name with search input
                    cout << upperName << " found at index " << i + 1 << endl;  // print 1-based index
                    return;                                // stop searching, already found
                }
            }
            cout << upperName << " not found.\n";  // only reached if loop finishes without finding
        }

        // removes a name at a given index (0-based internally)
        void removeName(size_t index) {
            if (index >= names.size()) {     // check if index is out of range
                cout << "Invalid index.\n";
                return;                      // exit early, nothing to remove
            }
            cout << "Removed: " << names[index] << endl;   // confirm what was removed
            names.erase(names.begin() + index);            // erase element at position index
                                                           // names.begin() is a pointer to first element
                                                           // + index moves it to the target position
        }

        // replaces the name at a given index with a new name (0-based internally)
        void modifyName(size_t index, const string& newName) {
            if (index >= names.size()) {     // check if index is out of range
                cout << "Invalid index.\n";
                return;                      // exit early, nothing to modify
            }
            names[index] = toUpper(newName); // overwrite old name with new uppercase name
            cout << "Updated successfully.\n";
        }

        // prints the name at a given index (0-based internally)
        // const = read only, does not modify anything
        void accessName(size_t index) const {
            if (index >= names.size()) {     // check if index is out of range
                cout << "Invalid index.\n";
                return;                      // exit early, nothing to access
            }
            cout << "Name: " << names[index] << endl;  // print the name at that position
        }
};


// =====================
//   HELPER FUNCTION
// =====================

// safely reads an index from the user, keeps asking until valid input is given
// prompt = the message shown to the user e.g. "Index to remove (1 to 3): "
size_t getIndex(const string& prompt) {
    string input;
    while (true) {                   // loop forever until valid input is given
        cout << prompt;
        getline(cin, input);         // read full line as string, avoids cin failure on bad input
        try {
            int val = stoi(input);   // try to convert string to integer, throws exception if it fails
            if (val < 1) {           // index must be at least 1 (we use 1-based display)
                cout << "Invalid index. Please enter a valid number.\n";
                continue;            // restart loop, ask again
            }
            return (size_t)val;      // cast to size_t and return valid index
        } catch (...) {              // catches any exception from stoi (e.g. user typed a letter)
            cout << "Invalid index. Please enter a valid number.\n";
                                     // loop continues automatically, asks again
        }
    }
}


// =====================
//       MAIN
// =====================
int main() {
    Namelist myList;    // create an instance of Namelist class
    int choice = -1;    // initialize to -1 so the while condition (choice != 0) starts as true

    do {
        // print menu
        cout << "\n ====== NAME-LIST ===== \n";
        cout << "\n1. Add\n2. Show\n3. Search\n4. Remove\n5. Modify\n6. Access\n0. Exit\nChoice: ";

        string input;
        getline(cin, input);   // read entire line as string, prevents cin failure on bad input

        try {
            choice = stoi(input);   // try to convert input to integer
        } catch (...) {             // if user typed a letter or symbol, stoi throws an exception
            cout << "Invalid input. Please enter a number.\n";
            continue;               // restart loop, skip the if/else block below
        }

        if (choice == 1) {
            string name;
            cout << "Enter name: ";
            getline(cin, name);       // read full name including spaces
            myList.addName(name);

        } else if (choice == 2) {
            myList.showNames();       // display all names

        } else if (choice == 3) {
            string name;
            cout << "Search name: ";
            getline(cin, name);       // read full name to search
            myList.searchName(name);

        } else if (choice == 4) {
            myList.showNames();       // show list first so user knows what index to pick
            size_t index = getIndex("Index to remove (1 to " + to_string(myList.getSize()) + "): ");
            myList.removeName(index - 1);   // subtract 1 to convert from 1-based display to 0-based internal

        } else if (choice == 5) {
            myList.showNames();       // show list first so user knows what index to pick
            size_t index = getIndex("Index to modify (1 to " + to_string(myList.getSize()) + "): ");
            string name;
            cout << "New Name: ";
            getline(cin, name);               // read new name
            myList.modifyName(index - 1, name);  // subtract 1 to convert from 1-based to 0-based

        } else if (choice == 6) {
            myList.showNames();       // show list first so user knows what index to pick
            size_t index = getIndex("Index to access (1 to " + to_string(myList.getSize()) + "): ");
            myList.accessName(index - 1);    // subtract 1 to convert from 1-based to 0-based

        } else if (choice != 0) {            // if choice is not 0-6, it's invalid
            cout << "Invalid choice. Pick from 0 to 6.\n";
        }

    } while (choice != 0);   // keep looping until user picks 0 to exit

    cout << "Goodbye\n";
    return 0;   // 0 means program ended successfully
}