#include <iostream>
using namespace std;

class Calculator {
    private: // Accesss identifiers
        double num1; // attributes
        double num2; // attributes

    public: // Access identifiers
        
        // Function to get input from user
        void getInput() {
            cout << "Enter first number: ";
            cin >> num1;

            cout << "Enter second number: ";
            cin >> num2;
        }

        double add() {      // double for floating or decimal points
            return num1 + num2;
        }

        double subtract() {
            return num1 - num2;
        }

        double multiply() {
            return num1 * num2;
        }

        double division() {
            return num2 / num2;
        }
};

// Main Program

int main() {
    Calculator calc; // create object of Calculator
    char choice; // single character like numbers and letters to choose.
    char again; // 

    do {
        cout << "\n ====== Simple OOP Calculator =====\n";
        cout  << "\n";
        cout << "Choose operation (+, -, *, /): ";
        cin >> choice;

        calc.getInput();
        
        switch(choice) {
            case '+':
                cout << "Result: " << calc.add() << endl;
                break;
            
            case '-':
                cout << "Result: " << calc.subtract() << endl;
                break;

            case '*':
                cout << "Result: " << calc.multiply() << endl;
                break;

            case '/':
                cout << "Result: " << calc.division() << endl;

            default:
                cout << "Invalid operator.\n";
        }

        cout << "\nDo you want to calculate again? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    cout << "Goodbye!\n";

    return 0;
    
}