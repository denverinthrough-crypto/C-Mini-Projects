#include <iostream>
using namespace std;


double convert(double temp ){
        return (temp * 9/5) + 32;
        
};

int main(){
    
    string choice;
    
    do {
        double num;

        cout << "Enter number: \n"; // user's input
        cin >> num;
        cout << "The temperature is: " << convert(num) << + " F" << "\n";

        cout << "Try again (Yes/No): \n";
        cin >> choice;
        cout << "\n";
    }
    while (choice == "Yes" || choice == "yes");

    cout << "Goodbye!\n";

    return 0;

    
}


// convert c to f - checked
// add temp to convert