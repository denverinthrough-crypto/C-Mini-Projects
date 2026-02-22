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
            if(amount > 0) {
                balance += amount; // increase balance
                cout << "Deposit $" << amount << " successfully.\n";

            } else {
                cout << "Invalid deposit amount.\n";
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
            cout << "Balance $" << balance << endl;
        }

};

/*
    ==========================
    MAIN PROGRAM
    ==========================
*/

int main() {

    // Create a new bank account object
    // Constructor runs here
    BankAccount myAccount("Denver", 12345, 500.0);

    // Show initial account state
    myAccount.showBalance();
    cout << endl;

    // Deposit money -> changes objects state
    myAccount.deposit(200);
    myAccount.showBalance();
    cout << endl;

    // Withdraw money -> changes object state
    myAccount.withdraw(100);
    myAccount.showBalance();
    cout << endl;

    // Attempt invalid withdraw
    myAccount.withdraw(1000);
    myAccount.showBalance();
    cout << endl;

    return 0; // program ends
}