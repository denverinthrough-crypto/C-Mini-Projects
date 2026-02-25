#include <iostream>
#include <limits>
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

    double add() { return num1 + num2; }
    double subtract() { return num1 - num2; }
    double multiply() { return num1 * num2; }
    double division() {
        if (num2 == 0) {
            cout << "Error: Cannot divide by zero.\n";
            return 0;
        }
        return num1 / num2;
    }

    void showOperation(char op) {
        cout << num1 << " " << op << " " << num2 << endl;
    }
};

int main() {
    Calculator calc;
    char again;

    do {
        char choice;

        cout << "\n===== Simple OOP Calculator =====\n";
        cout << "Choose options:\n";
        cout << "1. Add\n2. Subtract\n3. Multiply\n4. Division\n";
        cout << "Enter option: ";
        cin >> choice;

        if (choice < '1' || choice > '4') {
            cout << "Invalid option. Try again.\n";
            continue;
        }

        calc.getInput();

        double result = 0;
        char opChar;

        switch(choice) {
            case '1':
                opChar = '+';
                result = calc.add();
                break;
            case '2':
                opChar = '-';
                result = calc.subtract();
                break;
            case '3':
                opChar = '*';
                result = calc.multiply();
                break;
            case '4':
                opChar = '/';
                result = calc.division();
                break;
        }

        // Print the operation first
        calc.showOperation(opChar);

        // Wait for Enter key
        cout << "Press Enter to see result.....";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore leftover input
        cin.get(); // wait for Enter

        // Then print the result
        cout << "Result: " << result << endl;

        cout << "\nDo you want to calculate again? (y/n): ";
        cin >> again;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear input buffer

    } while(again == 'y' || again == 'Y');

    cout << "Goodbye!\n";
    return 0;
}