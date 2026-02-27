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
                cout << i << ": " << names[i] << endl;
            }
        }

        void searchName(const string& name) const {
            string upperName = toUpper(name);
            for (size_t i = 0; i < names.size(); i++) {
                if (names[i] == upperName) {
                    cout << upperName << " found at index " << i << endl;
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

int main() {
    Namelist myList;
    int choice = -1;

    do {
        cout << " ====== NAME-LIST ===== \n";
        cout << "\n1. Add\n2. Show\n3. Search\n4. Remove\n5. Modify\n6. Access\n0. Exit\nChoice: ";
        
        string input;
        getline(cin, input);  // read everything as string, no cin failure possible

        try {
            choice = stoi(input);  // try to convert to int
        } catch (...) {
            cout << "Invalid input. Please enter a number from 1 to 6: \n";
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
            size_t index;
            cout << "Index to remove, pick from 0 to 4: ";
            cin >> index;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            myList.removeName(index);

        } else if (choice == 5) {
            size_t index;
            string name;
            cout << "Index to modify: ";
            cin >> index;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "New Name: ";
            getline(cin, name);
            myList.modifyName(index, name);

        } else if (choice == 6) {
            size_t index;
            cout << "Index to access from 0 to 4: ";
            cin >> index;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            myList.accessName(index);
        }

    } while (choice != 0);

    cout << "Goodbye\n";
    return 0;
}