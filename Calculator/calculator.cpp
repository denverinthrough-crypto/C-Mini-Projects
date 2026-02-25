#include <iostream>
using namespace std;

class Calculator {
private:
    double num1;
    double num2;
   

public:
    void getInput() {
        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter second number: ";
        cin >> num2;
    }

    double add() {
        cout << num1;
        
    }

    double subtract() {
        return num1 - num2;
    }

    double multiply() {
        return num1 * num2;
    }

    double division() {
        if (num2 == 0) {
            cout << "Error: Cannot divide by zero.\n";
            return 0;
        }
        return num1 / num2;
    }
};

int main() {
    Calculator calc;
    char choice;
    char again;

    do {
        cout << "\n===== Simple OOP Calculator =====\n";
        cout << "Choose options:\n1. Add\n2. Subtract\n3. Multiply\n4. Division\n ";
        cout << "Enter option: ";
        cin >> choice;

        calc.getInput();

        switch(choice) {
            case '1':
                cout << "Result: " << calc.add() << endl;
                break;

            case '2':
                cout << "Result: " << calc.subtract() << endl;
                break;

            case '3':
                cout << "Result: " << calc.multiply() << endl;
                break;

            case '4':
                cout << "Result: " << calc.division() << endl;
                break; 
            
            default:
                cout << "Invalid number. Only numbers from 1 to 5.\n";
        }

        cout << "\nDo you want to calculate again? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    cout << "Goodbye!\n";
    return 0;
}