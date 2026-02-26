#include <iostream> // for cout / input-output
#include <string> // for string type
using namespace std;

/*
    ===============================
    BANK ACCOUNT CLASS
    ===============================
    this class represents ONE bank account.
    An object created from this class will own:
    - account holder name
    - account number
    - balance

*/

class BankAccount {
    private:
        // Private -> data is protected
        // Only class functions can change these values
        string accountHolder;
        int accountNumber;
        double balance;
        const double maxLimitDeposit = 2000.0;

    public:

        /*
            CONSTRUCTOR
            Runs automatically when an object is created.
            It sets the starting values of the account.
        */
        BankAccount(string name, int number, double initialBalance) {
            accountHolder = name;
            accountNumber = number;
            balance = initialBalance;
        }

        /*
            DEPOSIT FUNCTION
            Adds money to the balance.
            Checks that the amount is positive.
        */
        
        void deposit(double amount) {
            if (amount <= 0) {
                cout << "Invalie deposit amount.\n";

            } else if (amount > maxLimitDeposit) {
                cout << "$2000.0 maximum deposit!\n";

            } else {
                balance += amount;
                cout << "Deposit $ " << amount << " successfully.\n";

            }
        }

        /*
            WITHDRAW FUNCTION
            Removes money from the balance.
            Checks:
            - amount is positive
            - enough money exists
        */

        void withdraw(double amount) {
            if (amount > 0 && amount <= balance) {
                balance -= amount; // decrease balance
                cout << "Withdraw $" << amount << " successfully.\n";

            } else {
                cout << "Insufficient funds or invalid amount.\n";
            }
        }

        /*
            SHOW BALANCE
            Display account information.
            This does not change data -> read-only action.
        */

        void showBalance() {
            cout << "Account Holder: " << accountHolder << endl;
            cout << "Account Number: " << accountNumber << endl;
            cout << "Balance: $" << balance << endl;
        }

};

/*
    ==========================
    MAIN PROGRAM
    ==========================
*/

int main() {

    // Create one bank account object
    // Constructor automatically sets name, number, and starting balance
    BankAccount myAccount("Denver", 12345, 500.0);

    int choice; // stores menu choice from user
    double amount; // stores deposit/withdraw amount


    // Loop keeps program running until user choices Exit
    do {
        cout << "\n=== BANK MENU ===\n";
        cout << "1. Show Balance\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Exit\n";

        // Ask user what they want to do
        cout << "Choose: ";
        cin >> choice;

        // Decide what action to perform
        switch(choice) {

            // Case 1 -> just display account info
            case 1:
                myAccount.showBalance();
                break;

            // Case 2 -> deposit money
            case 2:
                cout << "Enter amount of deposit: ";
                cin >> amount; // read amount
                myAccount.deposit(amount); // call class function
                break;

            // Case 3 -> withdraw money
            case 3:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                myAccount.withdraw(amount);
                break;

            // Case 4 -> exit program
            case 4:
                cout << "Goodbye!\n";
                break;

            // Any other number -> invalid
            default:
                cout << "Invalid option.\n";


        }
    } while(choice != 4); // repeat until Exit is chosen

    return 0; // program ends

}