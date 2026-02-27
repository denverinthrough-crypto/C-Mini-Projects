#include <string>
#include <vector>
#include <iostream>
using namespace std;


class Namelist {
    private:
        vector<string> names; // store names

    public:
        // Add a name to the list

        void addName(const string& name) {
            names.push_back(name);
            cout << "Added: " << name << endl;

        }

        // Display all names
        void showNames() const {
            if (names.empty()) {
                cout << "No names in the list.\n";
                return;
            }
            for (size_t i = 0; i < names.size(); i++) {
                cout << i << ": " << names[i] << endl;
            
            }
        }

        // Search name

        void searchName(const string& name) const {
            for (size_t i = 0; i < names.size(); i++) {
                if (names[i] == name) {
                    cout << name << " found at index " << i << endl;
                    return;
                }
            }
            cout << name << " not found.\n";
        }

        // Remove Name
        void removeName(size_t index) {
            if(index >= names.size()) {
                cout << "Invalid index.\n";
                return;
            }
            cout << "Removed: " << names[index] << endl;
            names.erase(names.begin() + index);
        }

        // Modify names
        void modifyName(size_t index, const string& newName) {
            if(index >= names.size()) {
                cout << "Invalid index.\n";
                return;
            }
            names[index] = newName;
            cout << "Updated successfully.\n";
        }

        // Access name
        void accessName(size_t index) const {
            if(index >= names.size()) {
                cout << "Invalid index.\n";
                return;
            }
            cout << "Name: " << names[index] << endl;
        }

};

int main() {
    Namelist myList;
    int choice;

   do {
    cout << "\n1. Add\n2. Show\n3. Search\n4. Remove\n5. Modify\n6. Access\n0. Exit\nChoice: ";
    cin >> choice;

    if (choice == 1) {
        string name;
        cout << "Enter name: ";
        cin >> name;
        myList.addName(name);

    } else if (choice == 2) {
        myList.showNames();
    
    } else if (choice == 3) {
        string name;
        cout << "Search name: ";
        cin >> name;
        myList.searchName(name);

    } else if (choice == 4) {
        size_t index;
        cout << "Index to remove: ";
        cin >> index;
        myList.removeName(index);

    } else if (choice == 5) {
        size_t index;
        string name;

        cout << "Index to modify: ";
        cin >> index;
        cout << "New Name: ";
        cin >> name;

        myList.modifyName(index, name);

    } else if (choice == 6) {
        size_t index;
        cout << "Index to access: ";
        cin >> index;
        myList.accessName(index);
    }

   } while (choice != 0);

   cout << "Goodbye\n";


    return 0;
}
    
