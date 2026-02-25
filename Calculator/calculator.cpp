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
        return num1 + num2;
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
                break; // ✅ important!
            
            default:
                cout << "Invalid operator.\n";
        }

        cout << "\nDo you want to calculate again? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    cout << "Goodbye!\n";
    return 0;
}