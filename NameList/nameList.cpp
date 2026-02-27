#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <limits>
using namespace std;

class Namelist {
    private:
        vector<string> names;

        string toUpper(string text) const {
            transform(text.begin(), text.end(), text.begin(),
                [](unsigned char c) { return toupper(c); });
            return text;
        }

    public:

        int getSize() const {
            return names.size();
        }

        void addName(const string& name) {
            string upperName = toUpper(name);
            names.push_back(upperName);
            cout << "Added: " << upperName << endl;
        }

        void showNames() const {
            if (names.empty()) {
                cout << "No names in the list.\n";
                return;
            }
            for (size_t i = 0; i < names.size(); i++) {
                cout << i + 1 << ". " << names[i] << endl;
            }
        }

        void searchName(const string& name) const {
            string upperName = toUpper(name);
            for (size_t i = 0; i < names.size(); i++) {
                if (names[i] == upperName) {
                    cout << upperName << " found at index " << i + 1 << endl;
                    return;
                }
            }
            cout << upperName << " not found.\n";
        }

        void removeName(size_t index) {
            if (index >= names.size()) {
                cout << "Invalid index.\n";
                return;
            }
            cout << "Removed: " << names[index] << endl;
            names.erase(names.begin() + index);
        }

        void modifyName(size_t index, const string& newName) {
            if (index >= names.size()) {
                cout << "Invalid index.\n";
                return;
            }
            names[index] = toUpper(newName);
            cout << "Updated successfully.\n";
        }

        void accessName(size_t index) const {
            if (index >= names.size()) {
                cout << "Invalid index.\n";
                return;
            }
            cout << "Name: " << names[index] << endl;
        }
};

// helper function to safely get an index from user
size_t getIndex(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);
        try {
            int val = stoi(input);
            if (val < 1) {
                cout << "Invalid index. Please enter a valid number.\n";
                continue;
            }
            return (size_t)val;
        } catch (...) {
            cout << "Invalid index. Please enter a valid number.\n";
        }
    }
}

int main() {
    Namelist myList;
    int choice = -1;

    do {
        cout << "\n ====== NAME-LIST ===== \n";
        cout << "\n1. Add\n2. Show\n3. Search\n4. Remove\n5. Modify\n6. Access\n0. Exit\nChoice: ";

        string input;
        getline(cin, input);

        try {
            choice = stoi(input);
        } catch (...) {
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice == 1) {
            string name;
            cout << "Enter name: ";
            getline(cin, name);
            myList.addName(name);

        } else if (choice == 2) {
            myList.showNames();

        } else if (choice == 3) {
            string name;
            cout << "Search name: ";
            getline(cin, name);
            myList.searchName(name);

        } else if (choice == 4) {
            myList.showNames();
            size_t index = getIndex("Index to remove (1 to " + to_string(myList.getSize()) + "): ");
            myList.removeName(index - 1);

        } else if (choice == 5) {
            myList.showNames();
            size_t index = getIndex("Index to modify (1 to " + to_string(myList.getSize()) + "): ");
            string name;
            cout << "New Name: ";
            getline(cin, name);
            myList.modifyName(index - 1, name);

        } else if (choice == 6) {
            myList.showNames();
            size_t index = getIndex("Index to access (1 to " + to_string(myList.getSize()) + "): ");
            myList.accessName(index - 1);

        } else if (choice != 0) {
            cout << "Invalid choice. Pick from 0 to 6.\n";
        }

    } while (choice != 0);

    cout << "Goodbye\n";
    return 0;
}

