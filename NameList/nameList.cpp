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
        void showNames() {
            if (names.empty()) {
                cout << "No names in the list.\n";
            }
            else {
                cout << "Names in the list:\n";
                for (const string& name :  names) {
                    cout << "- " << name << endl;
                }
            }
        }
};

int main() {
    Namelist myList;

    myList.addName("Denver");
    myList.addName("Alice");
    myList.addName("Bob");

    myList.showNames();

    return 0;
}
    
