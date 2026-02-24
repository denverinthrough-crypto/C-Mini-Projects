#include <iostream>
#include <vector>
using namespace std;

int main() {

    // Create a vector to store student scores
    vector<int> scores;

    int choice; // variable to store user menu choice

    do {
        // Display menu
        cout << "\n=== Student Score Manager ===\n";
        cout << "1. Add score\n";
        cout << "2. Show scores\n";
        cout << "3. Remove score\n";
        cout << "4. Show average\n";
        cout << "5. Exit\n";
        cin >> choice;

        // Option 1: Add a score to the vector
        if (choice == 1) {
            int s;
            cout << "Enter score: ";
            cin >> s;
            // push_back adds element to the end of the vector
            scores.push_back(s);

        }

        // Option 2: Display all scores
        else if (choice == 2) {
            cout << "Scores: ";
            // Range-based for loop to go through each element
            for(int s : scores)
                cout << s << " ";
            cout << "\n";
        }

        // Option 3: Remove a score from the vector
        else if (choice == 3) {
            int removeScore;
            cout << "Enter score to remove: ";
            cin >> removeScore;

            bool found = false; // flag to check if score exists

            // Use iterator to safely remove element
            for (auto it = scores.begin(); it != scores.end(); ++it) {
                if (*it == removeScore) { // check value at iterator
                    it = scores.erase(it); // erase returns iterator to next element
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Score not found.\n";
        }

        // Option 4: Calculate and display average score
        else if (choice == 4) {
            if (scores.empty()){
                cout << "No scores yet.\n"; // handle empty vector
            } else {
                double sum = 0;
                for (int s : scores) sum += s; // add all elements
                cout << "Average: " << sum / scores.size() << "\n"; // compute average
            }
        }
    } while (choice != 5); // repeat until user chooses Exit

    cout << "Goodbye!\n";
    return 0;
}